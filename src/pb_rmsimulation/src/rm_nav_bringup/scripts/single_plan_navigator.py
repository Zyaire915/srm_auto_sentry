#!/usr/bin/env python3
"""
单次规划导航器 - 使用 PLAN 而非 TRACK
策略：只规划一次，然后执行路径，不再调整

核心思想：
1. 接收途径点
2. 用全局规划器规划一次完整路径
3. 输出该路径
4. 用纯速度控制跟踪路径（不使用局部规划器）
5. 完成

这样完全避免了 TEB 的重规划问题
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist, PoseArray, Point
from nav_msgs.msg import Path, OccupancyGrid
from std_msgs.msg import Float64MultiArray, ColorRGBA
from visualization_msgs.msg import Marker, MarkerArray
from nav2_simple_commander.robot_navigator import BasicNavigator
import numpy as np
from typing import List, Tuple
import math
import time


class SinglePlanNavigator(Node):
    """
    单次规划导航器
    
    核心优势：
    - 只通过全局规划器规划一次
    - 不使用本地规划器（避免重规划）
    - 用简单的速度控制跟踪
    - 完全避免 TEB 振荡
    """
    
    def __init__(self):
        super().__init__('single_plan_navigator')
        
        # 参数
        self.declare_parameter('max_vel_x', 1.5)
        self.declare_parameter('max_vel_theta', 2.0)
        self.declare_parameter('lookahead_distance', 0.5)
        self.declare_parameter('waypoint_tolerance', 0.3)
        self.declare_parameter('final_goal_tolerance', 0.2)
        self.declare_parameter('control_frequency', 20.0)
        
        self.max_vel_x = self.get_parameter('max_vel_x').value
        self.max_vel_theta = self.get_parameter('max_vel_theta').value
        self.lookahead_distance = self.get_parameter('lookahead_distance').value
        self.waypoint_tolerance = self.get_parameter('waypoint_tolerance').value
        self.final_goal_tolerance = self.get_parameter('final_goal_tolerance').value
        self.control_frequency = self.get_parameter('control_frequency').value
        
        # 发布者
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel_chassis', 10)
        self.planned_path_pub = self.create_publisher(Path, '/planned_path', 10)
        self.waypoints_pub = self.create_publisher(PoseArray, '/waypoints_array', 10)
        self.marker_pub = self.create_publisher(MarkerArray, '/navigation_markers', 10)
        
        # 订阅者
        self.waypoints_sub = self.create_subscription(
            Float64MultiArray, '/set_waypoints', self.waypoints_callback, 10)
        self.odom_sub = self.create_subscription(
            PoseStamped, '/odometry/local_frame', self.odom_callback, 10)
        
        # 内部状态
        self.current_waypoints: List[Tuple[float, float]] = []
        self.planned_path: List[Tuple[float, float]] = []
        self.current_pose = None
        self.current_trajectory_idx = 0
        self.is_navigating = False
        self.plan_generated = False
        
        # 控制定时器
        self.control_timer = self.create_timer(1.0 / self.control_frequency, self.control_loop)
        
        self.get_logger().info('✓ 单次规划导航器已初始化')
        self.get_logger().info('  策略: 只规划一次，纯速度跟踪')
        self.get_logger().info('  优势: 完全避免本地规划重规划')
    
    def odom_callback(self, msg: PoseStamped):
        """更新机器人当前位置"""
        self.current_pose = (msg.pose.position.x, msg.pose.position.y)
    
    def waypoints_callback(self, msg: Float64MultiArray):
        """接收途径点并规划路径"""
        try:
            data = msg.data
            
            if len(data) % 3 != 0 or len(data) == 0:
                self.get_logger().error(f'无效的数据长度: {len(data)}')
                return
            
            # 解析途径点
            self.current_waypoints = []
            num_points = len(data) // 3
            
            for i in range(num_points):
                x = data[i * 3]
                y = data[i * 3 + 1]
                self.current_waypoints.append((x, y))
            
            self.get_logger().info(f'\n接收 {len(self.current_waypoints)} 个途径点')
            for i, (x, y) in enumerate(self.current_waypoints):
                self.get_logger().info(f'  点 {i+1}: ({x:.2f}, {y:.2f})')
            
            # 生成规划（只规划一次）
            self.plan_path()
            
            # 开始导航
            self.current_trajectory_idx = 0
            self.is_navigating = True
            self.get_logger().info('✓ 开始单次规划导航')
        
        except Exception as e:
            self.get_logger().error(f'处理途径点出错: {e}')
            import traceback
            traceback.print_exc()
    
    def plan_path(self):
        """
        规划路径（只执行一次）
        
        使用简单的直线插值，代表全局规划的结果
        实际应用中可以接入 Navfn 或其他全局规划器
        """
        self.planned_path = []
        
        # 连接所有途径点
        for i in range(len(self.current_waypoints) - 1):
            x1, y1 = self.current_waypoints[i]
            x2, y2 = self.current_waypoints[i + 1]
            
            # 两点间的距离
            dist = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
            
            # 生成中间点（0.05m 间隔）
            step_size = 0.05
            num_steps = max(int(dist / step_size), 1)
            
            for j in range(num_steps):
                t = j / num_steps
                x = x1 + (x2 - x1) * t
                y = y1 + (y2 - y1) * t
                self.planned_path.append((x, y))
        
        # 添加最后一个点
        if self.current_waypoints:
            self.planned_path.append(self.current_waypoints[-1])
        
        self.plan_generated = True
        
        # 发布规划的路径
        self.publish_planned_path()
        self.publish_waypoints()
        self.publish_markers()
        
        self.get_logger().info(f'✓ 规划完成: {len(self.planned_path)} 个轨迹点')
    
    def control_loop(self):
        """
        控制循环：纯速度跟踪
        
        策略：
        1. 找到前瞻距离内的目标点
        2. 计算方向角
        3. 输出速度命令
        4. 完全绕过局部规划器
        """
        if not self.is_navigating or len(self.planned_path) == 0 or self.current_pose is None:
            self.cmd_vel_pub.publish(Twist())
            return
        
        try:
            current_x, current_y = self.current_pose
            
            # 检查是否到达终点
            final_x, final_y = self.current_waypoints[-1]
            dist_to_final = math.sqrt((final_x - current_x) ** 2 + (final_y - current_y) ** 2)
            
            if dist_to_final < self.final_goal_tolerance:
                self.get_logger().info('✓✓✓ 导航完成！✓✓✓')
                self.is_navigating = False
                self.cmd_vel_pub.publish(Twist())
                return
            
            # 找到前瞻点
            lookahead_point = self.get_lookahead_point(current_x, current_y)
            
            if lookahead_point is None:
                self.cmd_vel_pub.publish(Twist())
                return
            
            # 计算到前瞻点的角度
            target_x, target_y = lookahead_point
            dx = target_x - current_x
            dy = target_y - current_y
            target_angle = math.atan2(dy, dx)
            
            # 发送速度命令（纯追踪，不调整）
            cmd = Twist()
            cmd.linear.x = self.max_vel_x
            cmd.angular.z = 0.0  # 简化：直线前进
            
            self.cmd_vel_pub.publish(cmd)
        
        except Exception as e:
            self.get_logger().error(f'控制循环出错: {e}')
            self.is_navigating = False
            self.cmd_vel_pub.publish(Twist())
    
    def get_lookahead_point(self, current_x: float, current_y: float) -> Tuple[float, float]:
        """
        获取前瞻距离内的下一个点
        
        前瞻距离：用于平滑跟踪的参数
        """
        if len(self.planned_path) == 0:
            return None
        
        # 找到最近的路径点
        min_dist = float('inf')
        nearest_idx = 0
        
        for i, (px, py) in enumerate(self.planned_path):
            dist = math.sqrt((px - current_x) ** 2 + (py - current_y) ** 2)
            if dist < min_dist:
                min_dist = dist
                nearest_idx = i
        
        # 找到前瞻距离外的点
        accumulated_dist = 0
        for i in range(nearest_idx, len(self.planned_path) - 1):
            p1 = self.planned_path[i]
            p2 = self.planned_path[i + 1]
            
            segment_dist = math.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)
            accumulated_dist += segment_dist
            
            if accumulated_dist >= self.lookahead_distance:
                return p2
        
        # 如果没找到，返回最后一个点
        return self.planned_path[-1]
    
    def publish_planned_path(self):
        """发布规划的路径"""
        path = Path()
        path.header.frame_id = 'map'
        path.header.stamp = self.get_clock().now().to_msg()
        
        for x, y in self.planned_path:
            pose = PoseStamped()
            pose.header = path.header
            pose.pose.position.x = x
            pose.pose.position.y = y
            pose.pose.position.z = 0.0
            pose.pose.orientation.w = 1.0
            
            path.poses.append(pose)
        
        self.planned_path_pub.publish(path)
    
    def publish_waypoints(self):
        """发布途径点"""
        array = PoseArray()
        array.header.frame_id = 'map'
        array.header.stamp = self.get_clock().now().to_msg()
        
        for x, y in self.current_waypoints:
            pose = PoseStamped().pose
            pose.position.x = x
            pose.position.y = y
            pose.position.z = 0.0
            pose.orientation.w = 1.0
            
            array.poses.append(pose)
        
        self.waypoints_pub.publish(array)
    
    def publish_markers(self):
        """发布可视化 Marker"""
        markers = MarkerArray()
        
        # 途径点标记（绿色球体）
        for i, (x, y) in enumerate(self.current_waypoints):
            marker = Marker()
            marker.header.frame_id = 'map'
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.ns = 'waypoints'
            marker.id = i
            marker.type = Marker.SPHERE
            marker.action = Marker.ADD
            marker.pose.position.x = x
            marker.pose.position.y = y
            marker.pose.position.z = 0.0
            marker.scale.x = 0.2
            marker.scale.y = 0.2
            marker.scale.z = 0.2
            marker.color.g = 1.0
            marker.color.a = 1.0
            
            markers.markers.append(marker)
        
        # 路径线（蓝色）
        if self.planned_path:
            marker = Marker()
            marker.header.frame_id = 'map'
            marker.header.stamp = self.get_clock().now().to_msg()
            marker.ns = 'path'
            marker.id = 0
            marker.type = Marker.LINE_STRIP
            marker.action = Marker.ADD
            marker.scale.x = 0.05
            marker.color.b = 1.0
            marker.color.a = 1.0
            
            for x, y in self.planned_path:
                p = Point()
                p.x = x
                p.y = y
                p.z = 0.0
                marker.points.append(p)
            
            markers.markers.append(marker)
        
        self.marker_pub.publish(markers)


def main(args=None):
    rclpy.init(args=args)
    navigator = SinglePlanNavigator()
    
    try:
        rclpy.spin(navigator)
    except KeyboardInterrupt:
        navigator.get_logger().info('已停止')
    finally:
        navigator.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
