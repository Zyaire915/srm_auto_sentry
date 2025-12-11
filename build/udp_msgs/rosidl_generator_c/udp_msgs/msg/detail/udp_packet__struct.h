// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from udp_msgs:msg/UdpPacket.idl
// generated code does not contain a copyright notice

#ifndef UDP_MSGS__MSG__DETAIL__UDP_PACKET__STRUCT_H_
#define UDP_MSGS__MSG__DETAIL__UDP_PACKET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'address'
#include "rosidl_runtime_c/string.h"
// Member 'data'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/UdpPacket in the package udp_msgs.
typedef struct udp_msgs__msg__UdpPacket
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String address;
  uint16_t src_port;
  rosidl_runtime_c__uint8__Sequence data;
} udp_msgs__msg__UdpPacket;

// Struct for a sequence of udp_msgs__msg__UdpPacket.
typedef struct udp_msgs__msg__UdpPacket__Sequence
{
  udp_msgs__msg__UdpPacket * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} udp_msgs__msg__UdpPacket__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // UDP_MSGS__MSG__DETAIL__UDP_PACKET__STRUCT_H_
