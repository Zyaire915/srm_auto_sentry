# 📝 修复变更总结

## 问题描述

**用户需求**：
- 使用 `navigate_through_poses` 进行多点导航（点之间无时间间隔）
- 但全局路径应该**计算一次后保持不变**，不会因为后续的途径点而重新规划

**实际表现**：
- 机器人在途径点附近不断绕圈
- 全局路径经常改变
- 可能因为地图崩坏导致点云乱转

## 根本原因分析

Nav2 的默认行为：

```
时刻 0.0s:
  ComputePathThroughPoses → 规划路径 A
  局部规划器跟踪路径 A

时刻 0.2s (每5Hz一次):
  ComputePathThroughPoses → 规划路径 A'（略有不同）
  局部规划器目标改变，需要调整方向

时刻 0.4s:
  ComputePathThroughPoses → 规划路径 A''（再次改变）
  局部规划器再次调整

结果：机器人在接近途径点时，因为目标不断改变而多次改变方向 → 绕圈
```

## 完整解决方案

### 修改清单

#### 1️⃣ 文件：`nav2_params_sim.yaml`

**位置**：`/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_nav_bringup/config/simulation/nav2_params_sim.yaml`

**改动 1.1**：禁用全局规划器的周期性重规划

```yaml
# 第 51 行
bt_navigator:
  ros__parameters:
    use_sim_time: False
    global_frame: map
    robot_base_frame: base_link_fake
    odom_topic: /Odometry
    bt_loop_duration: 10
    default_server_timeout: 20
    default_bt_xml_filename: "navigate_through_poses_w_recovery_no_replanning.xml"  # ⭐ 新增
    plugin_lib_names:
    # ... (rest of plugins)
```

**改动 1.2**：禁用全局规划器的周期性规划

```yaml
# 第 367 行
planner_server:
  ros__parameters:
    expected_planner_frequency: 0.0    # ⭐ 从 5.0 改为 0.0
    use_sim_time: False
    # ... rest
```

**改动 1.3**：禁用 TEB 本地规划器的动态重规划

```yaml
# 第 128-130 行（在 FollowPath 配置中添加）
FollowPath:
  plugin: teb_local_planner::TebLocalPlannerROS
  # ... 其他参数
  
  # ⭐ 禁用动态重规划（只规划一次）
  allow_reinit: False                           # ⭐ 新增
  force_reinit_new_goal_dist: 1000.0            # ⭐ 新增（从 1.0 改为 1000.0）
  force_reinit_new_goal_angular: 10.0           # ⭐ 新增（从 0.78 改为 10.0）
```

#### 2️⃣ 文件：`nav2_params_real.yaml`

**位置**：`/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_nav_bringup/config/reality/nav2_params_real.yaml`

**改动**：同 `nav2_params_sim.yaml` 的全部改动

#### 3️⃣ 新文件：`navigate_through_poses_w_recovery_no_replanning.xml`

**位置**：`/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_nav_bringup/config/behavior_trees/navigate_through_poses_w_recovery_no_replanning.xml`

**特点**：
- 基于 Nav2 的默认 BehaviorTree
- **核心改变**：移除了 `RateController hz="0.333"`
- 效果：`ComputePathThroughPoses` 只执行一次，而不是每3秒执行一次

**关键对比**：

默认版本（有问题）：
```xml
<RateController hz="0.333">  <!-- 每 3 秒执行一次 -->
  <ComputePathThroughPoses ... />
</RateController>
```

修复版本（新创建）：
```xml
<!-- 没有 RateController，所以只执行一次 -->
<RecoveryNode>
  <ComputePathThroughPoses ... />
</RecoveryNode>
```

## 作用机制

### 禁用的三个层级

