// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from udp_msgs:srv/UdpSocket.idl
// generated code does not contain a copyright notice
#include "udp_msgs/srv/detail/udp_socket__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `local_address`
// Member `remote_address`
#include "rosidl_runtime_c/string_functions.h"

bool
udp_msgs__srv__UdpSocket_Request__init(udp_msgs__srv__UdpSocket_Request * msg)
{
  if (!msg) {
    return false;
  }
  // local_address
  if (!rosidl_runtime_c__String__init(&msg->local_address)) {
    udp_msgs__srv__UdpSocket_Request__fini(msg);
    return false;
  }
  // local_port
  // remote_address
  if (!rosidl_runtime_c__String__init(&msg->remote_address)) {
    udp_msgs__srv__UdpSocket_Request__fini(msg);
    return false;
  }
  // remote_port
  // is_broadcast
  return true;
}

void
udp_msgs__srv__UdpSocket_Request__fini(udp_msgs__srv__UdpSocket_Request * msg)
{
  if (!msg) {
    return;
  }
  // local_address
  rosidl_runtime_c__String__fini(&msg->local_address);
  // local_port
  // remote_address
  rosidl_runtime_c__String__fini(&msg->remote_address);
  // remote_port
  // is_broadcast
}

bool
udp_msgs__srv__UdpSocket_Request__are_equal(const udp_msgs__srv__UdpSocket_Request * lhs, const udp_msgs__srv__UdpSocket_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // local_address
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->local_address), &(rhs->local_address)))
  {
    return false;
  }
  // local_port
  if (lhs->local_port != rhs->local_port) {
    return false;
  }
  // remote_address
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->remote_address), &(rhs->remote_address)))
  {
    return false;
  }
  // remote_port
  if (lhs->remote_port != rhs->remote_port) {
    return false;
  }
  // is_broadcast
  if (lhs->is_broadcast != rhs->is_broadcast) {
    return false;
  }
  return true;
}

bool
udp_msgs__srv__UdpSocket_Request__copy(
  const udp_msgs__srv__UdpSocket_Request * input,
  udp_msgs__srv__UdpSocket_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // local_address
  if (!rosidl_runtime_c__String__copy(
      &(input->local_address), &(output->local_address)))
  {
    return false;
  }
  // local_port
  output->local_port = input->local_port;
  // remote_address
  if (!rosidl_runtime_c__String__copy(
      &(input->remote_address), &(output->remote_address)))
  {
    return false;
  }
  // remote_port
  output->remote_port = input->remote_port;
  // is_broadcast
  output->is_broadcast = input->is_broadcast;
  return true;
}

