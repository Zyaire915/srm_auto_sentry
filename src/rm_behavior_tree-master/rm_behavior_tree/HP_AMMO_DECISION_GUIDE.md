# HpAmmoDecision 节点使用指南

## 概述
`HpAmmoDecision` 是一个行为树条件节点，用于根据机器人的血量（HP）和弹量（Ammo）判断当前状态，并输出对应的导航目标点。

## 节点特性

### 输入端口（Input Ports）
- **hp_message**: `rm_decision_interfaces::msg::Sefdefined` 类型，从订阅话题获取的血量信息
- **ammo_message**: `pb_rm_interfaces::msg::ProjectileAllowance` 类型，从订阅话题获取的弹量信息
- **hp_threshold**: `int` 类型，血量阈值（默认值：250），单位为血点
- **ammo_threshold**: `int` 类型，弹量阈值（默认值：40），单位为弹量
- **pose_above_threshold**: `std::string` 类型，当血量和弹量都**高于**阈值时的目标点（格式：x;y;z; qx;qy;qz;qw）
- **pose_below_threshold**: `std::string` 类型，当血量或弹量**低于**阈值时的目标点（格式：x;y;z; qx;qy;qz;qw）

### 输出端口（Output Ports）
- **goal_pose**: `std::string` 类型，根据判断结果输出的目标点位字符串

## 判断逻辑

```
IF (current_hp >= hp_threshold) AND (current_ammo >= ammo_threshold) THEN
    输出: pose_above_threshold (点位A)
ELSE
    输出: pose_below_threshold (点位B)
END IF
```

## 返回值
- **SUCCESS**: 总是返回SUCCESS（只要输入数据有效）
- **FAILURE**: 当输入的hp_message或ammo_message为空时返回FAILURE

## XML 使用示例

### 基础使用
```xml
<HpAmmoDecision hp_message="{sefdefined}"
                ammo_message="{projectile_allowance}"
                hp_threshold="200"
                ammo_threshold="30"
                pose_above_threshold="7.89;5.76;0; 0;0;0;1"
                pose_below_threshold="5.24;2.26;0; 0;0;0;1"
                goal_pose="{goal_pose}"/>
```

### 完整的行为树示例
```xml
<?xml version="1.0" encoding="UTF-8"?>
<root BTCPP_format="4" main_tree_to_execute="MainTree">
  <BehaviorTree ID="MainTree">
    <ReactiveSequence>
      <!-- 订阅HP和弹量信息 -->
      <SubSefdefined topic_name="/srm/sefdefined"
                     sefdefined="{sefdefined}"/>
      <SubProjectileAllowance topic_name="referee/projectile_allowance"
                              projectile_allowance="{projectile_allowance}"/>
      
      <!-- 判断HP和弹量，输出目标点 -->
      <HpAmmoDecision hp_message="{sefdefined}"
                      ammo_message="{projectile_allowance}"
                      hp_threshold="200"
                      ammo_threshold="30"
                      pose_above_threshold="7.89;5.76;0; 0;0;0;1"
                      pose_below_threshold="5.24;2.26;0; 0;0;0;1"
                      goal_pose="{goal_pose}"/>
      
      <!-- 根据决策结果导航到对应点位 -->
      <SendGoal name="NavigateToPose"
                goal_pose="{goal_pose}"
                action_name="navigate_to_pose"/>
    </ReactiveSequence>
  </BehaviorTree>
</root>
```

## 参数说明

### 阈值参数
- **hp_threshold**: 
  - 默认值：250
  - 说明：当机器人血量高于此值且弹量也充足时，选择点位A（攻击/占位）
  - 建议范围：150-300

- **ammo_threshold**:
  - 默认值：40
  - 说明：当机器人弹量高于此值且血量也充足时，选择点位A（攻击/占位）
  - 建议范围：20-100

### 点位参数

#### pose_above_threshold (点位A - 正常状态)
- 用途：当HP和弹量都充足时，机器人导航到此点
- 建议配置：攻击性点位或占位点位
- 格式：`x;y;z; qx;qy;qz;qw`
  - x, y, z: 三维坐标
  - qx, qy, qz, qw: 四元数旋转角度

#### pose_below_threshold (点位B - 补给/撤退)
- 用途：当HP或弹量不足时，机器人导航到此点
- 建议配置：补给点或防守点位
- 格式：同上

## 与其他节点的关系

### 依赖节点
- **SubSefdefined**: 用于订阅HP信息话题
- **SubProjectileAllowance**: 用于订阅弹量信息话题

### 上游节点
- **IsHealthyAmmo**: 旧的条件节点，只返回SUCCESS/FAILURE
- **HpAmmoDecision**: 新节点，返回SUCCESS并输出目标点

## 编译和注册

### 已包含在 CMakeLists.txt 中：
```cmake
ament_auto_add_library(hp_ammo_decision SHARED 
    plugins/condition/hp_ammo_decision.cpp
)
add_target_dependencies(hp_ammo_decision)
```

### 自动注册：
节点通过以下宏自动注册到行为树工厂：
```cpp
BT_REGISTER_NODES(factory)
{
  factory.registerNodeType<rm_behavior_tree::HpAmmoDcisionAction>("HpAmmoDecision");
}
```

## 编译命令

```bash
cd /workspaces/srm_auto_sentry
colcon build --packages-select rm_behavior_tree
```

## 常见问题

### Q: 如果输入消息为空会怎样？
A: 节点返回FAILURE，整个序列中断。

### Q: 是否可以动态修改阈值？
A: 可以，在XML中修改`hp_threshold`和`ammo_threshold`属性即可，无需重新编译。

### Q: 点位格式错误会怎样？
A: SendGoal节点会处理字符串解析，如果格式错误会返回相应错误。

### Q: 如何调整为其他逻辑？
A: 修改`hp_ammo_decision.cpp`中的`checkHpAmmoAndDecide()`函数中的判断条件即可。

## 源代码文件

- 头文件: `include/rm_behavior_tree/plugins/condition/hp_ammo_decision.hpp`
- 实现文件: `plugins/condition/hp_ammo_decision.cpp`
- 示例配置: `config/hp_ammo_decision_test.xml`
