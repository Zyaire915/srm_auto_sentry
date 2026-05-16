# 前哨战决策系统 - 快速参考

## 📍 三个关键位置 (Waypoints)

### 位置A: 占据/攻击位置 (Waypoint A)
- **激活条件**: 血量 ✓ & 弹数 ✓ & 前哨战未完成 (switch_position = 0)
- **当前坐标**: `5.0; 0.0; 0; 0; 0; 0; 1`
- **说明**: 机器人去占据或攻击这个位置，争夺场地控制权

### 位置B: 防守位置 (Waypoint B)  
- **激活条件**: 血量 ✓ & 弹数 ✓ & 前哨战已完成 (switch_position = 1)
- **当前坐标**: `3.0; 2.0; 0; 0; 0; 0; 1`
- **说明**: 前哨战已经打完，机器人防守这个位置

### 位置C: 补给/撤退区 (Waypoint C)
- **激活条件**: 血量 < 250 OR 弹数 < 40
- **当前坐标**: `-2.5; 4.07; 0; 0; 0; 0; 1`
- **说明**: 供弹补血的安全区域

---

## ⚙️ 可配置参数

| 参数 | 默认值 | 位置 | 说明 |
|------|--------|------|------|
| HP阈值 | 250 | XML `hp_threshold` | 血量低于此值去C点 |
| 弹数阈值 | 40 | XML `ammo_threshold` | 弹数低于此值去C点 |
| 位置A坐标 | (5.0, 0.0) | XML Waypoint_A_Occupy | 修改占据位置 |
| 位置B坐标 | (3.0, 2.0) | XML Waypoint_B_Defend | 修改防守位置 |
| 位置C坐标 | (-2.5, 4.07) | XML Waypoint_C_Supply | 修改补给位置 |

---

## 📊 决策流程

```
血量 > 250 & 弹数 > 40 ?
├─ NO → 去位置C (补给区)
└─ YES
   └─ 前哨战完成了吗 (switch_position)?
      ├─ 0 (未完成) → 去位置A (占据)
      └─ 1 (已完成) → 去位置B (防守)
```

---

## 🔍 订阅的话题

| 话题 | 消息类型 | 关键字段 |
|------|---------|---------|
| `/referee/sefdefined` | Sefdefined | current_hp |
| `/referee/projectile_allowance` | ProjectileAllowance | projectile_allowance_17mm |
| `/referee/switch_position` | SwitchPosition | switch_position |
| `/game_status` | GameStatus | game_progress |

---

## 🎯 修改坐标的方法

编辑 `sentry_decision_with_outpost.xml`:

```xml
<!-- 修改位置A -->
<SendGoal name="Waypoint_A_Occupy"
          goal_pose="新X;新Y;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 修改位置B -->
<SendGoal name="Waypoint_B_Defend"
          goal_pose="新X;新Y;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- 修改位置C -->
<SendGoal name="Waypoint_C_Supply"
          goal_pose="新X;新Y;0; 0;0;0;1"
          action_name="navigate_to_pose"/>
```

坐标格式: `x; y; z; qx; qy; qz; qw`
- x, y, z: 笛卡尔坐标
- qx, qy, qz, qw: 四元数 (旋转)
- 默认 `[0, 0, 0, 1]` = 0度方向

---

## ✅ 实现完成清单

- ✅ 创建 ProjectileAllowance.msg 和 SwitchPosition.msg
- ✅ 添加 0x0208 和 0x000D 包的接收处理
- ✅ 创建 ROS 话题发布者
- ✅ 实现决策逻辑 XML 配置
- ✅ 配置三个关键位置坐标
- ✅ 配置血量和弹数阈值
- ✅ 生成完整文档

---

## 📝 下一步

1. 根据实际地图修改三个位置坐标
2. 根据比赛测试调整 HP 和弹数阈值
3. 编译 `pb_rm_interfaces` 和 `standard_robot_pp_ros2` 包
4. 加载 `sentry_decision_with_outpost.xml` 运行行为树
5. 监测 `/referee/projectile_allowance` 和 `/referee/switch_position` 话题

