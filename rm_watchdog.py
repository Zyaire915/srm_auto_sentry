import subprocess
import time
import os

# 定义必须存在的关键节点
REQUIRED_NODES = [
    "/standard_robot_node",
    "/bt_navigator",
    "/fast_lio_node"
]

def check_ros_health():
    try:
        # 使用 zsh 环境运行 ros2 node list
        cmd = "source /opt/ros/humble/setup.zsh && source /home/srm/srm_auto_sentry/install/setup.zsh && ros2 node list"
        output = subprocess.check_output(["/bin/zsh", "-c", cmd], stderr=subprocess.STDOUT).decode()
        
        for node in REQUIRED_NODES:
            if node not in output:
                print(f"[Watchdog] 警告: 节点 {node} 丢失！")
                return False
        return True
    except Exception as e:
        print(f"[Watchdog] 错误: 无法获取节点列表 - {e}")
        return False

if __name__ == "__main__":
    print("[Watchdog] 启动 ROS 2 逻辑监控...")
    while True:
        if not check_ros_health():
            print("[Watchdog] 检测到核心组件异常，正在执行系统级重启...")
            # 重启最顶层的服务，由于 Requires 关系，会触发链式重启
            os.system("sudo systemctl restart rm-bt.service")
            time.sleep(40) # 等待系统完全恢复
        time.sleep(10) # 每10秒巡检一次
