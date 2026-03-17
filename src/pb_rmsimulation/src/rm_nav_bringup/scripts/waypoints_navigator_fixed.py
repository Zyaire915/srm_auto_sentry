#!/usr/bin/env python3
"""
修复版本的多途径点导航器
==========================
核心差异：使用 ComputePathThroughPoses（只规划一次）而不是 navigate_through_poses
这样避免了 navigate_through_poses 的周期性重规划问题

工作流程：
1. 一次性调用 ComputePathThroughPoses，得到完整全局路径
2. 使用 FollowPath 严格跟随这个全局路径
3. 这样全局路径不会改变，避免绕圈问题
"""

import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from geometry_msgs.msg import PoseStamped, PoseArray
from nav2_msgs.action import FollowPath, ComputePathThroughPoses
from nav_msgs.msg import Path
from std_msgs.msg import Float64MultiArray
from rcl_interfaces.msg import Parameter, ParameterValue
from rcl_interfaces.srv import SetParameters
import math
from typing import List
import threading
import time


class WaypointsNavigatorFixed(Node):
    """
    修复版本的多途径点导航器
    
    关键改进：
    - 使用 ComputePathThroughPoses 只规划一次全局路径
    - 使用 FollowPath 严格跟随该路径
    - 避免 navigate_through_poses 的周期性重规划
    """
    
    def __init__(self):
        super().__init__('waypoints_navigator_fixed')
        
        # 参数声明
        self.declare_parameter('waypoint_tolerance', 1.0)
        self.declare_parameter('final_goal_tolerance', 0.25)
        
        # 获取参数
        self.waypoint_tolerance = self.get_parameter('waypoint_tolerance').value
        self.final_goal_tolerance = self.get_parameter('final_goal_tolerance').value
        
        # 创建 Action 客户端
        self.compute_path_client = ActionClient(
            self, ComputePathThroughPoses, 'compute_path_through_poses')
        self.follow_path_client = ActionClient(self, FollowPath, 'follow_path')
        
        # 等待 action servers
        if not self.compute_path_client.wait_for_server(timeout_sec=10):
            self.get_logger().error('compute_path_through_poses action server 不可用')
            raise RuntimeError('Action server 初始化失败')
        
        if not self.follow_path_client.wait_for_server(timeout_sec=10):
            self.get_logger().error('follow_path action server 不可用')
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
        
        self.get_logger().info('✓ 修复版多途径点导航器已初始化')
        self.get_logger().info('  - 订阅话题: /set_waypoints (Float64MultiArray)')
        self.get_logger().info('  - 发布话题: /global_route (Path), /waypoints_array (PoseArray)')
    
    def waypoints_callback(self, msg: Float64MultiArray):
        """接收途径点数据"""
        try:
            data = msg.data
            
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
            self.publish_waypoints_array(waypoints)
            
            # 启动导航
            if not self.is_navigating:
                self.get_logger().info(f'开始导航 {len(waypoints)} 个途径点')
                threading.Thread(target=self.navigate_waypoints, daemon=True).start()
        
        except Exception as e:
            self.get_logger().error(f'处理途径点时出错: {e}')
    
    def navigate_waypoints(self):
        """
        核心导航流程 - 只规划一次！
        
        步骤：
        1. 调用 ComputePathThroughPoses - 一次性计算完整路径
        2. 设置最终目标的容差
        3. 使用 FollowPath 严格跟随该路径
        """
        if self.is_navigating:
            self.get_logger().warn('已有导航任务在进行中')
            return
        
        self.is_navigating = True
        
        try:
            self.get_logger().info(f'\n--- 开始多途径点导航 ---')
            self.get_logger().info(f'总共 {len(self.current_waypoints)} 个途径点')
            
            # ⭐ 第1步：一次性计算全局路径
            # 这样避免了 navigate_through_poses 的周期性重规划
            computed_path = self.compute_path_once()
            
            if computed_path is None:
                self.get_logger().error('全局路径计算失败！')
                return
            
            self.get_logger().info(f'✓ 全局路径已计算（{len(computed_path.poses)} 个点）')
            self.publish_global_route(computed_path)
            
            # ⭐ 第2步：设置最终目标的容差
            self.set_goal_tolerance(self.final_goal_tolerance)
            time.sleep(0.5)
            
            # ⭐ 第3步：严格跟随这个固定的全局路径
            if self.follow_computed_path(computed_path):
                self.get_logger().info('\n✓✓✓ 所有途径点导航完成！✓✓✓')
            else:
                self.get_logger().error('路径跟随失败！')
        
        except Exception as e:
            self.get_logger().error(f'导航过程出错: {e}')
        
        finally:
            self.is_navigating = False
    
    def compute_path_once(self) -> Path:
        """
        一次性计算完整的全局路径
        
        关键点：只调用一次，避免重复规划导致路线变化
        """
        try:
            # 创建 action 目标
            goal = ComputePathThroughPoses.Goal()
            goal.goals = self.current_waypoints
            goal.planner_id = "GridBased"
            goal.start.header.frame_id = "map"
            goal.start.pose.position.x = 0.0
            goal.start.pose.position.y = 0.0
            goal.start.pose.orientation.w = 1.0
            
            self.get_logger().info('正在计算全局路径（一次性）...')
            
            # 发送目标
            future = self.compute_path_client.send_goal_async(goal)
            rclpy.spin_until_future_complete(self, future, timeout_sec=30)
            
            goal_handle = future.result()
            
            if not goal_handle.accepted:
                self.get_logger().error('路径计算目标被拒绝')
                return None
            
            # 等待结果
            result_future = goal_handle.get_result_async()
            rclpy.spin_until_future_complete(self, result_future, timeout_sec=300)
            
            result = result_future.result()
            
            if result.path.poses:
                return result.path
            else:
                self.get_logger().error('路径为空')
                return None
        
        except Exception as e:
            self.get_logger().error(f'计算路径时出错: {e}')
            return None
    
    def follow_computed_path(self, path: Path) -> bool:
        """
        严格跟随已计算的全局路径
        
        由于路径是固定的，不会改变，所以不会出现绕圈问题
        """
        try:
            # 创建 FollowPath 目标
            goal = FollowPath.Goal()
            goal.path = path
            goal.controller_id = "FollowPath"
            
            self.get_logger().info('开始跟随路径...')
            
            # 发送目标
            future = self.follow_path_client.send_goal_async(goal)
            rclpy.spin_until_future_complete(self, future, timeout_sec=30)
            
            goal_handle = future.result()
            
            if not goal_handle.accepted:
                self.get_logger().error('路径跟随目标被拒绝')
                return False
            
            # 等待结果
            result_future = goal_handle.get_result_async()
            rclpy.spin_until_future_complete(self, result_future, timeout_sec=600)
            
            result = result_future.result()
            
            if result and result.error_code == 0:  # SUCCESS
                return True
            else:
                self.get_logger().warn(f'路径跟随失败，错误码: {result.error_code if result else "None"}')
                return False
        
        except Exception as e:
            self.get_logger().error(f'跟随路径时出错: {e}')
            return False
    
    def set_goal_tolerance(self, tolerance: float) -> bool:
        """设置目标容差"""
        try:
            param = Parameter()
            param.name = 'general_goal_checker.xy_goal_tolerance'
            param.value = ParameterValue()
            param.value.type = 3  # double_value
            param.value.double_value = float(tolerance)
            
            request = SetParameters.Request()
            request.parameters = [param]
            
            future = self.set_params_client.call_async(request)
            rclpy.spin_until_future_complete(self, future, timeout_sec=2.0)
            
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
    
    def publish_global_route(self, path: Path):
        """发布全局路线用于 RViz 可视化"""
        try:
            self.route_pub.publish(path)
            self.get_logger().debug(f'已发布全局路径（{len(path.poses)} 个点）')
        except Exception as e:
            self.get_logger().error(f'发布路线时出错: {e}')
    
    def publish_waypoints_array(self, waypoints: List[PoseStamped]):
        """发布途径点"""
        try:
            pose_array = PoseArray()
            pose_array.header.frame_id = 'map'
            pose_array.header.stamp = self.get_clock().now().to_msg()
            pose_array.poses = [p.pose for p in waypoints]
            
            self.waypoints_pub.publish(pose_array)
            self.get_logger().debug(f'已发布 {len(waypoints)} 个途径点')
        except Exception as e:
            self.get_logger().error(f'发布途径点时出错: {e}')
    
    @staticmethod
    def create_pose(x: float, y: float, yaw: float = 0.0) -> PoseStamped:
        """创建位姿消息"""
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.pose.position.x = float(x)
        pose.pose.position.y = float(y)
        pose.pose.position.z = 0.0
        
        cos_yaw = math.cos(yaw / 2)
        sin_yaw = math.sin(yaw / 2)
        
        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = sin_yaw
        pose.pose.orientation.w = cos_yaw
        
        return pose


def main(args=None):
    rclpy.init(args=args)
    node = WaypointsNavigatorFixed()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('导航器已停止')
    except Exception as e:
        node.get_logger().error(f'错误: {e}')
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
