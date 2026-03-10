# HP 巡逻行为树集成指南

## 目标

将自定义多途径点导航方案集成到现有的 `hp_patrol_test` 行为树中，使其能够：

1. 根据 HP 值动态选择巡逻位置
2. 以最优的容差值导航到每个位置
3. 在途中位置使用宽松容差，最终位置使用严格容差

---

## 当前状态分析

### 现有架构

```
rm_behavior_tree
├── launch/
│   └── rm_behavior_tree.launch.py              # BT 启动器
├── config/
│   └── hp_patrol_test.xml                      # 巡逻行为树定义
├── plugins/
│   ├── action/
│   │   ├── hp_decision_patrol.cpp              # HP 决策节点
│   │   └── ...
│   └── ...
└── CMakeLists.txt
```

### 现有 hp_patrol_test.xml 结构

```xml
<root>
  <BehaviorTree>
    <!-- 巡逻位置决策 -->
    <Sequence>
      <HpDecisionPatrol/>           <!-- 输出：成功/失败 + 目标位置 -->
      <SendGoal goal_pose="{goal_pose}"/>  <!-- Nav2 action 调用 -->
    </Sequence>
  </BehaviorTree>
</root>
```

### 当前问题

⚠️ `SendGoal` 无法为不同目标使用不同的容差  
⚠️ Nav2 的 `navigate_through_poses` 也有同样的问题  

---

## 集成方案：3 个层次

### 层次 1：最小改动（使用 Python + BT）⭐ **推荐**

**概念：** 保持现有 BT 逻辑不变，但在 Nav2 导航层使用 Python 脚本处理容差

#### 步骤 1：启动脚本

创建 `/workspaces/srm_auto_sentry/decision.sh`（修改现有版本）：

```bash
#!/bin/bash

# 启动顺序很重要！

# 1. 启动导航系统
echo "启动导航系统..."
ros2 launch rm_nav_bringup bringup_launch.py

# 在另一个终端中执行：
# 2. 启动多途径点导航处理器
# ros2 launch rm_nav_bringup navigate_through_waypoints.launch.py

# 3. 启动行为树
# ros2 launch rm_behavior_tree rm_behavior_tree.launch.py style:=hp_patrol_test
```

#### 步骤 2：修改 hp_patrol_test.xml

```xml
<root main_tree_to_execute="HPPatrol">
  <BehaviorTree ID="HPPatrol">
    <Sequence>
      <!-- 1. 决策 HP 状态 -->
      <HpDecisionPatrol/>
      
      <!-- 2. 等待导航准备 -->
      <WaitAction msec="500"/>
      
      <!-- 3. 调用多途径点导航服务 -->
      <RosServiceCommand service_name="/navigate_through_waypoints/navigate"
                         request_type="custom_nav_msgs/NavigateThroughWaypoints">
        <param name="poses" value="{waypoint_list}"/>
        <param name="waypoint_tolerance" value="1.0"/>
        <param name="final_goal_tolerance" value="0.25"/>
      </RosServiceCommand>
      
      <!-- 4. 循环回到第一步 -->
      <AlwaysRunning/>
    </Sequence>
  </BehaviorTree>
</root>
```

#### 步骤 3：修改 HpDecisionPatrol

修改 `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/plugins/action/hp_decision_patrol.cpp`：

```cpp
// 原有输出：单个目标位置
// 新增输出：目标位置列表（路径）

class HpDecisionPatrol : public BT::SyncActionNode {
public:
    HpDecisionPatrol(const std::string& name, const BT::NodeConfig& config)
        : BT::SyncActionNode(name, config) {}
    
    static BT::PortsList providedPorts() {
        return {
            // 原有
            BT::OutputPort<geometry_msgs::msg::PoseStamped>("goal_pose"),
            // 新增：输出位置列表
            BT::OutputPort<std::vector<geometry_msgs::msg::PoseStamped>>("waypoint_list"),
        };
    }
    
    BT::NodeStatus tick() override {
        auto hp = getHP();
        
        // 构建巡逻路径
        std::vector<geometry_msgs::msg::PoseStamped> waypoints;
        
        if (hp > 200) {  // 高 HP：进攻型巡逻
            waypoints = {
                createPose(2.0, 2.0, 0.0),      // 途径点 1
                createPose(4.0, 2.0, M_PI_2),   // 途径点 2
                createPose(4.0, 4.0, M_PI),     // 最终位置
            };
        } else {  // 低 HP：防守型巡逻
            waypoints = {
                createPose(-2.0, -2.0, 0.0),
                createPose(-4.0, -2.0, M_PI_2),
                createPose(-4.0, -4.0, M_PI),
            };
        }
        
        // 输出
        setOutput<std::vector<geometry_msgs::msg::PoseStamped>>("waypoint_list", waypoints);
        setOutput<geometry_msgs::msg::PoseStamped>("goal_pose", waypoints.back());
        
        return BT::NodeStatus::SUCCESS;
    }
    
private:
    geometry_msgs::msg::PoseStamped createPose(double x, double y, double yaw) {
        geometry_msgs::msg::PoseStamped pose;
        pose.header.frame_id = "map";
        pose.pose.position.x = x;
        pose.pose.position.y = y;
        pose.pose.orientation = createQuaternion(yaw);
        return pose;
    }
};
```

