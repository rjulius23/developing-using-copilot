#ifndef SIMPLE_LANE_DETECTION_HPP
#define SIMPLE_LANE_DETECTION_HPP

#include "LaneDetectionAlgorithm.hpp"

class SimpleLaneDetection : public LaneDetectionAlgorithm {
public:
    double detectLaneOffset(const std::vector<int>& sensorData) override;
};

#endif // SIMPLE_LANE_DETECTION_HPP