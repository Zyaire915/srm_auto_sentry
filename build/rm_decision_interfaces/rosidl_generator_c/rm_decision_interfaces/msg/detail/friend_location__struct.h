// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_decision_interfaces:msg/FriendLocation.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__STRUCT_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FriendLocation in the package rm_decision_interfaces.
/**
  * 仅 RMUC 使用
  * v1.6.1 0x020B 地面机器人位置数据
 */
typedef struct rm_decision_interfaces__msg__FriendLocation
{
  double hero_x;
  double hero_y;
  double engineer_x;
  double engineer_y;
  double standard_3_x;
  double standard_3_y;
  double standard_4_x;
  double standard_4_y;
  double standard_5_x;
  double standard_5_y;
} rm_decision_interfaces__msg__FriendLocation;

// Struct for a sequence of rm_decision_interfaces__msg__FriendLocation.
typedef struct rm_decision_interfaces__msg__FriendLocation__Sequence
{
  rm_decision_interfaces__msg__FriendLocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_decision_interfaces__msg__FriendLocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__STRUCT_H_
