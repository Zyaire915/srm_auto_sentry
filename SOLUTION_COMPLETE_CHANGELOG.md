# 🎯 完整修复方案：无间隔多点导航 + 全局路径不变

## 问题诊断

你的需求：
- ✅ 使用 `navigate_through_poses` 导航（点之间无时间间隔）
- ✅ **但全局路径保持不变**（不会因为新的途径点而重新规划回头）

根本原因：
- Nav2 默认每0.2秒重规划一次全局路径
- 新的重规划可能改变整个路线
- 局部规划器的目标不断改变
- 结果：机器人在途径点附近绕圈

## 完整解决方案（3个层面的禁用）

### 🔧 修复 1：禁用全局路径周期性规划

**文件**：`nav2_params_sim.yaml` 和 `nav2_params_real.yaml`

**改动**：
```yaml
planner_server:
  ros__parameters:
    expected_planner_frequency: 0.0    # ⭐ 禁用周期性重规划
    # 默认值是 5.0 Hz（每0.2秒规划一次）
    # 改为 0.0 后，只在初始时规划一次
```

### 🔧 修复 2：禁用局部规划器的动态重规划

**文件**：同上

**改动**：在 TEB 配置中添加：
```yaml
FollowPath:
  plugin: teb_local_planner::TebLocalPlannerROS
  # ...
  allow_reinit: False                           # 禁止重新初始化
  force_reinit_new_goal_dist: 1000.0            # 极大的阈值，禁止因目标改变而重规划
  force_reinit_new_goal_angular: 10.0           # 极大的角度，禁止因目标旋转而重规划
```

### 🔧 修复 3：使用无重规划的 BehaviorTree

**文件**：
- `navigate_through_poses_w_recovery_no_replanning.xml` (新创建)
- `nav2_params_sim.yaml` 的 `bt_navigator` 部分

**改动**：
```yaml
bt_navigator:
  ros__parameters:
    # ...
    default_bt_xml_filename: "navigate_through_poses_w_recovery_no_replanning.xml"
    # 这个 BehaviorTree 移除了 RateController，只规划一次
```

## 效果对比

| 方面 | 修复前 | 修复后 |
|------|--------|--------|
| 全局路径更新频率 | 每 0.2 秒 ❌ | 仅一次 ✅ |
| 局部规划器重规划 | 频繁 ❌ | 禁用 ✅ |
| 目标改变时反应 | 重规划 ❌ | 保持路径 ✅ |
| 途径点间隔 | 无间隔 ✅ | 无间隔 ✅ |
| 绕圈问题 | 有 ❌ | 无 ✅ |

## 立即测试

### 步骤 1：启动导航系统

```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox nav_rviz:=True
```

### 步骤 2：运行原始导航器

```bash
ros2 run rm_nav_bringup waypoints_navigator
```

### 步骤 3：发送测试路线

```bash
ros2 run rm_nav_bringup waypoints_test_client 1
```

### 步骤 4：观察

在 RViz 中应该看到：
- ✅ 红色路线（全局路径）保持不变
- ✅ 机器人沿着红色路线平稳运动
- ✅ 无论导航过程中发生什么，路径都不改变
- ✅ 到达每个途径点时没有多余的转向

## 修改的文件列表

1. **`nav2_params_sim.yaml`**
   - L51: 添加 `default_bt_xml_filename`
   - L367: `expected_planner_frequency: 0.0`
   - L128-130: 添加 TEB 禁用重规划参数

2. **`nav2_params_real.yaml`** (同样改动)

3. **`navigate_through_poses_w_recovery_no_replanning.xml`** (新创建)
   - 移除 `RateController`，只规划一次

## 原理解析

### 为什么要禁用周期性规划？

```
禁用前（有问题）:
时刻 0.0s: ComputePathThroughPoses → 路径 A
时刻 0.2s: ComputePathThroughPoses → 路径 A' （略有不同）
时刻 0.4s: ComputePathThroughPoses → 路径 A'' （再次改变）
↓
局部规划器目标不断改变 → 机器人转向改变 → 绕圈

禁用后（正常）:
时刻 0.0s: ComputePathThroughPoses → 路径 A
← 不再重规划 →
机器人严格跟踪路径 A → 平稳运动 ✅
```

### BehaviorTree 的改变

**默认版本** (`navigate_through_poses_w_replanning_and_recovery.xml`):
```xml
<RateController hz="0.333">  <!-- 每 3 秒重规划一次 -->
  <ComputePathThroughPoses ... />
</RateController>
```

**修复版本** (`navigate_through_poses_w_recovery_no_replanning.xml`):
```xml
<!-- 移除 RateController，只执行一次 -->
<RecoveryNode>
  <ComputePathThroughPoses ... />  <!-- 仅执行一次 -->
</RecoveryNode>
```

## 常见问题

### Q: 为什么不直接修改 `waypoints_navigator.py`？
A: BehaviorTree 和参数是 Nav2 的核心，改动效果更彻底。修改参数文件是最可靠的方式。

### Q: 如果路径计算失败怎么办？
A: BehaviorTree 中的 `RecoveryNode` 会尝试清除代价地图并重试一次。

### Q: 能不能在运行时改这些参数？
A: 可以通过 `ros2 param set` 改某些参数，但 `expected_planner_frequency` 和 BehaviorTree 文件需要重启 Nav2。

## 验证方法

监控 `/plan` 话题，确认路径不变：

```bash
# 终端 1：启动导航
ros2 launch rm_nav_bringup waypoints_navigator.launch.py ...

# 终端 2：监控路径
ros2 topic echo /plan --once  # 第一次
# ... 等待导航中 ...
ros2 topic echo /plan --once  # 第二次
# 两次输出应该完全相同（除了时间戳）
```

---

✨ **总结**：通过禁用三层级别的重规划（全局规划、局部规划、BehaviorTree），保证全局路径计算一次且保持不变，从而实现无间隔多点导航而不会绕圈。

**关键配置**：
- `expected_planner_frequency: 0.0`
- `allow_reinit: False`
- `default_bt_xml_filename: "navigate_through_poses_w_recovery_no_replanning.xml"`

最后更新：2024年3月17日
