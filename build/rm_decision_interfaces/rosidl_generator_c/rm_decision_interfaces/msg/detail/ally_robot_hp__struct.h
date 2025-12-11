// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_decision_interfaces:msg/AllyRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AllyRobotHP in the package rm_decision_interfaces.
/**
  * 对应下位机的 ReceiveAllRobotHpData 结构体中的 data 部分
 */
typedef struct rm_decision_interfaces__msg__AllyRobotHP
{
  uint16_t ally_1_robot_hp;
  uint16_t ally_2_robot_hp;
  uint16_t ally_3_robot_hp;
  uint16_t ally_4_robot_hp;
  /// 5 reserved
  /// 哨兵通常是 7 号
  uint16_t ally_7_robot_hp;
  uint16_t ally_outpost_hp;
  uint16_t ally_base_hp;
} rm_decision_interfaces__msg__AllyRobotHP;

// Struct for a sequence of rm_decision_interfaces__msg__AllyRobotHP.
typedef struct rm_decision_interfaces__msg__AllyRobotHP__Sequence
{
  rm_decision_interfaces__msg__AllyRobotHP * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_decision_interfaces__msg__AllyRobotHP__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_H_
