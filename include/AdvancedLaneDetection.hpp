#ifndef ADVANCED_LANE_DETECTION_HPP
#define ADVANCED_LANE_DETECTION_HPP

#include "LaneDetectionAlgorithm.hpp"

class AdvancedLaneDetection : public LaneDetectionAlgorithm {
public:
    double detectLaneOffset(const std::vector<int>& sensorData) override;
};

#endif // ADVANCED_LANE_DETECTION_HPP
