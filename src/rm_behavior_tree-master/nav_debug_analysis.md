# 导航脱困逻辑分析 & 高血量点→低血量点未触发问题排查

## 一、整体架构

```
ReactiveSequence (hp_patrol_test.xml)
├── SubSefdefined          → 订阅血量，写入黑板 {the_hp_data}
├── HpDecisionPatrol       → 三态状态机，输出 {current_goal}
└── SendGoal               → 调用 Nav2 NavigateToPose action
```

**ReactiveSequence 的关键行为**：每次 tick 都从头重新执行所有子节点。只要任意子节点返回 FAILURE，整个序列立即中断并重新从头 tick。

---

## 二、脱困 / 中断导航的所有逻辑

### 2.1 HpDecisionPatrol 主动中断（`goal_changed` 机制）

**文件**：`plugins/action/hp_decision_patrol.cpp` 第 185-187 行

```cpp
if (goal_changed) {
    return BT::NodeStatus::FAILURE;  // 触发 ReactiveSequence 重新 tick，SendGoal 被 Halt
}
```

- 当目标坐标从 `high_hp` 切换到 `low_hp`（或反向）时，`goal_changed = true`
- 返回 FAILURE → ReactiveSequence 中断 SendGoal（调用 `onHalt()`）→ 下一 tick 用新目标重新发送

### 2.2 SendGoal 的 ABORTED / CANCELED

**文件**：`plugins/action/send_goal.cpp` 第 51-63 行

- Nav2 返回 ABORTED 或 CANCELED → SendGoal 返回 FAILURE
- ReactiveSequence 重新从头 tick → HpDecisionPatrol 重新决策目标 → SendGoal 重新发送

### 2.3 Nav2 内部脱困（TEB Local Planner）

**文件**：`rm_nav_bringup/config/simulation/nav2_params_sim.yaml`

| 参数 | 值 | 作用 |
|---|---|---|
| `shrink_horizon_backup` | True | 路径不可行时缩短规划范围 |
| `oscillation_recovery` | True | 检测到振荡时触发恢复 |
| `oscillation_recovery_min_duration` | 10.0s | 振荡恢复最短持续时间 |
| `failure_tolerance` | 0.3 | 控制器失败容忍度 |

**文件**：`rm_navigation/params/nav2_params.yaml`

- `SimpleProgressChecker`：`required_movement_radius: 0.5m`，`movement_time_allowance: 10.0s`
  - 10秒内未移动 0.5m → Nav2 判定卡住 → 触发 Recovery（spin/backup）→ 若仍失败则 ABORT goal
- Recovery plugins：`spin`、`backup`

### 2.4 TF2 距离判断（GOING_HOME → RECOVERING 转换）

**文件**：`plugins/action/hp_decision_patrol.cpp` 第 111-114 行

```cpp
double dist = distanceToPoint(low_hp_x, low_hp_y);
if (dist >= 0.0 && dist < ARRIVE_DIST_THRESHOLD) {  // ARRIVE_DIST_THRESHOLD = 0.3m
    state_ = PatrolState::RECOVERING;
}
```

- TF2 查询失败（返回 -1.0）时，**永远不会进入 RECOVERING 状态**

---

## 三、问题：到高血量点后 HP 掉半血，未触发回低血量点

### 3.1 状态机转换条件回顾

```
NORMAL → GOING_HOME：current_hp <= hp_threshold (200)
```

**xml 配置**（`hp_patrol_test.xml`）：
```xml
hp_threshold="200"   max_hp="360"
high_hp: (4.5, -0.07)
low_hp:  (0.0,  0.0)
```

### 3.2 猜测一：脱困逻辑干扰了导航切换 ✅ 高可能性

**问题链**：

1. 机器人在高血量点（4.5, -0.07）附近，HP 掉到 ≤200
2. `HpDecisionPatrol` 状态切换 NORMAL → GOING_HOME，目标变为 (0,0)
3. `goal_changed = true` → 返回 FAILURE → ReactiveSequence 中断 SendGoal
4. **下一 tick**：`goal_changed = false`（目标未再变化）→ 返回 SUCCESS → SendGoal 发送新目标 (0,0)
5. **此时若 Nav2 正处于 Recovery 状态**（spin/backup），新 goal 可能被 Nav2 **队列丢弃或 ABORT**
6. SendGoal 收到 ABORTED → 返回 FAILURE → ReactiveSequence 重新 tick
7. **循环**：每次 tick HpDecisionPatrol 返回 SUCCESS（目标未变），SendGoal 重新发送，Nav2 再次 ABORT

**关键点**：Nav2 在执行 Recovery behavior 期间，新的 NavigateToPose goal 可能被拒绝。

---

**另一个干扰路径**：

