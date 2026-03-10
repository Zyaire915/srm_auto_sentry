# 多途径点导航快速参考

## 🚀 30秒快速开始

### 启动系统
```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    nav_rviz:=True
```

### 发送路线
```bash
# 在新终端
ros2 run rm_nav_bringup waypoints_test_client 1
```

**Done！** 机器人会按照途径点自动导航。

---

## 📋 常用命令速查表

### 启动变体

| 用途 | 命令 |
|------|------|
| **仿真导航** | `ros2 launch rm_nav_bringup waypoints_navigator.launch.py world:=RMUL mode:=nav` |
| **实车导航** | `ros2 launch rm_nav_bringup waypoints_navigator.launch.py world:=best` |
| **高精度** | `... waypoint_tolerance:=0.5 final_goal_tolerance:=0.1` |
| **高速度** | `... waypoint_tolerance:=1.5 final_goal_tolerance:=0.5` |
| **只看地图** | `... nav_rviz:=True lio_rviz:=False` |

### 测试客户端

| 操作 | 命令 |
|------|------|
| **菜单模式** | `ros2 run rm_nav_bringup waypoints_test_client` |
| **矩形巡逻** | `ros2 run rm_nav_bringup waypoints_test_client 1` |
| **三角形** | `ros2 run rm_nav_bringup waypoints_test_client 2` |
| **7点复杂** | `ros2 run rm_nav_bringup waypoints_test_client 3` |
| **自定义** | `ros2 run rm_nav_bringup waypoints_test_client 4` |

### 调试命令

```bash
# 查看节点
ros2 node list | grep waypoints

# 查看话题
ros2 topic list | grep -E "(global_route|waypoints)"

# 发布调试数据
ros2 topic pub /set_waypoints std_msgs/Float64MultiArray 'data: [2, 2, 1, 4, 4, 0.25]'

# 检查参数
ros2 param get /controller_server general_goal_checker.xy_goal_tolerance

# 修改参数
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 1.0

# 查看导航器日志
ros2 node info /waypoints_navigator
```

---

## 📊 参数对照表

### 容差参数

| 场景 | 途径点容差 | 最终容差 | 使用场景 |
|------|---------|--------|--------|
| 🏃 快速 | 1.5 m | 0.5 m | 巡逻、急速移动 |
| 🚶 标准 | 1.0 m | 0.25 m | 通用场景 |
| 🎯 精准 | 0.5 m | 0.1 m | 精密作业 |
| 🔬 超精准 | 0.3 m | 0.05 m | 特殊要求 |

### 启动参数

| 参数 | 可选值 | 默认 | 说明 |
|------|--------|------|------|
| world | RMUL, RMUC | RMUL | 仿真世界 |
| mode | nav, mapping | nav | 导航模式 |
| lio | fastlio, pointlio | fastlio | LIO 类型 |
| localization | slam_toolbox, amcl, icp | slam_toolbox | 定位方式 |
| lio_rviz | True, False | False | 显示点云 |
| nav_rviz | True, False | True | 显示导航 |
| waypoint_tolerance | 0.0-2.0 | 1.0 | 途径点容差 |
| final_goal_tolerance | 0.0-0.5 | 0.25 | 最终容差 |

---

## 🔴 问题速查

| 问题 | 原因 | 解决 |
|------|------|------|
| 导航器无法启动 | Nav2 未启动 | 检查 `navigate_to_pose` action |
| 容差设置无效 | controller_server 离线 | 重启导航系统 |
| 机器人不动 | 定位不准 | 在 RViz 中设置初始位置 |
| RViz 无显示 | 话题发布失败 | 检查 `/global_route` topic |
| 到达不了目标 | 点在障碍物上 | 在 RViz 中查看代价地图 |

---

## 📝 数据格式速查

### 途径点数据格式

```
[x1, y1, tol1, x2, y2, tol2, ..., xn, yn, toln]
```

**示例：矩形巡逻 (4 个点)**
```python
[
    2.0, 2.0, 1.0,    # 点1: x=2, y=2, tolerance=1.0m
    4.0, 2.0, 1.0,    # 点2
    4.0, 4.0, 1.0,    # 点3
    2.0, 4.0, 0.25,   # 点4 (最终目标，严格容差)
]
```

