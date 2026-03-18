# 🔍 地图跑到一半就飞了 - 完整排查指南

## 📋 问题现象

- ✗ 机器人在地图上跑着跑着位置突然跳跃
- ✗ 在 RViz 中看到机器人"传送"到其他位置
- ✗ 坐标系可能发生变化
- ✗ 导航任务失败

---

## 🎯 快速诊断（3分钟）

### 步骤 1: 启动诊断工具

打开终端，运行：

```bash
# 编译脚本
cd /workspaces/srm_auto_sentry
source install/setup.zsh

# 运行诊断工具
ros2 run rm_nav_bringup diagnose_navigation_drift
```

你会看到实时诊断报告，包括：
- ✓ 当前位置和定位协方差
- ⚠️  位置跳跃检测
- ⚠️  协方差尖峰检测
- 📡 数据流状态
- 🔗 TF 树检查

### 步骤 2: 观察导航过程

在另一个终端启动导航：

```bash
# 启动导航系统
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox nav_rviz:=True

# 发送测试路线
ros2 run rm_nav_bringup waypoints_test_client 1
```

### 步骤 3: 查看诊断输出

关注诊断工具的输出，特别是：

```
⚠️  位置跳跃检测: 2.50m (Δt=0.050s)
    从 (5.12, 3.45) 到 (7.62, 3.50)

⚠️  协方差尖峰: 8.5x (从 0.0023 到 0.0195)
    可能丢失视觉信号或环境变化

❌ 严重 (频繁异常)
```

---

## 🔧 根据诊断结果排查

### 诊断结果 1️⃣: "位置跳跃"较多

**症状**: 诊断报告显示多次位置跳跃 (>0.5m)

**可能原因**:
- LiDAR 数据丢失或中断
- SLAM 算法重新初始化
- 地图更新导致坐标系变化

**排查步骤**:

```bash
# 终端1: 监控 LiDAR 数据
ros2 topic hz /cloud_registered

# 输出应该是稳定的频率（如 10Hz）
# 如果看到频率波动或时断时续，说明 LiDAR 有问题
```

```bash
# 终端2: 监控 AMCL 定位输出
ros2 topic echo /amcl_pose

# 看输出，检查:
# - 是否有频繁跳跃
# - 协方差 (covariance) 是否变化很大
```

```bash
# 终端3: 查看 SLAM 状态
ros2 service call /slam_toolbox/clear_queue std_srvs/srv/Empty

# 或检查 SLAM 地图质量
ros2 topic hz /map
```

---

### 诊断结果 2️⃣: "协方差尖峰"频繁

**症状**: 协方差突然增大 (>5 倍)

**可能原因**:
- 进入特征不足的区域（如空旷走廊、纯色墙壁）
- 光照变化导致 LiDAR 反射差异
- 环境中出现动态物体

**排查步骤**:

```bash
# 检查环境特征
# 在 RViz 中:
# 1. 添加 PointCloud2 → /cloud_registered
# 2. 添加 Map → /map
# 3. 观察机器人在什么地方出现问题

# 如果是在某些特定区域（如长走廊）有问题，可能是特征不足
```

**解决方案**:

在 `nav2_params_sim.yaml` 中调整 AMCL 参数：

```yaml
amcl:
  ros__parameters:
    # 增加粒子数，提高定位鲁棒性
    num_particles: 200  # 从 100 改为 200
    
    # 增加协方差噪声，让定位更容易收敛
    z_hit: 0.5          # 从 0.95 改为 0.5
    z_short: 0.1        # 从 0.1 改为 0.2
    z_max: 0.05         # 从 0.05 改为 0.1
    z_rand: 0.3         # 从 0.05 改为 0.3
```

---

### 诊断结果 3️⃣: "TF 树断裂"

**症状**: 诊断报告显示 `map -> base_link` 或 `odom -> base_link` 失败

**可能原因**:
- 定位节点崩溃
- TF 发布器出问题
- 坐标系配置错误

**排查步骤**:

```bash
# 检查 TF 树
ros2 run tf2_tools view_frames
# 会生成 frames.pdf，查看坐标系连接

# 监控 TF 话题
ros2 topic hz /tf
ros2 topic echo /tf
```

**解决方案**:

```bash
# 检查定位节点是否运行
ros2 node list | grep -E "slam|amcl"

# 如果 SLAM 节点死了，重启导航系统
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox
```

---

### 诊断结果 4️⃣: "定位协方差"始终很高

**症状**: 协方差值一直很大 (> 0.01)

**可能原因**:
- SLAM 初始化失败
- LiDAR 噪声过大
- 地图和现实环境不匹配

**排查步骤**:

