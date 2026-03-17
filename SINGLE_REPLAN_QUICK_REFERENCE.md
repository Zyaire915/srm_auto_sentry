# 快速对比：重规划 vs 单次规划

## 对比表

| 特性 | 默认配置 | 单次规划配置 |
|------|---------|-----------|
| 重规划频率 | 每 0.1s | 0（只初始化一次）|
| 规划次数 | 10-50 次 | 1 次 |
| 轨迹稳定性 | 低（不断变化） | 高（固定） |
| 振荡程度 | 高 | 几乎无 |
| 途径点时间 | 5-10s | 3-5s |
| CPU 使用率 | 高 | 低 |
| 避障能力 | 强（动态调整） | 弱（静态规划） |

---

## 单次规划的关键参数

```yaml
# 1. 禁止重新初始化（最核心）
allow_reinit: False
force_reinit_new_goal: False

# 2. 禁止更新全局路径
global_plan_overwrite_frequency: 0.0

# 3. 强制直线前进
weight_kinematics_forward_drive: 900.0

# 4. 严格跟踪路径点
weight_viapoint: 1.0

# 5. 禁用复杂规划
enable_homotopy_class_planning: False
enable_multithreading: False
```

---

## 快速调试命令

```bash
# 检查参数是否生效
ros2 param get /controller_server FollowPath.allow_reinit

# 查看规划频率
ros2 topic hz /local_plan

# 查看 TEB 日志
ros2 run rm_nav_bringup waypoints_navigator --ros-args --log-level DEBUG
```

---

## 三个快速测试方案

### ✅ 方案 A：完全锁定（推荐，适合绕桩）
```yaml
allow_reinit: False
force_reinit_new_goal: False
global_plan_overwrite_frequency: 0.0
weight_kinematics_forward_drive: 900.0
weight_viapoint: 1.0
weight_obstacle: 50.0
```

### ✅ 方案 B：中等限制（平衡安全）
```yaml
allow_reinit: False
global_plan_overwrite_frequency: 0.1
weight_kinematics_forward_drive: 500.0
weight_viapoint: 1.0
weight_obstacle: 100.0
```

### ✅ 方案 C：最小限制（保留灵活性）
```yaml
allow_reinit: False
global_plan_overwrite_frequency: 0.5
weight_kinematics_forward_drive: 300.0
weight_viapoint: 0.5
weight_obstacle: 150.0
```

---

## 效果验证

启动后在 RViz 中观察：

1. **规划路径** (`/global_plan`)
   - ✅ 单次规划：路径保持不变
   - ❌ 多次规划：路径不断改变

2. **轨迹稳定性**
   - ✅ 单次规划：机器人平稳前进
   - ❌ 多次规划：机器人在途径点间振荡

3. **运动速度**
   - ✅ 单次规划：相对稳定
   - ❌ 多次规划：时快时慢

---

## 何时使用单次规划

✅ 适用场景：
- 绕桩任务（固定点位置）
- 精密路径跟踪
- 环境静态，无动态障碍物
- 需要最小振荡

❌ 不适用场景：
- 动态环境（移动障碍物）
- 需要快速避障
- 目标点经常变化

---

## 当前项目配置

**文件位置**：
```
/workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_navigation/rm_navigation/params/nav2_params_pole_tracking.yaml
```

**已配置参数**：
```yaml
allow_reinit: False
force_reinit_new_goal: False
global_plan_overwrite_frequency: 0.0
enable_homotopy_class_planning: False
weight_kinematics_forward_drive: 900.0
weight_viapoint: 1.0
weight_obstacle: 50.0
```

---

## 使用命令

```bash
# 编译
colcon build --packages-select rm_navigation --symlink-install

# 启动
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    nav_rviz:=True waypoint_tolerance:=0.3 final_goal_tolerance:=0.2

# 发送途径点
ros2 run rm_nav_bringup waypoints_test_client 1
```
