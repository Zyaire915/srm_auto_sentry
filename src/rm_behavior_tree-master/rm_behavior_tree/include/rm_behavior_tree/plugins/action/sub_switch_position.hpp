#include "behaviortree_ros2/bt_topic_sub_node.hpp"
#include "pb_rm_interfaces/msg/switch_position.hpp"

namespace rm_behavior_tree
{

class SubSwitchPositionAction
: public BT::RosTopicSubNode<pb_rm_interfaces::msg::SwitchPosition>
{
public:
  SubSwitchPositionAction(
    const std::string & name, const BT::NodeConfig & conf, const BT::RosNodeParams & params);

  static BT::PortsList providedPorts();

  BT::NodeStatus onTick(
    const std::shared_ptr<pb_rm_interfaces::msg::SwitchPosition> & last_msg) override;
};

}  // namespace rm_behavior_tree
