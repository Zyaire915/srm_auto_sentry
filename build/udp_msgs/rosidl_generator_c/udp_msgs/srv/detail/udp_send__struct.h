// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from udp_msgs:srv/UdpSend.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__SRV__DETAIL__UDP_SEND__STRUCT_H_
#define UDP_MSGS__SRV__DETAIL__UDP_SEND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'local_address'
// Member 'remote_address'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/UdpSend in the package udp_msgs.
typedef struct udp_msgs__srv__UdpSend_Request
{
  rosidl_runtime_c__String local_address;
  uint16_t local_port;
  rosidl_runtime_c__String remote_address;
  uint16_t remote_port;
  rosidl_runtime_c__uint8__Sequence data;
} udp_msgs__srv__UdpSend_Request;

// Struct for a sequence of udp_msgs__srv__UdpSend_Request.
typedef struct udp_msgs__srv__UdpSend_Request__Sequence
{
  udp_msgs__srv__UdpSend_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} udp_msgs__srv__UdpSend_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/UdpSend in the package udp_msgs.
typedef struct udp_msgs__srv__UdpSend_Response
{
  bool sent;
} udp_msgs__srv__UdpSend_Response;

// Struct for a sequence of udp_msgs__srv__UdpSend_Response.
typedef struct udp_msgs__srv__UdpSend_Response__Sequence
{
  udp_msgs__srv__UdpSend_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} udp_msgs__srv__UdpSend_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UDP_MSGS__SRV__DETAIL__UDP_SEND__STRUCT_H_
