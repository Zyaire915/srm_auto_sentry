#!/usr/bin/env python3
"""
快速诊断脚本 - 地图跑到一半就飞了的问题
快速检查关键数据，5 秒钟给出诊断结果
"""

import rclpy
from rclpy.node import Node
import time
import subprocess
from typing import Dict, Any


class QuickDiagnostic(Node):
    """快速诊断工具"""
    
    def __init__(self):
        super().__init__('quick_diagnostic')
        self.results = {}
    
    def check_topic_frequency(self, topic_name: str, timeout: float = 2.0) -> float:
        """检查话题更新频率"""
        try:
            result = subprocess.run(
                ['ros2', 'topic', 'hz', topic_name, '-w', '10', '--timeout', str(int(timeout*10))],
                capture_output=True,
                text=True,
                timeout=int(timeout) + 5
            )
            
            # 从输出中提取频率
            for line in result.stdout.split('\n'):
                if 'average rate:' in line:
                    freq = float(line.split('average rate:')[1].split('Hz')[0].strip())
                    return freq
            return 0.0
        except:
            return 0.0
    
    def check_node_status(self, node_name: str) -> bool:
        """检查节点是否运行"""
        try:
            result = subprocess.run(
                ['ros2', 'node', 'list'],
                capture_output=True,
                text=True,
                timeout=5
            )
            return node_name in result.stdout
        except:
            return False
    
    def run_diagnosis(self):
        """运行诊断"""
        print("\n" + "="*70)
        print("🔍 ROS 导航系统快速诊断工具")
        print("="*70)
        
        # 1. 检查关键节点
        print("\n📋 [1] 检查关键节点状态...")
        nodes_to_check = [
            ('nav2_map_server', 'Map Server'),
            ('amcl', 'AMCL Localization'),
            ('bt_navigator', 'Behavior Tree Navigator'),
            ('controller_server', 'Controller Server'),
            ('planner_server', 'Planner Server'),
            ('slam_toolbox', 'SLAM Toolbox'),
            ('fast_lio', 'Fast LIO'),
        ]
        
        active_nodes = {}
        for node_pattern, display_name in nodes_to_check:
            is_active = self.check_node_status(node_pattern)
            status = "✓" if is_active else "✗"
            print(f"    {status} {display_name}")
            active_nodes[display_name] = is_active
        
        # 2. 检查关键话题频率
        print("\n📡 [2] 检查关键话题更新频率...")
        topics_to_check = [
            ('/cloud_registered', 'LiDAR Point Cloud'),
            ('/amcl_pose', 'AMCL Pose'),
            ('/odom', 'Odometry'),
            ('/map', 'Map'),
            ('/tf', 'TF Broadcast'),
            ('/plan', 'Global Plan'),
            ('/local_plan', 'Local Plan'),
        ]
        
        topic_freqs = {}
        for topic_name, display_name in topics_to_check:
            freq = self.check_topic_frequency(topic_name, timeout=2.0)
            status = "✓" if freq > 0.1 else "✗"
            print(f"    {status} {display_name:25s} {freq:6.1f} Hz")
            topic_freqs[display_name] = freq
        
        # 3. 诊断分析
        print("\n🔧 [3] 诊断分析...")
        
        issues = []
        
        # 检查 LiDAR
        if topic_freqs.get('LiDAR Point Cloud', 0) < 1:
            issues.append("❌ LiDAR 数据缺失或频率太低")
        
        # 检查 AMCL
        if not active_nodes.get('AMCL Localization', False):
            if not active_nodes.get('SLAM Toolbox', False):
                issues.append("❌ 定位系统未运行 (AMCL 或 SLAM Toolbox 都未启动)")
        
        if topic_freqs.get('AMCL Pose', 0) < 10:
            if topic_freqs.get('AMCL Pose', 0) > 0:
                issues.append("⚠️  AMCL 定位频率偏低 (<10Hz)")
        
        # 检查导航系统
        if not active_nodes.get('Behavior Tree Navigator', False):
            issues.append("❌ 导航器未运行 (bt_navigator)")
        
        if not active_nodes.get('Planner Server', False):
            issues.append("❌ 规划器未运行 (planner_server)")
        
        if not active_nodes.get('Controller Server', False):
            issues.append("❌ 控制器未运行 (controller_server)")
        
        # 检查地图
        if topic_freqs.get('Map', 0) < 0.1:
            issues.append("⚠️  地图更新缓慢或未更新")
        
        # 输出诊断结果
        if not issues:
            print("    ✅ 所有系统正常！")
        else:
            print("    以下项存在问题:")
            for issue in issues:
                print(f"      {issue}")
        
        # 4. 根本原因分析
        print("\n💡 [4] 可能原因分析...")
        
        if topic_freqs.get('LiDAR Point Cloud', 0) < 1:
            print("    🔸 LiDAR 数据问题:")
            print("       - 检查 LiDAR 硬件连接")
            print("       - 检查 LiDAR 驱动是否启动")
            print("       - 命令: ros2 topic echo /cloud_registered")
        
        if topic_freqs.get('AMCL Pose', 0) < 1:
            print("    🔸 定位系统问题:")
            print("       - AMCL/SLAM 未正确初始化")
            print("       - 地图可能加载失败")
            print("       - 命令: ros2 service call /slam_toolbox/clear_queue")
        
        # 5. 推荐行动
        print("\n📋 [5] 推荐行动...")
        
        if not active_nodes.get('Behavior Tree Navigator', False):
            print("    1️⃣  启动完整导航系统:")
            print("       ros2 launch rm_nav_bringup waypoints_navigator.launch.py \\")
            print("           world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox")
        else:
            print("    ✓ 导航系统已运行")
        
        if topic_freqs.get('AMCL Pose', 0) > 0:
            print("    2️⃣  运行持续诊断:")
            print("       ros2 run rm_nav_bringup diagnose_navigation_drift")
        
        if topic_freqs.get('LiDAR Point Cloud', 0) < 1:
            print("    3️⃣  检查 LiDAR:")
            print("       - 检查物理连接")
            print("       - 检查 LiDAR 配置文件")
            print("       - 重启 LiDAR 节点")
        
        print("\n" + "="*70)
        print("✨ 诊断完成")
        print("="*70 + "\n")


def main(args=None):
    rclpy.init(args=args)
    node = QuickDiagnostic()
    
    try:
        node.run_diagnosis()
    except Exception as e:
        print(f"诊断出错: {e}")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
