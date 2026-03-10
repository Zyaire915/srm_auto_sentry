# 自定义多途径点导航方案

## 概述

本方案不使用 Nav2 的 `navigate_through_poses` action，而是**手动处理每个途径点**，这样可以：

✅ 对途径点使用宽松的容差（更容易到达）  
✅ 对最终目标使用严格的容差（精确到达）  
✅ 完全灵活控制导航流程  
✅ 支持中断、错误恢复等高级功能  

---

## 文件结构

```
rm_nav_bringup/
├── include/
│   └── rm_nav_bringup/
│       └── navigate_through_waypoints.hpp        # C++ 头文件（可选）
├── src/
│   └── navigate_through_waypoints.cpp             # C++ 实现（可选）
├── scripts/
│   └── navigate_through_waypoints.py              # Python 实现（推荐）
├── config/
│   └── behavior_trees/
│       ├── navigate_through_waypoints.xml         # BT XML 版本 1
│       └── navigate_through_waypoints_simple.xml  # BT XML 版本 2
└── launch/
    └── navigate_through_waypoints.launch.py       # 启动文件
```

---

## 使用方法

### 方法 1：Python 脚本（最简单，推荐）

```bash
# 直接运行脚本
ros2 run rm_nav_bringup navigate_through_waypoints

# 或通过启动文件运行
ros2 launch rm_nav_bringup navigate_through_waypoints.launch.py \
    waypoint_tolerance:=1.0 \
    final_goal_tolerance:=0.25
```

#### Python 脚本用法示例：

```python
import rclpy
from geometry_msgs.msg import PoseStamped
from rm_nav_bringup.navigate_through_waypoints import NavigateThroughWaypoints

rclpy.init()
node = NavigateThroughWaypoints()

# 创建目标列表
poses = []

# 途径点 1
pose1 = PoseStamped()
pose1.header.frame_id = 'map'
pose1.pose.position.x = 2.0
pose1.pose.position.y = 2.0
pose1.pose.orientation.w = 1.0
poses.append(pose1)

# 途径点 2
pose2 = PoseStamped()
pose2.header.frame_id = 'map'
pose2.pose.position.x = 4.0
pose2.pose.position.y = 4.0
pose2.pose.orientation.w = 1.0
poses.append(pose2)

# 最终目标
final_goal = PoseStamped()
final_goal.header.frame_id = 'map'
final_goal.pose.position.x = 6.0
final_goal.pose.position.y = 6.0
final_goal.pose.orientation.w = 1.0
poses.append(final_goal)

# 执行导航
success = node.navigate_through_waypoints(poses, use_different_tolerances=True)

if success:
    print("✓ 导航成功！")
else:
    print("✗ 导航失败！")

rclpy.shutdown()
```

### 方法 2：C++ 插件（性能最优，需要编译）

修改 `rm_nav_bringup/CMakeLists.txt`，添加：

```cmake
# 添加依赖
find_package(behaviortree_ros2 REQUIRED)
find_package(nav2_msgs REQUIRED)

# 添加库
add_library(navigate_through_waypoints_plugin
  src/navigate_through_waypoints.cpp)
ament_target_dependencies(navigate_through_waypoints_plugin
  behaviortree_ros2
  nav2_msgs
  rclcpp
  geometry_msgs)

# 注册插件
pluginlib_export_class(
  rm_nav_bringup::NavigateThroughWaypoints
  behaviortree_ros2::BtServiceNode)
```

### 方法 3：Behavior Tree XML（与现有 BT 集成）

```xml
<NavigateThroughWaypoints 
    poses="{waypoints}"
    waypoint_tolerance="1.0"
    final_goal_tolerance="0.25"/>
```

---

## 参数配置

### 主要参数

| 参数 | 类型 | 默认值 | 说明 |
|------|------|--------|------|
| `waypoint_tolerance` | double | 1.0 | 途径点容差（米） |
| `final_goal_tolerance` | double | 0.25 | 最终目标容差（米） |
| `goal_checker_service_timeout` | double | 1.0 | ROS 服务超时时间（秒） |

### 参数修改

#### 方式 1：启动时指定

```bash
ros2 launch rm_nav_bringup navigate_through_waypoints.launch.py \
    waypoint_tolerance:=1.5 \
    final_goal_tolerance:=0.15
```

#### 方式 2：运行时动态修改

```bash
# 修改途径点容差
ros2 param set /navigate_through_waypoints waypoint_tolerance 1.5

# 修改最终目标容差
ros2 param set /navigate_through_waypoints final_goal_tolerance 0.15
```

