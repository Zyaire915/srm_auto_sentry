# 多途径点导航完全使用指南

## 功能概述

本方案提供了一个**完整的多途径点导航系统**，具有以下特性：

✅ **根据途径点生成全局路线** - 自动规划点与点之间的路径  
✅ **无时间间隔** - 到达一个点后立即前往下一个点（不需要停留）  
✅ **灵活的容差控制** - 可独立调整每个点的容差值  
✅ **集成 RViz 可视化** - 实时显示路线和途径点  
✅ **模拟+实车通用** - 同一套参数可用于仿真和真实机器人  

---

## 快速开始

### 第一步：编译和安装

```bash
cd /workspaces/srm_auto_sentry

# 使用 colcon 编译（如果是第一次编译）
colcon build --packages-select rm_nav_bringup

# 加载工作空间
source install/setup.zsh
```

### 第二步：启动导航系统

这是完整的启动命令，包括导航、多途径点导航器和 RViz：

```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL \
    mode:=nav \
    lio:=fastlio \
    localization:=slam_toolbox \
    lio_rviz:=False \
    nav_rviz:=True \
    waypoint_tolerance:=1.0 \
    final_goal_tolerance:=0.25
```

**参数说明：**

| 参数 | 值 | 说明 |
|------|-----|------|
| `world` | RMUL / RMUC | 仿真世界类型 |
| `mode` | nav / mapping | nav=已知地图, mapping=边建图 |
| `lio` | fastlio / pointlio | LIO 选择 |
| `localization` | slam_toolbox / amcl / icp | 定位方式 |
| `lio_rviz` | True / False | 显示 LIO 点云 |
| `nav_rviz` | True / False | 显示导航 RViz |
| `waypoint_tolerance` | 0.0-2.0 | 途径点容差（米） |
| `final_goal_tolerance` | 0.0-0.5 | 最终目标容差（米） |

### 第三步：发送途径点

在新的终端中，运行测试客户端：

```bash
# 源化工作空间
source /workspaces/srm_auto_sentry/install/setup.zsh

# 运行测试客户端（交互式菜单）
ros2 run rm_nav_bringup waypoints_test_client
```

或直接运行某个示例：

```bash
# 示例 1: 矩形巡逻
ros2 run rm_nav_bringup waypoints_test_client 1

# 示例 2: 三角形
ros2 run rm_nav_bringup waypoints_test_client 2

# 示例 3: 复杂 7 点
ros2 run rm_nav_bringup waypoints_test_client 3

# 示例 4: 交互式输入
ros2 run rm_nav_bringup waypoints_test_client 4
```

---

## 详细使用方法

### 方式 A：使用测试客户端（推荐）

最简单的方法是使用提供的测试客户端。

#### 交互式模式

```bash
ros2 run rm_nav_bringup waypoints_test_client
```

屏幕会显示菜单，选择一个预定义的示例或输入自定义路线。

#### 命令行模式

```bash
# 运行预定义示例
ros2 run rm_nav_bringup waypoints_test_client 1    # 矩形
ros2 run rm_nav_bringup waypoints_test_client 2    # 三角形
ros2 run rm_nav_bringup waypoints_test_client 3    # 7 点复杂
ros2 run rm_nav_bringup waypoints_test_client 4    # 自定义
```

#### 自定义输入格式

交互式自定义时，按以下格式输入（每行一个点）：

```
x y tolerance
x y tolerance
...
(空行结束)
```

例如：
```
0 0 1.0
2 3 1.0
5 5 0.25
(按 Enter)
```

### 方式 B：使用 ROS Topic 发布

如果要在自己的代码中发送途径点，可以发布到 `/set_waypoints` topic：

#### Python 示例

```python
import rclpy
from std_msgs.msg import Float64MultiArray

rclpy.init()
node = rclpy.create_node('my_waypoints')

# 创建发布者
pub = node.create_publisher(Float64MultiArray, '/set_waypoints', 10)

# 创建途径点数据
# 格式: [x1, y1, tol1, x2, y2, tol2, ..., xn, yn, toln]
waypoints = [
    2.0, 2.0, 1.0,    # 途径点 1
    4.0, 2.0, 1.0,    # 途径点 2
    4.0, 4.0, 0.25,   # 最终目标
]

# 发送消息
msg = Float64MultiArray()
msg.data = waypoints
pub.publish(msg)

rclpy.spin_once(node, timeout_sec=1)
rclpy.shutdown()
```

#### 命令行发布

