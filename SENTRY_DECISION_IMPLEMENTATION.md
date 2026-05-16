# RoboMaster 2026 Sentry Decision System - Implementation Guide

## Overview
This document describes the implementation of the two new data packets (0x0208: ProjectileAllowance and 0x000D: SwitchPosition) and the corresponding decision logic for sentry robot behavior.

---

## Task 1: Communication Mechanism (完成✓)

### 1.1 ROS Message Files Created

#### ProjectileAllowance.msg
Location: `/src/standard_robot_pp_ros2-master/src/pb_rm_interfaces/msg/ProjectileAllowance.msg`

```
uint16 projectile_allowance_17mm     # 机器人自身拥有的17mm弹丸允许发弹量
uint16 projectile_allowance_42mm     # 42mm弹丸允许发弹量
uint16 remaining_gold_coin           # 剩余金币数量
uint16 projectile_allowance_fortress # 堡垒增益点提供的储备17mm弹丸允许发弹量
```

#### SwitchPosition.msg
Location: `/src/standard_robot_pp_ros2-master/src/pb_rm_interfaces/msg/SwitchPosition.msg`

```
uint8 switch_position  # 前哨战状态: 0=未打完, 1=已打完
```

### 1.2 C++ Packet Structure Updates

**File**: `/src/standard_robot_pp_ros2-master/src/standard_robot_pp_ros2/include/packet_typedef.hpp`

Added packet ID definitions:
```cpp
const uint16_t ID_PROJECTILE_ALLOWANCE = 0x0208;  // 允许发弹量数据
const uint16_t ID_SWITCH_POSITION = 0x000D;       // 打前哨战与否标志位
```

Added receive wrapper structs:
```cpp
struct ReceiveProjectileAllowance {
  HeaderFrame frame_header;
  uint16_t cmd_id;
  struct {
    uint16_t projectile_allowance_17mm;
    uint16_t projectile_allowance_42mm;
    uint16_t remaining_gold_coin;
    uint16_t projectile_allowance_fortress;
  } __attribute__((packed)) data;
  uint16_t crc;
} __attribute__((packed));

struct ReceiveSwitchPosition {
  HeaderFrame frame_header;
  uint16_t cmd_id;
  struct {
    uint8_t switch_position;
  } __attribute__((packed)) data;
  uint16_t crc;
} __attribute__((packed));
```

### 1.3 ROS Node Updates

**File**: `/src/standard_robot_pp_ros2-master/src/standard_robot_pp_ros2/include/standard_robot_pp_ros2.hpp`

Added publisher declarations:
```cpp
rclcpp::Publisher<pb_rm_interfaces::msg::ProjectileAllowance>::SharedPtr projectile_allowance_pub_;
rclcpp::Publisher<pb_rm_interfaces::msg::SwitchPosition>::SharedPtr switch_position_pub_;
```

Added method declarations:
```cpp
void publishProjectileAllowance(ReceiveProjectileAllowance & data);
void publishSwitchPosition(ReceiveSwitchPosition & data);
```

### 1.4 ROS Node Implementation

**File**: `/src/standard_robot_pp_ros2-master/src/standard_robot_pp_ros2/src/standard_robot_pp_ros2.cpp`

1. **In createPublisher()**:
   ```cpp
   projectile_allowance_pub_ =
     this->create_publisher<pb_rm_interfaces::msg::ProjectileAllowance>("referee/projectile_allowance", 10);
   switch_position_pub_ =
     this->create_publisher<pb_rm_interfaces::msg::SwitchPosition>("referee/switch_position", 10);
   ```

2. **In receiveData() switch statement**:
   ```cpp
   case ID_PROJECTILE_ALLOWANCE: {
     ReceiveProjectileAllowance projectile_allowance_data =
       fromVector<ReceiveProjectileAllowance>(full_packet);
     publishProjectileAllowance(projectile_allowance_data);
   } break;
   
   case ID_SWITCH_POSITION: {
     ReceiveSwitchPosition switch_position_data = fromVector<ReceiveSwitchPosition>(full_packet);
     publishSwitchPosition(switch_position_data);
   } break;
   ```

