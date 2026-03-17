# 修复"机器人在途径点绕圈"问题 - 完整解决方案

## 问题诊断

您遇到的问题根本原因：
- `navigate_through_poses` action **会周期性地重新规划全局路径**
- 每次重规划，全局路径可能略有不同
- 局部规划器(TEB)跟踪的目标不断改变
- 结果：**机器人在途径点附近不断改变方向，导致绕圈**

## 真正的解决方案：使用 ComputePathThroughPoses + FollowPath

**原理**：
1. **一次性调用** `ComputePathThroughPoses` 计算完整全局路径
2. **持续使用** `FollowPath` 严格跟随这个固定的路径
3. 路径不变 → 目标不变 → 机器人不绕圈 ✓

## 实施步骤

### 第1步：更新CMakeLists.txt（注册新脚本）

编辑 `/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_nav_bringup/CMakeLists.txt`

在 `PROGRAMS` 部分添加新脚本：

```cmake
install(
  PROGRAMS
    scripts/waypoints_navigator.py
    scripts/waypoints_test_client.py
    scripts/single_plan_navigator.py
    scripts/waypoints_navigator_fixed.py        # ← 添加这一行
    scripts/diagnose_replanning.py               # ← 添加这一行
  DESTINATION lib/${PROJECT_NAME}
)
```

并在符号链接部分添加：

```cmake
execute_process(
  COMMAND ${CMAKE_COMMAND} -E create_symlink 
  waypoints_navigator_fixed.py 
  \${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/waypoints_navigator_fixed
)
execute_process(
  COMMAND ${CMAKE_COMMAND} -E create_symlink 
  diagnose_replanning.py 
  \${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/diagnose_replanning
)
```

### 第2步：编译

```bash
cd /workspaces/srm_auto_sentry
colcon build --packages-select rm_nav_bringup --symlink-install
source install/setup.zsh
```

### 第3步：诊断（可选）

首先，验证您的问题确实是重规划：

**终端 A - 启动导航系统：**
```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox nav_rviz:=True
```

**终端 B - 运行诊断：**
```bash
ros2 run rm_nav_bringup diagnose_replanning
```

观察输出：
- 如果看到多个 `⚠️ 全局路径改变了！` → 证实问题是重规划
- 如果只看到一个全局路径 → 问题可能不是重规划

### 第4步：使用修复版本

如果诊断确认是重规划问题，**替换为新导航器**：

**终端 C - 运行修复版导航器：**
```bash
ros2 run rm_nav_bringup waypoints_navigator_fixed
```

**终端 D - 发送测试路线：**
```bash
ros2 run rm_nav_bringup waypoints_test_client 1
```

## 核心改变对比

### 旧方案（有问题）
```
navigate_through_poses action
    ↓
Nav2 周期性调用 global_planner
    ↓
全局路径不断改变
    ↓
局部规划器目标不断改变
    ↓
🔴 机器人绕圈
```

### 新方案（修复）
```
ComputePathThroughPoses（调用一次）
    ↓
得到固定的全局路径
    ↓
FollowPath（持续跟踪）
    ↓
全局路径保持不变
    ↓
✅ 机器人平稳到达
```

## 文件列表

| 文件 | 说明 |
|------|------|
| `waypoints_navigator_fixed.py` | ⭐ 修复版导航器 - 只规划一次 |
| `diagnose_replanning.py` | 诊断工具 - 检测重规划问题 |

## 如何选择使用哪个导航器

| 导航器 | 优点 | 缺点 | 适用场景 |
|--------|------|------|---------|
| `waypoints_navigator` | 兼容原有代码 | 有绕圈问题 | 简单场景，不需要绕柱 |
| `waypoints_navigator_fixed` | ✅ 解决绕圈问题 | 无 | ⭐ **绕柱、精密导航** |

## 故障排除

### 问题：新导航器启动失败
**可能原因**：Nav2还没启动  
**解决**：先在终端A运行启动命令，再在终端C运行导航器

### 问题：导航器卡住不动
**可能原因**：全局路径计算失败  
**解决**：检查路径是否可达，目标是否在障碍物内

### 问题：路径计算一直超时
**可能原因**：Nav2不稳定  
**解决**：重启Nav2，或增加超时时间

## 参数配置

修复版导航器支持的参数：

```yaml
waypoint_tolerance: 1.0          # 途径点容差（米）
final_goal_tolerance: 0.25       # 最终目标容差（米）
```

动态调整（不需要重启）：
```bash
ros2 param set /waypoints_navigator_fixed waypoint_tolerance 0.5
ros2 param set /waypoints_navigator_fixed final_goal_tolerance 0.1
```

## 测试场景

### 场景1：矩形绕行
```bash
ros2 run rm_nav_bringup waypoints_test_client 1
```
预期：机器人平稳地沿矩形边界运动，在转角处不绕圈

### 场景2：绕柱（尖锐转角）
```bash
# 编写自定义客户端，生成尖锐转角的路线
```
预期：即使在尖锐转角，机器人也不会重复

### 场景3：长距离导航
```bash
# 创建5个以上的路点
```
预期：性能稳定，不会随路点增多而恶化

## 常见问题解答

### Q: 为什么 navigate_through_poses 会重规划？
A: Nav2 的设计思想是实时适应环境变化。但在静态环境中（如室内场景），这导致路径不必要地改变。新方案通过只规划一次来避免这个问题。

### Q: 修复版会不会错过动态障碍物？
A: 在当前应用场景（全局地图固定）中不会。如果需要动态避障，可以增加障碍物检测和重规划逻辑。

### Q: 性能怎么样？
A: 由于只规划一次，性能更好。ComputePathThroughPoses + FollowPath 比 navigate_through_poses 更轻量级。

---

**下一步**: 按照上述步骤实施，如有问题请反馈！

最后更新: 2024年3月17日
