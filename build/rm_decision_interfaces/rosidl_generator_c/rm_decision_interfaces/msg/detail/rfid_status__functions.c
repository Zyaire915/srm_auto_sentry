// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_decision_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice
#include "rm_decision_interfaces/msg/detail/rfid_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_decision_interfaces__msg__RfidStatus__init(rm_decision_interfaces__msg__RfidStatus * msg)
{
  if (!msg) {
    return false;
  }
  // friendly_base_gain_point
  // friendly_central_highland_gain_point
  // enemy_central_highland_gain_point
  // friendly_trapezoidal_gain_point
  // enemy_trapezoidal_gain_point
  // friendly_fly_slope_pre_gain
  // friendly_fly_slope_post_gain
  // enemy_fly_slope_pre_gain
  // enemy_fly_slope_post_gain
  // friendly_central_highland_under
  // friendly_central_highland_upper
  // enemy_central_highland_under
  // enemy_central_highland_upper
  // friendly_highway_under
  // friendly_highway_upper
  // enemy_highway_under
  // enemy_highway_upper
  // friendly_fortress_gain
  // friendly_outpost_gain
  // friendly_supply_zone_non_overlap
  // friendly_supply_zone_overlap
  // friendly_energy_mechanism_gain
  // enemy_energy_mechanism_gain
  // center_gain_point_rmul
  // enemy_fortress_gain
  // enemy_outpost_gain
  // friendly_tunnel_highway_under
  // friendly_tunnel_highway_upper
  // friendly_tunnel_trapezoid_low
  // friendly_tunnel_trapezoid_high
  // enemy_tunnel_highway_under
  // enemy_tunnel_highway_upper
  // enemy_tunnel_trapezoid_low
  // enemy_tunnel_trapezoid_high
  return true;
}

void
rm_decision_interfaces__msg__RfidStatus__fini(rm_decision_interfaces__msg__RfidStatus * msg)
{
  if (!msg) {
    return;
  }
  // friendly_base_gain_point
  // friendly_central_highland_gain_point
  // enemy_central_highland_gain_point
  // friendly_trapezoidal_gain_point
  // enemy_trapezoidal_gain_point
  // friendly_fly_slope_pre_gain
  // friendly_fly_slope_post_gain
  // enemy_fly_slope_pre_gain
  // enemy_fly_slope_post_gain
  // friendly_central_highland_under
  // friendly_central_highland_upper
  // enemy_central_highland_under
  // enemy_central_highland_upper
  // friendly_highway_under
  // friendly_highway_upper
  // enemy_highway_under
  // enemy_highway_upper
  // friendly_fortress_gain
  // friendly_outpost_gain
  // friendly_supply_zone_non_overlap
  // friendly_supply_zone_overlap
  // friendly_energy_mechanism_gain
  // enemy_energy_mechanism_gain
  // center_gain_point_rmul
  // enemy_fortress_gain
  // enemy_outpost_gain
  // friendly_tunnel_highway_under
  // friendly_tunnel_highway_upper
  // friendly_tunnel_trapezoid_low
  // friendly_tunnel_trapezoid_high
  // enemy_tunnel_highway_under
  // enemy_tunnel_highway_upper
  // enemy_tunnel_trapezoid_low
  // enemy_tunnel_trapezoid_high
}