udp_msgs__srv__UdpSocket_Request *
udp_msgs__srv__UdpSocket_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__srv__UdpSocket_Request * msg = (udp_msgs__srv__UdpSocket_Request *)allocator.allocate(sizeof(udp_msgs__srv__UdpSocket_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(udp_msgs__srv__UdpSocket_Request));
  bool success = udp_msgs__srv__UdpSocket_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
udp_msgs__srv__UdpSocket_Request__destroy(udp_msgs__srv__UdpSocket_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    udp_msgs__srv__UdpSocket_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
udp_msgs__srv__UdpSocket_Request__Sequence__init(udp_msgs__srv__UdpSocket_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__srv__UdpSocket_Request * data = NULL;

  if (size) {
    data = (udp_msgs__srv__UdpSocket_Request *)allocator.zero_allocate(size, sizeof(udp_msgs__srv__UdpSocket_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = udp_msgs__srv__UdpSocket_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        udp_msgs__srv__UdpSocket_Request__fini(&data[i - 1]);
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
udp_msgs__srv__UdpSocket_Request__Sequence__fini(udp_msgs__srv__UdpSocket_Request__Sequence * array)
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
      udp_msgs__srv__UdpSocket_Request__fini(&array->data[i]);
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

udp_msgs__srv__UdpSocket_Request__Sequence *
udp_msgs__srv__UdpSocket_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__srv__UdpSocket_Request__Sequence * array = (udp_msgs__srv__UdpSocket_Request__Sequence *)allocator.allocate(sizeof(udp_msgs__srv__UdpSocket_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = udp_msgs__srv__UdpSocket_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
udp_msgs__srv__UdpSocket_Request__Sequence__destroy(udp_msgs__srv__UdpSocket_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    udp_msgs__srv__UdpSocket_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
udp_msgs__srv__UdpSocket_Request__Sequence__are_equal(const udp_msgs__srv__UdpSocket_Request__Sequence * lhs, const udp_msgs__srv__UdpSocket_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!udp_msgs__srv__UdpSocket_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
udp_msgs__srv__UdpSocket_Request__Sequence__copy(
  const udp_msgs__srv__UdpSocket_Request__Sequence * input,
  udp_msgs__srv__UdpSocket_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(udp_msgs__srv__UdpSocket_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    udp_msgs__srv__UdpSocket_Request * data =
      (udp_msgs__srv__UdpSocket_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!udp_msgs__srv__UdpSocket_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          udp_msgs__srv__UdpSocket_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!udp_msgs__srv__UdpSocket_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
udp_msgs__srv__UdpSocket_Response__init(udp_msgs__srv__UdpSocket_Response * msg)
{
  if (!msg) {
    return false;
  }
  // socket_created
  return true;
}

void
udp_msgs__srv__UdpSocket_Response__fini(udp_msgs__srv__UdpSocket_Response * msg)
{
  if (!msg) {
    return;
  }
  // socket_created
}

bool
udp_msgs__srv__UdpSocket_Response__are_equal(const udp_msgs__srv__UdpSocket_Response * lhs, const udp_msgs__srv__UdpSocket_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // socket_created
  if (lhs->socket_created != rhs->socket_created) {
    return false;
  }
  return true;
}

bool
udp_msgs__srv__UdpSocket_Response__copy(
  const udp_msgs__srv__UdpSocket_Response * input,
  udp_msgs__srv__UdpSocket_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // socket_created
  output->socket_created = input->socket_created;
  return true;
}

udp_msgs__srv__UdpSocket_Response *
udp_msgs__srv__UdpSocket_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__srv__UdpSocket_Response * msg = (udp_msgs__srv__UdpSocket_Response *)allocator.allocate(sizeof(udp_msgs__srv__UdpSocket_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(udp_msgs__srv__UdpSocket_Response));
  bool success = udp_msgs__srv__UdpSocket_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
udp_msgs__srv__UdpSocket_Response__destroy(udp_msgs__srv__UdpSocket_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    udp_msgs__srv__UdpSocket_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
udp_msgs__srv__UdpSocket_Response__Sequence__init(udp_msgs__srv__UdpSocket_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__srv__UdpSocket_Response * data = NULL;

  if (size) {
    data = (udp_msgs__srv__UdpSocket_Response *)allocator.zero_allocate(size, sizeof(udp_msgs__srv__UdpSocket_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = udp_msgs__srv__UdpSocket_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        udp_msgs__srv__UdpSocket_Response__fini(&data[i - 1]);
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
udp_msgs__srv__UdpSocket_Response__Sequence__fini(udp_msgs__srv__UdpSocket_Response__Sequence * array)
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
      udp_msgs__srv__UdpSocket_Response__fini(&array->data[i]);
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

udp_msgs__srv__UdpSocket_Response__Sequence *
udp_msgs__srv__UdpSocket_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  udp_msgs__srv__UdpSocket_Response__Sequence * array = (udp_msgs__srv__UdpSocket_Response__Sequence *)allocator.allocate(sizeof(udp_msgs__srv__UdpSocket_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = udp_msgs__srv__UdpSocket_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
udp_msgs__srv__UdpSocket_Response__Sequence__destroy(udp_msgs__srv__UdpSocket_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    udp_msgs__srv__UdpSocket_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
udp_msgs__srv__UdpSocket_Response__Sequence__are_equal(const udp_msgs__srv__UdpSocket_Response__Sequence * lhs, const udp_msgs__srv__UdpSocket_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!udp_msgs__srv__UdpSocket_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
udp_msgs__srv__UdpSocket_Response__Sequence__copy(
  const udp_msgs__srv__UdpSocket_Response__Sequence * input,
  udp_msgs__srv__UdpSocket_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(udp_msgs__srv__UdpSocket_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    udp_msgs__srv__UdpSocket_Response * data =
      (udp_msgs__srv__UdpSocket_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!udp_msgs__srv__UdpSocket_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          udp_msgs__srv__UdpSocket_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!udp_msgs__srv__UdpSocket_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