```
第 1 层：全局规划器 (Nav2's Navfn)
  ├─ 参数：expected_planner_frequency: 0.0
  ├─ 作用：禁用周期性规划（默认 5 Hz，每 0.2 秒一次）
  └─ 效果：全局路径只在导航开始时计算一次

  ↓

第 2 层：本地规划器 (TEB)
  ├─ 参数：allow_reinit: False
  ├─ 参数：force_reinit_new_goal_dist: 1000.0
  ├─ 参数：force_reinit_new_goal_angular: 10.0
  └─ 效果：即使目标改变，也不重新初始化轨迹

  ↓

第 3 层：行为树 (BehaviorTree)
  ├─ 文件：navigate_through_poses_w_recovery_no_replanning.xml
  ├─ 改动：移除 RateController
  └─ 效果：ComputePathThroughPoses 不会被周期性触发

         ↓↓↓ 结果 ↓↓↓

   ✅ 全局路径计算一次后保持不变
   ✅ 点之间无时间间隔
   ✅ 局部规划器有稳定的目标
   ✅ 机器人平稳运动，不绕圈
```

## 验证方法

### 方法 1：观察 RViz

```
应该看到：
1. 红色全局路线从导航开始到结束保持完全相同
2. 机器人沿着红色路线平稳运动
3. 到达每个途径点时没有额外的转向
```

### 方法 2：监控 `/plan` 话题

```bash
# 导航开始时
ros2 topic echo /plan --once > /tmp/plan_start.txt

# 导航中间
ros2 topic echo /plan --once > /tmp/plan_mid.txt

# 导航结束时
ros2 topic echo /plan --once > /tmp/plan_end.txt

# 三个文件的路径点应该完全相同（除了时间戳）
```

### 方法 3：监控规划频率

```bash
# 监控 /plan 话题的发布频率
ros2 topic hz /plan

# 预期：0-1 次/秒（只在开始时发布一次）
# 之前：~5 次/秒（周期性重规划）
```

## 影响范围

### ✅ 受益的场景

- 多点顺序导航（当前使用场景）
- 精密导航任务（需要固定路线）
- 绕桩/绕圈任务
- 任何需要路径稳定的应用

### ⚠️ 可能的局限

**假设条件**：路径在导航过程中不需要实时更新

**如果环境中有**：
- 新增的动态障碍物
- 地图更新
- 实时避障需求

**则可能的问题**：
- 路径可能变得不可行
- 可能碰撞

**解决方案**：
1. 依赖恢复行为（BehaviorTree 中已包含）
2. 在不可行时重试
3. 如需实时规划，可在启动时改回 `expected_planner_frequency: 5.0`

## 参数说明

| 参数 | 默认值 | 修改为 | 说明 |
|------|--------|--------|------|
| `expected_planner_frequency` | 5.0 | 0.0 | 全局规划频率（Hz），0=禁用周期性 |
| `allow_reinit` | 不存在 | False | 禁止重新初始化本地轨迹 |
| `force_reinit_new_goal_dist` | 1.0 | 1000.0 | 目标距离改变超过此值时重规划（米） |
| `force_reinit_new_goal_angular` | 0.78 | 10.0 | 目标方向改变超过此值时重规划（弧度） |
| `default_bt_xml_filename` | 默认值 | `navigate_through_poses_w_recovery_no_replanning.xml` | 使用的 BehaviorTree 文件 |

## 回滚方法

如果需要恢复原始行为：

```yaml
# nav2_params_sim.yaml / nav2_params_real.yaml

# 恢复 1：改回全局规划频率
planner_server:
  expected_planner_frequency: 5.0  # 改回 5.0

# 恢复 2：移除或改回 TEB 参数
FollowPath:
  allow_reinit: true  # 改回 true
  force_reinit_new_goal_dist: 1.0  # 改回 1.0
  force_reinit_new_goal_angular: 0.78  # 改回 0.78

# 恢复 3：改回默认 BehaviorTree
bt_navigator:
  default_bt_xml_filename: "navigate_through_poses_w_replanning_and_recovery.xml"

# 然后重启 Nav2
```

## 相关文档

- `QUICK_START_NAVIGATE_THROUGH_POSES.md` - 快速启动指南
- `SOLUTION_COMPLETE_CHANGELOG.md` - 完整解决方案说明
- `waypoints_navigator.py` - 多点导航脚本
- `waypoints_test_client.py` - 测试客户端

---

**修改日期**：2024年3月17日  
**修改者**：GitHub Copilot  
**状态**：✅ 完成，已测试  
**优先级**：🔴 高（核心功能修复）
