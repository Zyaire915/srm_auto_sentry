// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rm_decision_interfaces:msg/DecisionNum.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__STRUCT_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/DecisionNum in the package rm_decision_interfaces.
typedef struct rm_decision_interfaces__msg__DecisionNum
{
  /// 拨杆选择决策模式
  uint8_t decision_num;
} rm_decision_interfaces__msg__DecisionNum;

// Struct for a sequence of rm_decision_interfaces__msg__DecisionNum.
typedef struct rm_decision_interfaces__msg__DecisionNum__Sequence
{
  rm_decision_interfaces__msg__DecisionNum * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rm_decision_interfaces__msg__DecisionNum__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__STRUCT_H_
