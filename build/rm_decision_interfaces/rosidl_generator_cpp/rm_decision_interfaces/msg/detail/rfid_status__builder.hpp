// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_decision_interfaces:msg/RfidStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_decision_interfaces/msg/detail/rfid_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_decision_interfaces
{

namespace msg
{

namespace builder
{

class Init_RfidStatus_enemy_tunnel_trapezoid_high
{
public:
  explicit Init_RfidStatus_enemy_tunnel_trapezoid_high(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  ::rm_decision_interfaces::msg::RfidStatus enemy_tunnel_trapezoid_high(::rm_decision_interfaces::msg::RfidStatus::_enemy_tunnel_trapezoid_high_type arg)
  {
    msg_.enemy_tunnel_trapezoid_high = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_tunnel_trapezoid_low
{
public:
  explicit Init_RfidStatus_enemy_tunnel_trapezoid_low(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_tunnel_trapezoid_high enemy_tunnel_trapezoid_low(::rm_decision_interfaces::msg::RfidStatus::_enemy_tunnel_trapezoid_low_type arg)
  {
    msg_.enemy_tunnel_trapezoid_low = std::move(arg);
    return Init_RfidStatus_enemy_tunnel_trapezoid_high(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_tunnel_highway_upper
{
public:
  explicit Init_RfidStatus_enemy_tunnel_highway_upper(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_tunnel_trapezoid_low enemy_tunnel_highway_upper(::rm_decision_interfaces::msg::RfidStatus::_enemy_tunnel_highway_upper_type arg)
  {
    msg_.enemy_tunnel_highway_upper = std::move(arg);
    return Init_RfidStatus_enemy_tunnel_trapezoid_low(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_tunnel_highway_under
{
public:
  explicit Init_RfidStatus_enemy_tunnel_highway_under(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_tunnel_highway_upper enemy_tunnel_highway_under(::rm_decision_interfaces::msg::RfidStatus::_enemy_tunnel_highway_under_type arg)
  {
    msg_.enemy_tunnel_highway_under = std::move(arg);
    return Init_RfidStatus_enemy_tunnel_highway_upper(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_tunnel_trapezoid_high
{
public:
  explicit Init_RfidStatus_friendly_tunnel_trapezoid_high(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_tunnel_highway_under friendly_tunnel_trapezoid_high(::rm_decision_interfaces::msg::RfidStatus::_friendly_tunnel_trapezoid_high_type arg)
  {
    msg_.friendly_tunnel_trapezoid_high = std::move(arg);
    return Init_RfidStatus_enemy_tunnel_highway_under(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_tunnel_trapezoid_low
{
public:
  explicit Init_RfidStatus_friendly_tunnel_trapezoid_low(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_tunnel_trapezoid_high friendly_tunnel_trapezoid_low(::rm_decision_interfaces::msg::RfidStatus::_friendly_tunnel_trapezoid_low_type arg)
  {
    msg_.friendly_tunnel_trapezoid_low = std::move(arg);
    return Init_RfidStatus_friendly_tunnel_trapezoid_high(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_tunnel_highway_upper
{
public:
  explicit Init_RfidStatus_friendly_tunnel_highway_upper(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_tunnel_trapezoid_low friendly_tunnel_highway_upper(::rm_decision_interfaces::msg::RfidStatus::_friendly_tunnel_highway_upper_type arg)
  {
    msg_.friendly_tunnel_highway_upper = std::move(arg);
    return Init_RfidStatus_friendly_tunnel_trapezoid_low(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_tunnel_highway_under
{
public:
  explicit Init_RfidStatus_friendly_tunnel_highway_under(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_tunnel_highway_upper friendly_tunnel_highway_under(::rm_decision_interfaces::msg::RfidStatus::_friendly_tunnel_highway_under_type arg)
  {
    msg_.friendly_tunnel_highway_under = std::move(arg);
    return Init_RfidStatus_friendly_tunnel_highway_upper(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_outpost_gain
{
public:
  explicit Init_RfidStatus_enemy_outpost_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_tunnel_highway_under enemy_outpost_gain(::rm_decision_interfaces::msg::RfidStatus::_enemy_outpost_gain_type arg)
  {
    msg_.enemy_outpost_gain = std::move(arg);
    return Init_RfidStatus_friendly_tunnel_highway_under(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_fortress_gain
{
public:
  explicit Init_RfidStatus_enemy_fortress_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_outpost_gain enemy_fortress_gain(::rm_decision_interfaces::msg::RfidStatus::_enemy_fortress_gain_type arg)
  {
    msg_.enemy_fortress_gain = std::move(arg);
    return Init_RfidStatus_enemy_outpost_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_center_gain_point_rmul
{
public:
  explicit Init_RfidStatus_center_gain_point_rmul(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_fortress_gain center_gain_point_rmul(::rm_decision_interfaces::msg::RfidStatus::_center_gain_point_rmul_type arg)
  {
    msg_.center_gain_point_rmul = std::move(arg);
    return Init_RfidStatus_enemy_fortress_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_energy_mechanism_gain
{
public:
  explicit Init_RfidStatus_enemy_energy_mechanism_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_center_gain_point_rmul enemy_energy_mechanism_gain(::rm_decision_interfaces::msg::RfidStatus::_enemy_energy_mechanism_gain_type arg)
  {
    msg_.enemy_energy_mechanism_gain = std::move(arg);
    return Init_RfidStatus_center_gain_point_rmul(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_energy_mechanism_gain
{
public:
  explicit Init_RfidStatus_friendly_energy_mechanism_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_energy_mechanism_gain friendly_energy_mechanism_gain(::rm_decision_interfaces::msg::RfidStatus::_friendly_energy_mechanism_gain_type arg)
  {
    msg_.friendly_energy_mechanism_gain = std::move(arg);
    return Init_RfidStatus_enemy_energy_mechanism_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_supply_zone_overlap
{
public:
  explicit Init_RfidStatus_friendly_supply_zone_overlap(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_energy_mechanism_gain friendly_supply_zone_overlap(::rm_decision_interfaces::msg::RfidStatus::_friendly_supply_zone_overlap_type arg)
  {
    msg_.friendly_supply_zone_overlap = std::move(arg);
    return Init_RfidStatus_friendly_energy_mechanism_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_supply_zone_non_overlap
{
public:
  explicit Init_RfidStatus_friendly_supply_zone_non_overlap(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_supply_zone_overlap friendly_supply_zone_non_overlap(::rm_decision_interfaces::msg::RfidStatus::_friendly_supply_zone_non_overlap_type arg)
  {
    msg_.friendly_supply_zone_non_overlap = std::move(arg);
    return Init_RfidStatus_friendly_supply_zone_overlap(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_outpost_gain
{
public:
  explicit Init_RfidStatus_friendly_outpost_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_supply_zone_non_overlap friendly_outpost_gain(::rm_decision_interfaces::msg::RfidStatus::_friendly_outpost_gain_type arg)
  {
    msg_.friendly_outpost_gain = std::move(arg);
    return Init_RfidStatus_friendly_supply_zone_non_overlap(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_fortress_gain
{
public:
  explicit Init_RfidStatus_friendly_fortress_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_outpost_gain friendly_fortress_gain(::rm_decision_interfaces::msg::RfidStatus::_friendly_fortress_gain_type arg)
  {
    msg_.friendly_fortress_gain = std::move(arg);
    return Init_RfidStatus_friendly_outpost_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_highway_upper
{
public:
  explicit Init_RfidStatus_enemy_highway_upper(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_fortress_gain enemy_highway_upper(::rm_decision_interfaces::msg::RfidStatus::_enemy_highway_upper_type arg)
  {
    msg_.enemy_highway_upper = std::move(arg);
    return Init_RfidStatus_friendly_fortress_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_highway_under
{
public:
  explicit Init_RfidStatus_enemy_highway_under(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_highway_upper enemy_highway_under(::rm_decision_interfaces::msg::RfidStatus::_enemy_highway_under_type arg)
  {
    msg_.enemy_highway_under = std::move(arg);
    return Init_RfidStatus_enemy_highway_upper(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_highway_upper
{
public:
  explicit Init_RfidStatus_friendly_highway_upper(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_highway_under friendly_highway_upper(::rm_decision_interfaces::msg::RfidStatus::_friendly_highway_upper_type arg)
  {
    msg_.friendly_highway_upper = std::move(arg);
    return Init_RfidStatus_enemy_highway_under(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_highway_under
{
public:
  explicit Init_RfidStatus_friendly_highway_under(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_highway_upper friendly_highway_under(::rm_decision_interfaces::msg::RfidStatus::_friendly_highway_under_type arg)
  {
    msg_.friendly_highway_under = std::move(arg);
    return Init_RfidStatus_friendly_highway_upper(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_central_highland_upper
{
public:
  explicit Init_RfidStatus_enemy_central_highland_upper(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_highway_under enemy_central_highland_upper(::rm_decision_interfaces::msg::RfidStatus::_enemy_central_highland_upper_type arg)
  {
    msg_.enemy_central_highland_upper = std::move(arg);
    return Init_RfidStatus_friendly_highway_under(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_central_highland_under
{
public:
  explicit Init_RfidStatus_enemy_central_highland_under(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_central_highland_upper enemy_central_highland_under(::rm_decision_interfaces::msg::RfidStatus::_enemy_central_highland_under_type arg)
  {
    msg_.enemy_central_highland_under = std::move(arg);
    return Init_RfidStatus_enemy_central_highland_upper(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_central_highland_upper
{
public:
  explicit Init_RfidStatus_friendly_central_highland_upper(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_central_highland_under friendly_central_highland_upper(::rm_decision_interfaces::msg::RfidStatus::_friendly_central_highland_upper_type arg)
  {
    msg_.friendly_central_highland_upper = std::move(arg);
    return Init_RfidStatus_enemy_central_highland_under(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_central_highland_under
{
public:
  explicit Init_RfidStatus_friendly_central_highland_under(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_central_highland_upper friendly_central_highland_under(::rm_decision_interfaces::msg::RfidStatus::_friendly_central_highland_under_type arg)
  {
    msg_.friendly_central_highland_under = std::move(arg);
    return Init_RfidStatus_friendly_central_highland_upper(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_fly_slope_post_gain
{
public:
  explicit Init_RfidStatus_enemy_fly_slope_post_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_central_highland_under enemy_fly_slope_post_gain(::rm_decision_interfaces::msg::RfidStatus::_enemy_fly_slope_post_gain_type arg)
  {
    msg_.enemy_fly_slope_post_gain = std::move(arg);
    return Init_RfidStatus_friendly_central_highland_under(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_fly_slope_pre_gain
{
public:
  explicit Init_RfidStatus_enemy_fly_slope_pre_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_fly_slope_post_gain enemy_fly_slope_pre_gain(::rm_decision_interfaces::msg::RfidStatus::_enemy_fly_slope_pre_gain_type arg)
  {
    msg_.enemy_fly_slope_pre_gain = std::move(arg);
    return Init_RfidStatus_enemy_fly_slope_post_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_fly_slope_post_gain
{
public:
  explicit Init_RfidStatus_friendly_fly_slope_post_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_fly_slope_pre_gain friendly_fly_slope_post_gain(::rm_decision_interfaces::msg::RfidStatus::_friendly_fly_slope_post_gain_type arg)
  {
    msg_.friendly_fly_slope_post_gain = std::move(arg);
    return Init_RfidStatus_enemy_fly_slope_pre_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_fly_slope_pre_gain
{
public:
  explicit Init_RfidStatus_friendly_fly_slope_pre_gain(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_fly_slope_post_gain friendly_fly_slope_pre_gain(::rm_decision_interfaces::msg::RfidStatus::_friendly_fly_slope_pre_gain_type arg)
  {
    msg_.friendly_fly_slope_pre_gain = std::move(arg);
    return Init_RfidStatus_friendly_fly_slope_post_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_trapezoidal_gain_point
{
public:
  explicit Init_RfidStatus_enemy_trapezoidal_gain_point(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_fly_slope_pre_gain enemy_trapezoidal_gain_point(::rm_decision_interfaces::msg::RfidStatus::_enemy_trapezoidal_gain_point_type arg)
  {
    msg_.enemy_trapezoidal_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_fly_slope_pre_gain(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_trapezoidal_gain_point
{
public:
  explicit Init_RfidStatus_friendly_trapezoidal_gain_point(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_trapezoidal_gain_point friendly_trapezoidal_gain_point(::rm_decision_interfaces::msg::RfidStatus::_friendly_trapezoidal_gain_point_type arg)
  {
    msg_.friendly_trapezoidal_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_trapezoidal_gain_point(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_enemy_central_highland_gain_point
{
public:
  explicit Init_RfidStatus_enemy_central_highland_gain_point(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_friendly_trapezoidal_gain_point enemy_central_highland_gain_point(::rm_decision_interfaces::msg::RfidStatus::_enemy_central_highland_gain_point_type arg)
  {
    msg_.enemy_central_highland_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_trapezoidal_gain_point(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_central_highland_gain_point
{
public:
  explicit Init_RfidStatus_friendly_central_highland_gain_point(::rm_decision_interfaces::msg::RfidStatus & msg)
  : msg_(msg)
  {}
  Init_RfidStatus_enemy_central_highland_gain_point friendly_central_highland_gain_point(::rm_decision_interfaces::msg::RfidStatus::_friendly_central_highland_gain_point_type arg)
  {
    msg_.friendly_central_highland_gain_point = std::move(arg);
    return Init_RfidStatus_enemy_central_highland_gain_point(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

class Init_RfidStatus_friendly_base_gain_point
{
public:
  Init_RfidStatus_friendly_base_gain_point()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RfidStatus_friendly_central_highland_gain_point friendly_base_gain_point(::rm_decision_interfaces::msg::RfidStatus::_friendly_base_gain_point_type arg)
  {
    msg_.friendly_base_gain_point = std::move(arg);
    return Init_RfidStatus_friendly_central_highland_gain_point(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RfidStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_decision_interfaces::msg::RfidStatus>()
{
  return rm_decision_interfaces::msg::builder::Init_RfidStatus_friendly_base_gain_point();
}

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__RFID_STATUS__BUILDER_HPP_
