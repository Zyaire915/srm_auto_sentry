// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/EventData.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__EventData __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__EventData __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EventData_
{
  using Type = EventData_<ContainerAllocator>;

  explicit EventData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->supply_zone_non_overlap = 0;
      this->supply_zone_overlap = 0;
      this->supply_zone_rmul = 0;
      this->small_energy_status = 0;
      this->big_energy_status = 0;
      this->central_highland_status = 0;
      this->trapezoidal_highland_status = 0;
      this->dart_last_hit_time = 0;
      this->dart_last_hit_target = 0;
      this->center_gain_point_status = 0;
      this->fortress_gain_point_status = 0;
      this->outpost_gain_point_status = 0;
      this->base_gain_point_status = 0;
    }
  }

  explicit EventData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->supply_zone_non_overlap = 0;
      this->supply_zone_overlap = 0;
      this->supply_zone_rmul = 0;
      this->small_energy_status = 0;
      this->big_energy_status = 0;
      this->central_highland_status = 0;
      this->trapezoidal_highland_status = 0;
      this->dart_last_hit_time = 0;
      this->dart_last_hit_target = 0;
      this->center_gain_point_status = 0;
      this->fortress_gain_point_status = 0;
      this->outpost_gain_point_status = 0;
      this->base_gain_point_status = 0;
    }
  }

  // field types and members
  using _supply_zone_non_overlap_type =
    uint8_t;
  _supply_zone_non_overlap_type supply_zone_non_overlap;
  using _supply_zone_overlap_type =
    uint8_t;
  _supply_zone_overlap_type supply_zone_overlap;
  using _supply_zone_rmul_type =
    uint8_t;
  _supply_zone_rmul_type supply_zone_rmul;
  using _small_energy_status_type =
    uint8_t;
  _small_energy_status_type small_energy_status;
  using _big_energy_status_type =
    uint8_t;
  _big_energy_status_type big_energy_status;
  using _central_highland_status_type =
    uint8_t;
  _central_highland_status_type central_highland_status;
  using _trapezoidal_highland_status_type =
    uint8_t;
  _trapezoidal_highland_status_type trapezoidal_highland_status;
  using _dart_last_hit_time_type =
    uint16_t;
  _dart_last_hit_time_type dart_last_hit_time;
  using _dart_last_hit_target_type =
    uint8_t;
  _dart_last_hit_target_type dart_last_hit_target;
  using _center_gain_point_status_type =
    uint8_t;
  _center_gain_point_status_type center_gain_point_status;
  using _fortress_gain_point_status_type =
    uint8_t;
  _fortress_gain_point_status_type fortress_gain_point_status;
  using _outpost_gain_point_status_type =
    uint8_t;
  _outpost_gain_point_status_type outpost_gain_point_status;
  using _base_gain_point_status_type =
    uint8_t;
  _base_gain_point_status_type base_gain_point_status;

  // setters for named parameter idiom
  Type & set__supply_zone_non_overlap(
    const uint8_t & _arg)
  {
    this->supply_zone_non_overlap = _arg;
    return *this;
  }
  Type & set__supply_zone_overlap(
    const uint8_t & _arg)
  {
    this->supply_zone_overlap = _arg;
    return *this;
  }
  Type & set__supply_zone_rmul(
    const uint8_t & _arg)
  {
    this->supply_zone_rmul = _arg;
    return *this;
  }
  Type & set__small_energy_status(
    const uint8_t & _arg)
  {
    this->small_energy_status = _arg;
    return *this;
  }
  Type & set__big_energy_status(
    const uint8_t & _arg)
  {
    this->big_energy_status = _arg;
    return *this;
  }
  Type & set__central_highland_status(
    const uint8_t & _arg)
  {
    this->central_highland_status = _arg;
    return *this;
  }
  Type & set__trapezoidal_highland_status(
    const uint8_t & _arg)
  {
    this->trapezoidal_highland_status = _arg;
    return *this;
  }
  Type & set__dart_last_hit_time(
    const uint16_t & _arg)
  {
    this->dart_last_hit_time = _arg;
    return *this;
  }
  Type & set__dart_last_hit_target(
    const uint8_t & _arg)
  {
    this->dart_last_hit_target = _arg;
    return *this;
  }
  Type & set__center_gain_point_status(
    const uint8_t & _arg)
  {
    this->center_gain_point_status = _arg;
    return *this;
  }
  Type & set__fortress_gain_point_status(
    const uint8_t & _arg)
  {
    this->fortress_gain_point_status = _arg;
    return *this;
  }
  Type & set__outpost_gain_point_status(
    const uint8_t & _arg)
  {
    this->outpost_gain_point_status = _arg;
    return *this;
  }
  Type & set__base_gain_point_status(
    const uint8_t & _arg)
  {
    this->base_gain_point_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::EventData_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::EventData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::EventData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::EventData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__EventData
    std::shared_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__EventData
    std::shared_ptr<pb_rm_interfaces::msg::EventData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EventData_ & other) const
  {
    if (this->supply_zone_non_overlap != other.supply_zone_non_overlap) {
      return false;
    }
    if (this->supply_zone_overlap != other.supply_zone_overlap) {
      return false;
    }
    if (this->supply_zone_rmul != other.supply_zone_rmul) {
      return false;
    }
    if (this->small_energy_status != other.small_energy_status) {
      return false;
    }
    if (this->big_energy_status != other.big_energy_status) {
      return false;
    }
    if (this->central_highland_status != other.central_highland_status) {
      return false;
    }
    if (this->trapezoidal_highland_status != other.trapezoidal_highland_status) {
      return false;
    }
    if (this->dart_last_hit_time != other.dart_last_hit_time) {
      return false;
    }
    if (this->dart_last_hit_target != other.dart_last_hit_target) {
      return false;
    }
    if (this->center_gain_point_status != other.center_gain_point_status) {
      return false;
    }
    if (this->fortress_gain_point_status != other.fortress_gain_point_status) {
      return false;
    }
    if (this->outpost_gain_point_status != other.outpost_gain_point_status) {
      return false;
    }
    if (this->base_gain_point_status != other.base_gain_point_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const EventData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EventData_

// alias to use template instance with default allocator
using EventData =
  pb_rm_interfaces::msg::EventData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__STRUCT_HPP_
