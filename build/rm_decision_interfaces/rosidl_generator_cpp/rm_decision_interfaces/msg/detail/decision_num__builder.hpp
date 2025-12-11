// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rm_decision_interfaces:msg/DecisionNum.idl
// generated code does not contain a copyright notice

#ifndef RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__BUILDER_HPP_
#define RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rm_decision_interfaces/msg/detail/decision_num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rm_decision_interfaces
{

namespace msg
{

namespace builder
{

class Init_DecisionNum_decision_num
{
public:
  Init_DecisionNum_decision_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::rm_decision_interfaces::msg::DecisionNum decision_num(::rm_decision_interfaces::msg::DecisionNum::_decision_num_type arg)
  {
    msg_.decision_num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rm_decision_interfaces::msg::DecisionNum msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rm_decision_interfaces::msg::DecisionNum>()
{
  return rm_decision_interfaces::msg::builder::Init_DecisionNum_decision_num();
}

}  // namespace rm_decision_interfaces

#endif  // RM_DECISION_INTERFACES__MSG__DETAIL__DECISION_NUM__BUILDER_HPP_
