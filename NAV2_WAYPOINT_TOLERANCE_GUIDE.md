# Nav2 途径点容差配置指南

## 问题背景
- `navigate_through_poses` 在处理多途径点导航时，所有目标点使用相同的容差
- 通常需要途径点（waypoint）的容差宽松一些（更容易到达），而最终目标的容差严格一些

## 实际情况 ⚠️

**重要发现：** Nav2 的 `navigate_through_poses` 无法动态选择不同的 goal checker。`goal_checker_plugins` 列表中只有第一个 checker 会被使用，其他的都会被忽略。

因此，**我之前建议的"双 checker"方案不可行**。

## 可行解决方案

### 方案 A：调整全局容差（最简单，推荐）

修改 `general_goal_checker` 的容差为适合途径点的值：

```yaml
controller_server:
  ros__parameters:
    goal_checker_plugins: ["general_goal_checker"]
    general_goal_checker:
      stateful: True
      plugin: "nav2_controller::SimpleGoalChecker"
      xy_goal_tolerance: 0.5-1.5    # 根据实际需要调整
      yaw_goal_tolerance: 6.28 or 0.25
```

**优点：** 简单易用  
**缺点：** 所有目标使用相同容差

### 方案 B：自定义 BT XML（推荐用于复杂场景）

不使用内置的 `navigate_through_poses`，而是手动处理：

```xml
<BehaviorTree ID="CustomNavigateThroughWaypoints">
  <Sequence>
    <!-- 第一部分：宽松容差处理途径点 -->
    <Parallel success_threshold="2" failure_threshold="1">
      <!-- 临时改为宽松容差 -->
      <RosServiceCommand service_name="/set_goal_checker_tolerance">
        <Input key="value" value="0.5"/>
      </RosServiceCommand>
      
      <!-- 处理每个途径点 -->
      <ForEach input_collection="{waypoints}" output_collection="{results}">
        <Sequence>
          <ComputePathToPose goal="{current}"/>
          <FollowPath/>
        </Sequence>
      </ForEach>
    </Parallel>
    
    <!-- 第二部分：严格容差处理最终目标 -->
    <RosServiceCommand service_name="/set_goal_checker_tolerance">
      <Input key="value" value="0.25"/>
    </RosServiceCommand>
    <NavigateToPose goal="{final_goal}"/>
  </Sequence>
</BehaviorTree>
```

### 方案 C：运行时动态修改（最灵活）

在你的 behavior tree 或 C++ 节点中，在处理途径点前后动态修改：

```bash
# 处理途径点（宽松容差）
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 0.5

# [导航到途径点]

# 处理最终目标（严格容差）
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 0.25

# [导航到最终目标]
```

## 当前配置

我已将所有配置改为**单一 goal checker** 且容差设为 **0.5-1.5m**（适合途径点）：

### 文件修改列表
1. `/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_nav_bringup/config/reality/nav2_params_real.yaml` ✅
2. `/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_nav_bringup/config/simulation/nav2_params_sim.yaml` ✅
3. `/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_navigation/rm_navigation/params/nav2_params.yaml` ✅

## 动态修改容差

运行时可以通过命令改变容差：

```bash
# 改为宽松（途径点）
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 1.0

# 改为严格（最终目标）
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 0.2

# 查看当前值
ros2 param get /controller_server general_goal_checker.xy_goal_tolerance
```

## 参数调整建议

| 参数 | 推荐值范围 | 说明 |
|------|----------|------|
| 途径点 xy_goal_tolerance | 0.3 - 1.0 m | 容差越大，越容易完成途径点 |
| 最终目标 xy_goal_tolerance | 0.1 - 0.5 m | 应比途径点更严格 |
| yaw_goal_tolerance | 6.28 | 通常不需要旋转精度，保持最大值 |

## 关于 `nav2_remove_passed_goals_action_bt_node`

这是 Nav2 的内置节点，无法通过 YAML 参数化配置。其作用是：
- 自动移除已到达的途径点，防止重复访问
- 在 `navigate_through_poses` 中自动使用
- **无法修改其参数**，行为是固定的

如需自定义行为，需要：
1. 在自定义 BT XML 中分别处理每个途径点
2. 使用 `ComputePathToPose` + `FollowPath` 的组合

## 效果验证

启动导航系统后，可以验证：
```bash
# 查看当前的 goal checker 配置
ros2 param get /controller_server goal_checker_plugins

# 查看具体的容差值
ros2 param get /controller_server waypoint_goal_checker.xy_goal_tolerance
ros2 param get /controller_server general_goal_checker.xy_goal_tolerance
```

## 高级用法

如需要更复杂的策略（例如，根据地形自动调整容差），可以：
1. 自定义 behavior tree 节点来动态修改 ROS 参数
2. 或在 C++ 中编写自定义的 goal checker plugin
