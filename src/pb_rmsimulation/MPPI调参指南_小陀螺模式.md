# MPPI控制器调参指南 - 小陀螺模式优化

## 问题描述
- 当前问题：小陀螺模式下（转速1.23rad/s）不能走直线，只能走圆弧
- 雷达位置：底盘上
- 使用控制器：MPPI (Model Predictive Path Integral)

## 核心问题分析

小陀螺模式下走圆弧的主要原因：
1. **TwirlingCritic权重过高** - 过度惩罚旋转导致控制器倾向于保持当前旋转状态
2. **PathAlignCritic权重不足** - 路径对齐约束太弱，无法强制直线跟随
3. **采样标准差不合理** - wz_std过大导致角速度探索空间过宽

## 推荐调参方案

### 方案一：降低旋转惩罚（推荐优先尝试）

```yaml
# 在 nav2_params_real.yaml 的 TwirlingCritic 部分
TwirlingCritic:
  enabled: true
  twirling_cost_power: 1
  twirling_cost_weight: 2.0    # 从 10.0 降低到 2.0，减少旋转惩罚
```

### 方案二：增强路径对齐约束

```yaml
# PathAlignCritic 部分
PathAlignCritic:
  enabled: true
  cost_power: 1
  cost_weight: 50.0              # 从 20.0 提高到 50.0
  threshold_to_consider: 1.5     # 从 1.0 提高到 1.5
  offset_from_furthest: 1        # 从 2 降低到 1，更关注近处路径
  use_path_orientations: false
```

### 方案三：调整采样参数

```yaml
# Sampling Standard Deviations 部分
vx_std: 0.6      # 从 0.8 降低，减少前向探索
vy_std: 0.6      # 从 0.8 降低，减少侧向探索
wz_std: 1.0      # 从 2.0 降低到 1.0，限制角速度探索范围
```

### 方案四：调整温度和折扣因子

```yaml
# Control Parameters 部分
temperature: 0.15    # 从 0.3 降低，更贪婪地选择最优轨迹
gamma: 0.15          # 从 0.07 提高，增加轨迹平滑度权重
```

## 动态调参命令

### 启动rqt_reconfigure
```bash
ros2 run rqt_reconfigure rqt_reconfigure
```

### 关键参数实时调整顺序

1. **第一步：降低TwirlingCritic权重**
   - 参数路径：`/controller_server/FollowPath/TwirlingCritic/twirling_cost_weight`
   - 建议值：10.0 → 5.0 → 2.0 → 1.0（逐步降低观察效果）

2. **第二步：提高PathAlignCritic权重**
   - 参数路径：`/controller_server/FollowPath/PathAlignCritic/cost_weight`
   - 建议值：20.0 → 30.0 → 40.0 → 50.0（逐步提高）

3. **第三步：调整采样标准差**
   - `wz_std`: 2.0 → 1.5 → 1.0
   - `vx_std`, `vy_std`: 0.8 → 0.6

4. **第四步：微调温度参数**
   - `temperature`: 0.3 → 0.2 → 0.15

## 综合推荐配置（小陀螺优化版）

```yaml
FollowPath:
  plugin: "nav2_mppi_controller::MPPIController"

  # 采样参数
  time_steps: 100
  model_dt: 0.05
  batch_size: 1200

  # 速度限制
  vx_max: 2.0
  vx_min: -2.0
  vy_max: 2.0
  wz_max: 6.0

  # 采样标准差 - 关键调整
  vx_std: 0.6        # ↓ 降低
  vy_std: 0.6        # ↓ 降低
  wz_std: 1.0        # ↓ 从2.0降低

  # 控制参数 - 关键调整
  temperature: 0.15   # ↓ 从0.3降低
  gamma: 0.15         # ↑ 从0.07提高

  # 代价函数
  PathAlignCritic:
    cost_weight: 50.0           # ↑ 从20.0提高
    threshold_to_consider: 1.5  # ↑ 从1.0提高
    offset_from_furthest: 1     # ↓ 从2降低

  TwirlingCritic:
    twirling_cost_weight: 2.0   # ↓ 从10.0降低
```

## 测试步骤

1. 备份当前配置文件
2. 应用方案一（降低TwirlingCritic）
3. 测试直线行走效果
4. 如果效果不佳，叠加方案二（增强PathAlign）
5. 使用rqt_reconfigure实时微调
6. 记录最佳参数组合

## 注意事项

- 小陀螺模式下雷达数据会有旋转畸变，确保TF时间戳正确
- 调参时注意观察是否出现震荡
- 如果直线性能改善但避障变差，适当提高ObstaclesCritic权重
- 建议在空旷环境先测试直线性能，再测试避障

## 可能的额外问题

如果调参后仍无法走直线，检查：
1. TF树是否正确（base_link → base_link_fake → map）
2. 里程计是否受小陀螺影响产生漂移
3. 全局规划器是否给出了直线路径
4. fake_vel_transform节点是否正确补偿了旋转速度
