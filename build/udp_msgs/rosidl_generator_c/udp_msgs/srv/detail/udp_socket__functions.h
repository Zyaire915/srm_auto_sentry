// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from udp_msgs:srv/UdpSocket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__SRV__DETAIL__UDP_SOCKET__FUNCTIONS_H_
#define UDP_MSGS__SRV__DETAIL__UDP_SOCKET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "udp_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "udp_msgs/srv/detail/udp_socket__struct.h"

/// Initialize srv/UdpSocket message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * udp_msgs__srv__UdpSocket_Request
 * )) before or use
 * udp_msgs__srv__UdpSocket_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Request__init(udp_msgs__srv__UdpSocket_Request * msg);

/// Finalize srv/UdpSocket message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Request__fini(udp_msgs__srv__UdpSocket_Request * msg);

/// Create srv/UdpSocket message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * udp_msgs__srv__UdpSocket_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
udp_msgs__srv__UdpSocket_Request *
udp_msgs__srv__UdpSocket_Request__create();

/// Destroy srv/UdpSocket message.
/**
 * It calls
 * udp_msgs__srv__UdpSocket_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Request__destroy(udp_msgs__srv__UdpSocket_Request * msg);

/// Check for srv/UdpSocket message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Request__are_equal(const udp_msgs__srv__UdpSocket_Request * lhs, const udp_msgs__srv__UdpSocket_Request * rhs);

/// Copy a srv/UdpSocket message.
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
udp_msgs__srv__UdpSocket_Request__copy(
  const udp_msgs__srv__UdpSocket_Request * input,
  udp_msgs__srv__UdpSocket_Request * output);

/// Initialize array of srv/UdpSocket messages.
/**
 * It allocates the memory for the number of elements and calls
 * udp_msgs__srv__UdpSocket_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Request__Sequence__init(udp_msgs__srv__UdpSocket_Request__Sequence * array, size_t size);

/// Finalize array of srv/UdpSocket messages.
/**
 * It calls
 * udp_msgs__srv__UdpSocket_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Request__Sequence__fini(udp_msgs__srv__UdpSocket_Request__Sequence * array);

/// Create array of srv/UdpSocket messages.
/**
 * It allocates the memory for the array and calls
 * udp_msgs__srv__UdpSocket_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
udp_msgs__srv__UdpSocket_Request__Sequence *
udp_msgs__srv__UdpSocket_Request__Sequence__create(size_t size);

/// Destroy array of srv/UdpSocket messages.
/**
 * It calls
 * udp_msgs__srv__UdpSocket_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Request__Sequence__destroy(udp_msgs__srv__UdpSocket_Request__Sequence * array);

/// Check for srv/UdpSocket message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Request__Sequence__are_equal(const udp_msgs__srv__UdpSocket_Request__Sequence * lhs, const udp_msgs__srv__UdpSocket_Request__Sequence * rhs);

/// Copy an array of srv/UdpSocket messages.
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
udp_msgs__srv__UdpSocket_Request__Sequence__copy(
  const udp_msgs__srv__UdpSocket_Request__Sequence * input,
  udp_msgs__srv__UdpSocket_Request__Sequence * output);

/// Initialize srv/UdpSocket message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * udp_msgs__srv__UdpSocket_Response
 * )) before or use
 * udp_msgs__srv__UdpSocket_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Response__init(udp_msgs__srv__UdpSocket_Response * msg);

/// Finalize srv/UdpSocket message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Response__fini(udp_msgs__srv__UdpSocket_Response * msg);

/// Create srv/UdpSocket message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * udp_msgs__srv__UdpSocket_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
udp_msgs__srv__UdpSocket_Response *
udp_msgs__srv__UdpSocket_Response__create();

/// Destroy srv/UdpSocket message.
/**
 * It calls
 * udp_msgs__srv__UdpSocket_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Response__destroy(udp_msgs__srv__UdpSocket_Response * msg);

/// Check for srv/UdpSocket message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Response__are_equal(const udp_msgs__srv__UdpSocket_Response * lhs, const udp_msgs__srv__UdpSocket_Response * rhs);

/// Copy a srv/UdpSocket message.
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
udp_msgs__srv__UdpSocket_Response__copy(
  const udp_msgs__srv__UdpSocket_Response * input,
  udp_msgs__srv__UdpSocket_Response * output);

/// Initialize array of srv/UdpSocket messages.
/**
 * It allocates the memory for the number of elements and calls
 * udp_msgs__srv__UdpSocket_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Response__Sequence__init(udp_msgs__srv__UdpSocket_Response__Sequence * array, size_t size);

/// Finalize array of srv/UdpSocket messages.
/**
 * It calls
 * udp_msgs__srv__UdpSocket_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Response__Sequence__fini(udp_msgs__srv__UdpSocket_Response__Sequence * array);

/// Create array of srv/UdpSocket messages.
/**
 * It allocates the memory for the array and calls
 * udp_msgs__srv__UdpSocket_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
udp_msgs__srv__UdpSocket_Response__Sequence *
udp_msgs__srv__UdpSocket_Response__Sequence__create(size_t size);

/// Destroy array of srv/UdpSocket messages.
/**
 * It calls
 * udp_msgs__srv__UdpSocket_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
void
udp_msgs__srv__UdpSocket_Response__Sequence__destroy(udp_msgs__srv__UdpSocket_Response__Sequence * array);

/// Check for srv/UdpSocket message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_udp_msgs
bool
udp_msgs__srv__UdpSocket_Response__Sequence__are_equal(const udp_msgs__srv__UdpSocket_Response__Sequence * lhs, const udp_msgs__srv__UdpSocket_Response__Sequence * rhs);

/// Copy an array of srv/UdpSocket messages.
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
udp_msgs__srv__UdpSocket_Response__Sequence__copy(
  const udp_msgs__srv__UdpSocket_Response__Sequence * input,
  udp_msgs__srv__UdpSocket_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // UDP_MSGS__SRV__DETAIL__UDP_SOCKET__FUNCTIONS_H_
