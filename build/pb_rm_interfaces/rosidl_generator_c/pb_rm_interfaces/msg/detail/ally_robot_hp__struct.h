// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/AllyRobotHP.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/AllyRobotHP in the package pb_rm_interfaces.
/**
  * 对应下位机的 ReceiveAllRobotHpData 结构体中的 data 部分
 */
typedef struct pb_rm_interfaces__msg__AllyRobotHP
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
} pb_rm_interfaces__msg__AllyRobotHP;

// Struct for a sequence of pb_rm_interfaces__msg__AllyRobotHP.
typedef struct pb_rm_interfaces__msg__AllyRobotHP__Sequence
{
  pb_rm_interfaces__msg__AllyRobotHP * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__AllyRobotHP__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__STRUCT_H_
