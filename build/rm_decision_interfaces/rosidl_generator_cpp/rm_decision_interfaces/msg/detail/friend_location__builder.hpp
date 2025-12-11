// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_decision_interfaces:msg/FriendLocation.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__BUILDER_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_decision_interfaces/msg/detail/friend_location__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_decision_interfaces
{

namespace msg
{

namespace builder
{

class Init_FriendLocation_standard_5_y
{
public:
  explicit Init_FriendLocation_standard_5_y(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  ::rm_decision_interfaces::msg::FriendLocation standard_5_y(::rm_decision_interfaces::msg::FriendLocation::_standard_5_y_type arg)
  {
    msg_.standard_5_y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_standard_5_x
{
public:
  explicit Init_FriendLocation_standard_5_x(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_standard_5_y standard_5_x(::rm_decision_interfaces::msg::FriendLocation::_standard_5_x_type arg)
  {
    msg_.standard_5_x = std::move(arg);
    return Init_FriendLocation_standard_5_y(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_standard_4_y
{
public:
  explicit Init_FriendLocation_standard_4_y(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_standard_5_x standard_4_y(::rm_decision_interfaces::msg::FriendLocation::_standard_4_y_type arg)
  {
    msg_.standard_4_y = std::move(arg);
    return Init_FriendLocation_standard_5_x(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_standard_4_x
{
public:
  explicit Init_FriendLocation_standard_4_x(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_standard_4_y standard_4_x(::rm_decision_interfaces::msg::FriendLocation::_standard_4_x_type arg)
  {
    msg_.standard_4_x = std::move(arg);
    return Init_FriendLocation_standard_4_y(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_standard_3_y
{
public:
  explicit Init_FriendLocation_standard_3_y(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_standard_4_x standard_3_y(::rm_decision_interfaces::msg::FriendLocation::_standard_3_y_type arg)
  {
    msg_.standard_3_y = std::move(arg);
    return Init_FriendLocation_standard_4_x(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_standard_3_x
{
public:
  explicit Init_FriendLocation_standard_3_x(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_standard_3_y standard_3_x(::rm_decision_interfaces::msg::FriendLocation::_standard_3_x_type arg)
  {
    msg_.standard_3_x = std::move(arg);
    return Init_FriendLocation_standard_3_y(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_engineer_y
{
public:
  explicit Init_FriendLocation_engineer_y(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_standard_3_x engineer_y(::rm_decision_interfaces::msg::FriendLocation::_engineer_y_type arg)
  {
    msg_.engineer_y = std::move(arg);
    return Init_FriendLocation_standard_3_x(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_engineer_x
{
public:
  explicit Init_FriendLocation_engineer_x(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_engineer_y engineer_x(::rm_decision_interfaces::msg::FriendLocation::_engineer_x_type arg)
  {
    msg_.engineer_x = std::move(arg);
    return Init_FriendLocation_engineer_y(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_hero_y
{
public:
  explicit Init_FriendLocation_hero_y(::rm_decision_interfaces::msg::FriendLocation & msg)
  : msg_(msg)
  {}
  Init_FriendLocation_engineer_x hero_y(::rm_decision_interfaces::msg::FriendLocation::_hero_y_type arg)
  {
    msg_.hero_y = std::move(arg);
    return Init_FriendLocation_engineer_x(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

class Init_FriendLocation_hero_x
{
public:
  Init_FriendLocation_hero_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FriendLocation_hero_y hero_x(::rm_decision_interfaces::msg::FriendLocation::_hero_x_type arg)
  {
    msg_.hero_x = std::move(arg);
    return Init_FriendLocation_hero_y(msg_);
  }

private:
  ::rm_decision_interfaces::msg::FriendLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_decision_interfaces::msg::FriendLocation>()
{
  return rm_decision_interfaces::msg::builder::Init_FriendLocation_hero_x();
}

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__FRIEND_LOCATION__BUILDER_HPP_
