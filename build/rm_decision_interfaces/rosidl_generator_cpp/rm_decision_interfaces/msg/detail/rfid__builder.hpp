// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_decision_interfaces:msg/RFID.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__RFID__BUILDER_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__RFID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_decision_interfaces/msg/detail/rfid__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_decision_interfaces
{

namespace msg
{

namespace builder
{

class Init_RFID_rfid_patrol_status
{
public:
  Init_RFID_rfid_patrol_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rm_decision_interfaces::msg::RFID rfid_patrol_status(::rm_decision_interfaces::msg::RFID::_rfid_patrol_status_type arg)
  {
    msg_.rfid_patrol_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_decision_interfaces::msg::RFID msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_decision_interfaces::msg::RFID>()
{
  return rm_decision_interfaces::msg::builder::Init_RFID_rfid_patrol_status();
}

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__RFID__BUILDER_HPP_
