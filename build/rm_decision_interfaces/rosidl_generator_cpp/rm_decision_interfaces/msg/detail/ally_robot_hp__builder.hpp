// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_decision_interfaces:msg/AllyRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__BUILDER_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_decision_interfaces/msg/detail/ally_robot_hp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_decision_interfaces
{

namespace msg
{

namespace builder
{

class Init_AllyRobotHP_ally_base_hp
{
public:
  explicit Init_AllyRobotHP_ally_base_hp(::rm_decision_interfaces::msg::AllyRobotHP & msg)
  : msg_(msg)
  {}
  ::rm_decision_interfaces::msg::AllyRobotHP ally_base_hp(::rm_decision_interfaces::msg::AllyRobotHP::_ally_base_hp_type arg)
  {
    msg_.ally_base_hp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllyRobotHP msg_;
};

class Init_AllyRobotHP_ally_outpost_hp
{
public:
  explicit Init_AllyRobotHP_ally_outpost_hp(::rm_decision_interfaces::msg::AllyRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllyRobotHP_ally_base_hp ally_outpost_hp(::rm_decision_interfaces::msg::AllyRobotHP::_ally_outpost_hp_type arg)
  {
    msg_.ally_outpost_hp = std::move(arg);
    return Init_AllyRobotHP_ally_base_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllyRobotHP msg_;
};

class Init_AllyRobotHP_ally_7_robot_hp
{
public:
  explicit Init_AllyRobotHP_ally_7_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllyRobotHP_ally_outpost_hp ally_7_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP::_ally_7_robot_hp_type arg)
  {
    msg_.ally_7_robot_hp = std::move(arg);
    return Init_AllyRobotHP_ally_outpost_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllyRobotHP msg_;
};

class Init_AllyRobotHP_ally_4_robot_hp
{
public:
  explicit Init_AllyRobotHP_ally_4_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllyRobotHP_ally_7_robot_hp ally_4_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP::_ally_4_robot_hp_type arg)
  {
    msg_.ally_4_robot_hp = std::move(arg);
    return Init_AllyRobotHP_ally_7_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllyRobotHP msg_;
};

class Init_AllyRobotHP_ally_3_robot_hp
{
public:
  explicit Init_AllyRobotHP_ally_3_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllyRobotHP_ally_4_robot_hp ally_3_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP::_ally_3_robot_hp_type arg)
  {
    msg_.ally_3_robot_hp = std::move(arg);
    return Init_AllyRobotHP_ally_4_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllyRobotHP msg_;
};

class Init_AllyRobotHP_ally_2_robot_hp
{
public:
  explicit Init_AllyRobotHP_ally_2_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllyRobotHP_ally_3_robot_hp ally_2_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP::_ally_2_robot_hp_type arg)
  {
    msg_.ally_2_robot_hp = std::move(arg);
    return Init_AllyRobotHP_ally_3_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllyRobotHP msg_;
};

class Init_AllyRobotHP_ally_1_robot_hp
{
public:
  Init_AllyRobotHP_ally_1_robot_hp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AllyRobotHP_ally_2_robot_hp ally_1_robot_hp(::rm_decision_interfaces::msg::AllyRobotHP::_ally_1_robot_hp_type arg)
  {
    msg_.ally_1_robot_hp = std::move(arg);
    return Init_AllyRobotHP_ally_2_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllyRobotHP msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_decision_interfaces::msg::AllyRobotHP>()
{
  return rm_decision_interfaces::msg::builder::Init_AllyRobotHP_ally_1_robot_hp();
}

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__ALLY_ROBOT_HP__BUILDER_HPP_