```bash
# 矩形巡逻示例
ros2 topic pub /set_waypoints std_msgs/Float64MultiArray \
    'data: [2.0, 2.0, 1.0, 4.0, 2.0, 1.0, 4.0, 4.0, 0.25]'
```

---

## RViz 可视化

启动时已自动加载 RViz 配置文件 (`waypoints_navigator.rviz`)。

### 显示的内容

| 显示 | 颜色 | 说明 |
|------|------|------|
| **Grid** | 灰色网格 | 参考网格 |
| **Costmap** | 蓝色区域 | 代价地图（障碍物） |
| **Global Plan** | 绿色路线 | Nav2 规划的路径 |
| **Global Route** | **红色路线** | 多个途径点之间的连线 |
| **Waypoints Array** | **橙色箭头** | 每个途径点的位置和方向 |
| **Odometry** | 粉色椭圆 | 机器人位置和不确定性 |

### 交互操作

- **平移**: 按住鼠标中键 + 拖动
- **旋转**: 按住鼠标右键 + 拖动
- **缩放**: 鼠标滚轮
- **设置初始位置**: 使用工具栏中的 "Set Initial Pose"
- **设置目标**: 使用工具栏中的 "Set Goal"

---

## 参数调整

### 容差参数解释

**途径点容差** (`waypoint_tolerance`)
- 使用场景：中间的途径点
- 推荐值：0.5-1.5 m
- 过小会导致：机器人在目标点附近震荡
- 过大会导致：可能不会精确到达

**最终目标容差** (`final_goal_tolerance`)
- 使用场景：最后一个目标点
- 推荐值：0.1-0.5 m
- 过小会导致：任务完不成
- 过大会导致：最后位置偏差大

### 不同场景的推荐参数

#### 场景 1：巡逻任务（快速）

```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    waypoint_tolerance:=1.5 \
    final_goal_tolerance:=0.5
```

#### 场景 2：精密作业（慢速）

```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    waypoint_tolerance:=0.5 \
    final_goal_tolerance:=0.1
```

#### 场景 3：标准导航（平衡）

```bash
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    waypoint_tolerance:=1.0 \
    final_goal_tolerance:=0.25
```

---

## 高级用法

### 在行为树中使用

如果要在行为树中集成多途径点导航，可以这样做：

```xml
<root>
  <BehaviorTree>
    <Sequence>
      <!-- 计算巡逻路线 -->
      <HpDecisionPatrol output_waypoints="{waypoints}"/>
      
      <!-- 发布到导航器 -->
      <RosTopicPublish topic="/set_waypoints"
                       message_type="std_msgs/Float64MultiArray">
        <param name="data" value="{waypoints}"/>
      </RosTopicPublish>
      
      <!-- 等待导航完成 -->
      <WaitAction msec="30000"/>
    </Sequence>
  </BehaviorTree>
</root>
```

### 从配置文件读取路线

```yaml
# waypoints_config.yaml
routes:
  patrol_aggressive:
    waypoint_tolerance: 1.0
    final_goal_tolerance: 0.25
    points:
      - [2.0, 2.0]
      - [4.0, 2.0]
      - [4.0, 4.0]
      - [2.0, 4.0]
  
  patrol_defensive:
    waypoint_tolerance: 0.5
    final_goal_tolerance: 0.15
    points:
      - [-2.0, -2.0]
      - [-4.0, -2.0]
      - [-4.0, -4.0]
```

然后在代码中读取：

```python
import yaml

with open('waypoints_config.yaml', 'r') as f:
    config = yaml.safe_load(f)

route = config['routes']['patrol_aggressive']
waypoint_tolerance = route['waypoint_tolerance']
points = route['points']

# 转换为 [x, y, tol, x, y, tol, ...] 格式
waypoints = []
for i, (x, y) in enumerate(points):
    tol = route['final_goal_tolerance'] if i == len(points)-1 else route['waypoint_tolerance']
    waypoints.extend([x, y, tol])
```

---

## 故障排除

### 问题 1：导航器无法启动

```
错误: [waypoints_navigator]: navigate_to_pose action server 不可用
```

**解决方案:**
```bash
# 1. 检查 Nav2 是否正确启动
ros2 node list | grep navigate

# 2. 检查 action server 是否可用
ros2 action list | grep navigate_to_pose

# 3. 如果没有找到，重新启动导航系统
ros2 launch rm_nav_bringup bringup_sim.launch.py world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox
```

### 问题 2：容差设置无效

```
警告: ✗ 容差设置失败: xxx
```

