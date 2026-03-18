#!/usr/bin/env python3
"""
导航中途丢失定位诊断工具
=======================

诊断机器人在导航过程中"飞走"的问题

症状：
- ✗ 地图跑到一半就飞了
- ✗ 在RViz中看到机器人位置跳跃
- ✗ 坐标系突然改变

可能原因：
1. 定位系统丢失 (SLAM/AMCL 跟踪失败)
2. LiDAR 数据中断
3. IMU 数据故障
4. TF 树断裂
5. 地图更新导致坐标系变化
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, QoSHistoryPolicy, QoSReliabilityPolicy
import math
import threading
from collections import deque
from geometry_msgs.msg import PoseWithCovarianceStamped, TransformStamped
from tf2_ros import TransformListener, Buffer
from sensor_msgs.msg import PointCloud2
from std_msgs.msg import String
from nav_msgs.msg import Odometry
import time


class NavigationDriftDiagnostic(Node):
    """诊断导航中途定位丢失的问题"""
    
    def __init__(self):
        super().__init__('diagnose_navigation_drift')
        
        # TF 监听器
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)
        
        # 历史数据缓冲区
        self.pose_history = deque(maxlen=100)  # 最后100个位置
        self.covariance_history = deque(maxlen=100)  # 对应的协方差
        self.timestamp_history = deque(maxlen=100)  # 时间戳
        
        # 状态变量
        self.last_pose = None
        self.last_covariance = None
        self.last_time = None
        self.tf_failures = 0
        self.covariance_spikes = 0
        self.position_jumps = 0
        self.lidar_updates = 0
        self.imu_updates = 0
        
        # 配置
        self.position_jump_threshold = 0.5  # 位置跳跃 > 0.5m 认为异常
        self.covariance_spike_threshold = 5.0  # 协方差增大 5 倍认为异常
        
        # 创建订阅者
        amcl_qos = QoSProfile(
            history=QoSHistoryPolicy.KEEP_LAST,
            depth=10,
            reliability=QoSReliabilityPolicy.BEST_EFFORT
        )
        
        self.amcl_sub = self.create_subscription(
            PoseWithCovarianceStamped,
            '/amcl_pose',
            self.amcl_callback,
            amcl_qos
        )
        
        self.odom_sub = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            amcl_qos
        )
        
        self.lidar_sub = self.create_subscription(
            PointCloud2,
            '/cloud_registered',  # 或其他 LiDAR 话题
            self.lidar_callback,
            amcl_qos
        )
        
        # 诊断发布者
        self.diagnostic_pub = self.create_publisher(String, '/diagnosis_report', 10)
        
        # 启动定期诊断线程
        self.diagnostic_thread = threading.Thread(target=self.run_diagnostics, daemon=True)
        self.diagnostic_thread.start()
        
        self.get_logger().info('✓ 导航定位诊断工具已启动')
        self.get_logger().info('  监控项目:')
        self.get_logger().info('    - AMCL 定位协方差变化')
        self.get_logger().info('    - 位置跳跃检测')
        self.get_logger().info('    - TF 变换可用性')
        self.get_logger().info('    - LiDAR 数据更新')
        self.get_logger().info('')
    
    def amcl_callback(self, msg: PoseWithCovarianceStamped):
        """监控 AMCL 定位输出"""
        try:
            pose = msg.pose.pose
            covariance = msg.pose.covariance[0]  # x 方向的协方差
            current_time = time.time()
            
            # 存储历史记录
            self.pose_history.append((pose.position.x, pose.position.y))
            self.covariance_history.append(covariance)
            self.timestamp_history.append(current_time)
            
            # 检查位置跳跃
            if self.last_pose is not None:
                dx = pose.position.x - self.last_pose[0]
                dy = pose.position.y - self.last_pose[1]
                distance = math.sqrt(dx**2 + dy**2)
                
                time_delta = current_time - self.last_time
                
                # 如果在 0.1 秒内位置跳跃 > threshold，说明可能丢失定位
                if time_delta < 0.1 and distance > self.position_jump_threshold:
                    self.position_jumps += 1
                    self.get_logger().warn(
                        f'⚠️  位置跳跃检测: {distance:.2f}m (Δt={time_delta:.3f}s)\n'
                        f'     从 ({self.last_pose[0]:.2f}, {self.last_pose[1]:.2f}) '
                        f'到 ({pose.position.x:.2f}, {pose.position.y:.2f})'
                    )
            
            # 检查协方差变化（协方差突增表示定位不确定性增大）
            if self.last_covariance is not None:
                cov_ratio = covariance / (self.last_covariance + 1e-6)
                
                if cov_ratio > self.covariance_spike_threshold:
                    self.covariance_spikes += 1
                    self.get_logger().warn(
                        f'⚠️  协方差尖峰: {cov_ratio:.1f}x (从 {self.last_covariance:.4f} '
                        f'到 {covariance:.4f})\n'
                        f'     可能丢失视觉信号或环境变化'
                    )
            
            self.last_pose = (pose.position.x, pose.position.y)
            self.last_covariance = covariance
            self.last_time = current_time
            
        except Exception as e:
            self.get_logger().error(f'处理 AMCL 消息时出错: {e}')
    
    def odom_callback(self, msg: Odometry):
        """监控里程计（用于对比 AMCL）"""
        pass
    
    def lidar_callback(self, msg: PointCloud2):
        """监控 LiDAR 数据更新"""
        self.lidar_updates += 1
    
    def run_diagnostics(self):
        """定期运行诊断"""
        while rclpy.ok():
            try:
                time.sleep(5)  # 每 5 秒诊断一次
                
                if not self.pose_history:
                    continue
                
                # 计算统计数据
                report = self.generate_diagnostic_report()
                
                # 发布报告
                report_msg = String()
                report_msg.data = report
                self.diagnostic_pub.publish(report_msg)
                
                # 打印报告
                self.get_logger().info('\n' + '='*60)
                self.get_logger().info(report)
                self.get_logger().info('='*60)
                
            except Exception as e:
                self.get_logger().error(f'诊断过程出错: {e}')
    
    def generate_diagnostic_report(self) -> str:
        """生成诊断报告"""
        report = "📊 导航定位诊断报告\n"
        report += "-" * 50 + "\n"
        
        # 1. 定位状态
        if not self.pose_history:
            report += "❌ 未接收到任何 AMCL 定位数据\n"
            return report
        
        current_x, current_y = self.pose_history[-1]
        current_cov = self.covariance_history[-1]
        
        report += f"🤖 当前位置: ({current_x:.2f}, {current_y:.2f})\n"
        report += f"📍 定位协方差(X): {current_cov:.6f}\n"
        
        # 2. 位置稳定性
        if len(self.pose_history) > 10:
            recent_poses = list(self.pose_history)[-10:]
            positions = [(p[0], p[1]) for p in recent_poses]
            
            # 计算最近位置的离散度
            mean_x = sum(p[0] for p in positions) / len(positions)
            mean_y = sum(p[1] for p in positions) / len(positions)
            variance = sum((p[0] - mean_x)**2 + (p[1] - mean_y)**2 for p in positions) / len(positions)
            std_dev = math.sqrt(variance)
            
            report += f"📈 最近 10 次位置标准差: {std_dev:.4f}m\n"
            
            if std_dev > 0.1:
                report += "   ⚠️  定位明显抖动，可能原因：\n"
                report += "      - LiDAR 数据质量差\n"
                report += "      - IMU 噪声过大\n"
                report += "      - 轮子打滑\n"
        
        # 3. 异常计数
        report += f"\n⚠️  异常检测:\n"
        report += f"   - 位置跳跃: {self.position_jumps} 次 (>0.5m)\n"
        report += f"   - 协方差尖峰: {self.covariance_spikes} 次 (>5x)\n"
        report += f"   - TF 失败: {self.tf_failures} 次\n"
        
        # 4. 数据流状态
        report += f"\n📡 数据流状态:\n"
        report += f"   - LiDAR 更新: {self.lidar_updates} 次\n"
        report += f"   - AMCL 数据点: {len(self.pose_history)}\n"
        
        # 5. 健康评分
        if self.position_jumps == 0 and self.covariance_spikes == 0 and std_dev < 0.05:
            health = "✅ 良好"
            report += f"\n👍 系统状态: {health}\n"
        elif self.position_jumps < 3 and self.covariance_spikes < 3:
            health = "⚠️  一般 (偶发异常)"
            report += f"\n👎 系统状态: {health}\n"
            report += "   建议检查 LiDAR 传感器和 IMU 校准\n"
        else:
            health = "❌ 严重 (频繁异常)"
            report += f"\n🔴 系统状态: {health}\n"
            report += "   定位系统可能故障，建议：\n"
            report += "   1. 检查 LiDAR 连接和数据\n"
            report += "   2. 验证 IMU 校准和数据范围\n"
            report += "   3. 检查 SLAM/AMCL 参数设置\n"
            report += "   4. 验证地图质量\n"
        
        # 6. TF 树检查
        report += f"\n🔗 TF 树检查:\n"
        try:
            # 检查关键变换
            transforms_to_check = [
                ('map', 'odom'),
                ('odom', 'base_link'),
                ('map', 'base_link')
            ]
            
            for parent, child in transforms_to_check:
                try:
                    self.tf_buffer.lookup_transform(parent, child, rclpy.time.Time())
                    report += f"   ✓ {parent} -> {child}\n"
                except:
                    report += f"   ✗ {parent} -> {child} (不可用)\n"
                    self.tf_failures += 1
        
        except Exception as e:
            report += f"   检查失败: {e}\n"
        
        return report


def main(args=None):
    rclpy.init(args=args)
    node = NavigationDriftDiagnostic()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('诊断工具已停止')
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
