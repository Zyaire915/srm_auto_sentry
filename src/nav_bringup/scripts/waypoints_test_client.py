#!/usr/bin/env python3
"""
多途径点导航测试客户端
用于向导航器发送途径点数据

使用方法：
1. 启动导航系统：
   ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
       world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
       nav_rviz:=True waypoint_tolerance:=1.0 final_goal_tolerance:=0.25

2. 在另一个终端运行此脚本：
   ros2 run rm_nav_bringup waypoints_test_client [示例编号]

3. 或在 Python 代码中调用相应函数
"""

import rclpy
from std_msgs.msg import Float64MultiArray
import sys


class WaypointsTestClient:
    """多途径点测试客户端"""
    
    def __init__(self):
        rclpy.init()
        self.node = rclpy.create_node('waypoints_test_client')
        
        # 创建发布者
        self.publisher = self.node.create_publisher(
            Float64MultiArray, '/set_waypoints', 10)
        
        self.node.get_logger().info('✓ 测试客户端已初始化')
        self.node.get_logger().info('可用示例：')
        self.node.get_logger().info('  1. 矩形巡逻路线')
        self.node.get_logger().info('  2. 三角形路线')
        self.node.get_logger().info('  3. 复杂路线 (7 个点)')
        self.node.get_logger().info('  4. 自定义路线')
    
    def publish_waypoints(self, waypoints: list, description: str = ""):
        """
        发布途径点
        
        Args:
            waypoints: 列表，格式为 [x1, y1, tol1, x2, y2, tol2, ...]
            description: 描述文字
        """
        msg = Float64MultiArray()
        msg.data = waypoints
        
        self.node.get_logger().info(f'\n📍 发布路线: {description}')
        self.node.get_logger().info(f'   数据: {waypoints}')
        
        # 发布多次确保到达
        for _ in range(3):
            self.publisher.publish(msg)
            rclpy.spin_once(self.node, timeout_sec=0.1)
        
        self.node.get_logger().info('✓ 路线已发布')
    
    def example_1_rectangle(self):
        """示例 1: 矩形巡逻"""
        waypoints = [
            # x, y, tolerance
            2.0, 2.0, 1.0,      # 途径点 1
            4.0, 2.0, 1.0,      # 途径点 2
            4.0, 4.0, 1.0,      # 途径点 3
            2.0, 4.0, 0.25,     # 最终目标（严格容差）
        ]
        self.publish_waypoints(waypoints, "矩形巡逻 (RMUL 地图)")
    
    def example_2_triangle(self):
        """示例 2: 三角形路线"""
        waypoints = [
            0.0, 0.0, 1.0,
            5.0, 0.0, 1.0,
            2.5, 4.33, 0.25,
        ]
        self.publish_waypoints(waypoints, "三角形路线")
    
    def example_3_complex(self):
        """示例 3: 复杂 7 点路线"""
        waypoints = [
            0.0, 0.0, 1.0,      # 起点附近
            2.0, 1.0, 1.0,
            3.0, 3.0, 1.0,
            4.0, 5.0, 1.0,
            3.0, 7.0, 1.0,
            1.0, 6.0, 1.0,
            0.0, 3.0, 0.25,     # 最终目标
        ]
        self.publish_waypoints(waypoints, "复杂 7 点路线")
    
    def example_4_custom(self):
        """示例 4: 交互式自定义路线"""
        self.node.get_logger().info('\n📝 输入自定义路线')
        self.node.get_logger().info('格式: x y tolerance (每行一个点，空行结束)\n')
        
        waypoints = []
        while True:
            try:
                line = input(f'点 {len(waypoints)//3 + 1}: ').strip()
                if not line:
                    break
                
                parts = line.split()
                if len(parts) != 3:
                    print('❌ 格式错误！请输入: x y tolerance')
                    continue
                
                x, y, tol = float(parts[0]), float(parts[1]), float(parts[2])
                waypoints.extend([x, y, tol])
                print(f'✓ 已添加点: ({x}, {y}), 容差: {tol}m')
            
            except ValueError:
                print('❌ 请输入有效的数字！')
            except KeyboardInterrupt:
                print('\n❌ 已取消')
                return
        
        if waypoints:
            self.publish_waypoints(waypoints, "自定义路线")
        else:
            self.node.get_logger().warn('❌ 未输入任何点')
    
    def run_example(self, example_num: int):
        """运行指定的示例"""
        examples = {
            1: ('矩形巡逻', self.example_1_rectangle),
            2: ('三角形路线', self.example_2_triangle),
            3: ('复杂 7 点路线', self.example_3_complex),
            4: ('自定义路线', self.example_4_custom),
        }
        
        if example_num not in examples:
            self.node.get_logger().error(f'❌ 未找到示例 {example_num}')
            self.node.get_logger().info('可用示例: 1, 2, 3, 4')
            return
        
        name, func = examples[example_num]
        self.node.get_logger().info(f'运行示例 {example_num}: {name}')
        func()
    
    def cleanup(self):
        """清理资源"""
        self.node.destroy_node()
        rclpy.shutdown()


def main(args=None):
    """主函数"""
    
    # 如果提供了参数，直接运行示例
    if len(sys.argv) > 1:
        try:
            example_num = int(sys.argv[1])
            client = WaypointsTestClient()
            client.run_example(example_num)
            client.cleanup()
            return
        except ValueError:
            print(f'❌ 无效参数: {sys.argv[1]} (需要是 1-4 的数字)')
            return
    
    # 交互式菜单
    client = WaypointsTestClient()
    
    try:
        while True:
            print('\n' + '='*50)
            print('多途径点导航测试客户端')
            print('='*50)
            print('1. 矩形巡逻路线')
            print('2. 三角形路线')
            print('3. 复杂 7 点路线')
            print('4. 自定义路线')
            print('0. 退出')
            print('='*50)
            
            choice = input('选择示例 (0-4): ').strip()
            
            if choice == '0':
                print('✓ 已退出')
                break
            
            try:
                num = int(choice)
                if 1 <= num <= 4:
                    client.run_example(num)
                else:
                    print('❌ 请输入 0-4 之间的数字')
            except ValueError:
                print('❌ 请输入有效的数字')
    
    except KeyboardInterrupt:
        print('\n✓ 已停止')
    finally:
        client.cleanup()


if __name__ == '__main__':
    main()
