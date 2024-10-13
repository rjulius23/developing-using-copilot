#ifndef LANE_DETECTION_ALGORITHM_HPP
#define LANE_DETECTION_ALGORITHM_HPP

#include <vector>
#include <iostream>

class LaneDetectionAlgorithm {
public:
    virtual ~LaneDetectionAlgorithm() = default;
    virtual double detectLaneOffset(const std::vector<int>& sensorData);
};

#endif // LANE_DETECTION_ALGORITHM_HPP

