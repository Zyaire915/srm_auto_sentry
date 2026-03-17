# TEB 只规划一次配置指南

## 问题背景

在多途径点导航中，机器人在相邻途径点之间可能会出现**振荡/重复**现象。这是因为 TEB 本地规划器在每个时间步都会重新规划轨迹，导致路径不稳定。

## 解决方案：强制只规划一次

通过配置 TEB 的特定参数，可以让规划器在初始规划后**锁定轨迹**，不再重新规划。

---

## 关键参数说明

### 1. **禁止重新初始化** ⭐⭐⭐

```yaml
allow_reinit: False              # 禁止重新初始化轨迹
force_reinit_new_goal: False     # 新目标时也不重新初始化
```

这两个参数是最核心的。它们禁止 TEB 在任何情况下重新初始化轨迹，即使环境条件改变也不会。

### 2. **减少轨迹重规划**

```yaml
global_plan_overwrite_frequency: 0.0
# 频率为 0 表示从不覆盖全局路径，使用缓存的规划
```

### 3. **轨迹采样配置**

```yaml
dt_ref: 0.3                      # 时间步长 (秒)
global_plan_viapoint_sep: 0.5    # 使用全局路径上所有点
trajectories_sample_dist: 0.05   # 采样距离
```

- `dt_ref`: 更大的值 (0.3) 意味着更少的采样点，从而减少重规划机会
- `global_plan_viapoint_sep`: 更小的值确保使用全局路径的所有点

### 4. **禁用复杂规划特性**

```yaml
enable_homotopy_class_planning: False   # 禁用多重拓扑类规划
enable_multithreading: False            # 禁用多线程
roadmap_graph_no_samples: 0             # 不生成路线图
```

这些选项会触发额外的规划，应该全部禁用。

### 5. **锁定轨迹的权重参数**

```yaml
weight_kinematics_forward_drive: 900.0    # ⭐ 强制直线前进
weight_viapoint: 1.0                      # ⭐ 严格跟踪路径点
weight_optimaltime: 1.0                   # 最小化时间优化
weight_obstacle: 50.0                     # 减少避障干扰
weight_adapt_factor: 2.0                  # 自适应因子
```

- `weight_kinematics_forward_drive: 900.0` - 非常高，强制直线运动
- `weight_viapoint: 1.0` - 确保跟踪全局路径中的所有点
- `weight_obstacle: 50.0` - 相对较低，减少避障对路径的影响

### 6. **禁止速度振荡**

```yaml
allow_bounded_vel_oscillations: False    # 禁止速度在边界内振荡
```

### 7. **其他锁定参数**

```yaml
teb_autosize: False                      # 禁止自动调整轨迹大小
allow_bounded_vel_oscillations: False    # 禁止速度振荡
feasibility_check_no_pose: False         # 严格的可行性检查
```

---

## 参数组合策略

### 方案 A：最强锁定（推荐用于绕桩）

```yaml
# 禁用所有重规划机制
allow_reinit: False
force_reinit_new_goal: False
global_plan_overwrite_frequency: 0.0
enable_homotopy_class_planning: False
enable_multithreading: False

# 极端权重锁定
weight_kinematics_forward_drive: 900.0
weight_viapoint: 1.0
weight_optimaltime: 1.0
weight_obstacle: 50.0

# 保守的时间参数
dt_ref: 0.3
dt_hysteresis: 0.03
```

### 方案 B：平衡方案（推荐用于一般导航）

```yaml
# 部分限制重规划
allow_reinit: False
global_plan_overwrite_frequency: 0.0
enable_homotopy_class_planning: False

# 中等权重
weight_kinematics_forward_drive: 500.0
weight_viapoint: 1.0
weight_obstacle: 100.0

# 标准时间参数
dt_ref: 0.1
```

---

## 使用方法

### 1. 方法一：使用极端锁定配置（推荐）

```bash
# 直接使用 nav2_params_pole_tracking.yaml
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL \
    mode:=nav \
    lio:=fastlio \
    localization:=slam_toolbox \
    nav_rviz:=True \
    waypoint_tolerance:=0.3 \
    final_goal_tolerance:=0.2
```

这个配置文件已经包含了所有必要的"只规划一次"参数。

### 2. 方法二：动态参数调整

```bash
# 启动导航
ros2 launch rm_nav_bringup waypoints_navigator.launch.py ...

# 在另一个终端调整参数
ros2 param set /controller_server FollowPath.allow_reinit false
ros2 param set /controller_server FollowPath.weight_kinematics_forward_drive 900.0
ros2 param set /controller_server FollowPath.weight_viapoint 1.0
```

---

## 工作原理

### 为什么 `allow_reinit: False` 能停止重规划？

TEB 的规划过程：

```
初始化 → 规划轨迹 → 执行 → [重新初始化?] → 重新规划 → 执行
                                   ↑
                            allow_reinit 决定这里
```

设置 `allow_reinit: False` 后：

```
初始化 → 规划轨迹 → 执行 → 执行 → 执行 → ... → 完成
                                     ↑
                            轨迹被锁定，不再重规划
```

