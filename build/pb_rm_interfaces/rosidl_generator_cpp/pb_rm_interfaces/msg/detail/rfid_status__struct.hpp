// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pb_rm_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__pb_rm_interfaces__msg__RfidStatus __attribute__((deprecated))
#else
# define DEPRECATED__pb_rm_interfaces__msg__RfidStatus __declspec(deprecated)
#endif

namespace pb_rm_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RfidStatus_
{
  using Type = RfidStatus_<ContainerAllocator>;

  explicit RfidStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->friendly_base_gain_point = 0;
      this->friendly_central_highland_gain_point = 0;
      this->enemy_central_highland_gain_point = 0;
      this->friendly_trapezoidal_gain_point = 0;
      this->enemy_trapezoidal_gain_point = 0;
      this->friendly_fly_slope_pre_gain = 0;
      this->friendly_fly_slope_post_gain = 0;
      this->enemy_fly_slope_pre_gain = 0;
      this->enemy_fly_slope_post_gain = 0;
      this->friendly_central_highland_under = 0;
      this->friendly_central_highland_upper = 0;
      this->enemy_central_highland_under = 0;
      this->enemy_central_highland_upper = 0;
      this->friendly_highway_under = 0;
      this->friendly_highway_upper = 0;
      this->enemy_highway_under = 0;
      this->enemy_highway_upper = 0;
      this->friendly_fortress_gain = 0;
      this->friendly_outpost_gain = 0;
      this->friendly_supply_zone_non_overlap = 0;
      this->friendly_supply_zone_overlap = 0;
      this->friendly_energy_mechanism_gain = 0;
      this->enemy_energy_mechanism_gain = 0;
      this->center_gain_point_rmul = 0;
      this->enemy_fortress_gain = 0;
      this->enemy_outpost_gain = 0;
      this->friendly_tunnel_highway_under = 0;
      this->friendly_tunnel_highway_upper = 0;
      this->friendly_tunnel_trapezoid_low = 0;
      this->friendly_tunnel_trapezoid_high = 0;
      this->enemy_tunnel_highway_under = 0;
      this->enemy_tunnel_highway_upper = 0;
      this->enemy_tunnel_trapezoid_low = 0;
      this->enemy_tunnel_trapezoid_high = 0;
    }
  }

  explicit RfidStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->friendly_base_gain_point = 0;
      this->friendly_central_highland_gain_point = 0;
      this->enemy_central_highland_gain_point = 0;
      this->friendly_trapezoidal_gain_point = 0;
      this->enemy_trapezoidal_gain_point = 0;
      this->friendly_fly_slope_pre_gain = 0;
      this->friendly_fly_slope_post_gain = 0;
      this->enemy_fly_slope_pre_gain = 0;
      this->enemy_fly_slope_post_gain = 0;
      this->friendly_central_highland_under = 0;
      this->friendly_central_highland_upper = 0;
      this->enemy_central_highland_under = 0;
      this->enemy_central_highland_upper = 0;
      this->friendly_highway_under = 0;
      this->friendly_highway_upper = 0;
      this->enemy_highway_under = 0;
      this->enemy_highway_upper = 0;
      this->friendly_fortress_gain = 0;
      this->friendly_outpost_gain = 0;
      this->friendly_supply_zone_non_overlap = 0;
      this->friendly_supply_zone_overlap = 0;
      this->friendly_energy_mechanism_gain = 0;
      this->enemy_energy_mechanism_gain = 0;
      this->center_gain_point_rmul = 0;
      this->enemy_fortress_gain = 0;
      this->enemy_outpost_gain = 0;
      this->friendly_tunnel_highway_under = 0;
      this->friendly_tunnel_highway_upper = 0;
      this->friendly_tunnel_trapezoid_low = 0;
      this->friendly_tunnel_trapezoid_high = 0;
      this->enemy_tunnel_highway_under = 0;
      this->enemy_tunnel_highway_upper = 0;
      this->enemy_tunnel_trapezoid_low = 0;
      this->enemy_tunnel_trapezoid_high = 0;
    }
  }

  // field types and members
  using _friendly_base_gain_point_type =
    uint8_t;
  _friendly_base_gain_point_type friendly_base_gain_point;
  using _friendly_central_highland_gain_point_type =
    uint8_t;
  _friendly_central_highland_gain_point_type friendly_central_highland_gain_point;
  using _enemy_central_highland_gain_point_type =
    uint8_t;
  _enemy_central_highland_gain_point_type enemy_central_highland_gain_point;
  using _friendly_trapezoidal_gain_point_type =
    uint8_t;
  _friendly_trapezoidal_gain_point_type friendly_trapezoidal_gain_point;
  using _enemy_trapezoidal_gain_point_type =
    uint8_t;
  _enemy_trapezoidal_gain_point_type enemy_trapezoidal_gain_point;
  using _friendly_fly_slope_pre_gain_type =
    uint8_t;
  _friendly_fly_slope_pre_gain_type friendly_fly_slope_pre_gain;
  using _friendly_fly_slope_post_gain_type =
    uint8_t;
  _friendly_fly_slope_post_gain_type friendly_fly_slope_post_gain;
  using _enemy_fly_slope_pre_gain_type =
    uint8_t;
  _enemy_fly_slope_pre_gain_type enemy_fly_slope_pre_gain;
  using _enemy_fly_slope_post_gain_type =
    uint8_t;
  _enemy_fly_slope_post_gain_type enemy_fly_slope_post_gain;
  using _friendly_central_highland_under_type =
    uint8_t;
  _friendly_central_highland_under_type friendly_central_highland_under;
  using _friendly_central_highland_upper_type =
    uint8_t;
  _friendly_central_highland_upper_type friendly_central_highland_upper;
  using _enemy_central_highland_under_type =
    uint8_t;
  _enemy_central_highland_under_type enemy_central_highland_under;
  using _enemy_central_highland_upper_type =
    uint8_t;
  _enemy_central_highland_upper_type enemy_central_highland_upper;
  using _friendly_highway_under_type =
    uint8_t;
  _friendly_highway_under_type friendly_highway_under;
  using _friendly_highway_upper_type =
    uint8_t;
  _friendly_highway_upper_type friendly_highway_upper;
  using _enemy_highway_under_type =
    uint8_t;
  _enemy_highway_under_type enemy_highway_under;
  using _enemy_highway_upper_type =
    uint8_t;
  _enemy_highway_upper_type enemy_highway_upper;
  using _friendly_fortress_gain_type =
    uint8_t;
  _friendly_fortress_gain_type friendly_fortress_gain;
  using _friendly_outpost_gain_type =
    uint8_t;
  _friendly_outpost_gain_type friendly_outpost_gain;
  using _friendly_supply_zone_non_overlap_type =
    uint8_t;
  _friendly_supply_zone_non_overlap_type friendly_supply_zone_non_overlap;
  using _friendly_supply_zone_overlap_type =
    uint8_t;
  _friendly_supply_zone_overlap_type friendly_supply_zone_overlap;
  using _friendly_energy_mechanism_gain_type =
    uint8_t;
  _friendly_energy_mechanism_gain_type friendly_energy_mechanism_gain;
  using _enemy_energy_mechanism_gain_type =
    uint8_t;
  _enemy_energy_mechanism_gain_type enemy_energy_mechanism_gain;
  using _center_gain_point_rmul_type =
    uint8_t;
  _center_gain_point_rmul_type center_gain_point_rmul;
  using _enemy_fortress_gain_type =
    uint8_t;
  _enemy_fortress_gain_type enemy_fortress_gain;
  using _enemy_outpost_gain_type =
    uint8_t;
  _enemy_outpost_gain_type enemy_outpost_gain;
  using _friendly_tunnel_highway_under_type =
    uint8_t;
  _friendly_tunnel_highway_under_type friendly_tunnel_highway_under;
  using _friendly_tunnel_highway_upper_type =
    uint8_t;
  _friendly_tunnel_highway_upper_type friendly_tunnel_highway_upper;
  using _friendly_tunnel_trapezoid_low_type =
    uint8_t;
  _friendly_tunnel_trapezoid_low_type friendly_tunnel_trapezoid_low;
  using _friendly_tunnel_trapezoid_high_type =
    uint8_t;
  _friendly_tunnel_trapezoid_high_type friendly_tunnel_trapezoid_high;
  using _enemy_tunnel_highway_under_type =
    uint8_t;
  _enemy_tunnel_highway_under_type enemy_tunnel_highway_under;
  using _enemy_tunnel_highway_upper_type =
    uint8_t;
  _enemy_tunnel_highway_upper_type enemy_tunnel_highway_upper;
  using _enemy_tunnel_trapezoid_low_type =
    uint8_t;
  _enemy_tunnel_trapezoid_low_type enemy_tunnel_trapezoid_low;
  using _enemy_tunnel_trapezoid_high_type =
    uint8_t;
  _enemy_tunnel_trapezoid_high_type enemy_tunnel_trapezoid_high;

  // setters for named parameter idiom
  Type & set__friendly_base_gain_point(
    const uint8_t & _arg)
  {
    this->friendly_base_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_central_highland_gain_point(
    const uint8_t & _arg)
  {
    this->friendly_central_highland_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_central_highland_gain_point(
    const uint8_t & _arg)
  {
    this->enemy_central_highland_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_trapezoidal_gain_point(
    const uint8_t & _arg)
  {
    this->friendly_trapezoidal_gain_point = _arg;
    return *this;
  }
  Type & set__enemy_trapezoidal_gain_point(
    const uint8_t & _arg)
  {
    this->enemy_trapezoidal_gain_point = _arg;
    return *this;
  }
  Type & set__friendly_fly_slope_pre_gain(
    const uint8_t & _arg)
  {
    this->friendly_fly_slope_pre_gain = _arg;
    return *this;
  }
  Type & set__friendly_fly_slope_post_gain(
    const uint8_t & _arg)
  {
    this->friendly_fly_slope_post_gain = _arg;
    return *this;
  }
  Type & set__enemy_fly_slope_pre_gain(
    const uint8_t & _arg)
  {
    this->enemy_fly_slope_pre_gain = _arg;
    return *this;
  }
  Type & set__enemy_fly_slope_post_gain(
    const uint8_t & _arg)
  {
    this->enemy_fly_slope_post_gain = _arg;
    return *this;
  }
  Type & set__friendly_central_highland_under(
    const uint8_t & _arg)
  {
    this->friendly_central_highland_under = _arg;
    return *this;
  }
  Type & set__friendly_central_highland_upper(
    const uint8_t & _arg)
  {
    this->friendly_central_highland_upper = _arg;
    return *this;
  }
  Type & set__enemy_central_highland_under(
    const uint8_t & _arg)
  {
    this->enemy_central_highland_under = _arg;
    return *this;
  }
  Type & set__enemy_central_highland_upper(
    const uint8_t & _arg)
  {
    this->enemy_central_highland_upper = _arg;
    return *this;
  }
  Type & set__friendly_highway_under(
    const uint8_t & _arg)
  {
    this->friendly_highway_under = _arg;
    return *this;
  }
  Type & set__friendly_highway_upper(
    const uint8_t & _arg)
  {
    this->friendly_highway_upper = _arg;
    return *this;
  }
  Type & set__enemy_highway_under(
    const uint8_t & _arg)
  {
    this->enemy_highway_under = _arg;
    return *this;
  }
  Type & set__enemy_highway_upper(
    const uint8_t & _arg)
  {
    this->enemy_highway_upper = _arg;
    return *this;
  }
  Type & set__friendly_fortress_gain(
    const uint8_t & _arg)
  {
    this->friendly_fortress_gain = _arg;
    return *this;
  }
  Type & set__friendly_outpost_gain(
    const uint8_t & _arg)
  {
    this->friendly_outpost_gain = _arg;
    return *this;
  }
  Type & set__friendly_supply_zone_non_overlap(
    const uint8_t & _arg)
  {
    this->friendly_supply_zone_non_overlap = _arg;
    return *this;
  }
  Type & set__friendly_supply_zone_overlap(
    const uint8_t & _arg)
  {
    this->friendly_supply_zone_overlap = _arg;
    return *this;
  }
  Type & set__friendly_energy_mechanism_gain(
    const uint8_t & _arg)
  {
    this->friendly_energy_mechanism_gain = _arg;
    return *this;
  }
  Type & set__enemy_energy_mechanism_gain(
    const uint8_t & _arg)
  {
    this->enemy_energy_mechanism_gain = _arg;
    return *this;
  }
  Type & set__center_gain_point_rmul(
    const uint8_t & _arg)
  {
    this->center_gain_point_rmul = _arg;
    return *this;
  }
  Type & set__enemy_fortress_gain(
    const uint8_t & _arg)
  {
    this->enemy_fortress_gain = _arg;
    return *this;
  }
  Type & set__enemy_outpost_gain(
    const uint8_t & _arg)
  {
    this->enemy_outpost_gain = _arg;
    return *this;
  }
  Type & set__friendly_tunnel_highway_under(
    const uint8_t & _arg)
  {
    this->friendly_tunnel_highway_under = _arg;
    return *this;
  }
  Type & set__friendly_tunnel_highway_upper(
    const uint8_t & _arg)
  {
    this->friendly_tunnel_highway_upper = _arg;
    return *this;
  }
  Type & set__friendly_tunnel_trapezoid_low(
    const uint8_t & _arg)
  {
    this->friendly_tunnel_trapezoid_low = _arg;
    return *this;
  }
  Type & set__friendly_tunnel_trapezoid_high(
    const uint8_t & _arg)
  {
    this->friendly_tunnel_trapezoid_high = _arg;
    return *this;
  }
  Type & set__enemy_tunnel_highway_under(
    const uint8_t & _arg)
  {
    this->enemy_tunnel_highway_under = _arg;
    return *this;
  }
  Type & set__enemy_tunnel_highway_upper(
    const uint8_t & _arg)
  {
    this->enemy_tunnel_highway_upper = _arg;
    return *this;
  }
  Type & set__enemy_tunnel_trapezoid_low(
    const uint8_t & _arg)
  {
    this->enemy_tunnel_trapezoid_low = _arg;
    return *this;
  }
  Type & set__enemy_tunnel_trapezoid_high(
    const uint8_t & _arg)
  {
    this->enemy_tunnel_trapezoid_high = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pb_rm_interfaces__msg__RfidStatus
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pb_rm_interfaces__msg__RfidStatus
    std::shared_ptr<pb_rm_interfaces::msg::RfidStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RfidStatus_ & other) const
  {
    if (this->friendly_base_gain_point != other.friendly_base_gain_point) {
      return false;
    }
    if (this->friendly_central_highland_gain_point != other.friendly_central_highland_gain_point) {
      return false;
    }
    if (this->enemy_central_highland_gain_point != other.enemy_central_highland_gain_point) {
      return false;
    }
    if (this->friendly_trapezoidal_gain_point != other.friendly_trapezoidal_gain_point) {
      return false;
    }
    if (this->enemy_trapezoidal_gain_point != other.enemy_trapezoidal_gain_point) {
      return false;
    }
    if (this->friendly_fly_slope_pre_gain != other.friendly_fly_slope_pre_gain) {
      return false;
    }
    if (this->friendly_fly_slope_post_gain != other.friendly_fly_slope_post_gain) {
      return false;
    }
    if (this->enemy_fly_slope_pre_gain != other.enemy_fly_slope_pre_gain) {
      return false;
    }
    if (this->enemy_fly_slope_post_gain != other.enemy_fly_slope_post_gain) {
      return false;
    }
    if (this->friendly_central_highland_under != other.friendly_central_highland_under) {
      return false;
    }
    if (this->friendly_central_highland_upper != other.friendly_central_highland_upper) {
      return false;
    }
    if (this->enemy_central_highland_under != other.enemy_central_highland_under) {
      return false;
    }
    if (this->enemy_central_highland_upper != other.enemy_central_highland_upper) {
      return false;
    }
    if (this->friendly_highway_under != other.friendly_highway_under) {
      return false;
    }
    if (this->friendly_highway_upper != other.friendly_highway_upper) {
      return false;
    }
    if (this->enemy_highway_under != other.enemy_highway_under) {
      return false;
    }
    if (this->enemy_highway_upper != other.enemy_highway_upper) {
      return false;
    }
    if (this->friendly_fortress_gain != other.friendly_fortress_gain) {
      return false;
    }
    if (this->friendly_outpost_gain != other.friendly_outpost_gain) {
      return false;
    }
    if (this->friendly_supply_zone_non_overlap != other.friendly_supply_zone_non_overlap) {
      return false;
    }
    if (this->friendly_supply_zone_overlap != other.friendly_supply_zone_overlap) {
      return false;
    }
    if (this->friendly_energy_mechanism_gain != other.friendly_energy_mechanism_gain) {
      return false;
    }
    if (this->enemy_energy_mechanism_gain != other.enemy_energy_mechanism_gain) {
      return false;
    }
    if (this->center_gain_point_rmul != other.center_gain_point_rmul) {
      return false;
    }
    if (this->enemy_fortress_gain != other.enemy_fortress_gain) {
      return false;
    }
    if (this->enemy_outpost_gain != other.enemy_outpost_gain) {
      return false;
    }
    if (this->friendly_tunnel_highway_under != other.friendly_tunnel_highway_under) {
      return false;
    }
    if (this->friendly_tunnel_highway_upper != other.friendly_tunnel_highway_upper) {
      return false;
    }
    if (this->friendly_tunnel_trapezoid_low != other.friendly_tunnel_trapezoid_low) {
      return false;
    }
    if (this->friendly_tunnel_trapezoid_high != other.friendly_tunnel_trapezoid_high) {
      return false;
    }
    if (this->enemy_tunnel_highway_under != other.enemy_tunnel_highway_under) {
      return false;
    }
    if (this->enemy_tunnel_highway_upper != other.enemy_tunnel_highway_upper) {
      return false;
    }
    if (this->enemy_tunnel_trapezoid_low != other.enemy_tunnel_trapezoid_low) {
      return false;
    }
    if (this->enemy_tunnel_trapezoid_high != other.enemy_tunnel_trapezoid_high) {
      return false;
    }
    return true;
  }
  bool operator!=(const RfidStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RfidStatus_

// alias to use template instance with default allocator
using RfidStatus =
  pb_rm_interfaces::msg::RfidStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__RFID_STATUS__STRUCT_HPP_
