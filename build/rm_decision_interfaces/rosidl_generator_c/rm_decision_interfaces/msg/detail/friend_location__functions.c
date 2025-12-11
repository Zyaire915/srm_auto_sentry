// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_decision_interfaces:msg/FriendLocation.idl
// generated code does not contain a copyright notice
#include "rm_decision_interfaces/msg/detail/friend_location__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_decision_interfaces__msg__FriendLocation__init(rm_decision_interfaces__msg__FriendLocation * msg)
{
  if (!msg) {
    return false;
  }
  // hero_x
  // hero_y
  // engineer_x
  // engineer_y
  // standard_3_x
  // standard_3_y
  // standard_4_x
  // standard_4_y
  // standard_5_x
  // standard_5_y
  return true;
}

void
rm_decision_interfaces__msg__FriendLocation__fini(rm_decision_interfaces__msg__FriendLocation * msg)
{
  if (!msg) {
    return;
  }
  // hero_x
  // hero_y
  // engineer_x
  // engineer_y
  // standard_3_x
  // standard_3_y
  // standard_4_x
  // standard_4_y
  // standard_5_x
  // standard_5_y
}

bool
rm_decision_interfaces__msg__FriendLocation__are_equal(const rm_decision_interfaces__msg__FriendLocation * lhs, const rm_decision_interfaces__msg__FriendLocation * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // hero_x
  if (lhs->hero_x != rhs->hero_x) {
    return false;
  }
  // hero_y
  if (lhs->hero_y != rhs->hero_y) {
    return false;
  }
  // engineer_x
  if (lhs->engineer_x != rhs->engineer_x) {
    return false;
  }
  // engineer_y
  if (lhs->engineer_y != rhs->engineer_y) {
    return false;
  }
  // standard_3_x
  if (lhs->standard_3_x != rhs->standard_3_x) {
    return false;
  }
  // standard_3_y
  if (lhs->standard_3_y != rhs->standard_3_y) {
    return false;
  }
  // standard_4_x
  if (lhs->standard_4_x != rhs->standard_4_x) {
    return false;
  }
  // standard_4_y
  if (lhs->standard_4_y != rhs->standard_4_y) {
    return false;
  }
  // standard_5_x
  if (lhs->standard_5_x != rhs->standard_5_x) {
    return false;
  }
  // standard_5_y
  if (lhs->standard_5_y != rhs->standard_5_y) {
    return false;
  }
  return true;
}

bool
rm_decision_interfaces__msg__FriendLocation__copy(
  const rm_decision_interfaces__msg__FriendLocation * input,
  rm_decision_interfaces__msg__FriendLocation * output)
{
  if (!input || !output) {
    return false;
  }
  // hero_x
  output->hero_x = input->hero_x;
  // hero_y
  output->hero_y = input->hero_y;
  // engineer_x
  output->engineer_x = input->engineer_x;
  // engineer_y
  output->engineer_y = input->engineer_y;
  // standard_3_x
  output->standard_3_x = input->standard_3_x;
  // standard_3_y
  output->standard_3_y = input->standard_3_y;
  // standard_4_x
  output->standard_4_x = input->standard_4_x;
  // standard_4_y
  output->standard_4_y = input->standard_4_y;
  // standard_5_x
  output->standard_5_x = input->standard_5_x;
  // standard_5_y
  output->standard_5_y = input->standard_5_y;
  return true;
}

rm_decision_interfaces__msg__FriendLocation *
rm_decision_interfaces__msg__FriendLocation__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__FriendLocation * msg = (rm_decision_interfaces__msg__FriendLocation *)allocator.allocate(sizeof(rm_decision_interfaces__msg__FriendLocation), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_decision_interfaces__msg__FriendLocation));
  bool success = rm_decision_interfaces__msg__FriendLocation__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_decision_interfaces__msg__FriendLocation__destroy(rm_decision_interfaces__msg__FriendLocation * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_decision_interfaces__msg__FriendLocation__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_decision_interfaces__msg__FriendLocation__Sequence__init(rm_decision_interfaces__msg__FriendLocation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__FriendLocation * data = NULL;

  if (size) {
    data = (rm_decision_interfaces__msg__FriendLocation *)allocator.zero_allocate(size, sizeof(rm_decision_interfaces__msg__FriendLocation), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_decision_interfaces__msg__FriendLocation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_decision_interfaces__msg__FriendLocation__fini(&data[i - 1]);
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
rm_decision_interfaces__msg__FriendLocation__Sequence__fini(rm_decision_interfaces__msg__FriendLocation__Sequence * array)
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
      rm_decision_interfaces__msg__FriendLocation__fini(&array->data[i]);
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

rm_decision_interfaces__msg__FriendLocation__Sequence *
rm_decision_interfaces__msg__FriendLocation__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__FriendLocation__Sequence * array = (rm_decision_interfaces__msg__FriendLocation__Sequence *)allocator.allocate(sizeof(rm_decision_interfaces__msg__FriendLocation__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_decision_interfaces__msg__FriendLocation__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_decision_interfaces__msg__FriendLocation__Sequence__destroy(rm_decision_interfaces__msg__FriendLocation__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_decision_interfaces__msg__FriendLocation__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_decision_interfaces__msg__FriendLocation__Sequence__are_equal(const rm_decision_interfaces__msg__FriendLocation__Sequence * lhs, const rm_decision_interfaces__msg__FriendLocation__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_decision_interfaces__msg__FriendLocation__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_decision_interfaces__msg__FriendLocation__Sequence__copy(
  const rm_decision_interfaces__msg__FriendLocation__Sequence * input,
  rm_decision_interfaces__msg__FriendLocation__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_decision_interfaces__msg__FriendLocation);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_decision_interfaces__msg__FriendLocation * data =
      (rm_decision_interfaces__msg__FriendLocation *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_decision_interfaces__msg__FriendLocation__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_decision_interfaces__msg__FriendLocation__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_decision_interfaces__msg__FriendLocation__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
