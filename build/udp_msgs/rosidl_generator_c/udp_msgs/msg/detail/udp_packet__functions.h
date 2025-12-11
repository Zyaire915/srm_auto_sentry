// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from udp_msgs:msg/UdpPacket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__MSG__DETAIL__UDP_PACKET__FUNCTIONS_H_
#define UDP_MSGS__MSG__DETAIL__UDP_PACKET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "udp_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "udp_msgs/msg/detail/udp_packet__struct.h"

/// Initialize msg/UdpPacket message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * udp_msgs__msg__UdpPacket
 * )) before or use
 * udp_msgs__msg__UdpPacket__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__msg__UdpPacket__init(udp_msgs__msg__UdpPacket * msg);

/// Finalize msg/UdpPacket message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__msg__UdpPacket__fini(udp_msgs__msg__UdpPacket * msg);

/// Create msg/UdpPacket message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * udp_msgs__msg__UdpPacket__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
udp_msgs__msg__UdpPacket *
udp_msgs__msg__UdpPacket__create();

/// Destroy msg/UdpPacket message.
/**
 * It calls
 * udp_msgs__msg__UdpPacket__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__msg__UdpPacket__destroy(udp_msgs__msg__UdpPacket * msg);

/// Check for msg/UdpPacket message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__msg__UdpPacket__are_equal(const udp_msgs__msg__UdpPacket * lhs, const udp_msgs__msg__UdpPacket * rhs);

/// Copy a msg/UdpPacket message.
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
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__msg__UdpPacket__copy(
  const udp_msgs__msg__UdpPacket * input,
  udp_msgs__msg__UdpPacket * output);

/// Initialize array of msg/UdpPacket messages.
/**
 * It allocates the memory for the number of elements and calls
 * udp_msgs__msg__UdpPacket__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__msg__UdpPacket__Sequence__init(udp_msgs__msg__UdpPacket__Sequence * array, size_t size);

/// Finalize array of msg/UdpPacket messages.
/**
 * It calls
 * udp_msgs__msg__UdpPacket__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__msg__UdpPacket__Sequence__fini(udp_msgs__msg__UdpPacket__Sequence * array);

/// Create array of msg/UdpPacket messages.
/**
 * It allocates the memory for the array and calls
 * udp_msgs__msg__UdpPacket__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
udp_msgs__msg__UdpPacket__Sequence *
udp_msgs__msg__UdpPacket__Sequence__create(size_t size);

/// Destroy array of msg/UdpPacket messages.
/**
 * It calls
 * udp_msgs__msg__UdpPacket__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__msg__UdpPacket__Sequence__destroy(udp_msgs__msg__UdpPacket__Sequence * array);

/// Check for msg/UdpPacket message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__msg__UdpPacket__Sequence__are_equal(const udp_msgs__msg__UdpPacket__Sequence * lhs, const udp_msgs__msg__UdpPacket__Sequence * rhs);

/// Copy an array of msg/UdpPacket messages.
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
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__msg__UdpPacket__Sequence__copy(
  const udp_msgs__msg__UdpPacket__Sequence * input,
  udp_msgs__msg__UdpPacket__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UDP_MSGS__MSG__DETAIL__UDP_PACKET__FUNCTIONS_H_