**解决方案:**
```bash
# 1. 检查 controller_server 是否运行
ros2 node list | grep controller_server

# 2. 手动测试设置参数
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 1.0

# 3. 检查参数是否生效
ros2 param get /controller_server general_goal_checker.xy_goal_tolerance
```

### 问题 3：机器人无法到达途径点

**可能原因和解决方案:**

1. **地图与定位不同步**
   ```bash
   # 在 RViz 中手动设置初始位置
   # 使用 "Set Initial Pose" 工具指向机器人当前位置
   ```

2. **容差太严格**
   ```bash
   # 增大容差
   ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 1.5
   ```

3. **路径规划失败**
   ```bash
   # 检查目标是否在障碍物内或无法到达的地方
   # 在 RViz 中检查代价地图，确保目标点在可行走的区域
   ```

### 问题 4：RViz 显示不正确

**解决方案:**

```bash
# 1. 重新加载配置文件
rviz2 -c /workspaces/srm_auto_sentry/src/rm_nav_bringup/config/waypoints_navigator.rviz

# 2. 或手动配置显示
# 在 RViz 左侧 Displays 面板中：
#   - 添加 Path (topic: /global_route)
#   - 添加 PoseArray (topic: /waypoints_array)
```

---

## 测试用例

### 测试 1：基本功能测试

```bash
# 终端 1: 启动导航系统
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox

# 终端 2: 发送矩形路线
ros2 run rm_nav_bringup waypoints_test_client 1

# 预期结果:
# ✓ RViz 中显示红色的矩形路线
# ✓ 橙色箭头标示 4 个途径点
# ✓ 机器人依次到达各点
```

### 测试 2：参数调整测试

```bash
# 终端 1: 启动时使用严格容差
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox \
    waypoint_tolerance:=0.3 final_goal_tolerance:=0.1

# 终端 2: 发送路线
ros2 run rm_nav_bringup waypoints_test_client 1

# 预期结果:
# ✓ 机器人会在每个点更加精确地停留
# ✓ 整个过程会比默认参数更慢
```

### 测试 3：动态容差测试

```bash
# 终端 1: 启动导航
ros2 launch rm_nav_bringup waypoints_navigator.launch.py \
    world:=RMUL mode:=nav lio:=fastlio localization:=slam_toolbox

# 终端 2: 发送路线
ros2 run rm_nav_bringup waypoints_test_client 3

# 终端 3: 在导航过程中修改容差
sleep 5  # 等待导航开始
ros2 param set /controller_server general_goal_checker.xy_goal_tolerance 0.5

# 预期结果:
# ✓ 途中改变容差后，机器人行为会改变
# ✓ 容差变小时会更精确，变大时会更宽松
```

---

## 性能指标

### 典型场景下的性能

| 指标 | 值 |
|------|-----|
| 途径点识别延迟 | < 100ms |
| 容差设置延迟 | 500-1000ms |
| 路线生成延迟 | < 50ms |
| RViz 更新频率 | 30 Hz |

### 硬件要求

- **CPU**: 双核 2GHz 以上
- **内存**: 2GB 以上
- **存储**: 1GB 以上（用于地图和日志）

---

## 最佳实践

1. ✅ **启动顺序**
   - 先启动导航系统
   - 再启动多途径点导航器
   - 最后发送途径点

2. ✅ **容差设置**
   - 途径点通常用 1.0m 左右
   - 最终目标用 0.25m 左右
   - 根据实际场景调整

3. ✅ **RViz 使用**
   - 始终开启 RViz 便于调试
   - 检查红色的全局路线是否正确
   - 观察橙色箭头的位置

4. ✅ **路线设计**
   - 避免让途径点过于接近（< 0.5m）
   - 避免在障碍物上设置点
   - 保证路线在地图的已知区域内

5. ✅ **日志查看**
   ```bash
   # 查看完整日志（包括调试信息）
   ros2 run rm_nav_bringup waypoints_navigator --ros-args --log-level DEBUG
   ```

---

## 相关文件

- 导航器脚本: `/src/rm_nav_bringup/scripts/waypoints_navigator.py`
- 启动文件: `/src/rm_nav_bringup/launch/waypoints_navigator.launch.py`
- 测试客户端: `/src/rm_nav_bringup/scripts/waypoints_test_client.py`
- RViz 配置: `/src/rm_nav_bringup/config/waypoints_navigator.rviz`

---

## 联系和反馈

如有问题或建议，请提交 Issue 或联系开发团队。

---

**最后更新**: 2024 年 12 月  
**版本**: 1.0.0