1. HP 掉到 ≤200，状态切换，`goal_changed=true`，返回 FAILURE
2. ReactiveSequence 重新 tick，**SubSefdefined 先执行**
3. 若此时血量数据更新延迟或丢包，`hp_input` 读取失败 → HpDecisionPatrol 返回 FAILURE
4. 状态机**没有执行**，`state_` 仍为 NORMAL（因为 tick 在读取 hp_msg 失败后直接 return FAILURE，第 80-82 行）
5. 下一 tick 血量恢复正常读取，但如果 HP 已经回升（被动回血/补给），可能不再触发切换

### 3.3 猜测二：Nav2 路径规划失败 ✅ 中等可能性

**可能原因**：

1. **目标点 (0,0) 在代价地图中被标记为障碍**
   - 机器人出生点/初始点附近可能有静态障碍物
   - 全局代价地图未及时更新

2. **TEB 规划器 shrink_horizon 触发**
   - 从 (4.5, -0.07) 到 (0,0) 距离约 4.5m，若中间有障碍，TEB 缩短规划范围后可能陷入局部最优

3. **SimpleProgressChecker 超时**
   - 若路径中有窄道，机器人移动缓慢，10s 内未移动 0.5m → Nav2 触发 Recovery → Recovery 失败 → goal ABORT
   - SendGoal 返回 FAILURE → ReactiveSequence 重新 tick → 重新发送目标 → 循环

4. **Nav2 action server 未就绪**（概率较低）
   - SendGoal 的 `onFailure` 返回 FAILURE，但不会重试

---

## 四、排查步骤

### Step 1：确认状态机是否切换

在 `hp_decision_patrol.cpp` tick() 中添加日志，确认 `state_` 是否从 NORMAL 切换到 GOING_HOME：

```
[HpDecisionPatrol] HP=195, threshold=200, state: NORMAL -> GOING_HOME
[HpDecisionPatrol] goal_changed=true, returning FAILURE
[HpDecisionPatrol] goal=(0.0, 0.0), returning SUCCESS
```

若日志显示切换了但导航未执行，问题在 Nav2 侧。

### Step 2：检查 SendGoal 日志

观察 `send_goal.cpp` 的输出：
- `Goal_pose: [ 0.0, 0.0, ... ]` → 确认目标已发送
- `Goal was aborted` → Nav2 拒绝了目标
- `Goal was canceled` → 被 HpDecisionPatrol 的 FAILURE 中断

### Step 3：检查 Nav2 状态

```bash
ros2 topic echo /navigate_to_pose/_action/status
```

观察 goal 状态变化，是否出现 ABORTED。

### Step 4：检查代价地图

```bash
ros2 topic echo /global_costmap/costmap
```

确认 (0,0) 点的代价值是否为障碍（254）。

### Step 5：检查 TF2

```bash
ros2 run tf2_tools view_frames
ros2 topic echo /tf
```

确认 `map → base_link` TF 是否正常发布，避免 `distanceToPoint` 始终返回 -1.0。

---

## 五、最可能的根因

| 优先级 | 根因 | 证据 |
|---|---|---|
| ★★★ | Nav2 在 Recovery 期间拒绝新 goal，导致 SendGoal 循环 ABORT | `nav2_params_sim.yaml` 中 Recovery 插件存在；`movement_time_allowance=10s` 较短 |
| ★★☆ | `hp_input` 读取失败导致状态机未执行 tick，state_ 停留在 NORMAL | `hp_decision_patrol.cpp:80-82` 直接 return FAILURE 不更新状态 |
| ★★☆ | 目标点 (0,0) 在代价地图中不可达 | 需实际检查地图 |
| ★☆☆ | TF2 查询失败，GOING_HOME 无法转 RECOVERING（但不影响导航目标切换） | `distanceToPoint` 返回 -1.0 时跳过转换 |

---

## 六、相关文件索引

| 文件 | 关键逻辑 |
|---|---|
| `rm_behavior_tree/config/hp_patrol_test.xml` | BT 树结构，hp_threshold=200，目标坐标 |
| `rm_behavior_tree/plugins/action/hp_decision_patrol.cpp` | 三态状态机，goal_changed 中断机制，TF2 距离判断 |
| `rm_behavior_tree/include/.../hp_decision_patrol.hpp` | ARRIVE_DIST_THRESHOLD=0.3m |
| `rm_behavior_tree/plugins/action/send_goal.cpp` | Nav2 action 调用，ABORTED/CANCELED 处理 |
| `rm_nav_bringup/config/simulation/nav2_params_sim.yaml` | TEB recovery 参数，failure_tolerance=0.3 |
| `rm_navigation/params/nav2_params.yaml` | SimpleProgressChecker，movement_time_allowance=10s |
