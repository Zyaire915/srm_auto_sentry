// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_decision_interfaces:msg/EventData.idl
// generated code does not contain a copyright notice
#include "rm_decision_interfaces/msg/detail/event_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_decision_interfaces__msg__EventData__init(rm_decision_interfaces__msg__EventData * msg)
{
  if (!msg) {
    return false;
  }
  // supply_zone_non_overlap
  // supply_zone_overlap
  // supply_zone_rmul
  // small_energy_status
  // big_energy_status
  // central_highland_status
  // trapezoidal_highland_status
  // dart_last_hit_time
  // dart_last_hit_target
  // center_gain_point_status
  // fortress_gain_point_status
  // outpost_gain_point_status
  // base_gain_point_status
  return true;
}

void
rm_decision_interfaces__msg__EventData__fini(rm_decision_interfaces__msg__EventData * msg)
{
  if (!msg) {
    return;
  }
  // supply_zone_non_overlap
  // supply_zone_overlap
  // supply_zone_rmul
  // small_energy_status
  // big_energy_status
  // central_highland_status
  // trapezoidal_highland_status
  // dart_last_hit_time
  // dart_last_hit_target
  // center_gain_point_status
  // fortress_gain_point_status
  // outpost_gain_point_status
  // base_gain_point_status
}

bool
rm_decision_interfaces__msg__EventData__are_equal(const rm_decision_interfaces__msg__EventData * lhs, const rm_decision_interfaces__msg__EventData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // supply_zone_non_overlap
  if (lhs->supply_zone_non_overlap != rhs->supply_zone_non_overlap) {
    return false;
  }
  // supply_zone_overlap
  if (lhs->supply_zone_overlap != rhs->supply_zone_overlap) {
    return false;
  }
  // supply_zone_rmul
  if (lhs->supply_zone_rmul != rhs->supply_zone_rmul) {
    return false;
  }
  // small_energy_status
  if (lhs->small_energy_status != rhs->small_energy_status) {
    return false;
  }
  // big_energy_status
  if (lhs->big_energy_status != rhs->big_energy_status) {
    return false;
  }
  // central_highland_status
  if (lhs->central_highland_status != rhs->central_highland_status) {
    return false;
  }
  // trapezoidal_highland_status
  if (lhs->trapezoidal_highland_status != rhs->trapezoidal_highland_status) {
    return false;
  }
  // dart_last_hit_time
  if (lhs->dart_last_hit_time != rhs->dart_last_hit_time) {
    return false;
  }
  // dart_last_hit_target
  if (lhs->dart_last_hit_target != rhs->dart_last_hit_target) {
    return false;
  }
  // center_gain_point_status
  if (lhs->center_gain_point_status != rhs->center_gain_point_status) {
    return false;
  }
  // fortress_gain_point_status
  if (lhs->fortress_gain_point_status != rhs->fortress_gain_point_status) {
    return false;
  }
  // outpost_gain_point_status
  if (lhs->outpost_gain_point_status != rhs->outpost_gain_point_status) {
    return false;
  }
  // base_gain_point_status
  if (lhs->base_gain_point_status != rhs->base_gain_point_status) {
    return false;
  }
  return true;
}

bool
rm_decision_interfaces__msg__EventData__copy(
  const rm_decision_interfaces__msg__EventData * input,
  rm_decision_interfaces__msg__EventData * output)
{
  if (!input || !output) {
    return false;
  }
  // supply_zone_non_overlap
  output->supply_zone_non_overlap = input->supply_zone_non_overlap;
  // supply_zone_overlap
  output->supply_zone_overlap = input->supply_zone_overlap;
  // supply_zone_rmul
  output->supply_zone_rmul = input->supply_zone_rmul;
  // small_energy_status
  output->small_energy_status = input->small_energy_status;
  // big_energy_status
  output->big_energy_status = input->big_energy_status;
  // central_highland_status
  output->central_highland_status = input->central_highland_status;
  // trapezoidal_highland_status
  output->trapezoidal_highland_status = input->trapezoidal_highland_status;
  // dart_last_hit_time
  output->dart_last_hit_time = input->dart_last_hit_time;
  // dart_last_hit_target
  output->dart_last_hit_target = input->dart_last_hit_target;
  // center_gain_point_status
  output->center_gain_point_status = input->center_gain_point_status;
  // fortress_gain_point_status
  output->fortress_gain_point_status = input->fortress_gain_point_status;
  // outpost_gain_point_status
  output->outpost_gain_point_status = input->outpost_gain_point_status;
  // base_gain_point_status
  output->base_gain_point_status = input->base_gain_point_status;
  return true;
}

rm_decision_interfaces__msg__EventData *
rm_decision_interfaces__msg__EventData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__EventData * msg = (rm_decision_interfaces__msg__EventData *)allocator.allocate(sizeof(rm_decision_interfaces__msg__EventData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_decision_interfaces__msg__EventData));
  bool success = rm_decision_interfaces__msg__EventData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_decision_interfaces__msg__EventData__destroy(rm_decision_interfaces__msg__EventData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_decision_interfaces__msg__EventData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_decision_interfaces__msg__EventData__Sequence__init(rm_decision_interfaces__msg__EventData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__EventData * data = NULL;

  if (size) {
    data = (rm_decision_interfaces__msg__EventData *)allocator.zero_allocate(size, sizeof(rm_decision_interfaces__msg__EventData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_decision_interfaces__msg__EventData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_decision_interfaces__msg__EventData__fini(&data[i - 1]);
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
rm_decision_interfaces__msg__EventData__Sequence__fini(rm_decision_interfaces__msg__EventData__Sequence * array)
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
      rm_decision_interfaces__msg__EventData__fini(&array->data[i]);
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

rm_decision_interfaces__msg__EventData__Sequence *
rm_decision_interfaces__msg__EventData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__EventData__Sequence * array = (rm_decision_interfaces__msg__EventData__Sequence *)allocator.allocate(sizeof(rm_decision_interfaces__msg__EventData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_decision_interfaces__msg__EventData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_decision_interfaces__msg__EventData__Sequence__destroy(rm_decision_interfaces__msg__EventData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_decision_interfaces__msg__EventData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_decision_interfaces__msg__EventData__Sequence__are_equal(const rm_decision_interfaces__msg__EventData__Sequence * lhs, const rm_decision_interfaces__msg__EventData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_decision_interfaces__msg__EventData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_decision_interfaces__msg__EventData__Sequence__copy(
  const rm_decision_interfaces__msg__EventData__Sequence * input,
  rm_decision_interfaces__msg__EventData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_decision_interfaces__msg__EventData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_decision_interfaces__msg__EventData * data =
      (rm_decision_interfaces__msg__EventData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_decision_interfaces__msg__EventData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_decision_interfaces__msg__EventData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_decision_interfaces__msg__EventData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
