#!/usr/bin/env python3
"""
诊断脚本：检查 navigate_through_poses 是否在重规划全局路径
"""

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from nav2_msgs.action import NavigateThroughPoses
from rclpy.action import ActionClient
from nav_msgs.msg import Path
import time
from typing import List


class NavigateThroughPosesDiagnostic(Node):
    """诊断 navigate_through_poses 的重规划问题"""
    
    def __init__(self):
        super().__init__('navigate_through_poses_diagnostic')
        
        # 创建客户端
        self.nav_client = ActionClient(self, NavigateThroughPoses, 'navigate_through_poses')
        
        # 订阅全局路径，监控其变化
        self.path_subscriber = self.create_subscription(
            Path, '/plan', self._on_global_path, 10)
        
        # 记录路径变化
        self.path_history: List[Path] = []
        self.path_update_count = 0
        
        # 等待action server
        if not self.nav_client.wait_for_server(timeout_sec=10):
            self.get_logger().error('navigate_through_poses action server 不可用')
            raise RuntimeError('Action server 不可用')
        
        self.get_logger().info('✓ 诊断节点已初始化')
        self.get_logger().info('  - 监控话题: /plan (全局路径)')
        self.get_logger().info('  - 观察导航过程中路径是否改变')
    
    def _on_global_path(self, msg: Path):
        """
        当全局路径更新时调用
        """
        self.path_update_count += 1
        
        if self.path_update_count == 1:
            self.get_logger().info(f'[#1] 初始全局路径接收: {len(msg.poses)} 个点')
            self.path_history.append(msg)
        else:
            # 比较与前一次的路径是否不同
            if len(msg.poses) != len(self.path_history[-1].poses):
                self.get_logger().warn(
                    f'[#{self.path_update_count}] ⚠️  全局路径改变了！ '
                    f'之前:{len(self.path_history[-1].poses)}点 -> 现在:{len(msg.poses)}点')
            elif self._paths_different(msg, self.path_history[-1]):
                self.get_logger().warn(
                    f'[#{self.path_update_count}] ⚠️  全局路径坐标改变了！ '
                    f'这会导致机器人在途径点附近重复!')
            else:
                self.get_logger().info(
                    f'[#{self.path_update_count}] 路径更新，但内容相同（可能只是时间戳更新）')
            
            self.path_history.append(msg)
    
    @staticmethod
    def _paths_different(path1: Path, path2: Path) -> bool:
        """检查两个路径是否坐标不同"""
        if len(path1.poses) != len(path2.poses):
            return True
        
        # 比较前几个和最后几个点
        threshold = 0.05  # 5cm 容差
        for i in [0, len(path1.poses)//2, -1]:
            p1 = path1.poses[i]
            p2 = path2.poses[i]
            
            dx = p1.pose.position.x - p2.pose.position.x
            dy = p1.pose.position.y - p2.pose.position.y
            
            if abs(dx) > threshold or abs(dy) > threshold:
                return True
        
        return False
    
    def test_navigate_through_poses(self):
        """测试 navigate_through_poses"""
        
        # 创建测试路线
        waypoints = [
            self.create_pose(2.0, 2.0),
            self.create_pose(4.0, 4.0),
            self.create_pose(2.0, 4.0),
        ]
        
        self.get_logger().info('\n=======================================')
        self.get_logger().info('开始测试：navigate_through_poses')
        self.get_logger().info('途径点:')
        for i, wp in enumerate(waypoints):
            self.get_logger().info(
                f'  [{i+1}] ({wp.pose.position.x:.1f}, {wp.pose.position.y:.1f})')
        self.get_logger().info('观察导航过程中 /plan 话题是否多次更新且内容改变')
        self.get_logger().info('=======================================\n')
        
        # 发送导航目标
        goal = NavigateThroughPoses.Goal()
        goal.poses = waypoints
        
        try:
            future = self.nav_client.send_goal_async(goal)
            rclpy.spin_until_future_complete(self, future, timeout_sec=10)
            
            goal_handle = future.result()
            if not goal_handle.accepted:
                self.get_logger().error('目标被拒绝')
                return
            
            self.get_logger().info('✓ 目标已发送，等待导航完成...')
            self.get_logger().info('(如果看到多个 ⚠️  警告，说明发生了重规划)')
            
            # 等待导航完成（或超时30秒以观察重规划)
            result_future = goal_handle.get_result_async()
            rclpy.spin_until_future_complete(self, result_future, timeout_sec=60)
            
            # 汇总结果
            self.get_logger().info(f'\n=======================================')
            self.get_logger().info(f'导航完成。诊断结果：')
            self.get_logger().info(f'  - 全局路径更新次数: {self.path_update_count}')
            
            if self.path_update_count > 1:
                self.get_logger().warn(
                    f'⚠️  全局路径被多次更新！这说明 navigate_through_poses 在重复规划')
                self.get_logger().warn(
                    f'  每次路径改变时，局部规划器的目标会改变，导致机器人在途径点绕圈')
            else:
                self.get_logger().info(
                    f'✓ 全局路径只更新了一次，没有重规划问题')
            
            self.get_logger().info(f'=======================================\n')
        
        except Exception as e:
            self.get_logger().error(f'测试失败: {e}')
    
    @staticmethod
    def create_pose(x: float, y: float) -> PoseStamped:
        """创建位姿"""
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.pose.position.x = x
        pose.pose.position.y = y
        pose.pose.orientation.w = 1.0
        return pose


def main(args=None):
    rclpy.init(args=args)
    node = NavigateThroughPosesDiagnostic()
    
    try:
        # 给导航系统时间启动
        time.sleep(1)
        
        # 运行诊断测试
        node.test_navigate_through_poses()
        
        # 保持节点运行以观察 /plan 话题的变化
        rclpy.spin(node)
    
    except KeyboardInterrupt:
        node.get_logger().info('诊断已停止')
    except Exception as e:
        node.get_logger().error(f'错误: {e}')
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
