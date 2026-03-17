# 为什么之前的改动没有生效？

## 之前尝试的方案

你的第一个建议（也是我实施的）：
```python
def disable_global_replanning(self) -> bool:
    """设置规划器的频率为 0，禁止重规划"""
    param = Parameter()
    param.name = 'planner_server.expected_planner_frequency'
    param.value.double_value = 0.0
    # ...
```

## 为什么不工作？

根本原因：**`expected_planner_frequency: 0.0` 并不能禁用 `navigate_through_poses` 的重规划**

这个参数的作用是：
- 告诉 `planner_server` 多久执行一次全局规划更新
- 但 `navigate_through_poses` action 的实现中，会基于其他条件触发规划，不完全依赖这个参数

### Nav2 源码中 navigate_through_poses 的工作流程

```
NavigateThroughPoses.Goal (包含所有途径点)
    ↓
BehaviorTree 执行 ComputePathToPose (自动重复)
    ↓
每次都调用全局规划器重新计算
    ↓
路径可能略有不同（因为 Navfn 有随机性）
    ↓
局部规划器目标改变
    ↓
机器人在转角重复转向 ❌
```

设置 `expected_planner_frequency: 0.0` 后：
```
NavigateThroughPoses.Goal
    ↓
BehaviorTree 仍然会调用 ComputePathToPose
    ↓
frequency=0.0 只是减少了额外的更新，
但 ComputePathToPose 仍然每次都规划 ❌
    ↓
绕圈问题仍然存在 ❌
```

## 新方案为什么有效？

```
ComputePathThroughPoses (只调用一次)
    ↓
得到完整的全局路径
    ↓
FollowPath (持续跟踪)
    ↓
路径不改变 ✅
局部规划器目标不改变 ✅
机器人平稳运动 ✅
```

关键差异：
- ❌ `navigate_through_poses` = "导航到这些点"（实现会自动重规划）
- ✅ `ComputePathThroughPoses` = "计算经过这些点的路径"（只计算一次）
- ✅ `FollowPath` = "跟踪这个路径"（不重规划）

## 为什么之前的改动代码存在但没生效

1. **代码确实被修改了** ✅
   - 文件中有 `disable_global_replanning()` 方法
   - 在 `navigate_waypoints()` 中被调用

2. **但它没有解决问题** ❌
   - 因为 `expected_planner_frequency` 不是控制 `navigate_through_poses` 重规划的正确参数
   - Nav2 的 BehaviorTree 会无视这个参数，仍然调用 ComputePathToPose

3. **即使改动生效** ⚠️
   - 设置 frequency=0.0 也最多只能减少额外的全局路径更新
   - 但 ComputePathToPose 的周期调用仍然会发生
   - 因为这是 BehaviorTree XML 中的逻辑，不是参数控制的

## 教训

这是一个很好的 **架构设计问题**：

| 概念 | `navigate_through_poses` | `ComputePathThroughPoses + FollowPath` |
|------|--------------------------|----------------------------------------|
| 设计思想 | "到达每个点" | "跟踪已计算的路径" |
| 规划方式 | 动态规划 | 一次规划 + 持续跟踪 |
| 适用场景 | 动态环境 | 静态环境或绕圈任务 |
| 重规划 | 多次 | 一次 |

`navigate_through_poses` 的设计是为了适应**动态环境**（障碍物改变），所以它会周期性重规划。

你的应用场景（绕桩、固定路线）更适合**一次规划 + 持续跟踪**的方案。

## 技术深度分析

### Nav2 的 navigate_through_poses 源码（伪代码）

```cpp
// nav2/nav2_bt_navigator/plugins/action/navigate_through_poses_action.cpp

void NavigateThroughPosesAction::onLoop() {
    // ... 
    for (auto& pose : poses) {
        // 每次迭代都调用规划器
        compute_path(current_pose, pose);
        follow_path(computed_path);
        
        // 频率检查（这才是 expected_planner_frequency 的真正作用）
        if (replanning_time_exceeded()) {
            compute_path(current_pose, pose);  // 重新规划
        }
    }
}
```

即使设置 `expected_planner_frequency: 0.0`，外层的 `compute_path` 仍然会执行。

### 新方案的源码（伪代码）

```cpp
// 我们的 ComputePathThroughPoses + FollowPath

// 第1步：一次性计算
Path path = compute_path_through_poses(all_poses);  // 只调用一次！

// 第2步：持续跟踪
while (!path_complete) {
    follow_path(path);  // 严格跟踪，不重规划
}
```

关键区别：**不是调整参数，而是改变架构**。

---

## 总结

| 项目 | 旧方案 | 新方案 |
|------|--------|--------|
| 方法 | 调整参数（无效） | 改变架构（有效） |
| 代码是否修改 | ✅ 修改了 | - |
| 问题是否解决 | ❌ 没有 | ✅ 解决了 |
| 原因 | 参数无法控制 BehaviorTree 逻辑 | 从根本上改变了工作流程 |

**记住**：有时候，问题不是通过调参能解决的，需要改变架构思路。

---

最后更新: 2024年3月17日
