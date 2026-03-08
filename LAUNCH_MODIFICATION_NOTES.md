# SLAM + ICP Launch 修改说明

## 修改目标

改进 `bringup_real.launch.py` 使其能够按照正确顺序运行 SLAM Toolbox 和 ICP Registration，实现通过 ICP 获得初始位姿来快速修正 SLAM 的定位。

## 核心执行流程

### 步骤 A: 启动 SLAM Toolbox（T+0s）
- SLAM 以定位模式启动，进入监听状态
- 初始位姿设置为地图原点 `[0.0, 0.0, 0.0]`
- 此时 SLAM 可能无法准确定位（扫描点和地图对不上）

### 步骤 B: 延迟 3 秒后启动 ICP Registration（T+3s）
- ICP 节点启动，加载参考 PCD 点云
- 等待实时点云数据输入
- 开始点云配准计算

### 步骤 C: ICP 计算完毕发布初始位姿（T+3s ~ T+10s）
- ICP 对比参考 PCD 和当前实时点云
- 计算出机器人在地图中的真实位置
- 通过 `/initialpose` 话题发送给 SLAM Toolbox

### 步骤 D: 延迟 10 秒后启动 Navigation2（T+10s）
- SLAM 已接收并应用了 ICP 的位姿修正
- Navigation2 基于正确的位姿开始路径规划
- SLAM 维持定位精度

## 文件修改内容

### 1. 导入语句（第 6-11 行）

添加了事件处理器支持：
```python
from launch.actions import ... RegisterEventHandler
from launch.event_handlers import OnProcessStart
```

### 2. 定位逻辑重构（第 265-333 行）

原来的互斥定位方法改为并行结构，并为 ICP 模式添加 SLAM：

- **仅 SLAM 模式**：立即启动 SLAM（condition: 'slam_toolbox'）
- **ICP 模式**：同时启动 SLAM 和延迟 ICP（condition: 'icp'）
- **AMCL 模式**：启动 AMCL（condition: 'amcl'）
- **ICP 延迟**：设置为 3 秒

### 3. Navigation2 条件延迟（第 357-377 行）

```python
start_navigation2_delayed = TimerAction(
    period=10.0,  # 延迟 10 秒
    actions=[start_navigation2],
    condition = LaunchConfigurationEquals('localization', 'icp')  # 仅 ICP 模式延迟
)

start_navigation2_immediate = start_navigation2  # 其他模式立即启动
```

### 4. 启动顺序更新（第 395-401 行）

同时添加延迟和立即版本的 Navigation2，通过条件判断决定执行哪个。

## 使用方法

### 启动 ICP + SLAM 定位模式

```bash
ros2 launch rm_nav_bringup bringup_real.launch.py \
    mode:=nav \
    localization:=icp \
    world:=328
```

### 启动其他定位模式

**仅 SLAM Toolbox**
```bash
ros2 launch rm_nav_bringup bringup_real.launch.py \
    mode:=nav \
    localization:=slam_toolbox \
    world:=328
```

**AMCL 定位**
```bash
ros2 launch rm_nav_bringup bringup_real.launch.py \
    mode:=nav \
    localization:=amcl \
    world:=328
```

**建图模式**
```bash
ros2 launch rm_nav_bringup bringup_real.launch.py \
    mode:=mapping \
    world:=328
```

## 时间参数调优

### ICP 启动延迟

位置：第 310 行 `TimerAction period=3.0`

推荐值：
- SLAM 配置简单：1-2 秒
- SLAM 配置复杂：3-5 秒

增加此延迟可确保 SLAM 完全初始化后再启动 ICP。

### Navigation2 启动延迟

位置：第 372 行 `TimerAction period=10.0`

推荐值：
- 小型点云（<100K 点）：5-7 秒
- 中型点云（100K-500K 点）：8-12 秒
- 大型点云（>500K 点）：15-20 秒