3. **Publish methods**:
   ```cpp
   void StandardRobotPpRos2Node::publishProjectileAllowance(ReceiveProjectileAllowance & projectile_allowance)
   {
     pb_rm_interfaces::msg::ProjectileAllowance msg;
     msg.projectile_allowance_17mm = projectile_allowance.data.projectile_allowance_17mm;
     msg.projectile_allowance_42mm = projectile_allowance.data.projectile_allowance_42mm;
     msg.remaining_gold_coin = projectile_allowance.data.remaining_gold_coin;
     msg.projectile_allowance_fortress = projectile_allowance.data.projectile_allowance_fortress;
     projectile_allowance_pub_->publish(msg);
   }
   
   void StandardRobotPpRos2Node::publishSwitchPosition(ReceiveSwitchPosition & switch_position)
   {
     pb_rm_interfaces::msg::SwitchPosition msg;
     msg.switch_position = switch_position.data.switch_position;
     switch_position_pub_->publish(msg);
   }
   ```

### 1.5 Published Topics

- **Projectile Allowance**: `/referee/projectile_allowance`
  - Type: `pb_rm_interfaces/msg/ProjectileAllowance`
  - Fields: projectile_allowance_17mm, projectile_allowance_42mm, remaining_gold_coin, projectile_allowance_fortress

- **Switch Position**: `/referee/switch_position`
  - Type: `pb_rm_interfaces/msg/SwitchPosition`
  - Fields: switch_position (0=未打完, 1=已打完)

---

## Task 2: Decision Logic (完成✓)

### 2.1 Strategy Overview

The decision logic is implemented in a Behavior Tree XML configuration that uses the following rules:

```
IF (hp > hp_threshold AND ammo_17mm > ammo_threshold):
    IF switch_position == 0 (outpost not completed):
        GO TO Waypoint A (Occupy/Attack Position)
    ELSE (switch_position == 1, outpost completed):
        GO TO Waypoint B (Defend Position)
ELSE (hp or ammo below thresholds):
    GO TO Waypoint C (Supply/Retreat Area)
```

### 2.2 Configuration File

**File**: `/src/rm_behavior_tree-master/rm_behavior_tree/config/sentry_decision_with_outpost.xml`

#### Configurable Parameters:

1. **Health Threshold** (血量阈值)
   - Location: `IsHealthyAmmo` node, `hp_threshold` attribute
   - Current Value: 250 HP
   - Usage: If current HP < 250, robot goes to supply area

2. **Ammo Threshold** (弹数阈值)
   - Location: `IsHealthyAmmo` node, `ammo_threshold` attribute
   - Current Value: 40 projectiles
   - Usage: If 17mm ammo < 40, robot goes to supply area

3. **Waypoint A** (占据/攻击位置)
   - Location: `Waypoint_A_Occupy` SendGoal node
   - Current Coordinates: x=5.0, y=0.0, z=0
   - Rotation: [0, 0, 0, 1] (identity quaternion)
   - Purpose: Used when outpost is not completed (switch_position = 0)

4. **Waypoint B** (防守位置)
   - Location: `Waypoint_B_Defend` SendGoal node
   - Current Coordinates: x=3.0, y=2.0, z=0
   - Rotation: [0, 0, 0, 1] (identity quaternion)
   - Purpose: Used when outpost is completed (switch_position = 1)

5. **Waypoint C** (补给/撤退区)
   - Location: `Waypoint_C_Supply` SendGoal node
   - Current Coordinates: x=-2.5, y=4.07, z=0
   - Rotation: [0, 0, 0, 1] (identity quaternion)
   - Purpose: Supply area when HP or ammo below thresholds

### 2.3 How to Customize the Configuration

To modify the decision thresholds or waypoint coordinates, edit the XML file:

