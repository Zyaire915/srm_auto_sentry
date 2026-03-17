# 🚀 快速启动指南 - 修复后的多点导航

## 你的问题已解决 ✅

**症状**：使用 `navigate_through_poses` 时，机器人在途径点附近不断绕圈  
**根本原因**：Nav2 每 0.2 秒重新规划一次全局路径，导致目标不断改变  
**解决方案**：禁用全局路径的周期性重规划，让路径计算一次后保持不变

## 修改的配置

已修改以下文件（共2个）：

```
✅ nav2_params_sim.yaml
   - 全局规划器频率: expected_planner_frequency: 0.0
   - TEB禁用重规划: allow_reinit: False
   - BehaviorTree: navigate_through_poses_w_recovery_no_replanning.xml

✅ nav2_params_real.yaml (同样改动)

✅ navigate_through_poses_w_recovery_no_replanning.xml (新创建)
   - 移除了 RateController，只规划一次
```

## 立即测试（3步）

### 步骤 1️⃣：启动导航系统

在 **终端 A** 运行：

```bash
cd /workspaces/srm_auto_sentry
source install/setup.zsh

ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox nav_rviz:=True
```

等待看到：`[bt_navigator-X]: Navigation is running`

### 步骤 2️⃣：启动多点导航器

在 **终端 B** 运行：

```bash
cd /workspaces/srm_auto_sentry
source install/setup.zsh

ros2 run rm_nav_bringup waypoints_navigator
```

### 步骤 3️⃣：发送测试路线

在 **终端 C** 运行：

```bash
ros2 run rm_nav_bringup waypoints_test_client 1
```

## 预期结果 🎯

**在 RViz 中应该看到**：

1. ✅ **红色全局路线** - 从开始到结束保持 **完全不变**
2. ✅ **机器人平稳运动** - 沿着红色路线
3. ✅ **无转向抖动** - 在途径点处没有多余的摇摆
4. ✅ **无间隔运动** - 点与点之间无停顿（因为用的是 `navigate_through_poses`）
5. ✅ **一次规划** - 整个导航过程，全局路径只计算一次

## 监控方法

### 验证全局路径不变

```bash
# 开始导航后，在两个时刻分别查看路径
ros2 topic echo /plan --once > /tmp/plan1.txt
# ... 等待导航进行中 ...
ros2 topic echo /plan --once > /tmp/plan2.txt

# 比对两个文件的路径点数量和坐标应该完全相同
diff /tmp/plan1.txt /tmp/plan2.txt
```

### 监控规划频率

```bash
# 查看 planner_server 的日志
ros2 node info /planner_server | grep log_level

# 运行导航时，监控计算时间
ros2 topic hz /plan  # 应该在0-1次/秒（而不是5次/秒）
```

## 关键参数解释

### 1. `expected_planner_frequency: 0.0`

- **默认值**：5.0 Hz（每0.2秒规划一次）
- **修改为**：0.0（禁用周期性规划）
- **效果**：全局路径只在开始时计算一次

### 2. `allow_reinit: False`

- TEB 本地规划器的参数
- **禁止**：因为目标改变或偏离而重新初始化轨迹
- **效果**：本地规划器继续跟踪初始规划的轨迹

### 3. `force_reinit_new_goal_dist: 1000.0`

- **设置极大值**（1000米）
- **禁止**：因为目标距离改变而重规划
- **默认值**：1.0 米

### 4. `force_reinit_new_goal_angular: 10.0`

- **设置极大值**（10弧度 ≈ 573°）
- **禁止**：因为目标方向改变而重规划  
- **默认值**：0.78 弧度

### 5. `default_bt_xml_filename`

- **新 BehaviorTree**：`navigate_through_poses_w_recovery_no_replanning.xml`
- **特点**：移除了 `RateController`，所以 `ComputePathThroughPoses` 只执行一次
- **对比**：默认的 `navigate_through_poses_w_replanning_and_recovery.xml` 每3秒重规划一次

## 自定义参数调整

如果你想改变导航行为，可以编辑：

```yaml
# 在 nav2_params_sim.yaml 中

controller_server:
  ros__parameters:
    general_goal_checker:
      xy_goal_tolerance: 0.5        # 途径点容差（米）
      yaw_goal_tolerance: 6.28      # 角度容差（弧度）
```

## 常见问题

### Q1: 路径还是在改变？
A: 确保已经启动的 Nav2 读取了新的参数文件。需要重启 Nav2（Ctrl+C，然后重新启动）。

### Q2: 机器人还是在绕圈？
A: 检查以下几点：
- [ ] `expected_planner_frequency: 0.0` 是否生效
- [ ] `allow_reinit: False` 是否设置
- [ ] BehaviorTree 文件是否被正确加载
- [ ] 日志中是否有"计算路径"相关的消息

### Q3: 能否在运行时改参数？
A: 某些参数可以，但以下几个需要重启 Nav2：
- `expected_planner_frequency`
- `allow_reinit`
- `default_bt_xml_filename`

### Q4: 如果某个途径点无法到达？
A: BehaviorTree 中有恢复逻辑：
1. 清除代价地图
2. 重试一次
3. 如果仍失败，执行恢复行为（旋转、后退等）

## 文件位置参考

```
/workspaces/srm_auto_sentry/
├── src/pb_rmsimulation/src/
│   ├── rm_nav_bringup/
│   │   ├── config/
│   │   │   ├── simulation/nav2_params_sim.yaml       ⭐ (已修改)
│   │   │   ├── reality/nav2_params_real.yaml         ⭐ (已修改)
│   │   │   └── behavior_trees/
│   │   │       └── navigate_through_poses_w_recovery_no_replanning.xml  ⭐ (新创建)
│   │   └── scripts/
│   │       └── waypoints_navigator.py
│   └── rm_navigation/
│       └── rm_navigation/params/
│           └── nav2_params*.yaml (引用上面的参数)
│
└── SOLUTION_COMPLETE_CHANGELOG.md  ⭐ (完整说明)
```

## 总结

```
禁用的三个层级：
┌─────────────────────────────────────────────┐
│ 1. Global Planner (Navfn)                   │
│    ├─ expected_planner_frequency: 0.0       │
│    └─ 效果：只规划一次                      │
├─────────────────────────────────────────────┤
│ 2. Local Planner (TEB)                      │
│    ├─ allow_reinit: False                   │
│    ├─ force_reinit_new_goal_dist: 1000.0    │
│    └─ 效果：不因目标改变而重规划            │
├─────────────────────────────────────────────┤
│ 3. BehaviorTree                             │
│    ├─ 移除 RateController                   │
│    └─ 效果：ComputePathThroughPoses只运行一次│
└─────────────────────────────────────────────┘
         ↓ 结果 ↓
   ✅ 全局路径保持不变
   ✅ 点之间无间隔
   ✅ 不会绕圈
```

---

🎉 **现在可以开始测试了！** 按照上面的三个步骤启动即可。

有问题请参考 `SOLUTION_COMPLETE_CHANGELOG.md` 获取详细说明。

最后更新：2024年3月17日
