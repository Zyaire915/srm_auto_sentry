/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2026, TU Dortmund
 *  All rights reserved.
 *
 *********************************************************************/

#ifndef EDGE_PREDICTED_OBSTACLE_H
#define EDGE_PREDICTED_OBSTACLE_H

#include "teb_local_planner/g2o_types/vertex_pose.h"
#include "teb_local_planner/g2o_types/base_teb_edges.h"
#include "teb_local_planner/g2o_types/penalties.h"
#include "teb_local_planner/obstacles.h"
#include "teb_local_planner/obstacle_tracker.h"
#include "teb_local_planner/teb_config.h"

namespace teb_local_planner
{

/**
 * @class EdgePredictedObstacle
 * @brief Edge for predicted obstacle avoidance using Kalman filter tracking
 */
class EdgePredictedObstacle : public BaseTebUnaryEdge<2, const Obstacle*, VertexPose>
{
public:
  /**
   * @brief Constructor
   * @param t Time for prediction
   * @param tracker Pointer to obstacle tracker
   * @param track_id Tracking ID of obstacle
   */
  EdgePredictedObstacle(double t, const ObstacleTracker* tracker, int track_id)
    : t_(t), tracker_(tracker), track_id_(track_id)
  {
    this->setMeasurement(nullptr);
  }

  /**
   * @brief Compute error for optimization
   */
  void computeError()
  {
    const VertexPose* bandpt = static_cast<const VertexPose*>(_vertices[0]);

    if (!tracker_ || !tracker_->hasTrack(track_id_))
    {
      _error.setZero();
      return;
    }

    Eigen::Vector2d pred_pos = tracker_->getPredictedPosition(track_id_, t_, *cfg_);
    double dist = (bandpt->position() - pred_pos).norm() - robot_model_->getInscribedRadius();

    _error[0] = penaltyBoundFromBelow(dist, cfg_->obstacles.min_obstacle_dist, cfg_->optim.penalty_epsilon);
    _error[1] = penaltyBoundFromBelow(dist, cfg_->obstacles.inflation_dist, 0.0);
  }

  /**
   * @brief Compute Jacobian for efficient optimization
   */
  void linearizeOplus()
  {
    const VertexPose* bandpt = static_cast<const VertexPose*>(_vertices[0]);

    if (!tracker_ || !tracker_->hasTrack(track_id_))
    {
      _jacobianOplusXi.setZero();
      return;
    }

    Eigen::Vector2d robot_pos = bandpt->position();
    Eigen::Vector2d pred_pos = tracker_->getPredictedPosition(track_id_, t_, *cfg_);
    Eigen::Vector2d diff = robot_pos - pred_pos;
    double dist = diff.norm();

    if (dist < 1e-5)
    {
      _jacobianOplusXi.setZero();
      return;
    }

    Eigen::Vector2d grad = diff / dist;

    double penalty_deriv_0 = penaltyBoundFromBelowDerivative(
      dist - robot_model_->getInscribedRadius(),
      cfg_->obstacles.min_obstacle_dist,
      cfg_->optim.penalty_epsilon
    );

    double penalty_deriv_1 = penaltyBoundFromBelowDerivative(
      dist - robot_model_->getInscribedRadius(),
      cfg_->obstacles.inflation_dist,
      0.0
    );

    _jacobianOplusXi(0, 0) = penalty_deriv_0 * grad[0];
    _jacobianOplusXi(0, 1) = penalty_deriv_0 * grad[1];
    _jacobianOplusXi(0, 2) = 0.0;

    _jacobianOplusXi(1, 0) = penalty_deriv_1 * grad[0];
    _jacobianOplusXi(1, 1) = penalty_deriv_1 * grad[1];
    _jacobianOplusXi(1, 2) = 0.0;
  }

  /**
   * @brief Set configuration and robot model
   */
  void setParameters(const TebConfig& cfg, const BaseRobotFootprintModel* robot_model, const Obstacle* obstacle)
  {
    cfg_ = &cfg;
    robot_model_ = robot_model;
  }

public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW

private:
  double t_;                              //!< Prediction time
  const ObstacleTracker* tracker_;        //!< Pointer to tracker
  int track_id_;                          //!< Tracking ID
  const TebConfig* cfg_;                  //!< Configuration
  const BaseRobotFootprintModel* robot_model_; //!< Robot model
};

} // namespace teb_local_planner

#endif // EDGE_PREDICTED_OBSTACLE_H
