#!/usr/bin/env python3
"""
多途径点导航器
- 支持根据途径点列表生成全局路线
- 点与点之间无时间间隔
- 支持动态调整每个点的坐标和容差
"""

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from geometry_msgs.msg import PoseStamped, PoseArray
from nav2_msgs.action import NavigateToPose
from nav_msgs.msg import Path
from std_msgs.msg import Float64MultiArray
from rcl_interfaces.msg import Parameter, ParameterValue
from rcl_interfaces.srv import SetParameters
import math
from typing import List, Tuple
import threading
import time


class WaypointsNavigator(Node):
    """
    多途径点导航器
    
    功能：
    - 接收途径点列表，生成完整的全局路线
    - 无间隔地依次导航到每个途径点
    - 支持动态调整每个点的坐标和容差
    """
    
    def __init__(self):
        super().__init__('waypoints_navigator')
        
        # 参数声明
        self.declare_parameter('waypoint_tolerance', 1.0)
        self.declare_parameter('final_goal_tolerance', 0.25)
        self.declare_parameter('goal_checker_timeout', 1.0)
        
        # 获取参数
        self.waypoint_tolerance = self.get_parameter('waypoint_tolerance').value
        self.final_goal_tolerance = self.get_parameter('final_goal_tolerance').value
        self.goal_checker_timeout = self.get_parameter('goal_checker_timeout').value
        
        # Nav2 Action 客户端
        self.nav_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        
        # 等待 action server
        if not self.nav_client.wait_for_server(timeout_sec=10):
            self.get_logger().error('navigate_to_pose action server 不可用')
            raise RuntimeError('Action server 初始化失败')
        
        # SetParameters 服务客户端
        self.set_params_client = self.create_client(SetParameters, '/controller_server/set_parameters')
        while not self.set_params_client.wait_for_service(timeout_sec=1):
            self.get_logger().info('等待 /controller_server/set_parameters 服务...')
        
        # 发布者
        self.route_pub = self.create_publisher(Path, '/global_route', 10)
        self.waypoints_pub = self.create_publisher(PoseArray, '/waypoints_array', 10)
        
        # 订阅者
        self.waypoints_sub = self.create_subscription(
            Float64MultiArray, '/set_waypoints', self.waypoints_callback, 10)
        
        # 内部状态
        self.current_waypoints: List[PoseStamped] = []
        self.current_tolerances: List[float] = []
        self.is_navigating = False
        self.current_goal_handle = None
        
        self.get_logger().info('✓ 多途径点导航器已初始化')
        self.get_logger().info('  - 订阅话题: /set_waypoints (Float64MultiArray)')
        self.get_logger().info('  - 发布话题: /global_route (Path), /waypoints_array (PoseArray)')
    
    def waypoints_callback(self, msg: Float64MultiArray):
        """
        接收途径点数据
        
        消息格式：[x1, y1, tol1, x2, y2, tol2, ..., xn, yn, toln]
        其中每个点包含：(x坐标, y坐标, tolerance)
        """
        try:
            data = msg.data
            
            # 验证数据长度必须是 3 的倍数
            if len(data) % 3 != 0 or len(data) == 0:
                self.get_logger().error(
                    f'无效的途径点数据格式！长度: {len(data)} (需要是 3 的倍数)')
                return
            
            # 解析途径点
            waypoints = []
            tolerances = []
            num_points = len(data) // 3
            
            for i in range(num_points):
                x = data[i * 3]
                y = data[i * 3 + 1]
                tolerance = data[i * 3 + 2]
                
                pose = self.create_pose(x, y, 0.0)
                waypoints.append(pose)
                tolerances.append(tolerance)
                
                self.get_logger().info(
                    f'  途径点 {i+1}: ({x:.2f}, {y:.2f}), 容差: {tolerance:.2f}m')
            
            # 存储并执行
            self.current_waypoints = waypoints
            self.current_tolerances = tolerances
            
            # 发布全局路线
            self.publish_global_route(waypoints)
            
            # 启动导航（如果不在导航中）
            if not self.is_navigating:
                self.get_logger().info(f'开始导航 {len(waypoints)} 个途径点')
                threading.Thread(target=self.navigate_waypoints, daemon=True).start()
        
        except Exception as e:
            self.get_logger().error(f'处理途径点时出错: {e}')
    
    def navigate_waypoints(self):
        """依次导航到所有途径点（无间隔）"""
        if self.is_navigating:
            self.get_logger().warn('已有导航任务在进行中')
            return
        
        self.is_navigating = True
        
        try:
            for i, (pose, tolerance) in enumerate(zip(self.current_waypoints, self.current_tolerances)):
                self.get_logger().info(f'\n--- 导航到途径点 {i+1}/{len(self.current_waypoints)} ---')
                self.get_logger().info(f'位置: ({pose.pose.position.x:.2f}, {pose.pose.position.y:.2f})')
                self.get_logger().info(f'容差: {tolerance:.2f}m')
                
                # 设置此点的容差
                self.set_goal_tolerance(tolerance)
                time.sleep(0.5)  # 等待参数生效
                
                # 发送导航目标
                if not self.send_navigation_goal(pose):
                    self.get_logger().error(f'导航到途径点 {i+1} 失败！')
                    break
                
                self.get_logger().info(f'✓ 到达途径点 {i+1}')
            
            self.get_logger().info('\n✓✓✓ 所有途径点导航完成！✓✓✓')
        
        except Exception as e:
            self.get_logger().error(f'导航过程出错: {e}')
        
        finally:
            self.is_navigating = False
    
    def send_navigation_goal(self, goal_pose: PoseStamped) -> bool:
        """
        发送单个导航目标并等待完成
        
        Args:
            goal_pose: 目标位姿
            
        Returns:
            成功返回 True，失败返回 False
        """
        try:
            # 创建 action 目标
            goal = NavigateToPose.Goal()
            goal.pose = goal_pose
            
            # 发送目标
            future = self.nav_client.send_goal_async(goal)
            rclpy.spin_until_future_complete(self, future, timeout_sec=30)
            
            self.current_goal_handle = future.result()
            
            if not self.current_goal_handle.accepted:
                self.get_logger().error('目标被导航器拒绝')
                return False
            
            # 等待结果
            result_future = self.current_goal_handle.get_result_async()
            rclpy.spin_until_future_complete(self, result_future, timeout_sec=300)
            
            result = result_future.result()
            
            if result.status == 4:  # SUCCEEDED
                return True
            else:
                self.get_logger().warn(f'导航失败，状态码: {result.status}')
                return False
        
        except Exception as e:
            self.get_logger().error(f'发送导航目标时出错: {e}')
            return False
    
    def set_goal_tolerance(self, tolerance: float) -> bool:
        """
        设置目标容差
        
        Args:
            tolerance: 容差值（米）
            
        Returns:
            设置成功返回 True
        """
        try:
            # 创建参数
            param = Parameter()
            param.name = 'general_goal_checker.xy_goal_tolerance'
            param.value = ParameterValue()
            param.value.type = 3  # double_value
            param.value.double_value = float(tolerance)
            
            # 调用服务
            request = SetParameters.Request()
            request.parameters = [param]
            
            future = self.set_params_client.call_async(request)
            rclpy.spin_until_future_complete(self, future, timeout_sec=self.goal_checker_timeout)
            
            response = future.result()
            
            if response.results[0].successful:
                self.get_logger().debug(f'✓ 容差已设置为 {tolerance:.2f}m')
                return True
            else:
                self.get_logger().warn(f'✗ 容差设置失败: {response.results[0].reason}')
                return False
        
        except Exception as e:
            self.get_logger().error(f'设置容差时出错: {e}')
            return False
    
    def publish_global_route(self, waypoints: List[PoseStamped]):
        """发布全局路线用于 RViz 可视化"""
        try:
            path_msg = Path()
            path_msg.header.frame_id = 'map'
            path_msg.header.stamp = self.get_clock().now().to_msg()
            path_msg.poses = waypoints
            
            self.route_pub.publish(path_msg)
            
            # 同时发布为 PoseArray
            pose_array = PoseArray()
            pose_array.header.frame_id = 'map'
            pose_array.header.stamp = self.get_clock().now().to_msg()
            pose_array.poses = [p.pose for p in waypoints]
            
            self.waypoints_pub.publish(pose_array)
            
            self.get_logger().debug(f'已发布 {len(waypoints)} 个途径点的全局路线')
        
        except Exception as e:
            self.get_logger().error(f'发布路线时出错: {e}')
    
    @staticmethod
    def create_pose(x: float, y: float, yaw: float = 0.0) -> PoseStamped:
        """
        创建位姿消息
        
        Args:
            x: X 坐标
            y: Y 坐标
            yaw: 偏航角（弧度）
            
        Returns:
            PoseStamped 消息
        """
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.pose.position.x = float(x)
        pose.pose.position.y = float(y)
        pose.pose.position.z = 0.0
        
        # 从偏航角创建四元数
        cos_yaw = math.cos(yaw / 2)
        sin_yaw = math.sin(yaw / 2)
        
        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = sin_yaw
        pose.pose.orientation.w = cos_yaw
        
        return pose


def main(args=None):
    rclpy.init(args=args)
    node = WaypointsNavigator()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('导航器已停止')
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
