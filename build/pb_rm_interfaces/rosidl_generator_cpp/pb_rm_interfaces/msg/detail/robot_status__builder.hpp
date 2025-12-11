// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_shooter_17mm_1_barrel_heat
{
public:
  explicit Init_RobotStatus_shooter_17mm_1_barrel_heat(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::RobotStatus shooter_17mm_1_barrel_heat(::pb_rm_interfaces::msg::RobotStatus::_shooter_17mm_1_barrel_heat_type arg)
  {
    msg_.shooter_17mm_1_barrel_heat = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_maximum_hp
{
public:
  explicit Init_RobotStatus_maximum_hp(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_shooter_17mm_1_barrel_heat maximum_hp(::pb_rm_interfaces::msg::RobotStatus::_maximum_hp_type arg)
  {
    msg_.maximum_hp = std::move(arg);
    return Init_RobotStatus_shooter_17mm_1_barrel_heat(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_current_hp
{
public:
  explicit Init_RobotStatus_current_hp(::pb_rm_interfaces::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_maximum_hp current_hp(::pb_rm_interfaces::msg::RobotStatus::_current_hp_type arg)
  {
    msg_.current_hp = std::move(arg);
    return Init_RobotStatus_maximum_hp(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_id
{
public:
  Init_RobotStatus_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_current_hp robot_id(::pb_rm_interfaces::msg::RobotStatus::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotStatus_current_hp(msg_);
  }

private:
  ::pb_rm_interfaces::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::RobotStatus>()
{
  return pb_rm_interfaces::msg::builder::Init_RobotStatus_robot_id();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
