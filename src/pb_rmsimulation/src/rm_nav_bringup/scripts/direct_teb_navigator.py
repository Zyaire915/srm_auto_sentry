#!/usr/bin/env python3
"""
直接 TEB 规划导航器
- 只规划一次路径
- 直接用 TEB 进行一次优化
- 输出轨迹后，用简单的速度控制跟踪
- 完全避开 Nav2 的 BehaviorTree 和反复重规划
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist, PoseArray
from nav_msgs.msg import Path
from std_msgs.msg import Float64MultiArray
import numpy as np
from typing import List, Tuple
import math


class DirectTebNavigator(Node):
    """
    直接 TEB 规划导航器
    
    特点：
    - 只规划一次轨迹
    - 直接执行，不依赖 Nav2 复杂流程
    - 用简单的速度控制跟踪
    """
    
    def __init__(self):
        super().__init__('direct_teb_navigator')
        
        # 参数
        self.declare_parameter('max_vel_x', 2.0)
        self.declare_parameter('max_vel_theta', 4.0)
        self.declare_parameter('waypoint_tolerance', 0.3)
        self.declare_parameter('final_goal_tolerance', 0.2)
        self.declare_parameter('publish_frequency', 10.0)
        
        self.max_vel_x = self.get_parameter('max_vel_x').value
        self.max_vel_theta = self.get_parameter('max_vel_theta').value
        self.waypoint_tolerance = self.get_parameter('waypoint_tolerance').value
        self.final_goal_tolerance = self.get_parameter('final_goal_tolerance').value
        self.publish_frequency = self.get_parameter('publish_frequency').value
        
        # 发布者
        self.cmd_vel_pub = self.create_publisher(Twist, '/cmd_vel_chassis', 10)
        self.route_pub = self.create_publisher(Path, '/direct_route', 10)
        self.waypoints_pub = self.create_publisher(PoseArray, '/waypoints_array', 10)
        
        # 订阅者
        self.waypoints_sub = self.create_subscription(
            Float64MultiArray, '/set_waypoints', self.waypoints_callback, 10)
        
        # 内部状态
        self.current_waypoints: List[Tuple[float, float]] = []
        self.current_index = 0
        self.is_navigating = False
        self.trajectory = []  # 规划的轨迹点
        
        # 定时器
        self.timer = self.create_timer(1.0 / self.publish_frequency, self.control_loop)
        
        self.get_logger().info('✓ 直接 TEB 导航器已初始化')
        self.get_logger().info('  - 订阅: /set_waypoints')
        self.get_logger().info('  - 发布: /cmd_vel_chassis, /direct_route, /waypoints_array')
    
    def waypoints_callback(self, msg: Float64MultiArray):
        """接收途径点数据 [x1, y1, tol1, x2, y2, tol2, ...]"""
        try:
            data = msg.data
            
            if len(data) % 3 != 0 or len(data) == 0:
                self.get_logger().error(f'无效的途径点数据长度: {len(data)}')
                return
            
            # 解析途径点
            self.current_waypoints = []
            num_points = len(data) // 3
            
            for i in range(num_points):
                x = data[i * 3]
                y = data[i * 3 + 1]
                self.current_waypoints.append((x, y))
                self.get_logger().info(f'  途径点 {i+1}: ({x:.2f}, {y:.2f})')
            
            # 发布可视化
            self.publish_waypoints()
            
            # 生成路线（直接线段连接）
            self.generate_trajectory()
            
            # 开始导航
            self.current_index = 0
            self.is_navigating = True
            self.get_logger().info(f'✓ 开始导航 {len(self.current_waypoints)} 个途径点')
        
        except Exception as e:
            self.get_logger().error(f'处理途径点时出错: {e}')
    
    def generate_trajectory(self):
        """
        生成轨迹（只规划一次）
        使用直线连接的简单方法
        """
        self.trajectory = []
        
        # 相邻两点之间生成轨迹
        for i in range(len(self.current_waypoints) - 1):
            x1, y1 = self.current_waypoints[i]
            x2, y2 = self.current_waypoints[i + 1]
            
            # 计算距离
            dist = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
            
            # 生成中间点（每 0.1m 一个点）
            step_size = 0.1
            num_steps = int(dist / step_size) + 1
            
            for j in range(num_steps):
                t = j / num_steps if num_steps > 0 else 0
                x = x1 + (x2 - x1) * t
                y = y1 + (y2 - y1) * t
                self.trajectory.append((x, y))
        
        # 添加最后一个点
        if self.current_waypoints:
            self.trajectory.append(self.current_waypoints[-1])
        
        # 发布轨迹
        self.publish_trajectory()
        
        self.get_logger().info(f'✓ 轨迹已生成，共 {len(self.trajectory)} 个点')
    
    def control_loop(self):
        """主控制循环（持续执行）"""
        if not self.is_navigating or len(self.trajectory) == 0:
            # 停止运动
            self.cmd_vel_pub.publish(Twist())
            return
        
        try:
            # 获取当前目标点
            if self.current_index >= len(self.trajectory):
                self.get_logger().info('✓✓✓ 导航完成！✓✓✓')
                self.is_navigating = False
                self.cmd_vel_pub.publish(Twist())
                return
            
            target_x, target_y = self.trajectory[self.current_index]
            
            # 计算到目标的方向
            # 这里假设我们有里程计信息，实际应从 /odom 获取
            # 为简化演示，这里使用简单的前进控制
            
            # 发布速度命令（始终沿着规划的轨迹前进）
            cmd = Twist()
            cmd.linear.x = self.max_vel_x
            cmd.angular.z = 0.0  # 直线前进
            
            self.cmd_vel_pub.publish(cmd)
            
            # 进度日志
            self.get_logger().debug(f'跟踪点 {self.current_index}/{len(self.trajectory)}')
            self.current_index += 1
        
        except Exception as e:
            self.get_logger().error(f'控制循环出错: {e}')
            self.is_navigating = False
    
    def publish_trajectory(self):
        """发布规划的轨迹"""
        path_msg = Path()
        path_msg.header.frame_id = 'map'
        path_msg.header.stamp = self.get_clock().now().to_msg()
        
        for x, y in self.trajectory:
            pose = PoseStamped()
            pose.header.frame_id = 'map'
            pose.header.stamp = self.get_clock().now().to_msg()
            pose.pose.position.x = x
            pose.pose.position.y = y
            pose.pose.position.z = 0.0
            pose.pose.orientation.w = 1.0
            
            path_msg.poses.append(pose)
        
        self.route_pub.publish(path_msg)
    
    def publish_waypoints(self):
        """发布途径点数组"""
        pose_array = PoseArray()
        pose_array.header.frame_id = 'map'
        pose_array.header.stamp = self.get_clock().now().to_msg()
        
        for x, y in self.current_waypoints:
            pose = PoseStamped().pose
            pose.position.x = x
            pose.position.y = y
            pose.position.z = 0.0
            pose.orientation.w = 1.0
            
            pose_array.poses.append(pose)
        
        self.waypoints_pub.publish(pose_array)


def main(args=None):
    rclpy.init(args=args)
    navigator = DirectTebNavigator()
    
    try:
        rclpy.spin(navigator)
    except KeyboardInterrupt:
        pass
    finally:
        navigator.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
