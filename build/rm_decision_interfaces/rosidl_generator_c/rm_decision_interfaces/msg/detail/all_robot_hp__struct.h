// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_decision_interfaces:msg/AllRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__STRUCT_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AllRobotHP in the package rm_decision_interfaces.
/**
  * v1.6.1 0x0003 机器人血量数据
 */
typedef struct rm_decision_interfaces__msg__AllRobotHP
{
  uint16_t red_1_robot_hp;
  uint16_t red_2_robot_hp;
  uint16_t red_3_robot_hp;
  uint16_t red_4_robot_hp;
  uint16_t red_5_robot_hp;
  uint16_t red_7_robot_hp;
  uint16_t red_outpost_hp;
  uint16_t red_base_hp;
  uint16_t blue_1_robot_hp;
  uint16_t blue_2_robot_hp;
  uint16_t blue_3_robot_hp;
  uint16_t blue_4_robot_hp;
  uint16_t blue_5_robot_hp;
  uint16_t blue_7_robot_hp;
  uint16_t blue_outpost_hp;
  uint16_t blue_base_hp;
} rm_decision_interfaces__msg__AllRobotHP;

// Struct for a sequence of rm_decision_interfaces__msg__AllRobotHP.
typedef struct rm_decision_interfaces__msg__AllRobotHP__Sequence
{
  rm_decision_interfaces__msg__AllRobotHP * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_decision_interfaces__msg__AllRobotHP__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__STRUCT_H_
