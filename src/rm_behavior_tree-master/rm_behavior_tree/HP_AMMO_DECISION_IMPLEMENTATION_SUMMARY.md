# HpAmmoDecision 节点实现完成总结

## 📋 完成内容

### 1. 核心文件创建

#### 头文件 - `hp_ammo_decision.hpp`
位置: `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/include/rm_behavior_tree/plugins/condition/hp_ammo_decision.hpp`

**功能**:
- 定义 `HpAmmoDcisionAction` 类，继承自 `BT::SimpleConditionNode`
- 提供 6 个输入端口和 1 个输出端口

#### 实现文件 - `hp_ammo_decision.cpp`
位置: `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/plugins/condition/hp_ammo_decision.cpp`

**功能**:
- 实现节点逻辑：根据HP和弹量判断，输出对应点位
- 自动注册到行为树工厂中

### 2. 构建系统更新

**文件**: `CMakeLists.txt`
- 添加了新的库注册: `hp_ammo_decision`
- 在 `is_healthy_ammo` 之后添加，保持代码组织清晰

### 3. 配置文件示例

**文件**: `hp_ammo_decision_test.xml`
位置: `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/config/hp_ammo_decision_test.xml`

展示了如何在行为树中使用新节点。

## 🎯 节点设计细节

### 输入端口

| 端口名 | 类型 | 默认值 | 说明 |
|--------|------|--------|------|
| hp_message | Sefdefined | - | 血量信息 |
| ammo_message | ProjectileAllowance | - | 弹量信息 |
| hp_threshold | int | 250 | 血量阈值 |
| ammo_threshold | int | 40 | 弹量阈值 |
| pose_above_threshold | string | "7.89;5.76;0; 0;0;0;1" | 高于阈值时的点位 |
| pose_below_threshold | string | "5.24;2.26;0; 0;0;0;1" | 低于阈值时的点位 |

### 输出端口

| 端口名 | 类型 | 说明 |
|--------|------|------|
| goal_pose | string | 根据判断结果输出的目标点 |

### 判断逻辑

```
IF (current_hp >= hp_threshold) AND (current_ammo >= ammo_threshold)
    THEN setOutput goal_pose = pose_above_threshold  // 点位A
    ELSE setOutput goal_pose = pose_below_threshold  // 点位B
END IF
RETURN SUCCESS
```

## 📦 依赖关系

### 依赖的现有节点
- `SubSefdefined`: 订阅HP信息
- `SubProjectileAllowance`: 订阅弹量信息
- `SendGoal`: 执行导航

### 依赖的消息类型
- `rm_decision_interfaces::msg::Sefdefined`
- `pb_rm_interfaces::msg::ProjectileAllowance`

## 🔧 编译步骤

### 1. 构建项目
```bash
cd /workspaces/srm_auto_sentry
colcon build --packages-select rm_behavior_tree
```

### 2. 验证编译
```bash
# 查看编译输出
source install/setup.bash
```

## 📝 XML 使用示例

### 最小化使用
```xml
<HpAmmoDecision hp_message="{sefdefined}"
                ammo_message="{projectile_allowance}"
                goal_pose="{goal_pose}"/>
```
使用所有默认值（hp_threshold=250, ammo_threshold=40）

### 自定义阈值和点位
```xml
<HpAmmoDecision hp_message="{sefdefined}"
                ammo_message="{projectile_allowance}"
                hp_threshold="200"
                ammo_threshold="30"
                pose_above_threshold="7.89;5.76;0; 0;0;0;1"
                pose_below_threshold="5.24;2.26;0; 0;0;0;1"
                goal_pose="{goal_pose}"/>
```

### 完整行为树示例
```xml
<?xml version="1.0" encoding="UTF-8"?>
<root BTCPP_format="4" main_tree_to_execute="MainTree">
  <BehaviorTree ID="MainTree">
    <ReactiveSequence>
      <!-- 订阅数据 -->
      <SubSefdefined topic_name="/srm/sefdefined" sefdefined="{sefdefined}"/>
      <SubProjectileAllowance topic_name="referee/projectile_allowance" 
                              projectile_allowance="{projectile_allowance}"/>
      
      <!-- 判断并输出点位 -->
      <HpAmmoDecision hp_message="{sefdefined}"
                      ammo_message="{projectile_allowance}"
                      hp_threshold="200"
                      ammo_threshold="30"
                      pose_above_threshold="7.89;5.76;0; 0;0;0;1"
                      pose_below_threshold="5.24;2.26;0; 0;0;0;1"
                      goal_pose="{goal_pose}"/>
      
      <!-- 执行导航 -->
      <SendGoal name="NavigateToPose"
                goal_pose="{goal_pose}"
                action_name="navigate_to_pose"/>
    </ReactiveSequence>
  </BehaviorTree>
</root>
```

## 🔄 与现有节点的关系

### vs IsHealthyAmmo
| 特性 | IsHealthyAmmo | HpAmmoDecision |
|------|---------------|----------------|
| 节点类型 | 条件判断 | 条件判断+输出 |
| 返回值 | SUCCESS/FAILURE | 总是SUCCESS |
| 输出 | 无 | goal_pose字符串 |
| 用途 | 检查是否都健康 | 根据状态输出不同点位 |

## ✨ 节点优势

1. **参数可配置**: 所有阈值和点位都在XML中配置，无需重编译
2. **逻辑简洁**: 直接判断HP和弹量，输出对应点位
3. **易于集成**: 与现有的SubSefdefined、SubProjectileAllowance完美配合
4. **易于扩展**: 如需修改逻辑，只需编辑cpp文件中的判断条件

## 📁 文件结构

```
rm_behavior_tree/
├── include/rm_behavior_tree/plugins/condition/
│   └── hp_ammo_decision.hpp                          (新增)
├── plugins/condition/
│   └── hp_ammo_decision.cpp                          (新增)
├── config/
│   └── hp_ammo_decision_test.xml                     (新增)
├── CMakeLists.txt                                    (已修改)
├── HP_AMMO_DECISION_GUIDE.md                         (新增详细文档)
└── HP_AMMO_DECISION_IMPLEMENTATION_SUMMARY.md        (此文件)
```

## 🚀 下一步建议

1. **编译验证**
   ```bash
   colcon build --packages-select rm_behavior_tree
   ```

2. **集成到主配置**
   - 在 `sentry_decision_with_outpost.xml` 中使用新节点
   - 根据实际业务调整参数

3. **测试验证**
   - 在模拟环境测试
   - 验证HP和弹量的判断逻辑
   - 确认点位输出正确

4. **性能优化**
   - 如需要，可将固定计算移至构造函数
   - 监测消息订阅的延迟

## 📞 技术支持

如有问题请参考:
- 详细使用指南: `HP_AMMO_DECISION_GUIDE.md`
- 源代码注释: `hp_ammo_decision.cpp`
- 行为树示例: `config/hp_ammo_decision_test.xml`