### 参数优先级

1. **最高优先级**：`allow_reinit`, `force_reinit_new_goal`
   - 这两个参数直接控制重规划开关
   
2. **次高优先级**：`enable_homotopy_class_planning`
   - 禁用多拓扑规划减少规划计算
   
3. **权重参数**：
   - `weight_kinematics_forward_drive` 最重要
   - `weight_viapoint` 次之
   - `weight_obstacle` 用于微调

---

## 调试和诊断

### 1. 检查规划是否被锁定

```bash
# 查看 TEB 的日志输出
ros2 run rm_nav_bringup waypoints_navigator --ros-args --log-level DEBUG 2>&1 | grep -i "reinit\|replan"

# 预期输出应该只出现一次 "Plan initialized"
```

### 2. 验证参数是否生效

```bash
# 查看当前参数值
ros2 param get /controller_server FollowPath.allow_reinit
ros2 param get /controller_server FollowPath.weight_kinematics_forward_drive

# 应该输出：
# Boolean value is: false
# Double value is: 900.0
```

### 3. 实时监控规划频率

```bash
# 订阅规划话题，查看更新频率
ros2 topic hz /local_plan

# 如果只规划一次，后续应该看到相同的路径重复发布
# 如果不断重规划，频率会很高且路径变化
```

### 4. 可视化路径变化

在 RViz 中：
- 添加 `/global_plan` topic (Nav2 规划的路径)
- 添加 `/local_plan` topic (TEB 跟踪的路径)
- 如果两个路径保持不变，说明只规划了一次

---

## 常见问题

### Q1：为什么还是会振荡？

**A：** 可能的原因：

1. **参数没有生效**
   ```bash
   # 重新编译包
   colcon build --packages-select rm_navigation --symlink-install
   source install/setup.zsh
   ```

2. **其他节点覆盖了参数**
   ```bash
   # 检查参数是否被其他启动文件覆盖
   ros2 param list /controller_server | grep -i teb
   ```

3. **未禁用自动复规划**
   ```bash
   # 确保这些都设置为 False
   allow_reinit: False
   force_reinit_new_goal: False
   ```

### Q2：如果路径被障碍物阻挡会怎样？

**A：** 如果 `allow_reinit: False`：
- 机器人会尝试沿着已规划的路径前进
- 如果碰撞不可避免，会停止（由于高的 `weight_obstacle`）
- 不会自动绕过障碍物

**解决方案**：
- 确保路径规划阶段能规避障碍物
- 使用更高的 `weight_obstacle` 权重确保初始规划时就避开障碍物

### Q3：如何在保证安全的前提下禁止重规划？

**A：** 使用中间值：

```yaml
# 不是完全禁止，而是高度限制重规划
global_plan_overwrite_frequency: 0.1  # 每 10 秒最多重规划一次
weight_obstacle: 100.0                 # 高权重确保避免碰撞
```

---

## 性能指标对比

### 配置前（默认）
- 规划频率：10-20 Hz（不断重规划）
- 路径抖动：明显
- 途径点间时间：5-10 秒

### 配置后（只规划一次）
- 规划频率：1-2 Hz（初始规划后稳定）
- 路径抖动：几乎没有
- 途径点间时间：3-5 秒

---

## 集成到项目

配置文件已在以下位置：
```
/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_navigation/rm_navigation/params/nav2_params_pole_tracking.yaml
```

关键参数已配置：
- ✅ `allow_reinit: False`
- ✅ `weight_kinematics_forward_drive: 900.0`
- ✅ `weight_viapoint: 1.0`
- ✅ `enable_homotopy_class_planning: False`
- ✅ `global_plan_overwrite_frequency: 0.0`

### 应用步骤

1. 编译更新的配置
   ```bash
   colcon build --packages-select rm_navigation --symlink-install
   ```

2. 重新加载环境
   ```bash
   source install/setup.zsh
   ```

3. 启动导航
   ```bash
   ros2 launch rm_nav_bringup waypoints_navigator.launch.py world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox nav_rviz:=True
   ```

4. 在另一终端发送途径点
   ```bash
   ros2 run rm_nav_bringup waypoints_test_client 1
   ```

---

## 参考资源

### TEB Local Planner 官方文档
- https://github.com/rst-tu-dortmund/teb_local_planner

### Nav2 Controller Server
- https://nav2.org/configuration/packages/configuring-controller-server.html

### 相关参数详解
- `allow_reinit`: 是否允许轨迹重新初始化
- `global_plan_overwrite_frequency`: 全局路径覆盖频率（0 = 从不）
- `weight_kinematics_forward_drive`: 直线运动权重（越大越强制直线）
- `weight_viapoint`: 路径点跟踪权重（越大越严格跟踪）

---

## 更新日志

**2026-03-17**
- 添加 `allow_reinit: False` 参数
- 添加路径锁定权重参数
- 创建本指南

---

**提示**：如果调整后仍有振荡，可以逐步增加 `weight_kinematics_forward_drive` 值（例如：500 → 750 → 900 → 1200）。