### ROS Topic 发布格式

```bash
ros2 topic pub /set_waypoints std_msgs/Float64MultiArray \
    'data: [x1, y1, tol1, x2, y2, tol2, ...]'
```

---

## 🔍 RViz 图例

| 符号 | 颜色 | 含义 |
|------|------|------|
| 🟦 | 蓝色 | 代价地图（障碍物） |
| 🟩 | 绿色 | 全局路径 (Nav2 规划) |
| 🟥 | **红色** | **全局路线** (多途径点) |
| 🟧 | **橙色** | **途径点** (箭头) |
| 🟪 | 粉色 | 机器人位置不确定性 |

---

## ⚙️ 常见配置组合

### 组合 1：RMUL 仿真 + 快速导航
```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    waypoint_tolerance:=1.5 final_goal_tolerance:=0.5 nav_rviz:=True
```

### 组合 2：RMUC 仿真 + 精准导航
```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUC mode:=nav lio:=fastlio localization:=amcl \
    waypoint_tolerance:=0.5 final_goal_tolerance:=0.15 nav_rviz:=True
```

### 组合 3：实车 + Point LIO
```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=best mode:=nav lio:=pointlio localization:=slam_toolbox \
    waypoint_tolerance:=1.0 final_goal_tolerance:=0.25
```

### 组合 4：边建图边导航
```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=mapping lio:=fastlio \
    waypoint_tolerance:=1.0 final_goal_tolerance:=0.25 nav_rviz:=True
```

---

## 🎯 集成到行为树

### 简单集成示例

```xml
<root main_tree_to_execute="Patrol">
  <BehaviorTree ID="Patrol">
    <Sequence>
      <!-- 发布途径点 -->
      <RosTopicPublish topic="/set_waypoints"
                       message_type="std_msgs/Float64MultiArray">
        <param name="data" value="[2,2,1.0, 4,4,0.25]"/>
      </RosTopicPublish>
      
      <!-- 等待完成（30秒超时） -->
      <WaitAction msec="30000"/>
      
      <!-- 循环 -->
      <AlwaysRunning/>
    </Sequence>
  </BehaviorTree>
</root>
```

---

## 📦 文件结构

```
rm_nav_bringup/
├── scripts/
│   ├── waypoints_navigator.py          # 核心导航器
│   └── waypoints_test_client.py         # 测试客户端
├── launch/
│   └── waypoints_navigator.launch.py    # 启动文件
├── config/
│   └── waypoints_navigator.rviz         # RViz 配置
└── ...
```

---

## 🔗 相关资源

- 完整指南: `WAYPOINTS_NAVIGATION_GUIDE.md`
- 集成指南: `INTEGRATION_GUIDE.md`
- Nav2 官方: https://nav2.readthedocs.io/
- 项目主页: `/pb_rmsimulation/README.md`

---

## 💡 常用技巧

### 技巧 1：快速测试不同容差

```bash
# 终端 1: 启动系统
ros2 launch rm_nav_bringup waypoints_navigator.launch.py world:=RMUL

# 终端 2: 发送路线
ros2 run rm_nav_bringup waypoints_test_client 1

# 终端 3: 动态调整
for tol in 0.5 1.0 1.5; do
    echo "设置容差为 $tol"
    ros2 param set /controller_server general_goal_checker.xy_goal_tolerance $tol
    sleep 5
done
```

### 技巧 2：保存好的参数组合

```bash
# 创建快速启动脚本 fast_patrol.sh
#!/bin/bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    waypoint_tolerance:=1.5 final_goal_tolerance:=0.5 nav_rviz:=True

# 使用
chmod +x fast_patrol.sh
./fast_patrol.sh
```

### 技巧 3：在 Python 中直接使用

```python
import rclpy
from std_msgs.msg import Float64MultiArray

rclpy.init()
pub = rclpy.create_node('test').create_publisher(
    Float64MultiArray, '/set_waypoints', 10)

msg = Float64MultiArray()
msg.data = [2, 2, 1.0, 4, 4, 0.25]
pub.publish(msg)
```

---

**最后更新**: 2024年12月  
**快速参考卡片 v1.0**