### 层次 2：中等改动（自定义 BT 节点）

**概念：** 创建一个新的 BT 节点 `NavigateThroughWaypoints`，直接在 BT 中处理容差

#### 步骤 1：创建 BT 节点

在 `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/plugins/action/` 中创建新文件：

`navigate_through_waypoints_node.cpp`

```cpp
#include "behaviortree_cpp/action_node.h"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "nav2_msgs/action/navigate_to_pose.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using NavigateToPose = nav2_msgs::action::NavigateToPose;
using GoalHandleNavigateToPose = rclcpp_action::ClientGoalHandle<NavigateToPose>;

class NavigateThroughWaypoints : public BT::AsyncActionNode {
public:
    NavigateThroughWaypoints(const std::string& name, 
                            const BT::NodeConfig& config,
                            rclcpp::Node::SharedPtr ros_node)
        : BT::AsyncActionNode(name, config), 
          node_(ros_node) {
        
        action_client_ = rclcpp_action::create_client<NavigateToPose>(
            node_, "navigate_to_pose");
    }
    
    static BT::PortsList providedPorts() {
        return {
            BT::InputPort<std::vector<geometry_msgs::msg::PoseStamped>>("poses"),
            BT::InputPort<double>("waypoint_tolerance", 1.0),
            BT::InputPort<double>("final_goal_tolerance", 0.25),
        };
    }
    
    BT::NodeStatus tick() override {
        auto poses = getInput<std::vector<geometry_msgs::msg::PoseStamped>>("poses");
        auto wp_tol = getInput<double>("waypoint_tolerance");
        auto fg_tol = getInput<double>("final_goal_tolerance");
        
        // 遍历所有途径点
        for (size_t i = 0; i < poses.value().size(); ++i) {
            const auto& pose = poses.value()[i];
            double tolerance = (i == poses.value().size() - 1) ? 
                               fg_tol.value() : wp_tol.value();
            
            // 设置容差并发送目标
            setTolerance(tolerance);
            if (!sendGoal(pose)) {
                return BT::NodeStatus::FAILURE;
            }
        }
        
        return BT::NodeStatus::SUCCESS;
    }
    
private:
    rclcpp::Node::SharedPtr node_;
    rclcpp_action::Client<NavigateToPose>::SharedPtr action_client_;
    
    void setTolerance(double tolerance) {
        // 通过 /controller_server/set_parameters 服务设置
        // ...
    }
    
    bool sendGoal(const geometry_msgs::msg::PoseStamped& pose) {
        // 发送目标并等待完成
        // ...
        return true;
    }
};
```

#### 步骤 2：注册节点

在 `CMakeLists.txt` 中注册：

```cmake
add_library(navigate_through_waypoints_node SHARED
  plugins/action/navigate_through_waypoints_node.cpp)

pluginlib_export_class(
  rm_behavior_tree::NavigateThroughWaypoints
  behaviortree_ros2::BtActionNode)
```

#### 步骤 3：在 hp_patrol_test.xml 中使用

```xml
<root main_tree_to_execute="HPPatrol">
  <BehaviorTree ID="HPPatrol">
    <Sequence>
      <!-- 决策目标位置列表 -->
      <HpDecisionPatrol output_poses="{poses}"/>
      
      <!-- 使用自定义节点导航 -->
      <NavigateThroughWaypoints 
          poses="{poses}"
          waypoint_tolerance="1.0"
          final_goal_tolerance="0.25"/>
      
      <!-- 循环 -->
      <AlwaysRunning/>
    </Sequence>
  </BehaviorTree>
</root>
```

### 层次 3：完全重构（性能优先）

**概念：** 用 Python 节点替代整个 BT，直接实现 HP 决策 + 路径规划

#### 步骤 1：创建完整的 Python 节点

