// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_decision_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_decision_interfaces/msg/detail/game_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_decision_interfaces
{

namespace msg
{

namespace builder
{

class Init_GameStatus_sync_time_stamp
{
public:
  explicit Init_GameStatus_sync_time_stamp(::rm_decision_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  ::rm_decision_interfaces::msg::GameStatus sync_time_stamp(::rm_decision_interfaces::msg::GameStatus::_sync_time_stamp_type arg)
  {
    msg_.sync_time_stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_decision_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_stage_remain_time
{
public:
  explicit Init_GameStatus_stage_remain_time(::rm_decision_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_sync_time_stamp stage_remain_time(::rm_decision_interfaces::msg::GameStatus::_stage_remain_time_type arg)
  {
    msg_.stage_remain_time = std::move(arg);
    return Init_GameStatus_sync_time_stamp(msg_);
  }

private:
  ::rm_decision_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_game_progress
{
public:
  explicit Init_GameStatus_game_progress(::rm_decision_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_stage_remain_time game_progress(::rm_decision_interfaces::msg::GameStatus::_game_progress_type arg)
  {
    msg_.game_progress = std::move(arg);
    return Init_GameStatus_stage_remain_time(msg_);
  }

private:
  ::rm_decision_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_game_type
{
public:
  Init_GameStatus_game_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameStatus_game_progress game_type(::rm_decision_interfaces::msg::GameStatus::_game_type_type arg)
  {
    msg_.game_type = std::move(arg);
    return Init_GameStatus_game_progress(msg_);
  }

private:
  ::rm_decision_interfaces::msg::GameStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_decision_interfaces::msg::GameStatus>()
{
  return rm_decision_interfaces::msg::builder::Init_GameStatus_game_type();
}

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
