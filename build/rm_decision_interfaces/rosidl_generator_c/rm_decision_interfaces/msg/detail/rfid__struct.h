// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_decision_interfaces:msg/RFID.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__RFID__STRUCT_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__RFID__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/RFID in the package rm_decision_interfaces.
/**
  * v1.6.1 0x0209 机器人RFID状态（此处仅保留我方哨兵巡逻区）
  * 仅用于 RMUC
 */
typedef struct rm_decision_interfaces__msg__RFID
{
  bool rfid_patrol_status;
} rm_decision_interfaces__msg__RFID;

// Struct for a sequence of rm_decision_interfaces__msg__RFID.
typedef struct rm_decision_interfaces__msg__RFID__Sequence
{
  rm_decision_interfaces__msg__RFID * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_decision_interfaces__msg__RFID__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__RFID__STRUCT_H_
