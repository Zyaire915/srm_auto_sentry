// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_decision_interfaces:msg/AllRobotHP.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__BUILDER_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_decision_interfaces/msg/detail/all_robot_hp__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_decision_interfaces
{

namespace msg
{

namespace builder
{

class Init_AllRobotHP_blue_base_hp
{
public:
  explicit Init_AllRobotHP_blue_base_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  ::rm_decision_interfaces::msg::AllRobotHP blue_base_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_base_hp_type arg)
  {
    msg_.blue_base_hp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_outpost_hp
{
public:
  explicit Init_AllRobotHP_blue_outpost_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_base_hp blue_outpost_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_outpost_hp_type arg)
  {
    msg_.blue_outpost_hp = std::move(arg);
    return Init_AllRobotHP_blue_base_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_7_robot_hp
{
public:
  explicit Init_AllRobotHP_blue_7_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_outpost_hp blue_7_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_7_robot_hp_type arg)
  {
    msg_.blue_7_robot_hp = std::move(arg);
    return Init_AllRobotHP_blue_outpost_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_5_robot_hp
{
public:
  explicit Init_AllRobotHP_blue_5_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_7_robot_hp blue_5_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_5_robot_hp_type arg)
  {
    msg_.blue_5_robot_hp = std::move(arg);
    return Init_AllRobotHP_blue_7_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_4_robot_hp
{
public:
  explicit Init_AllRobotHP_blue_4_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_5_robot_hp blue_4_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_4_robot_hp_type arg)
  {
    msg_.blue_4_robot_hp = std::move(arg);
    return Init_AllRobotHP_blue_5_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_3_robot_hp
{
public:
  explicit Init_AllRobotHP_blue_3_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_4_robot_hp blue_3_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_3_robot_hp_type arg)
  {
    msg_.blue_3_robot_hp = std::move(arg);
    return Init_AllRobotHP_blue_4_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_2_robot_hp
{
public:
  explicit Init_AllRobotHP_blue_2_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_3_robot_hp blue_2_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_2_robot_hp_type arg)
  {
    msg_.blue_2_robot_hp = std::move(arg);
    return Init_AllRobotHP_blue_3_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_blue_1_robot_hp
{
public:
  explicit Init_AllRobotHP_blue_1_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_2_robot_hp blue_1_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_blue_1_robot_hp_type arg)
  {
    msg_.blue_1_robot_hp = std::move(arg);
    return Init_AllRobotHP_blue_2_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_base_hp
{
public:
  explicit Init_AllRobotHP_red_base_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_blue_1_robot_hp red_base_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_base_hp_type arg)
  {
    msg_.red_base_hp = std::move(arg);
    return Init_AllRobotHP_blue_1_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_outpost_hp
{
public:
  explicit Init_AllRobotHP_red_outpost_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_base_hp red_outpost_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_outpost_hp_type arg)
  {
    msg_.red_outpost_hp = std::move(arg);
    return Init_AllRobotHP_red_base_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_7_robot_hp
{
public:
  explicit Init_AllRobotHP_red_7_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_outpost_hp red_7_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_7_robot_hp_type arg)
  {
    msg_.red_7_robot_hp = std::move(arg);
    return Init_AllRobotHP_red_outpost_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_5_robot_hp
{
public:
  explicit Init_AllRobotHP_red_5_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_7_robot_hp red_5_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_5_robot_hp_type arg)
  {
    msg_.red_5_robot_hp = std::move(arg);
    return Init_AllRobotHP_red_7_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_4_robot_hp
{
public:
  explicit Init_AllRobotHP_red_4_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_5_robot_hp red_4_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_4_robot_hp_type arg)
  {
    msg_.red_4_robot_hp = std::move(arg);
    return Init_AllRobotHP_red_5_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_3_robot_hp
{
public:
  explicit Init_AllRobotHP_red_3_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_4_robot_hp red_3_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_3_robot_hp_type arg)
  {
    msg_.red_3_robot_hp = std::move(arg);
    return Init_AllRobotHP_red_4_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_2_robot_hp
{
public:
  explicit Init_AllRobotHP_red_2_robot_hp(::rm_decision_interfaces::msg::AllRobotHP & msg)
  : msg_(msg)
  {}
  Init_AllRobotHP_red_3_robot_hp red_2_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_2_robot_hp_type arg)
  {
    msg_.red_2_robot_hp = std::move(arg);
    return Init_AllRobotHP_red_3_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

class Init_AllRobotHP_red_1_robot_hp
{
public:
  Init_AllRobotHP_red_1_robot_hp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AllRobotHP_red_2_robot_hp red_1_robot_hp(::rm_decision_interfaces::msg::AllRobotHP::_red_1_robot_hp_type arg)
  {
    msg_.red_1_robot_hp = std::move(arg);
    return Init_AllRobotHP_red_2_robot_hp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::AllRobotHP msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_decision_interfaces::msg::AllRobotHP>()
{
  return rm_decision_interfaces::msg::builder::Init_AllRobotHP_red_1_robot_hp();
}

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__ALL_ROBOT_HP__BUILDER_HPP_
