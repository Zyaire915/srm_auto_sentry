// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_decision_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotStatus in the package rm_decision_interfaces.
/**
  * v1.6.1 0x0201 机器人性能体系数据
 */
typedef struct rm_decision_interfaces__msg__RobotStatus
{
  /// 机器人ID （1~7->红，101~107->蓝
  uint8_t robot_id;
  /// 血量
  uint16_t current_hp;
  /// v1.6.1 0x0202 实时功率热量数据
  /// 枪口热量
  uint16_t shooter_heat;
  /// 经下位机处理后的数据
  /// 队伍颜色 0->红 1->蓝
  bool team_color;
  /// 是否受到攻击 0->未受到攻击 1->受到攻击
  bool is_attacked;
} rm_decision_interfaces__msg__RobotStatus;

// Struct for a sequence of rm_decision_interfaces__msg__RobotStatus.
typedef struct rm_decision_interfaces__msg__RobotStatus__Sequence
{
  rm_decision_interfaces__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_decision_interfaces__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