bool
rm_decision_interfaces__msg__RfidStatus__are_equal(const rm_decision_interfaces__msg__RfidStatus * lhs, const rm_decision_interfaces__msg__RfidStatus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // friendly_base_gain_point
  if (lhs->friendly_base_gain_point != rhs->friendly_base_gain_point) {
    return false;
  }
  // friendly_central_highland_gain_point
  if (lhs->friendly_central_highland_gain_point != rhs->friendly_central_highland_gain_point) {
    return false;
  }
  // enemy_central_highland_gain_point
  if (lhs->enemy_central_highland_gain_point != rhs->enemy_central_highland_gain_point) {
    return false;
  }
  // friendly_trapezoidal_gain_point
  if (lhs->friendly_trapezoidal_gain_point != rhs->friendly_trapezoidal_gain_point) {
    return false;
  }
  // enemy_trapezoidal_gain_point
  if (lhs->enemy_trapezoidal_gain_point != rhs->enemy_trapezoidal_gain_point) {
    return false;
  }
  // friendly_fly_slope_pre_gain
  if (lhs->friendly_fly_slope_pre_gain != rhs->friendly_fly_slope_pre_gain) {
    return false;
  }
  // friendly_fly_slope_post_gain
  if (lhs->friendly_fly_slope_post_gain != rhs->friendly_fly_slope_post_gain) {
    return false;
  }
  // enemy_fly_slope_pre_gain
  if (lhs->enemy_fly_slope_pre_gain != rhs->enemy_fly_slope_pre_gain) {
    return false;
  }
  // enemy_fly_slope_post_gain
  if (lhs->enemy_fly_slope_post_gain != rhs->enemy_fly_slope_post_gain) {
    return false;
  }
  // friendly_central_highland_under
  if (lhs->friendly_central_highland_under != rhs->friendly_central_highland_under) {
    return false;
  }
  // friendly_central_highland_upper
  if (lhs->friendly_central_highland_upper != rhs->friendly_central_highland_upper) {
    return false;
  }
  // enemy_central_highland_under
  if (lhs->enemy_central_highland_under != rhs->enemy_central_highland_under) {
    return false;
  }
  // enemy_central_highland_upper
  if (lhs->enemy_central_highland_upper != rhs->enemy_central_highland_upper) {
    return false;
  }
  // friendly_highway_under
  if (lhs->friendly_highway_under != rhs->friendly_highway_under) {
    return false;
  }
  // friendly_highway_upper
  if (lhs->friendly_highway_upper != rhs->friendly_highway_upper) {
    return false;
  }
  // enemy_highway_under
  if (lhs->enemy_highway_under != rhs->enemy_highway_under) {
    return false;
  }
  // enemy_highway_upper
  if (lhs->enemy_highway_upper != rhs->enemy_highway_upper) {
    return false;
  }
  // friendly_fortress_gain
  if (lhs->friendly_fortress_gain != rhs->friendly_fortress_gain) {
    return false;
  }
  // friendly_outpost_gain
  if (lhs->friendly_outpost_gain != rhs->friendly_outpost_gain) {
    return false;
  }
  // friendly_supply_zone_non_overlap
  if (lhs->friendly_supply_zone_non_overlap != rhs->friendly_supply_zone_non_overlap) {
    return false;
  }
  // friendly_supply_zone_overlap
  if (lhs->friendly_supply_zone_overlap != rhs->friendly_supply_zone_overlap) {
    return false;
  }
  // friendly_energy_mechanism_gain
  if (lhs->friendly_energy_mechanism_gain != rhs->friendly_energy_mechanism_gain) {
    return false;
  }
  // enemy_energy_mechanism_gain
  if (lhs->enemy_energy_mechanism_gain != rhs->enemy_energy_mechanism_gain) {
    return false;
  }
  // center_gain_point_rmul
  if (lhs->center_gain_point_rmul != rhs->center_gain_point_rmul) {
    return false;
  }
  // enemy_fortress_gain
  if (lhs->enemy_fortress_gain != rhs->enemy_fortress_gain) {
    return false;
  }
  // enemy_outpost_gain
  if (lhs->enemy_outpost_gain != rhs->enemy_outpost_gain) {
    return false;
  }
  // friendly_tunnel_highway_under
  if (lhs->friendly_tunnel_highway_under != rhs->friendly_tunnel_highway_under) {
    return false;
  }
  // friendly_tunnel_highway_upper
  if (lhs->friendly_tunnel_highway_upper != rhs->friendly_tunnel_highway_upper) {
    return false;
  }
  // friendly_tunnel_trapezoid_low
  if (lhs->friendly_tunnel_trapezoid_low != rhs->friendly_tunnel_trapezoid_low) {
    return false;
  }
  // friendly_tunnel_trapezoid_high
  if (lhs->friendly_tunnel_trapezoid_high != rhs->friendly_tunnel_trapezoid_high) {
    return false;
  }
  // enemy_tunnel_highway_under
  if (lhs->enemy_tunnel_highway_under != rhs->enemy_tunnel_highway_under) {
    return false;
  }
  // enemy_tunnel_highway_upper
  if (lhs->enemy_tunnel_highway_upper != rhs->enemy_tunnel_highway_upper) {
    return false;
  }
  // enemy_tunnel_trapezoid_low
  if (lhs->enemy_tunnel_trapezoid_low != rhs->enemy_tunnel_trapezoid_low) {
    return false;
  }
  // enemy_tunnel_trapezoid_high
  if (lhs->enemy_tunnel_trapezoid_high != rhs->enemy_tunnel_trapezoid_high) {
    return false;
  }
  return true;
}

