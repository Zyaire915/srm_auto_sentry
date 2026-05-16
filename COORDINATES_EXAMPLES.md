# 位置坐标示例 - 不同比赛地图

本文档提供了不同场景下推荐的位置坐标设置。

## RMUC 2026 标准赛场

> 适用于 RMUC (RoboMaster University Challenge) 标准赛场

### 红方配置

```xml
<!-- 位置A: 占据中路/红方前哨站方向 -->
<SendGoal name="Waypoint_A_Occupy"
          goal_pose="5.5;0.5;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 位置B: 防守红方高地/决策区 -->
<SendGoal name="Waypoint_B_Defend"
          goal_pose="3.0;2.5;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 位置C: 补给区 (红方基地侧) -->
<SendGoal name="Waypoint_C_Supply"
          goal_pose="-1.0;3.5;0; 0;0;0;1"
          action_name="navigate_to_pose"/>
```

### 蓝方配置

```xml
<!-- 位置A: 占据中路/蓝方前哨站方向 -->
<SendGoal name="Waypoint_A_Occupy"
          goal_pose="5.5;-0.5;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 位置B: 防守蓝方高地/决策区 -->
<SendGoal name="Waypoint_B_Defend"
          goal_pose="3.0;-2.5;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 位置C: 补给区 (蓝方基地侧) -->
<SendGoal name="Waypoint_C_Supply"
          goal_pose="-1.0;-3.5;0; 0;0;0;1"
          action_name="navigate_to_pose"/>
```

---

## RMUL 高校赛 (3V3)

> 适用于 RMUL 高校单项赛 3V3 地图

### 配置示例

```xml
<!-- 位置A: 占据高地/资源区附近 -->
<SendGoal name="Waypoint_A_Occupy"
          goal_pose="4.0;1.0;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 位置B: 防守基地周边 -->
<SendGoal name="Waypoint_B_Defend"
          goal_pose="2.0;0.0;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 位置C: 补给区 -->
<SendGoal name="Waypoint_C_Supply"
          goal_pose="-2.0;2.0;0; 0;0;0;1"
          action_name="navigate_to_pose"/>
```

---

## 自定义地图配置

### 步骤1: 获取坐标

使用 rviz 或地图编辑工具，记录以下位置的坐标:

1. **位置A**: 你希望哨兵占据/攻击的位置 (当前哨战未完成时)
   - 通常是关键的场地位置，如资源区、高地周边等

2. **位置B**: 前哨战打完后的防守位置
   - 通常是更靠后的防守阵地

3. **位置C**: 补给/撤退区
   - 通常是己方基地附近的安全区域

### 步骤2: 转换为 ROS 坐标

假设从地图工具获得像素坐标 (px, py)，需要转换为 ROS 坐标:

```
ROS_x = (px - origin_x) * resolution
ROS_y = (py - origin_y) * resolution
```

### 步骤3: 计算旋转四元数 (可选)

如果需要特定方向，使用欧拉角转换:

```python
# Python 示例
from tf_transformations import quaternion_from_euler

# 绕Z轴旋转45度 (弧度制)
qx, qy, qz, qw = quaternion_from_euler(0, 0, 0.785)  # π/4 = 45度

# 输出格式: qx; qy; qz; qw
print(f"{qx}; {qy}; {qz}; {qw}")
```

默认方向 (0 度): `0; 0; 0; 1`

---

## 调试和微调

### 查看当前位置

```bash
# 监听导航状态
ros2 topic echo /navigate_to_pose

# 查看哨兵当前位置
ros2 topic echo /tf
```

### 实时调整坐标

1. 运行行为树: `ros2 launch rm_behavior_tree sentry_decision_with_outpost.launch.py`
2. 编辑 XML 文件中的坐标
3. 重新加载行为树 (无需重新编译)

### 测试特定位置

临时修改 XML 以测试单个位置:

```xml
<!-- 临时强制导航到位置A测试 -->
<SendGoal name="Test_Waypoint_A"
          goal_pose="YOUR_TEST_X;YOUR_TEST_Y;0; 0;0;0;1"
          action_name="navigate_to_pose"/>
```

---

## 常见问题

### Q: 坐标范围是多少?
A: 取决于地图大小。通常 RMUC 地图为 ±8m，RMUL 为 ±6m

### Q: 可以动态修改坐标吗?
A: 可以。编辑 XML 后重新加载行为树，无需重新编译 C++ 代码

### Q: 旋转方向怎么设定?
A: 使用四元数表示。默认 `[0, 0, 0, 1]` 表示0度，可用欧拉角转换

### Q: 多个哨兵如何配置不同坐标?
A: 创建多个 XML 文件，如 `sentry_decision_red.xml`、`sentry_decision_blue.xml`

---

## 参考值汇总

| 参数 | 推荐范围 | 默认值 |
|------|---------|--------|
| HP 阈值 | 200-300 | 250 |
| 弹数阈值 | 30-50 | 40 |
| 位置A X坐标 | 3.0-6.0 | 5.0 |
| 位置A Y坐标 | -1.5-1.5 | 0.0 |
| 位置B X坐标 | 1.0-4.0 | 3.0 |
| 位置B Y坐标 | -3.0-3.0 | 2.0 |
| 位置C X坐标 | -3.0--1.0 | -2.5 |
| 位置C Y坐标 | 2.0-5.0 | 4.07 |

---

## 快速配置模板

复制下面的模板，修改坐标值:

```xml
<!-- 修改这里的坐标值 -->
<SendGoal name="Waypoint_A_Occupy"
          goal_pose="X_A;Y_A;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<SendGoal name="Waypoint_B_Defend"
          goal_pose="X_B;Y_B;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<SendGoal name="Waypoint_C_Supply"
          goal_pose="X_C;Y_C;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 修改这里的阈值 -->
<IsHealthyAmmo hp_message="{sefdefined}"
               ammo_message="{projectile_allowance}"
               hp_threshold="HP_THRESHOLD"
               ammo_threshold="AMMO_THRESHOLD"/>
```

