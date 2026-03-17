# 绮桩导航配置指南

## 问题描述

在使用多途径点导航进行绮桩任务时，TEB 局部规划器和全局路径之间会产生冲突，导致机器人在途径点之间反复振荡。这是因为 TEB 会进行自己的轨迹优化，与预定义的绮桩路径不符。

## 解决方案

我们提供了一个**专用的参数配置文件**：`nav2_params_pole_tracking.yaml`

这个配置通过调整 TEB 本地规划器的参数，让它严格跟随全局路径，而不是自己进行优化。

## 使用方法

### 方法一：使用专用参数文件启动（推荐）

```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL \
    mode:=nav \
    lio:=fastlio \
    localization:=slam_toolbox \
    nav_rviz:=True \
    waypoint_tolerance:=0.3 \
    final_goal_tolerance:=0.2
```

然后修改启动文件使用特殊参数，或者直接启动 nav2：

```bash
ros2 launch rm_navigation bringup_sim.launch.py \
    world:=RMUL \
    mode:=nav \
    lio:=fastlio \
    localization:=slam_toolbox \
    params_file:=/workspaces/srm_auto_sentry/install/rm_navigation/share/rm_navigation/params/nav2_params_pole_tracking.yaml
```

### 方法二：参数动态修改

如果已经启动了 Nav2，可以在运行时修改参数：

```bash
# 禁用自动调整大小
ros2 param set /controller_server FollowPath.teb_autosize False

# 增加时间步长
ros2 param set /controller_server FollowPath.dt_ref 0.3

# 增加经过点权重
ros2 param set /controller_server FollowPath.weight_viapoint 1.0

# 增加向前驱动权重
ros2 param set /controller_server FollowPath.weight_kinematics_forward_drive 900.0

# 减少障碍物权重
ros2 param set /controller_server FollowPath.weight_obstacle 50.0
```

## 配置文件的关键参数说明

### 路径跟踪相关

| 参数 | 值 | 说明 |
|------|-----|------|
| `global_plan_viapoint_sep` | 0.5 | 经过点分离距离，越小跟踪越精确 |
| `weight_viapoint` | 1.0 | 经过点权重，越大越严格跟踪 |
| `weight_kinematics_forward_drive` | 900.0 | 前进驱动权重，强制向前 |
| `teb_autosize` | False | 禁用自动大小调整，保持稳定 |
| `dt_ref` | 0.3 | 时间步长，越大越平滑 |

###速度和加速度约束

| 参数 | 值 | 说明 |
|------|-----|------|
| `max_vel_x` | 2.0 | 最大前进速度 |
| `max_vel_y` | 0.0 | 最大侧向速度（禁止）|
| `max_vel_theta` | 4.0 | 最大角速度 |
| `acc_lim_x` | 2.5 | 前进加速度限制 |

### 优化权重

| 参数 | 值 | 说明 |
|------|-----|------|
| `weight_obstacle` | 50.0 | 避障权重，降低避免干扰 |
| `weight_optimaltime` | 1.0 | 时间优化权重，最小化 |
| `weight_kinematics_turning_radius` | 50.0 | 转弯半径权重 |

### 禁用项目

| 参数 | 值 | 说明 |
|------|-----|------|
| `enable_homotopy_class_planning` | False | 禁用同伦类规划，保持简单 |
| `allow_init_with_backwards_motion` | False | 禁止反向初始化 |
| `allow_backwards_motion` | False | 禁止反向运动 |

## 实际使用案例

### 场景：绮桩任务

```bash
# 终端 1：启动导航系统（使用绮桩专用参数）
ros2 launch rm_navigation bringup_sim.launch.py \
    world:=RMUL \
    mode:=nav \
    lio:=fastlio \
    localization:=slam_toolbox \
    params_file:=/workspaces/srm_auto_sentry/install/rm_navigation/share/rm_navigation/params/nav2_params_pole_tracking.yaml

# 终端 2：启动多途径点导航器和 RViz
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    nav_rviz:=True waypoint_tolerance:=0.3 final_goal_tolerance:=0.2

# 终端 3：发送绮桩路线
ros2 run rm_nav_bringup waypoints_test_client
# 选择示例 1 或其他路线
```

