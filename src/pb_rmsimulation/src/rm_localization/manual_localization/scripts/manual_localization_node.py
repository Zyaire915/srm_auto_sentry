#!/usr/bin/env python3
"""
manual_localization_node
========================
Lightweight node for manual localization via RViz "2D Pose Estimate".

Behaviour
---------
1. On startup the node broadcasts a static identity transform
   map -> odom  (T = I).
2. The node subscribes to ``/initialpose`` (geometry_msgs/PoseWithCovarianceStamped)
   which is published by the "2D Pose Estimate" button in RViz.
3. When a message arrives it is interpreted as  T_{map -> base_link}.
   The node looks up the current  T_{odom -> base_link}  and computes

       T_{map -> odom} = T_{map -> base_link} * T_{odom -> base_link}^{-1}

   This updated transform is then broadcast continuously at a fixed rate.
"""

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, DurabilityPolicy

from geometry_msgs.msg import (
    PoseWithCovarianceStamped,
    TransformStamped,
)
from tf2_ros import (
    Buffer,
    TransformBroadcaster,
    TransformListener,
)
import tf2_ros
import numpy as np
from rclpy.time import Time
from rclpy.duration import Duration


# ── Quaternion helpers (avoid external dependency) ──────────────────────
def q_to_mat(q):
    """Quaternion (x, y, z, w) -> 4×4 homogeneous matrix."""
    x, y, z, w = q
    return np.array([
        [1 - 2*(y*y + z*z),     2*(x*y - z*w),     2*(x*z + y*w), 0],
        [    2*(x*y + z*w), 1 - 2*(x*x + z*z),     2*(y*z - x*w), 0],
        [    2*(x*z - y*w),     2*(y*z + x*w), 1 - 2*(x*x + y*y), 0],
        [                0,                  0,                  0, 1],
    ])


def mat_to_q(m):
    """4×4 homogeneous matrix -> quaternion (x, y, z, w)."""
    tr = m[0, 0] + m[1, 1] + m[2, 2]
    if tr > 0:
        s = 0.5 / np.sqrt(tr + 1.0)
        w = 0.25 / s
        x = (m[2, 1] - m[1, 2]) * s
        y = (m[0, 2] - m[2, 0]) * s
        z = (m[1, 0] - m[0, 1]) * s
    elif m[0, 0] > m[1, 1] and m[0, 0] > m[2, 2]:
        s = 2.0 * np.sqrt(1.0 + m[0, 0] - m[1, 1] - m[2, 2])
        w = (m[2, 1] - m[1, 2]) / s
        x = 0.25 * s
        y = (m[0, 1] + m[1, 0]) / s
        z = (m[0, 2] + m[2, 0]) / s
    elif m[1, 1] > m[2, 2]:
        s = 2.0 * np.sqrt(1.0 + m[1, 1] - m[0, 0] - m[2, 2])
        w = (m[0, 2] - m[2, 0]) / s
        x = (m[0, 1] + m[1, 0]) / s
        y = 0.25 * s
        z = (m[1, 2] + m[2, 1]) / s
    else:
        s = 2.0 * np.sqrt(1.0 + m[2, 2] - m[0, 0] - m[1, 1])
        w = (m[1, 0] - m[0, 1]) / s
        x = (m[0, 2] + m[2, 0]) / s
        y = (m[1, 2] + m[2, 1]) / s
        z = 0.25 * s
    return (x, y, z, w)


def pose_to_mat(pose):
    """geometry_msgs/Pose -> 4×4 homogeneous matrix."""
    p = pose.position
    o = pose.orientation
    m = q_to_mat((o.x, o.y, o.z, o.w))
    m[0, 3] = p.x
    m[1, 3] = p.y
    m[2, 3] = p.z
    return m


def transform_to_mat(tf_msg: TransformStamped):
    """geometry_msgs/TransformStamped -> 4×4 homogeneous matrix."""
    t = tf_msg.transform.translation
    r = tf_msg.transform.rotation
    m = q_to_mat((r.x, r.y, r.z, r.w))
    m[0, 3] = t.x
    m[1, 3] = t.y
    m[2, 3] = t.z
    return m


# ── Node ────────────────────────────────────────────────────────────────
class ManualLocalizationNode(Node):
    def __init__(self):
        super().__init__('manual_localization_node')

        # Parameters
        self.declare_parameter('publish_rate', 50.0)       # Hz
        self.declare_parameter('odom_frame', 'odom')
        self.declare_parameter('map_frame', 'map')
        self.declare_parameter('base_frame', 'base_link')

        rate = self.get_parameter('publish_rate').value
        self.odom_frame = self.get_parameter('odom_frame').value
        self.map_frame = self.get_parameter('map_frame').value
        self.base_frame = self.get_parameter('base_frame').value

        # TF infrastructure
        self.tf_buffer = Buffer(cache_time=Duration(seconds=30.0))
        self.tf_listener = TransformListener(self.tf_buffer, self)
        self.tf_broadcaster = TransformBroadcaster(self)

        # Initial map->odom is identity
        self.T_map_odom = np.eye(4)

        # Subscribe to RViz "2D Pose Estimate"
        self.create_subscription(
            PoseWithCovarianceStamped,
            '/initialpose',
            self._initialpose_cb,
            10,
        )

        # Timer for periodic TF broadcast
        period = 1.0 / rate
        self.create_timer(period, self._publish_tf)

        self.get_logger().info(
            f'Manual localization node started – broadcasting '
            f'{self.map_frame} -> {self.odom_frame} at {rate} Hz'
        )

    # ── Callback: /initialpose ──────────────────────────────────────────
    def _initialpose_cb(self, msg: PoseWithCovarianceStamped):
        """
        msg gives  T_{map -> base_link}.
        We need    T_{map -> odom} = T_{map -> base_link} * T_{base_link -> odom}
                                   = T_{map -> base_link} * inv(T_{odom -> base_link})
        """
        # T_{map -> base_link} from the incoming pose
        T_map_base = pose_to_mat(msg.pose.pose)

        # Look up T_{odom -> base_link}
        try:
            tf_odom_base = self.tf_buffer.lookup_transform(
                self.odom_frame, self.base_frame, Time()
            )
        except (tf2_ros.LookupException,
                tf2_ros.ConnectivityException,
                tf2_ros.ExtrapolationException) as e:
            self.get_logger().warn(
                f'Could not look up {self.odom_frame} -> {self.base_frame}: {e}'
            )
            return

        T_odom_base = transform_to_mat(tf_odom_base)

        # T_{map -> odom} = T_{map -> base_link} * inv(T_{odom -> base_link})
        self.T_map_odom = T_map_base @ np.linalg.inv(T_odom_base)

        self.get_logger().info('Updated map -> odom from /initialpose')

    # ── Periodic broadcast ──────────────────────────────────────────────
    def _publish_tf(self):
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = self.map_frame
        t.child_frame_id = self.odom_frame

        t.transform.translation.x = float(self.T_map_odom[0, 3])
        t.transform.translation.y = float(self.T_map_odom[1, 3])
        t.transform.translation.z = float(self.T_map_odom[2, 3])

        qx, qy, qz, qw = mat_to_q(self.T_map_odom)
        t.transform.rotation.x = float(qx)
        t.transform.rotation.y = float(qy)
        t.transform.rotation.z = float(qz)
        t.transform.rotation.w = float(qw)

        self.tf_broadcaster.sendTransform(t)


def main(args=None):
    rclpy.init(args=args)
    node = ManualLocalizationNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