```xml
<!-- To change HP threshold (default 250) -->
<IsHealthyAmmo hp_message="{sefdefined}"
               ammo_message="{projectile_allowance}"
               hp_threshold="250"           <!-- Change this value -->
               ammo_threshold="40"/>

<!-- To change Waypoint A (default x=5.0, y=0.0) -->
<SendGoal name="Waypoint_A_Occupy"
          goal_pose="5.0;0.0;0; 0;0;0;1"  <!-- Format: x;y;z; qx;qy;qz;qw -->
          action_name="navigate_to_pose"/>

<!-- To change Waypoint B (default x=3.0, y=2.0) -->
<SendGoal name="Waypoint_B_Defend"
          goal_pose="3.0;2.0;0; 0;0;0;1"
          action_name="navigate_to_pose"/>

<!-- To change Waypoint C (default x=-2.5, y=4.07) -->
<SendGoal name="Waypoint_C_Supply"
          goal_pose="-2.5;4.07;0; 0;0;0;1"
          action_name="navigate_to_pose"/>
```

### 2.4 Tree Nodes Used

The behavior tree uses the following custom nodes:

- **IsGameTime**: Check if game is running
- **IsHealthyAmmo**: Check if HP and ammo are both above thresholds
- **IsOutpostNotCompleted**: Check if outpost is not completed (switch_position = 0)
- **SubSefdefined**: Subscribe to robot status (for current HP)
- **SubProjectileAllowance**: Subscribe to projectile allowance (for ammo count)
- **SubSwitchPosition**: Subscribe to outpost status
- **SendGoal**: Send navigation goal to move_base or nav2

---

## 3. Integration Steps

### 3.1 Build the packages
```bash
cd /workspaces/srm_auto_sentry
colcon build --packages-select pb_rm_interfaces standard_robot_pp_ros2 rm_behavior_tree
```

### 3.2 Source the setup
```bash
source install/setup.zsh
```

### 3.3 Run the sentry system

**Option 1: Using the dedicated launch file**
```bash
ros2 launch rm_behavior_tree sentry_decision_with_outpost.launch.py
```

**Option 2: Using the generic launch file with style parameter**
```bash
ros2 launch rm_behavior_tree rm_behavior_tree.launch.py style:=sentry_decision_with_outpost
```

---

## 4. Data Flow Diagram

```
Serial Port (0x0208 & 0x000D packets)
    ↓
standard_robot_pp_ros2 node
    ├→ /referee/projectile_allowance (0x0208)
    ├→ /referee/switch_position (0x000D)
    └→ /referee/sefdefined (0x000B, existing)
    ↓
rm_behavior_tree node (sentry_decision_with_outpost.xml)
    ├→ Decision Logic
    └→ /navigate_to_pose action

Waypoint Selection Logic:
    HP > 250 & Ammo > 40 ?
    ├─ NO → Go to Waypoint C (Supply/Retreat)
    └─ YES
       └─ switch_position == 0 ? 
          ├─ YES (not completed) → Go to Waypoint A (Occupy/Attack)
          └─ NO (completed) → Go to Waypoint B (Defend)
```

---

## 5. Testing Checklist

- [ ] Verify pb_rm_interfaces package builds successfully
- [ ] Verify standard_robot_pp_ros2 compiles and runs
- [ ] Confirm `/referee/projectile_allowance` topic is published
- [ ] Confirm `/referee/switch_position` topic is published
- [ ] Test behavior tree loads sentry_decision_with_outpost.xml
- [ ] Verify robot navigates to Waypoint A when outpost not completed
- [ ] Verify robot navigates to Waypoint B when outpost is completed
- [ ] Verify robot navigates to Waypoint C when HP/ammo below thresholds
- [ ] Adjust waypoint coordinates based on actual map layout
- [ ] Adjust HP/ammo thresholds based on game testing

---

## 6. Notes

- All waypoint coordinates are in the global map frame (x, y, z)
- Rotation is specified as quaternion (qx, qy, qz, qw)
- Default quaternion [0, 0, 0, 1] = identity (0° rotation)
- The XML file can be edited and reloaded without rebuilding
- Current implementation assumes nav2/move_base for navigation
- Thresholds are configurable per competition map