## 效果对比

### 原始配置（DWB/TEB 正常优化）
- ❌ 机器人在途径点之间振荡
- ❌ 路径偏离预定轨迹
- ❌ 任务完成时间长

### 绮桩专用配置
- ✅ 机器人精确跟随预定路线
- ✅ 无路径偏离
- ✅ 平稳导航
- ✅ 适合精密任务

## 参数调整指南

如果机器人的表现仍不理想，可以微调以下参数：

### 如果机器人过度优化（偏离路径）

```bash
# 增加经过点权重
ros2 param set /controller_server FollowPath.weight_viapoint 2.0

# 增加向前驱动权重
ros2 param set /controller_server FollowPath.weight_kinematics_forward_drive 1000.0

# 减少时间优化权重
ros2 param set /controller_server FollowPath.weight_optimaltime 0.5
```

### 如果机器人运动不稳定（抖动）

```bash
# 增加时间步长
ros2 param set /controller_server FollowPath.dt_ref 0.4

# 减少采样点数
ros2 param set /controller_server FollowPath.max_samples 300

# 增加避障权重以稳定
ros2 param set /controller_server FollowPath.weight_obstacle 100.0
```

### 如果机器人速度过快或过慢

```bash
# 调整最大速度
ros2 param set /controller_server FollowPath.max_vel_x 1.5

# 调整最大角速度
ros2 param set /controller_controller FollowPath.max_vel_theta 3.0
```

## 与实车集成

本配置同时适用于仿真和实车：

1. **仿真环境**：直接使用上述启动命令
2. **实车环境**：
   - 将 `world:=RMUL` 改为实际机器人配置
   - 将 `lio:=fastlio` 改为实车使用的传感器
   - 将 `localization:=slam_toolbox` 改为实车定位方案
   - **参数配置完全相同**，无需修改

## 故障排除

### 问题 1：参数设置不生效

```bash
# 检查当前参数值
ros2 param get /controller_server FollowPath.weight_viapoint

# 查看参数的最小/最大值
ros2 param describe /controller_server FollowPath.weight_viapoint
```

###问题 2：仍然有振荡

- 检查 TEB 的日志级别：
  ```bash
  ros2 run rm_navigation bringup_sim.launch.py ... --ros-args --log-level teb_local_planner:=DEBUG
  ```
- 查看是否有 "oscillation" 警告，如果有，增加 `weight_viapoint` 或降低 `weight_obstacle`

### 问题 3：机器人无法完成任务

- 检查途径点的间距是否过小（< 0.5m）
- 检查目标点是否在可行走区域内
- 增加容差值：`waypoint_tolerance:=0.5`

## 高级用法

### 自定义绮桩参数组

可以创建多个参数文件用于不同的任务：

```bash
# 高精度绮桩
cp nav2_params_pole_tracking.yaml nav2_params_pole_tracking_precise.yaml
# 编辑该文件，设置更严格的参数

# 快速巡逻
cp nav2_params_pole_tracking.yaml nav2_params_patrol_fast.yaml
# 编辑该文件，放松参数约束
```

然后在启动时选择：

```bash
ros2 launch rm_navigation bringup_sim.launch.py \
    ... \
    params_file:=.../nav2_params_pole_tracking_precise.yaml
```

## 参考资源

- TEB 本地规划器官方文档：http://wiki.ros.org/teb_local_planner
- Nav2 控制器配置：https://navigation.ros.org/configuration/index.html
- 多途径点导航指南：见 WAYPOINTS_NAVIGATION_GUIDE.md

---

**最后更新**：2026-03-17  
**版本**：1.0.0