---

## 工作流程

```
┌─────────────────────────────────────────┐
│ 输入：poses 列表（包含所有途径点 + 最终目标）│
└────────────┬────────────────────────────┘
             │
             ▼
    ┌────────────────────┐
    │ 对于每个途径点：    │
    ├────────────────────┤
    │ 1. 设置宽松容差    │
    │ 2. 计算路径        │
    │ 3. 跟随路径        │
    │ 4. 检查到达        │
    └────────┬───────────┘
             │
    (重复直到倒数第二个目标点)
             │
             ▼
    ┌────────────────────┐
    │ 处理最终目标：      │
    ├────────────────────┤
    │ 1. 设置严格容差    │
    │ 2. 计算路径        │
    │ 3. 跟随路径        │
    │ 4. 检查到达        │
    └────────┬───────────┘
             │
             ▼
    ┌────────────────────┐
    │ 返回结果：成功/失败│
    └────────────────────┘
```

---

## 容差配置建议

| 场景 | 途径点容差 | 最终目标容差 | 说明 |
|------|----------|-------------|------|
| 巡逻任务 | 1.0-1.5 m | 0.5 m | 途径点不需要精确，最终位置相对精确 |
| 分拣任务 | 0.5 m | 0.1 m | 所有位置都需要相对精确 |
| 快速导航 | 2.0 m | 1.0 m | 容差较大，速度优先 |
| 精密作业 | 0.2 m | 0.05 m | 所有位置都需要非常精确 |

---

## 与 Nav2 的差异对比

| 特性 | `navigate_through_poses` | 本方案 |
|------|----------------------|--------|
| 自动去除已通过的目标 | ✅ 自动 | ❌ 需手动处理 |
| 灵活容差控制 | ❌ 无 | ✅ 完全灵活 |
| 途中中断和恢复 | ❌ 困难 | ✅ 容易 |
| 高级逻辑集成 | ❌ 受限 | ✅ 完全开放 |
| 性能 | ✅ 最优 | ⚠️ 轻微额外开销 |
| 实现复杂度 | ✅ 简单 | ⚠️ 中等 |

---

## 故障排除

### 问题 1：容差设置不生效

**症状：** 修改容差参数后，导航行为没有改变

**解决：** 
```bash
# 检查 controller_server 是否运行
ros2 node list | grep controller_server

# 检查参数是否成功设置
ros2 param get /controller_server general_goal_checker.xy_goal_tolerance
```

### 问题 2：到达目标点后立即开始下一个

**症状：** 导航器到达一个途径点后，立即开始导航到下一个，没有停顿

**解决：** 增加等待时间

```python
# 在 navigat_to_pose 后添加
time.sleep(1.0)  # 停留 1 秒
```

### 问题 3：最终目标无法精确到达

**症状：** 最终目标容差已经很小（如 0.05m），但仍无法到达

**可能原因：**
- 容差设置太严格（小于机器人精度）
- 路径规划器无法找到完全准确的路径
- 局部规划器振荡

**解决：**
```yaml
# 调整 TEB 局部规划器参数
min_obstacle_dist: 0.3      # 减小避障距离
weight_obstacle: 50.0       # 降低障碍物权重
weight_optimaltime: 0.2     # 增加时间优化权重
```

---

## 扩展功能

### 添加暂停/恢复功能

```python
def pause_navigation(self):
    """暂停当前导航"""
    if self._action_client._goal_handle:
        self._action_client._goal_handle.cancel()
        self.get_logger().info('导航已暂停')

def resume_navigation(self):
    """恢复导航"""
    # 继续导航到当前未完成的目标
    pass
```

### 添加目标修改功能

```python
def update_waypoints(self, new_poses: List[PoseStamped]):
    """动态更新途径点"""
    # 可用于实时路径修改
    pass
```

---

## 最佳实践

1. ✅ **在启动时设置合理的容差**
2. ✅ **为每个任务类型定义容差配置**
3. ✅ **添加日志记录便于调试**
4. ✅ **测试不同网络延迟下的行为**
5. ✅ **在实机上验证后再部署**

---

## 参考链接

- [Nav2 官方文档](https://nav2.readthedocs.io/)
- [BehaviorTree.CPP 文档](https://www.behaviortree.dev/)
- [ROS 2 Action 教程](https://docs.ros.org/en/humble/Tutorials/Intermediate/Writing-an-Action-Server-Client.html)