创建 `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/scripts/hp_patrol_controller.py`：

```python
#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from pb_rm_interfaces.msg import AllyRobotHP
import asyncio
from rm_nav_bringup.navigate_through_waypoints import NavigateThroughWaypoints

class HPPatrolController(Node):
    """综合 HP 决策和多途径点导航"""
    
    def __init__(self):
        super().__init__('hp_patrol_controller')
        
        # 订阅 HP 信息
        self.hp_sub = self.create_subscription(
            AllyRobotHP, '/hp_info', self.hp_callback, 10)
        
        # 创建导航器
        self.navigator = NavigateThroughWaypoints()
        self.current_hp = 0
    
    def hp_callback(self, msg: AllyRobotHP):
        """HP 更新回调"""
        self.current_hp = msg.ally_hp
        self.plan_and_navigate()
    
    def plan_and_navigate(self):
        """根据 HP 规划路径并导航"""
        
        if self.current_hp > 200:
            # 高 HP：进攻型巡逻
            waypoints = self.create_offense_patrol_waypoints()
            waypoint_tolerance = 1.0
            final_goal_tolerance = 0.25
        else:
            # 低 HP：防守型巡逻
            waypoints = self.create_defense_patrol_waypoints()
            waypoint_tolerance = 0.5
            final_goal_tolerance = 0.15
        
        # 执行导航
        success = self.navigator.navigate_through_waypoints(
            waypoints,
            waypoint_tolerance,
            final_goal_tolerance)
        
        if success:
            self.get_logger().info('✓ 巡逻路线完成')
        else:
            self.get_logger().error('✗ 巡逻路线失败，重新规划')
            self.plan_and_navigate()  # 重试
    
    def create_offense_patrol_waypoints(self):
        """创建进攻型巡逻路线"""
        waypoints = []
        
        poses_data = [
            (2.0, 2.0, 0.0),
            (4.0, 2.0, 1.57),
            (4.0, 4.0, 3.14),
        ]
        
        for x, y, yaw in poses_data:
            pose = self.create_pose(x, y, yaw)
            waypoints.append(pose)
        
        return waypoints
    
    def create_defense_patrol_waypoints(self):
        """创建防守型巡逻路线"""
        waypoints = []
        
        poses_data = [
            (-2.0, -2.0, 0.0),
            (-4.0, -2.0, 1.57),
            (-4.0, -4.0, 3.14),
        ]
        
        for x, y, yaw in poses_data:
            pose = self.create_pose(x, y, yaw)
            waypoints.append(pose)
        
        return waypoints
    
    @staticmethod
    def create_pose(x: float, y: float, yaw: float) -> PoseStamped:
        """创建位姿消息"""
        pose = PoseStamped()
        pose.header.frame_id = 'map'
        pose.pose.position.x = x
        pose.pose.position.y = y
        
        # 从偏航角创建四元数
        import math
        cy = math.cos(yaw * 0.5)
        sy = math.sin(yaw * 0.5)
        pose.pose.orientation.x = 0.0
        pose.pose.orientation.y = 0.0
        pose.pose.orientation.z = sy
        pose.pose.orientation.w = cy
        
        return pose


def main(args=None):
    rclpy.init(args=args)
    node = HPPatrolController()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
```

---

## 推荐集成方案：层次 1 + 增强

### 配置步骤

#### 1. 更新启动脚本

修改 `/workspaces/srm_auto_sentry/decision.sh`：

```bash
#!/bin/bash

set -e  # 错误时退出

# 获取工作空间路径
WORKSPACE_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 加载 ROS 环境
source /opt/ros/humble/setup.zsh

# 验证导航系统运行
echo "验证导航系统..."
ros2 node list | grep -q "controller_server" || {
    echo "启动导航系统..."
    ros2 launch rm_nav_bringup bringup_launch.py &
    sleep 5
}

# 启动多途径点导航处理器
echo "启动多途径点导航处理器..."
ros2 launch rm_nav_bringup navigate_through_waypoints.launch.py &
sleep 2

# 启动行为树
echo "启动 HP 巡逻行为树..."
ros2 launch rm_behavior_tree rm_behavior_tree.launch.py style:=hp_patrol_test

# 等待
wait
```

#### 2. 修改 hp_patrol_test.xml

创建新版本 `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/config/hp_patrol_test_v2.xml`：

