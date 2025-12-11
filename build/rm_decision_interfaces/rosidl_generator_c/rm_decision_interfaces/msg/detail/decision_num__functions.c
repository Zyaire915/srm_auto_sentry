// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rm_decision_interfaces:msg/DecisionNum.idl
// generated code does not contain a copyright notice
#include "rm_decision_interfaces/msg/detail/decision_num__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
rm_decision_interfaces__msg__DecisionNum__init(rm_decision_interfaces__msg__DecisionNum * msg)
{
  if (!msg) {
    return false;
  }
  // decision_num
  return true;
}

void
rm_decision_interfaces__msg__DecisionNum__fini(rm_decision_interfaces__msg__DecisionNum * msg)
{
  if (!msg) {
    return;
  }
  // decision_num
}

bool
rm_decision_interfaces__msg__DecisionNum__are_equal(const rm_decision_interfaces__msg__DecisionNum * lhs, const rm_decision_interfaces__msg__DecisionNum * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // decision_num
  if (lhs->decision_num != rhs->decision_num) {
    return false;
  }
  return true;
}

bool
rm_decision_interfaces__msg__DecisionNum__copy(
  const rm_decision_interfaces__msg__DecisionNum * input,
  rm_decision_interfaces__msg__DecisionNum * output)
{
  if (!input || !output) {
    return false;
  }
  // decision_num
  output->decision_num = input->decision_num;
  return true;
}

rm_decision_interfaces__msg__DecisionNum *
rm_decision_interfaces__msg__DecisionNum__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__DecisionNum * msg = (rm_decision_interfaces__msg__DecisionNum *)allocator.allocate(sizeof(rm_decision_interfaces__msg__DecisionNum), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rm_decision_interfaces__msg__DecisionNum));
  bool success = rm_decision_interfaces__msg__DecisionNum__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rm_decision_interfaces__msg__DecisionNum__destroy(rm_decision_interfaces__msg__DecisionNum * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rm_decision_interfaces__msg__DecisionNum__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rm_decision_interfaces__msg__DecisionNum__Sequence__init(rm_decision_interfaces__msg__DecisionNum__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__DecisionNum * data = NULL;

  if (size) {
    data = (rm_decision_interfaces__msg__DecisionNum *)allocator.zero_allocate(size, sizeof(rm_decision_interfaces__msg__DecisionNum), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rm_decision_interfaces__msg__DecisionNum__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rm_decision_interfaces__msg__DecisionNum__fini(&data[i - 1]);
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
rm_decision_interfaces__msg__DecisionNum__Sequence__fini(rm_decision_interfaces__msg__DecisionNum__Sequence * array)
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
      rm_decision_interfaces__msg__DecisionNum__fini(&array->data[i]);
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

rm_decision_interfaces__msg__DecisionNum__Sequence *
rm_decision_interfaces__msg__DecisionNum__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rm_decision_interfaces__msg__DecisionNum__Sequence * array = (rm_decision_interfaces__msg__DecisionNum__Sequence *)allocator.allocate(sizeof(rm_decision_interfaces__msg__DecisionNum__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rm_decision_interfaces__msg__DecisionNum__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rm_decision_interfaces__msg__DecisionNum__Sequence__destroy(rm_decision_interfaces__msg__DecisionNum__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rm_decision_interfaces__msg__DecisionNum__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rm_decision_interfaces__msg__DecisionNum__Sequence__are_equal(const rm_decision_interfaces__msg__DecisionNum__Sequence * lhs, const rm_decision_interfaces__msg__DecisionNum__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rm_decision_interfaces__msg__DecisionNum__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rm_decision_interfaces__msg__DecisionNum__Sequence__copy(
  const rm_decision_interfaces__msg__DecisionNum__Sequence * input,
  rm_decision_interfaces__msg__DecisionNum__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rm_decision_interfaces__msg__DecisionNum);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rm_decision_interfaces__msg__DecisionNum * data =
      (rm_decision_interfaces__msg__DecisionNum *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rm_decision_interfaces__msg__DecisionNum__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rm_decision_interfaces__msg__DecisionNum__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rm_decision_interfaces__msg__DecisionNum__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