**计算公式**：
```
Nav2 延迟 = ICP 启动延迟 + ICP 计算时间 + 安全余量(1-2s)
```

## 监控和调试

### 查看节点启动顺序

```bash
# 在另一个终端运行
watch -n 0.5 'ros2 node list'
```

应该看到以下顺序：
1. SLAM 节点立即出现
2. ~3 秒后 ICP 节点出现
3. ~10 秒后 Navigation2 节点出现

### 监测位姿变化

```bash
ros2 topic echo /amcl_pose --field=pose.pose
```

预期行为：
- T+0-3s：位姿保持 [0, 0, 0]
- T+3-10s：ICP 发布新位姿，SLAM 跳转
- T+10s+：位姿持续更新

### 检查 ICP 输出

```bash
ros2 topic echo /initialpose
```

### 查看 Navigation2 路径

```bash
ros2 topic echo /plan
```

## 话题映射

| 话题 | 方向 | 内容 |
|------|------|------|
| `/initialpose` | ICP → SLAM | 计算的初始位姿 |
| `/amcl_pose` | SLAM → Nav2 | 当前位姿估计 |
| `/scan` | LIO → SLAM | 激光扫描数据 |
| `/plan` | Nav2 | 路径规划 |

## 故障排除

### 问题 1：SLAM 位姿在收到 `/initialpose` 后不变

**可能原因**：
- SLAM 没有正确配置定位模式
- `/initialpose` 消息没有被发送
- SLAM 启动延迟不足

**解决方案**：
1. 增加 ICP 启动延迟到 5 秒
2. 检查 SLAM 配置文件 `mapper_params_localization_real.yaml`
3. 验证 `/initialpose` 话题是否有数据

### 问题 2：ICP 计算超时，Navigation2 启动时仍未完成

**可能原因**：
- 点云过大，计算耗时
- Navigation2 启动延迟太短

**解决方案**：
1. 增加 Navigation2 延迟到 15 秒
2. 优化 ICP 参数降低计算时间
3. 检查点云大小是否合理

### 问题 3：位姿跳转后扫描点仍不匹配地图

**可能原因**：
- ICP 配准精度不足
- 参考 PCD 与实际环境不一致
- 机器人运动正在进行

**解决方案**：
1. 检查 ICP fitness score（配准质量）
2. 验证 PCD 地图的准确性
3. 确保启动时机器人静止不动

## 技术细节

### 为什么不能同时启动 SLAM 和 Navigation2？

- Navigation2 依赖 SLAM 提供的位姿信息
- 如果 SLAM 位姿错误（原点），Nav2 的路径规划也会错误
- ICP 需要时间计算，Navigation2 需要等待 SLAM 接收新位姿

### 为什么 ICP 有 3 秒延迟？

- SLAM Toolbox 初始化需要时间加载参数和配置
- 激光扫描数据也需要时间开始流入
- 3 秒延迟确保 SLAM 已完全就绪

### TimerAction vs RegisterEventHandler

- **TimerAction**：简单的固定延迟，适合已知的初始化时间
- **RegisterEventHandler**：监听事件触发，更精确但更复杂

本实现选择 TimerAction 是因为时间可预估且配置简单。

## 性能优化建议

1. **点云预处理**：
   - 在 ICP 前对点云进行体素滤波
   - 减少点数来加快计算

2. **SLAM 配置**：
   - 启用扫描匹配而非粒子滤波
   - 提高更新频率

3. **并行处理**：
   - 确保 SLAM、ICP、Navigation2 运行在不同线程

## 版本信息

- ROS 2：Humble / Iron
- SLAM Toolbox：2.x
- Navigation 2：Humble / Iron

## 参考

- SLAM Toolbox 配置：`config/reality/mapper_params_localization_real.yaml`
- ICP 配置：`config/simulation/icp_registration_sim.yaml`
- Navigation2 配置：`config/reality/nav2_params_real.yaml`
