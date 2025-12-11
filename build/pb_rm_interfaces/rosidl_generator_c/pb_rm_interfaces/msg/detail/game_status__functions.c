// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pb_rm_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice
#include "pb_rm_interfaces/msg/detail/game_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
pb_rm_interfaces__msg__GameStatus__init(pb_rm_interfaces__msg__GameStatus * msg)
{
  if (!msg) {
    return false;
  }
  // game_type
  // game_progress
  // stage_remain_time
  // sync_time_stamp
  return true;
}

void
pb_rm_interfaces__msg__GameStatus__fini(pb_rm_interfaces__msg__GameStatus * msg)
{
  if (!msg) {
    return;
  }
  // game_type
  // game_progress
  // stage_remain_time
  // sync_time_stamp
}

bool
pb_rm_interfaces__msg__GameStatus__are_equal(const pb_rm_interfaces__msg__GameStatus * lhs, const pb_rm_interfaces__msg__GameStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // game_type
  if (lhs->game_type != rhs->game_type) {
    return false;
  }
  // game_progress
  if (lhs->game_progress != rhs->game_progress) {
    return false;
  }
  // stage_remain_time
  if (lhs->stage_remain_time != rhs->stage_remain_time) {
    return false;
  }
  // sync_time_stamp
  if (lhs->sync_time_stamp != rhs->sync_time_stamp) {
    return false;
  }
  return true;
}

bool
pb_rm_interfaces__msg__GameStatus__copy(
  const pb_rm_interfaces__msg__GameStatus * input,
  pb_rm_interfaces__msg__GameStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // game_type
  output->game_type = input->game_type;
  // game_progress
  output->game_progress = input->game_progress;
  // stage_remain_time
  output->stage_remain_time = input->stage_remain_time;
  // sync_time_stamp
  output->sync_time_stamp = input->sync_time_stamp;
  return true;
}

pb_rm_interfaces__msg__GameStatus *
pb_rm_interfaces__msg__GameStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__GameStatus * msg = (pb_rm_interfaces__msg__GameStatus *)allocator.allocate(sizeof(pb_rm_interfaces__msg__GameStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pb_rm_interfaces__msg__GameStatus));
  bool success = pb_rm_interfaces__msg__GameStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pb_rm_interfaces__msg__GameStatus__destroy(pb_rm_interfaces__msg__GameStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pb_rm_interfaces__msg__GameStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pb_rm_interfaces__msg__GameStatus__Sequence__init(pb_rm_interfaces__msg__GameStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__GameStatus * data = NULL;

  if (size) {
    data = (pb_rm_interfaces__msg__GameStatus *)allocator.zero_allocate(size, sizeof(pb_rm_interfaces__msg__GameStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pb_rm_interfaces__msg__GameStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pb_rm_interfaces__msg__GameStatus__fini(&data[i - 1]);
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
pb_rm_interfaces__msg__GameStatus__Sequence__fini(pb_rm_interfaces__msg__GameStatus__Sequence * array)
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
      pb_rm_interfaces__msg__GameStatus__fini(&array->data[i]);
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

pb_rm_interfaces__msg__GameStatus__Sequence *
pb_rm_interfaces__msg__GameStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pb_rm_interfaces__msg__GameStatus__Sequence * array = (pb_rm_interfaces__msg__GameStatus__Sequence *)allocator.allocate(sizeof(pb_rm_interfaces__msg__GameStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pb_rm_interfaces__msg__GameStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pb_rm_interfaces__msg__GameStatus__Sequence__destroy(pb_rm_interfaces__msg__GameStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pb_rm_interfaces__msg__GameStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pb_rm_interfaces__msg__GameStatus__Sequence__are_equal(const pb_rm_interfaces__msg__GameStatus__Sequence * lhs, const pb_rm_interfaces__msg__GameStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pb_rm_interfaces__msg__GameStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pb_rm_interfaces__msg__GameStatus__Sequence__copy(
  const pb_rm_interfaces__msg__GameStatus__Sequence * input,
  pb_rm_interfaces__msg__GameStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pb_rm_interfaces__msg__GameStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pb_rm_interfaces__msg__GameStatus * data =
      (pb_rm_interfaces__msg__GameStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pb_rm_interfaces__msg__GameStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pb_rm_interfaces__msg__GameStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pb_rm_interfaces__msg__GameStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
