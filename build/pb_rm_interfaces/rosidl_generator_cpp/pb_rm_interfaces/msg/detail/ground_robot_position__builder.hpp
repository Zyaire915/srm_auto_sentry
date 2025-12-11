// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/GroundRobotPosition.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/ground_robot_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_GroundRobotPosition_standard_5_y
{
public:
  explicit Init_GroundRobotPosition_standard_5_y(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::GroundRobotPosition standard_5_y(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_5_y_type arg)
  {
    msg_.standard_5_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_standard_5_x
{
public:
  explicit Init_GroundRobotPosition_standard_5_x(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_5_y standard_5_x(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_5_x_type arg)
  {
    msg_.standard_5_x = std::move(arg);
    return Init_GroundRobotPosition_standard_5_y(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_standard_4_y
{
public:
  explicit Init_GroundRobotPosition_standard_4_y(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_5_x standard_4_y(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_4_y_type arg)
  {
    msg_.standard_4_y = std::move(arg);
    return Init_GroundRobotPosition_standard_5_x(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_standard_4_x
{
public:
  explicit Init_GroundRobotPosition_standard_4_x(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_4_y standard_4_x(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_4_x_type arg)
  {
    msg_.standard_4_x = std::move(arg);
    return Init_GroundRobotPosition_standard_4_y(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_standard_3_y
{
public:
  explicit Init_GroundRobotPosition_standard_3_y(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_4_x standard_3_y(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_3_y_type arg)
  {
    msg_.standard_3_y = std::move(arg);
    return Init_GroundRobotPosition_standard_4_x(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_standard_3_x
{
public:
  explicit Init_GroundRobotPosition_standard_3_x(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_3_y standard_3_x(::pb_rm_interfaces::msg::GroundRobotPosition::_standard_3_x_type arg)
  {
    msg_.standard_3_x = std::move(arg);
    return Init_GroundRobotPosition_standard_3_y(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_engineer_y
{
public:
  explicit Init_GroundRobotPosition_engineer_y(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_standard_3_x engineer_y(::pb_rm_interfaces::msg::GroundRobotPosition::_engineer_y_type arg)
  {
    msg_.engineer_y = std::move(arg);
    return Init_GroundRobotPosition_standard_3_x(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_engineer_x
{
public:
  explicit Init_GroundRobotPosition_engineer_x(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_engineer_y engineer_x(::pb_rm_interfaces::msg::GroundRobotPosition::_engineer_x_type arg)
  {
    msg_.engineer_x = std::move(arg);
    return Init_GroundRobotPosition_engineer_y(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_hero_y
{
public:
  explicit Init_GroundRobotPosition_hero_y(::pb_rm_interfaces::msg::GroundRobotPosition & msg)
  : msg_(msg)
  {}
  Init_GroundRobotPosition_engineer_x hero_y(::pb_rm_interfaces::msg::GroundRobotPosition::_hero_y_type arg)
  {
    msg_.hero_y = std::move(arg);
    return Init_GroundRobotPosition_engineer_x(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

class Init_GroundRobotPosition_hero_x
{
public:
  Init_GroundRobotPosition_hero_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GroundRobotPosition_hero_y hero_x(::pb_rm_interfaces::msg::GroundRobotPosition::_hero_x_type arg)
  {
    msg_.hero_x = std::move(arg);
    return Init_GroundRobotPosition_hero_y(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GroundRobotPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::GroundRobotPosition>()
{
  return pb_rm_interfaces::msg::builder::Init_GroundRobotPosition_hero_x();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GROUND_ROBOT_POSITION__BUILDER_HPP_
