// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rm_decision_interfaces:msg/GameRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__GAME_ROBOT_HP__FUNCTIONS_H_
#define RM_DECISION_INTERFACES__MSG__DETAIL__GAME_ROBOT_HP__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "rm_decision_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "rm_decision_interfaces/msg/detail/game_robot_hp__struct.h"

/// Initialize msg/GameRobotHP message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rm_decision_interfaces__msg__GameRobotHP
 * )) before or use
 * rm_decision_interfaces__msg__GameRobotHP__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
bool
rm_decision_interfaces__msg__GameRobotHP__init(rm_decision_interfaces__msg__GameRobotHP * msg);

/// Finalize msg/GameRobotHP message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
void
rm_decision_interfaces__msg__GameRobotHP__fini(rm_decision_interfaces__msg__GameRobotHP * msg);

/// Create msg/GameRobotHP message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rm_decision_interfaces__msg__GameRobotHP__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
rm_decision_interfaces__msg__GameRobotHP *
rm_decision_interfaces__msg__GameRobotHP__create();

/// Destroy msg/GameRobotHP message.
/**
 * It calls
 * rm_decision_interfaces__msg__GameRobotHP__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
void
rm_decision_interfaces__msg__GameRobotHP__destroy(rm_decision_interfaces__msg__GameRobotHP * msg);

/// Check for msg/GameRobotHP message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
bool
rm_decision_interfaces__msg__GameRobotHP__are_equal(const rm_decision_interfaces__msg__GameRobotHP * lhs, const rm_decision_interfaces__msg__GameRobotHP * rhs);

/// Copy a msg/GameRobotHP message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
bool
rm_decision_interfaces__msg__GameRobotHP__copy(
  const rm_decision_interfaces__msg__GameRobotHP * input,
  rm_decision_interfaces__msg__GameRobotHP * output);

/// Initialize array of msg/GameRobotHP messages.
/**
 * It allocates the memory for the number of elements and calls
 * rm_decision_interfaces__msg__GameRobotHP__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
bool
rm_decision_interfaces__msg__GameRobotHP__Sequence__init(rm_decision_interfaces__msg__GameRobotHP__Sequence * array, size_t size);

/// Finalize array of msg/GameRobotHP messages.
/**
 * It calls
 * rm_decision_interfaces__msg__GameRobotHP__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
void
rm_decision_interfaces__msg__GameRobotHP__Sequence__fini(rm_decision_interfaces__msg__GameRobotHP__Sequence * array);

/// Create array of msg/GameRobotHP messages.
/**
 * It allocates the memory for the array and calls
 * rm_decision_interfaces__msg__GameRobotHP__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
rm_decision_interfaces__msg__GameRobotHP__Sequence *
rm_decision_interfaces__msg__GameRobotHP__Sequence__create(size_t size);

/// Destroy array of msg/GameRobotHP messages.
/**
 * It calls
 * rm_decision_interfaces__msg__GameRobotHP__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
void
rm_decision_interfaces__msg__GameRobotHP__Sequence__destroy(rm_decision_interfaces__msg__GameRobotHP__Sequence * array);

/// Check for msg/GameRobotHP message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
bool
rm_decision_interfaces__msg__GameRobotHP__Sequence__are_equal(const rm_decision_interfaces__msg__GameRobotHP__Sequence * lhs, const rm_decision_interfaces__msg__GameRobotHP__Sequence * rhs);

/// Copy an array of msg/GameRobotHP messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rm_decision_interfaces
bool
rm_decision_interfaces__msg__GameRobotHP__Sequence__copy(
  const rm_decision_interfaces__msg__GameRobotHP__Sequence * input,
  rm_decision_interfaces__msg__GameRobotHP__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__GAME_ROBOT_HP__FUNCTIONS_H_