```xml
<root main_tree_to_execute="HPPatrol">
  <BehaviorTree ID="HPPatrol">
    <Repeat times="99999">
      <Sequence>
        <!-- 1. 决策 HP 状态并生成巡逻路线 -->
        <HpDecisionPatrol output_list="{waypoints}"/>
        
        <!-- 2. 等待导航系统就绪 -->
        <Retry num_attempts="3">
          <IsActionServerReady service_name="/navigate_to_pose"/>
        </Retry>
        
        <!-- 3. 执行多途径点导航 -->
        <PublishMessage 
            topic="/hp_patrol_waypoints"
            message_type="geometry_msgs/PoseArray">
          <param name="poses" value="{waypoints}"/>
        </PublishMessage>
        
        <!-- 4. 等待导航完成 -->
        <WaitAction msec="5000"/>
      </Sequence>
    </Repeat>
  </BehaviorTree>
</root>
```

#### 3. 创建容差配置文件

创建 `/workspaces/srm_auto_sentry/src/rm_behavior_tree-master/rm_behavior_tree/config/waypoint_tolerances.yaml`：

```yaml
# HP 巡逻容差配置

hp_high_threshold: 200
hp_low_threshold: 100

# 进攻型（HP > 200）
offense_patrol:
  waypoint_tolerance: 1.0      # 1 米
  final_goal_tolerance: 0.25   # 25 厘米
  speed: "fast"
  timeout: 30.0  # 秒

# 标准型（100 < HP <= 200）
standard_patrol:
  waypoint_tolerance: 0.75
  final_goal_tolerance: 0.2
  speed: "normal"
  timeout: 40.0

# 防守型（HP <= 100）
defense_patrol:
  waypoint_tolerance: 0.5
  final_goal_tolerance: 0.15
  speed: "slow"
  timeout: 50.0
```

---

## 验证检查清单

### 前置条件检查

- [ ] Nav2 导航系统正确启动
- [ ] `/controller_server` 节点运行
- [ ] `/navigate_to_pose` action server 可用
- [ ] `/hp_info` topic 发布 HP 数据

### 功能检查

```bash
# 1. 检查 action server
ros2 action list | grep navigate_to_pose

# 2. 检查参数
ros2 param get /controller_server general_goal_checker.xy_goal_tolerance

# 3. 测试手动导航
ros2 action send_goal /navigate_to_pose nav2_msgs/action/NavigateToPose \
  '{pose: {header: {frame_id: "map"}, pose: {position: {x: 1.0, y: 1.0}, orientation: {w: 1.0}}}}'

# 4. 检查 HP 订阅
ros2 topic echo /hp_info
```

### 功能测试

```bash
# 1. 启动导航
ros2 launch rm_nav_bringup bringup_launch.py

# 2. 在新终端启动多途径点导航
ros2 launch rm_nav_bringup navigate_through_waypoints.launch.py

# 3. 在新终端启动行为树
ros2 launch rm_behavior_tree rm_behavior_tree.launch.py style:=hp_patrol_test_v2

# 4. 模拟 HP 变化（可选）
ros2 topic pub /hp_info pb_rm_interfaces/msg/AllyRobotHP '{ally_hp: 250}'
```

---

## 故障排除

### 问题 1：容差设置不生效

```bash
# 检查服务调用
ros2 service call /controller_server/set_parameters rcl_interfaces/srv/SetParameters \
  '{parameters: [{name: "general_goal_checker.xy_goal_tolerance", value: {type: 3, double_value: 1.0}}]}'
```

### 问题 2：行为树无法找到节点

```bash
# 检查已注册的 BT 节点
ros2 run behaviortree_cpp list_registered_nodes
```

### 问题 3：多途径点导航服务超时

```bash
# 增加超时时间
ros2 param set /navigate_through_waypoints goal_checker_service_timeout 2.0
```

---

## 性能优化建议

1. **容差优化**
   - 进攻型：途径点 1.0m，最终 0.25m
   - 防守型：途径点 0.5m，最终 0.15m

2. **导航参数微调**
   ```yaml
   controller_server:
     plugins: ["FollowPath"]
     FollowPath:
       plugin: "nav2_teb_local_planner::TebLocalPlannerROS"
       teb_autosize: True
       obstacle_cost_margin: 0.5
   ```

3. **监控和日志**
   ```bash
   # 启用调试日志
   ros2 run rm_behavior_tree hp_patrol_controller --ros-args --log-level DEBUG
   ```

---

## 参考资源

- [Nav2 参数文档](https://nav2.readthedocs.io/en/humble/configuration/)
- [BehaviorTree.CPP 教程](https://www.behaviortree.dev/)
- [ROS 2 Action 指南](https://docs.ros.org/en/humble/Tutorials/Intermediate/Writing-an-Action-Server-Client.html)