bool
rm_decision_interfaces__msg__RfidStatus__copy(
  const rm_decision_interfaces__msg__RfidStatus * input,
  rm_decision_interfaces__msg__RfidStatus * output)
{
  if (!input || !output) {
    return false;
  }
  // friendly_base_gain_point
  output->friendly_base_gain_point = input->friendly_base_gain_point;
  // friendly_central_highland_gain_point
  output->friendly_central_highland_gain_point = input->friendly_central_highland_gain_point;
  // enemy_central_highland_gain_point
  output->enemy_central_highland_gain_point = input->enemy_central_highland_gain_point;
  // friendly_trapezoidal_gain_point
  output->friendly_trapezoidal_gain_point = input->friendly_trapezoidal_gain_point;
  // enemy_trapezoidal_gain_point
  output->enemy_trapezoidal_gain_point = input->enemy_trapezoidal_gain_point;
  // friendly_fly_slope_pre_gain
  output->friendly_fly_slope_pre_gain = input->friendly_fly_slope_pre_gain;
  // friendly_fly_slope_post_gain
  output->friendly_fly_slope_post_gain = input->friendly_fly_slope_post_gain;
  // enemy_fly_slope_pre_gain
  output->enemy_fly_slope_pre_gain = input->enemy_fly_slope_pre_gain;
  // enemy_fly_slope_post_gain
  output->enemy_fly_slope_post_gain = input->enemy_fly_slope_post_gain;
  // friendly_central_highland_under
  output->friendly_central_highland_under = input->friendly_central_highland_under;
  // friendly_central_highland_upper
  output->friendly_central_highland_upper = input->friendly_central_highland_upper;
  // enemy_central_highland_under
  output->enemy_central_highland_under = input->enemy_central_highland_under;
  // enemy_central_highland_upper
  output->enemy_central_highland_upper = input->enemy_central_highland_upper;
  // friendly_highway_under
  output->friendly_highway_under = input->friendly_highway_under;
  // friendly_highway_upper
  output->friendly_highway_upper = input->friendly_highway_upper;
  // enemy_highway_under
  output->enemy_highway_under = input->enemy_highway_under;
  // enemy_highway_upper
  output->enemy_highway_upper = input->enemy_highway_upper;
  // friendly_fortress_gain
  output->friendly_fortress_gain = input->friendly_fortress_gain;
  // friendly_outpost_gain
  output->friendly_outpost_gain = input->friendly_outpost_gain;
  // friendly_supply_zone_non_overlap
  output->friendly_supply_zone_non_overlap = input->friendly_supply_zone_non_overlap;
  // friendly_supply_zone_overlap
  output->friendly_supply_zone_overlap = input->friendly_supply_zone_overlap;
  // friendly_energy_mechanism_gain
  output->friendly_energy_mechanism_gain = input->friendly_energy_mechanism_gain;
  // enemy_energy_mechanism_gain
  output->enemy_energy_mechanism_gain = input->enemy_energy_mechanism_gain;
  // center_gain_point_rmul
  output->center_gain_point_rmul = input->center_gain_point_rmul;
  // enemy_fortress_gain
  output->enemy_fortress_gain = input->enemy_fortress_gain;
  // enemy_outpost_gain
  output->enemy_outpost_gain = input->enemy_outpost_gain;
  // friendly_tunnel_highway_under
  output->friendly_tunnel_highway_under = input->friendly_tunnel_highway_under;
  // friendly_tunnel_highway_upper
  output->friendly_tunnel_highway_upper = input->friendly_tunnel_highway_upper;
  // friendly_tunnel_trapezoid_low
  output->friendly_tunnel_trapezoid_low = input->friendly_tunnel_trapezoid_low;
  // friendly_tunnel_trapezoid_high
  output->friendly_tunnel_trapezoid_high = input->friendly_tunnel_trapezoid_high;
  // enemy_tunnel_highway_under
  output->enemy_tunnel_highway_under = input->enemy_tunnel_highway_under;
  // enemy_tunnel_highway_upper
  output->enemy_tunnel_highway_upper = input->enemy_tunnel_highway_upper;
  // enemy_tunnel_trapezoid_low
  output->enemy_tunnel_trapezoid_low = input->enemy_tunnel_trapezoid_low;
  // enemy_tunnel_trapezoid_high
  output->enemy_tunnel_trapezoid_high = input->enemy_tunnel_trapezoid_high;
  return true;
}

