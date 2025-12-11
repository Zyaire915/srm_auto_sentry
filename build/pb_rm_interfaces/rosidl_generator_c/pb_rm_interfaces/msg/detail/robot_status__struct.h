// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RobotStatus in the package pb_rm_interfaces.
/**
  * RobotStatus.msg
 */
typedef struct pb_rm_interfaces__msg__RobotStatus
{
  uint8_t robot_id;
  uint16_t current_hp;
  uint16_t maximum_hp;
  uint16_t shooter_17mm_1_barrel_heat;
} pb_rm_interfaces__msg__RobotStatus;

// Struct for a sequence of pb_rm_interfaces__msg__RobotStatus.
typedef struct pb_rm_interfaces__msg__RobotStatus__Sequence
{
  pb_rm_interfaces__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pb_rm_interfaces__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
