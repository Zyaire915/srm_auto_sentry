// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pb_rm_interfaces:msg/GameStatus.idl
// generated code does not contain a copyright notice

#ifndef PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
#define PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pb_rm_interfaces/msg/detail/game_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pb_rm_interfaces
{

namespace msg
{

namespace builder
{

class Init_GameStatus_sync_time_stamp
{
public:
  explicit Init_GameStatus_sync_time_stamp(::pb_rm_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  ::pb_rm_interfaces::msg::GameStatus sync_time_stamp(::pb_rm_interfaces::msg::GameStatus::_sync_time_stamp_type arg)
  {
    msg_.sync_time_stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_stage_remain_time
{
public:
  explicit Init_GameStatus_stage_remain_time(::pb_rm_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_sync_time_stamp stage_remain_time(::pb_rm_interfaces::msg::GameStatus::_stage_remain_time_type arg)
  {
    msg_.stage_remain_time = std::move(arg);
    return Init_GameStatus_sync_time_stamp(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_game_progress
{
public:
  explicit Init_GameStatus_game_progress(::pb_rm_interfaces::msg::GameStatus & msg)
  : msg_(msg)
  {}
  Init_GameStatus_stage_remain_time game_progress(::pb_rm_interfaces::msg::GameStatus::_game_progress_type arg)
  {
    msg_.game_progress = std::move(arg);
    return Init_GameStatus_stage_remain_time(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GameStatus msg_;
};

class Init_GameStatus_game_type
{
public:
  Init_GameStatus_game_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GameStatus_game_progress game_type(::pb_rm_interfaces::msg::GameStatus::_game_type_type arg)
  {
    msg_.game_type = std::move(arg);
    return Init_GameStatus_game_progress(msg_);
  }

private:
  ::pb_rm_interfaces::msg::GameStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pb_rm_interfaces::msg::GameStatus>()
{
  return pb_rm_interfaces::msg::builder::Init_GameStatus_game_type();
}

}  // namespace pb_rm_interfaces

#endif  // PB_RM_INTERFACES__MSG__DETAIL__GAME_STATUS__BUILDER_HPP_