rm_decision_interfaces__msg__RfidStatus *
rm_decision_interfaces__msg__RfidStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__RfidStatus * msg = (rm_decision_interfaces__msg__RfidStatus *)allocator.allocate(sizeof(rm_decision_interfaces__msg__RfidStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_decision_interfaces__msg__RfidStatus));
  bool success = rm_decision_interfaces__msg__RfidStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_decision_interfaces__msg__RfidStatus__destroy(rm_decision_interfaces__msg__RfidStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_decision_interfaces__msg__RfidStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_decision_interfaces__msg__RfidStatus__Sequence__init(rm_decision_interfaces__msg__RfidStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__RfidStatus * data = NULL;

  if (size) {
    data = (rm_decision_interfaces__msg__RfidStatus *)allocator.zero_allocate(size, sizeof(rm_decision_interfaces__msg__RfidStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_decision_interfaces__msg__RfidStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_decision_interfaces__msg__RfidStatus__fini(&data[i - 1]);
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
rm_decision_interfaces__msg__RfidStatus__Sequence__fini(rm_decision_interfaces__msg__RfidStatus__Sequence * array)
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
      rm_decision_interfaces__msg__RfidStatus__fini(&array->data[i]);
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

rm_decision_interfaces__msg__RfidStatus__Sequence *
rm_decision_interfaces__msg__RfidStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__RfidStatus__Sequence * array = (rm_decision_interfaces__msg__RfidStatus__Sequence *)allocator.allocate(sizeof(rm_decision_interfaces__msg__RfidStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_decision_interfaces__msg__RfidStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_decision_interfaces__msg__RfidStatus__Sequence__destroy(rm_decision_interfaces__msg__RfidStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_decision_interfaces__msg__RfidStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_decision_interfaces__msg__RfidStatus__Sequence__are_equal(const rm_decision_interfaces__msg__RfidStatus__Sequence * lhs, const rm_decision_interfaces__msg__RfidStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_decision_interfaces__msg__RfidStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_decision_interfaces__msg__RfidStatus__Sequence__copy(
  const rm_decision_interfaces__msg__RfidStatus__Sequence * input,
  rm_decision_interfaces__msg__RfidStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_decision_interfaces__msg__RfidStatus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_decision_interfaces__msg__RfidStatus * data =
      (rm_decision_interfaces__msg__RfidStatus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_decision_interfaces__msg__RfidStatus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_decision_interfaces__msg__RfidStatus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_decision_interfaces__msg__RfidStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
