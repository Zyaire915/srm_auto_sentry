// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/EventData.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/event_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_EventData_base_gain_point_status
{
public:
  explicit Init_EventData_base_gain_point_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::EventData base_gain_point_status(::pb_rm_interfaces::msg::EventData::_base_gain_point_status_type arg)
  {
    msg_.base_gain_point_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_outpost_gain_point_status
{
public:
  explicit Init_EventData_outpost_gain_point_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_base_gain_point_status outpost_gain_point_status(::pb_rm_interfaces::msg::EventData::_outpost_gain_point_status_type arg)
  {
    msg_.outpost_gain_point_status = std::move(arg);
    return Init_EventData_base_gain_point_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_fortress_gain_point_status
{
public:
  explicit Init_EventData_fortress_gain_point_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_outpost_gain_point_status fortress_gain_point_status(::pb_rm_interfaces::msg::EventData::_fortress_gain_point_status_type arg)
  {
    msg_.fortress_gain_point_status = std::move(arg);
    return Init_EventData_outpost_gain_point_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_center_gain_point_status
{
public:
  explicit Init_EventData_center_gain_point_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_fortress_gain_point_status center_gain_point_status(::pb_rm_interfaces::msg::EventData::_center_gain_point_status_type arg)
  {
    msg_.center_gain_point_status = std::move(arg);
    return Init_EventData_fortress_gain_point_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_dart_last_hit_target
{
public:
  explicit Init_EventData_dart_last_hit_target(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_center_gain_point_status dart_last_hit_target(::pb_rm_interfaces::msg::EventData::_dart_last_hit_target_type arg)
  {
    msg_.dart_last_hit_target = std::move(arg);
    return Init_EventData_center_gain_point_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_dart_last_hit_time
{
public:
  explicit Init_EventData_dart_last_hit_time(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_dart_last_hit_target dart_last_hit_time(::pb_rm_interfaces::msg::EventData::_dart_last_hit_time_type arg)
  {
    msg_.dart_last_hit_time = std::move(arg);
    return Init_EventData_dart_last_hit_target(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_trapezoidal_highland_status
{
public:
  explicit Init_EventData_trapezoidal_highland_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_dart_last_hit_time trapezoidal_highland_status(::pb_rm_interfaces::msg::EventData::_trapezoidal_highland_status_type arg)
  {
    msg_.trapezoidal_highland_status = std::move(arg);
    return Init_EventData_dart_last_hit_time(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_central_highland_status
{
public:
  explicit Init_EventData_central_highland_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_trapezoidal_highland_status central_highland_status(::pb_rm_interfaces::msg::EventData::_central_highland_status_type arg)
  {
    msg_.central_highland_status = std::move(arg);
    return Init_EventData_trapezoidal_highland_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_big_energy_status
{
public:
  explicit Init_EventData_big_energy_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_central_highland_status big_energy_status(::pb_rm_interfaces::msg::EventData::_big_energy_status_type arg)
  {
    msg_.big_energy_status = std::move(arg);
    return Init_EventData_central_highland_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_small_energy_status
{
public:
  explicit Init_EventData_small_energy_status(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_big_energy_status small_energy_status(::pb_rm_interfaces::msg::EventData::_small_energy_status_type arg)
  {
    msg_.small_energy_status = std::move(arg);
    return Init_EventData_big_energy_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_supply_zone_rmul
{
public:
  explicit Init_EventData_supply_zone_rmul(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_small_energy_status supply_zone_rmul(::pb_rm_interfaces::msg::EventData::_supply_zone_rmul_type arg)
  {
    msg_.supply_zone_rmul = std::move(arg);
    return Init_EventData_small_energy_status(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_supply_zone_overlap
{
public:
  explicit Init_EventData_supply_zone_overlap(::pb_rm_interfaces::msg::EventData & msg)
  : msg_(msg)
  {}
  Init_EventData_supply_zone_rmul supply_zone_overlap(::pb_rm_interfaces::msg::EventData::_supply_zone_overlap_type arg)
  {
    msg_.supply_zone_overlap = std::move(arg);
    return Init_EventData_supply_zone_rmul(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

class Init_EventData_supply_zone_non_overlap
{
public:
  Init_EventData_supply_zone_non_overlap()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EventData_supply_zone_overlap supply_zone_non_overlap(::pb_rm_interfaces::msg::EventData::_supply_zone_non_overlap_type arg)
  {
    msg_.supply_zone_non_overlap = std::move(arg);
    return Init_EventData_supply_zone_overlap(msg_);
  }

private:
  ::pb_rm_interfaces::msg::EventData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::EventData>()
{
  return pb_rm_interfaces::msg::builder::Init_EventData_supply_zone_non_overlap();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__EVENT_DATA__BUILDER_HPP_
