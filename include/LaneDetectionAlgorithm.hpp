#ifndef LANE_KEEPING_ASSISTANT_HPP
#define LANE_KEEPING_ASSISTANT_HPP

#include "LaneDetectionAlgorithm.hpp"
#include <vector>

class LaneKeepingAssistant {
private:
    LaneDetectionAlgorithm* laneDetector;

public:
    LaneKeepingAssistant(LaneDetectionAlgorithm* detector);
    double processSensorData(const std::vector<int>& sensorData);
};

#endif // LANE_KEEPING_ASSISTANT_HPP
