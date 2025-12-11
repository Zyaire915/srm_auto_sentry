// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from udp_msgs:msg/UdpPacket.idl
// generated code does not contain a copyright notice
#include "udp_msgs/msg/detail/udp_packet__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `address`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
udp_msgs__msg__UdpPacket__init(udp_msgs__msg__UdpPacket * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    udp_msgs__msg__UdpPacket__fini(msg);
    return false;
  }
  // address
  if (!rosidl_runtime_c__String__init(&msg->address)) {
    udp_msgs__msg__UdpPacket__fini(msg);
    return false;
  }
  // src_port
  // data
  if (!rosidl_runtime_c__uint8__Sequence__init(&msg->data, 0)) {
    udp_msgs__msg__UdpPacket__fini(msg);
    return false;
  }
  return true;
}

void
udp_msgs__msg__UdpPacket__fini(udp_msgs__msg__UdpPacket * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // address
  rosidl_runtime_c__String__fini(&msg->address);
  // src_port
  // data
  rosidl_runtime_c__uint8__Sequence__fini(&msg->data);
}

bool
udp_msgs__msg__UdpPacket__are_equal(const udp_msgs__msg__UdpPacket * lhs, const udp_msgs__msg__UdpPacket * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // address
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->address), &(rhs->address)))
  {
    return false;
  }
  // src_port
  if (lhs->src_port != rhs->src_port) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__uint8__Sequence__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  return true;
}

bool
udp_msgs__msg__UdpPacket__copy(
  const udp_msgs__msg__UdpPacket * input,
  udp_msgs__msg__UdpPacket * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // address
  if (!rosidl_runtime_c__String__copy(
      &(input->address), &(output->address)))
  {
    return false;
  }
  // src_port
  output->src_port = input->src_port;
  // data
  if (!rosidl_runtime_c__uint8__Sequence__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  return true;
}

udp_msgs__msg__UdpPacket *
udp_msgs__msg__UdpPacket__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__msg__UdpPacket * msg = (udp_msgs__msg__UdpPacket *)allocator.allocate(sizeof(udp_msgs__msg__UdpPacket), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(udp_msgs__msg__UdpPacket));
  bool success = udp_msgs__msg__UdpPacket__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
udp_msgs__msg__UdpPacket__destroy(udp_msgs__msg__UdpPacket * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    udp_msgs__msg__UdpPacket__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
udp_msgs__msg__UdpPacket__Sequence__init(udp_msgs__msg__UdpPacket__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__msg__UdpPacket * data = NULL;

  if (size) {
    data = (udp_msgs__msg__UdpPacket *)allocator.zero_allocate(size, sizeof(udp_msgs__msg__UdpPacket), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = udp_msgs__msg__UdpPacket__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        udp_msgs__msg__UdpPacket__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
udp_msgs__msg__UdpPacket__Sequence__fini(udp_msgs__msg__UdpPacket__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      udp_msgs__msg__UdpPacket__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

udp_msgs__msg__UdpPacket__Sequence *
udp_msgs__msg__UdpPacket__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__msg__UdpPacket__Sequence * array = (udp_msgs__msg__UdpPacket__Sequence *)allocator.allocate(sizeof(udp_msgs__msg__UdpPacket__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = udp_msgs__msg__UdpPacket__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
udp_msgs__msg__UdpPacket__Sequence__destroy(udp_msgs__msg__UdpPacket__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    udp_msgs__msg__UdpPacket__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
udp_msgs__msg__UdpPacket__Sequence__are_equal(const udp_msgs__msg__UdpPacket__Sequence * lhs, const udp_msgs__msg__UdpPacket__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!udp_msgs__msg__UdpPacket__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
udp_msgs__msg__UdpPacket__Sequence__copy(
  const udp_msgs__msg__UdpPacket__Sequence * input,
  udp_msgs__msg__UdpPacket__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(udp_msgs__msg__UdpPacket);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    udp_msgs__msg__UdpPacket * data =
      (udp_msgs__msg__UdpPacket *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!udp_msgs__msg__UdpPacket__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          udp_msgs__msg__UdpPacket__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!udp_msgs__msg__UdpPacket__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