```bash
# 1. 检查地图质量
# 在 RViz 中查看 /map，地图应该清晰

# 2. 检查 LiDAR 配置
cat /workspaces/srm_auto_sentry/src/pb_rmsimulation/src/rm_nav_bringup/config/simulation/fastlio_mid360_sim.yaml

# 关注：
# - filter_size_surf: 0.5  (表面滤波大小)
# - filter_size_map: 0.5   (地图滤波大小)
# - point_filter_num: 3    (点云采样)
```

**解决方案**:

```yaml
# 在 fastlio_mid360_sim.yaml 中调整:
LiDAR:
  frame_id: lidar_link
  feature_param:
    point_filter_num: 3  # 减少采样，降低噪声
    filter_size_surf: 0.5  # 增加表面滤波
    filter_size_map: 0.5   # 增加地图滤波
```

---

## 🛠️ 高级排查：查看实时日志

### 查看 SLAM 日志

```bash
# 获取 slam_toolbox 节点详细日志
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    log_level:=DEBUG
```

关注日志中的：
- `[slam_toolbox]` 关于地图更新的消息
- `[amcl]` 关于定位失败的警告
- `[tf2]` 关于变换缓冲区的错误

### 监控关键话题

```bash
# 终端1: 监控定位
ros2 topic echo /amcl_pose --no-arr

# 终端2: 监控 LiDAR
ros2 topic hz /cloud_registered

# 终端3: 监控地图更新
ros2 topic hz /map

# 终端4: 监控里程计（对比 AMCL）
ros2 topic echo /odom --no-arr
```

---

## 🎯 根本解决方案

### 方案 A: 使用更稳定的定位（推荐）

在 `waypoints_navigator.launch.py` 中指定定位方式：

```bash
# 使用 SLAM (更稳定，适合导航)
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    localization:=slam_toolbox \
    world:=RMUL mode:=nav

# 不要使用 AMCL (容易丢失)
```

### 方案 B: 提高定位容错能力

修改 `nav2_params_sim.yaml`:

```yaml
# 增加恢复策略
bt_navigator:
  ros__parameters:
    # 在定位失败时自动重新初始化
    use_um_start_pose_with_confidence: true
    
    # 恢复行为 - 旋转以获取足够特征
    recover_behaviors: ["spin", "backup", "reinitialize"]
```

### 方案 C: 实时监控和自动恢复

编辑 `diagnose_navigation_drift.py` 来自动触发恢复：

```python
if self.position_jumps > 5:
    self.get_logger().error('定位频繁跳跃，触发恢复机制...')
    self.trigger_recovery()

def trigger_recovery(self):
    """触发定位恢复"""
    # 发送旋转命令重新初始化 SLAM
    # 或调用 /reset_map 服务
```

---

## 📊 性能参考

| 指标 | 正常范围 | 异常范围 |
|------|---------|---------|
| 位置跳跃 | 0-1 次/分钟 | >5 次/分钟 |
| 协方差 | 0.001-0.005 | >0.01 |
| 协方差波动 | <1.5x | >5x |
| LiDAR 频率 | 稳定 10Hz | <5Hz 或不稳定 |
| AMCL 频率 | 稳定 30Hz | <10Hz |

---

## ✅ 快速检查清单

在运行下面的诊断命令后，对照以下检查：

```bash
# 1. 启动完整系统
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox nav_rviz:=True

# 2. 运行诊断工具
ros2 run rm_nav_bringup diagnose_navigation_drift

# 3. 发送测试路线
ros2 run rm_nav_bringup waypoints_test_client 1

# 4. 观察输出
```

**检查项**:
- ✓ 诊断报告是否显示"良好"状态？
- ✓ 位置跳跃是否为 0？
- ✓ 协方差是否稳定在 0.001-0.005？
- ✓ TF 树是否完整（所有变换可用）？
- ✓ LiDAR 数据是否稳定更新？

---

## 🆘 如果还是不行

按以下顺序逐步排查：

1. **检查 LiDAR 硬件**
   ```bash
   ros2 topic echo /cloud_registered | head -20
   # 应该有点云数据
   ```

2. **检查 IMU**
   ```bash
   ros2 topic echo /imu --no-arr
   # 应该有稳定的加速度和角速度
   ```

3. **验证地图**
   ```bash
   # RViz 中查看 /map 话题
   # 地图应该清晰，不应该有太多黑块
   ```

4. **重新启动定位**
   ```bash
   # 停止当前导航
   ros2 node kill <node_name>
   
   # 清除旧数据，重新启动
   ros2 service call /slam_toolbox/serialize_map std_srvs/srv/Empty
   ```

5. **检查日志**
   ```bash
   # 查看 ROS 日志目录
   cat ~/.ros/log/latest/*/stderr
   ```

---

## 📞 如果需要更多帮助

收集以下信息：
1. 诊断工具的完整输出
2. RViz 中的截图
3. 涉及的地图文件
4. 硬件配置信息

---

最后更新: 2024年3月17日
