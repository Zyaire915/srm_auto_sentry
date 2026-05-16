#include <string>
#include "behaviortree_cpp/condition_node.h"
#include "pb_rm_interfaces/msg/switch_position.hpp"

namespace rm_behavior_tree
{

class IsOutpostNotCompletedAction : public BT::SimpleConditionNode
{
public:
  explicit IsOutpostNotCompletedAction(const std::string & name, const BT::NodeConfig & config);

  static BT::PortsList providedPorts()
  {
    return {
      BT::InputPort<pb_rm_interfaces::msg::SwitchPosition>("switch_position"),
    };
  }

private:
  BT::NodeStatus checkOutpostStatus();
};

}  // namespace rm_behavior_tree
