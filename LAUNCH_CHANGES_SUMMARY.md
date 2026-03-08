# Launch 修改总结

## ✅ 已完成的修改

已成功修改 `bringup_real.launch.py` 以支持 SLAM + ICP 的顺序执行。

### 关键改动

**导入语句**（第 6-11 行）
- 添加 `RegisterEventHandler` 和 `OnProcessStart`

**定位逻辑**（第 265-333 行）
- 为 ICP 模式添加独立的 SLAM 启动节点
- ICP 启动延迟改为 3 秒（从原来的 7 秒）

**Navigation2 启动**（第 357-401 行）
- 添加条件延迟逻辑
- ICP 模式延迟 10 秒
- 其他模式立即启动

## ⏱️ 执行时序

| 时间 | 事件 | 说明 |
|------|------|------|
| T+0s | SLAM 启动 | 进入定位模式，位姿 [0,0,0] |
| T+3s | ICP 启动 | 开始点云配准 |
| T+3-10s | ICP 计算 | 对比 PCD 和实时点云 |
| T+10s | Nav2 启动 | SLAM 已接收位姿修正 |

## 🚀 使用方法

**启动 ICP + SLAM 模式**

```bash
ros2 launch rm_nav_bringup bringup_real.launch.py \
    mode:=nav localization:=icp world:=328
```

**其他模式**

- 仅 SLAM: `localization:=slam_toolbox`
- AMCL: `localization:=amcl`
- 建图: `mode:=mapping`

## ⚙️ 时间参数调优

### ICP 启动延迟（第 310 行）

```python
TimerAction(period=3.0, ...)
```

推荐值: 1-5 秒（取决于 SLAM 复杂度）

### Navigation2 启动延迟（第 372 行）

```python
TimerAction(period=10.0, ...)
```

公式: `Nav2延迟 = ICP延迟 + ICP计算时间 + 1-2秒余量`

- 小点云: 5-7 秒
- 中点云: 8-12 秒  
- 大点云: 15-20 秒

## 📊 监控

**查看节点启动顺序**

```bash
watch -n 0.5 'ros2 node list'
```

**监测位姿**

```bash
ros2 topic echo /amcl_pose --field=pose.pose
```

**检查 ICP 输出**

```bash
ros2 topic echo /initialpose
```

## 🔧 故障排除

| 问题 | 可能原因 | 解决方案 |
|------|--------|--------|
| SLAM 收到位姿后不变 | SLAM 未配置定位模式 | 检查 mapper_params_localization_real.yaml |
| ICP 计算超时 | 点云太大或延迟太短 | 增加 Nav2 延迟到 15-20s |
| 位姿跳转后仍不匹配 | ICP 配准精度低 | 检查 fitness score 或优化 ICP 参数 |

## 📝 文件位置

- 主文件: `src/pb_rmsimulation/src/rm_nav_bringup/launch/bringup_real.launch.py`
- SLAM 配置: `config/reality/mapper_params_localization_real.yaml`
- ICP 配置: `config/simulation/icp_registration_sim.yaml`
- Nav2 配置: `config/reality/nav2_params_real.yaml`

## 💡 核心逻辑

```
[T+0s] SLAM 启动 (定位模式)
         ↓
   [等待 3 秒]
         ↓
[T+3s] ICP 启动 (开始计算)
         ↓
   [计算点云配准 ~7s]
         ↓
[T+10s] ICP 发布 /initialpose
       SLAM 接收并"跳转"到正确位置
         ↓
[T+10s] Navigation2 启动
       基于正确位姿规划路径
```

## ✨ 优点

- ✅ SLAM 和 ICP 能够协作而非互斥
- ✅ 快速获得准确的初始位姿
- ✅ 保持 SLAM 长期定位精度
- ✅ 支持多种定位模式
- ✅ 时间参数易于调整

## 🔗 相关话题

- `/initialpose`: ICP → SLAM（位姿修正）
- `/amcl_pose`: SLAM → Nav2（位姿估计）
- `/scan`: LIO → SLAM（激光数据）
- `/plan`: Nav2（路径规划）
