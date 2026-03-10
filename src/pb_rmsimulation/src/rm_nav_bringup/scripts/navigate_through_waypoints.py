#!/usr/bin/env python3
"""
多途径点导航客户端
不使用 navigate_through_poses，而是手动处理每个途径点
支持不同的途径点和最终目标容差
"""

import sys
from typing import List
import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateToPose
from rcl_interfaces.srv import SetParameters
from rcl_interfaces.msg import Parameter, ParameterValue


class NavigateThroughWaypoints(Node):
    """
    导航到一系列途径点的节点
    特点：可以为途径点和最终目标设置不同的容差
    """

    def __init__(self):
        super().__init__('navigate_through_waypoints')
        
        # 声明参数
        self.declare_parameter('waypoint_tolerance', 1.0)
        self.declare_parameter('final_goal_tolerance', 0.25)
        self.declare_parameter('goal_checker_service_timeout', 1.0)
        
        # 创建 action client
        self._action_client = ActionClient(self, NavigateToPose, 'navigate_to_pose')
        
        # 创建 service client 来修改参数
        self._set_param_client = self.create_client(
            SetParameters, '/controller_server/set_parameters')
        
        self.get_logger().info('NavigateThroughWaypoints 节点已初始化')

    def set_goal_checker_tolerance(self, tolerance: float) -> bool:
        """
        动态设置 goal checker 的容差
        
        Args:
            tolerance: 容差值（米）
            
        Returns:
            是否设置成功
        """
        timeout = self.get_parameter('goal_checker_service_timeout').value
        
        if not self._set_param_client.wait_for_service(timeout_sec=timeout):
            self.get_logger().warn('Goal checker service 不可用')
            return False

        # 创建参数请求
        param = Parameter()
        param.name = 'general_goal_checker.xy_goal_tolerance'
        param.value = ParameterValue(double_value=tolerance)

        request = SetParameters.Request()
        request.parameters = [param]

        future = self._set_param_client.call_async(request)
        
        # 等待响应
        try:
            response = future.result(timeout_sec=timeout)
            if response.results[0].successful:
                self.get_logger().info(f'设置容差为 {tolerance} m')
                return True
            else:
                self.get_logger().error(f'参数设置失败: {response.results[0].reason}')
                return False
        except Exception as e:
            self.get_logger().error(f'设置参数异常: {e}')
            return False

    def navigate_to_pose(self, pose: PoseStamped, timeout_sec: float = 300.0) -> bool:
        """
        导航到单个目标点
        
        Args:
            pose: 目标位置
            timeout_sec: 超时时间（秒）
            
        Returns:
            是否导航成功
        """
        if not self._action_client.server_is_ready():
            self.get_logger().error('navigate_to_pose action server 未就绪')
            return False

        # 创建目标
        goal_msg = NavigateToPose.Goal()
        goal_msg.pose = pose

        self.get_logger().info(f'发送导航目标: ({pose.pose.position.x:.2f}, {pose.pose.position.y:.2f})')

        # 发送目标
        future = self._action_client.send_goal_async(goal_msg)

        # 等待结果
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout_sec)

        if future.result() is None:
            self.get_logger().error('导航失败')
            return False

        result_future = future.result().get_result_async()
        rclpy.spin_until_future_complete(self, result_future, timeout_sec=timeout_sec)

        if result_future.result() is None:
            self.get_logger().error('获取结果失败')
            return False

        self.get_logger().info('到达目标点')
        return True

    def navigate_through_waypoints(
        self, 
        poses: List[PoseStamped],
        use_different_tolerances: bool = True
    ) -> bool:
        """
        导航到一系列途径点
        
        Args:
            poses: 位置列表，最后一个是最终目标
            use_different_tolerances: 是否对途径点和最终目标使用不同的容差
            
        Returns:
            是否全部导航成功
        """
        if not poses:
            self.get_logger().error('位置列表为空')
            return False

        waypoint_tolerance = self.get_parameter('waypoint_tolerance').value
        final_goal_tolerance = self.get_parameter('final_goal_tolerance').value

        # 导航到所有途径点
        for i, pose in enumerate(poses[:-1]):
            is_final = (i == len(poses) - 2)
            
            if use_different_tolerances:
                # 对途径点设置较宽松的容差
                if not self.set_goal_checker_tolerance(waypoint_tolerance):
                    return False
            
            self.get_logger().info(f'--- 导航到途径点 {i + 1}/{len(poses) - 1} ---')
            
            if not self.navigate_to_pose(pose):
                return False

        # 导航到最终目标
        if use_different_tolerances:
            # 对最终目标设置严格的容差
            if not self.set_goal_checker_tolerance(final_goal_tolerance):
                return False
        
        self.get_logger().info(f'--- 导航到最终目标 ---')
        
        if not self.navigate_to_pose(poses[-1]):
            return False

        self.get_logger().info('✓ 成功导航到所有目标点！')
        return True


def main(args=None):
    """
    示例：导航到多个途径点
    """
    rclpy.init(args=args)
    node = NavigateThroughWaypoints()

    # 示例：创建一个包含 3 个途径点和 1 个最终目标的路径
    poses = []
    
    # 途径点 1: (2.0, 2.0)
    pose1 = PoseStamped()
    pose1.header.frame_id = 'map'
    pose1.pose.position.x = 2.0
    pose1.pose.position.y = 2.0
    pose1.pose.orientation.w = 1.0
    poses.append(pose1)
    
    # 途径点 2: (4.0, 2.0)
    pose2 = PoseStamped()
    pose2.header.frame_id = 'map'
    pose2.pose.position.x = 4.0
    pose2.pose.position.y = 2.0
    pose2.pose.orientation.w = 1.0
    poses.append(pose2)
    
    # 途径点 3: (4.0, 4.0)
    pose3 = PoseStamped()
    pose3.header.frame_id = 'map'
    pose3.pose.position.x = 4.0
    pose3.pose.position.y = 4.0
    pose3.pose.orientation.w = 1.0
    poses.append(pose3)
    
    # 最终目标: (2.0, 4.0)
    final_goal = PoseStamped()
    final_goal.header.frame_id = 'map'
    final_goal.pose.position.x = 2.0
    final_goal.pose.position.y = 4.0
    final_goal.pose.orientation.w = 1.0
    poses.append(final_goal)

    # 执行导航
    success = node.navigate_through_waypoints(poses, use_different_tolerances=True)

    if success:
        node.get_logger().info('导航成功！')
    else:
        node.get_logger().error('导航失败！')

    rclpy.shutdown()


if __name__ == '__main__':
    main()
