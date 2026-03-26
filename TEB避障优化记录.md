# TEB 局部规划器避障优化记录

## 问题描述

**现象：**
- 机器人在行进时底盘会小陀螺旋转（spin_speed: -6.0 rad/s）
- 雷达固定在底盘上，随底盘一起旋转
- 避障效果差，特别是在动态对抗场景中

**场景：**
- 比赛环境，存在其他移动的机器人
- 需要在高速旋转的同时保持良好的避障能力

---

## 坐标系分析

### 坐标系结构
```
map (全局地图坐标系，固定)
  └─ odom (里程计坐标系，相对固定)
      └─ base_link (底盘坐标系，小陀螺旋转 6rad/s)
          ├─ base_link_fake (虚拟坐标系，朝向TEB规划方向)
          └─ livox_frame (雷达坐标系，固定在底盘上)
```

### base_link_fake 的作用
- 由 `fake_vel_transform` 节点创建
- 朝向始终指向 TEB 规划的目标方向
- 不随底盘小陀螺旋转
- 用于速度转换和路径规划

---

## 根本原因分析

### 相对速度问题
底盘旋转时，雷达看到的障碍物"相对速度"远超配置限制：

**相对速度计算：**
- 底盘旋转速度：6 rad/s
- 障碍物距离：1m
- 旋转产生的相对速度：6 m/s
- 对方机器人真实速度：2-3 m/s
- **总相对速度：8-10 m/s**

**原配置问题：**
- `max_obstacle_velocity: 2.0 m/s` ❌ 远小于实际相对速度
- `max_obstacle_acceleration: 1.0 m/s²` ❌ 无法应对快速变化
- `tracking_dist_threshold: 0.5m` ❌ 数据关联阈值太小

**结果：**
- 卡尔曼滤波器认为障碍物速度"异常"
- 障碍物跟踪失败
- 避障效果差

---

## 已完成的修改

### 文件位置
`./src/pb_rmsimulation/src/rm_nav_bringup/config/reality/nav2_params_real.yaml`

### 1. 添加机器人足迹模型配置
**位置：** 第165-170行

```yaml
footprint_model:
  type: "circular"
  radius: 0.27
```

**原因：**
- TEB 需要显式配置 footprint_model 用于轨迹优化
- 如果不配置，会使用默认的 PointRobotFootprint（半径0.0）
- 必须与 URDF 中的机器人半径（0.27m）一致

