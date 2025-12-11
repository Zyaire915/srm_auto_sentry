// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/GameRobotHP.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GAME_ROBOT_HP__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__GAME_ROBOT_HP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/GameRobotHP in the package pb_rm_interfaces.
/**
  * GameRobotHP.msg
 */
typedef struct pb_rm_interfaces__msg__GameRobotHP
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
} pb_rm_interfaces__msg__GameRobotHP;

// Struct for a sequence of pb_rm_interfaces__msg__GameRobotHP.
typedef struct pb_rm_interfaces__msg__GameRobotHP__Sequence
{
  pb_rm_interfaces__msg__GameRobotHP * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__GameRobotHP__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GAME_ROBOT_HP__STRUCT_H_
