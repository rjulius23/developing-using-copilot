#include "LaneKeepingAssistant.hpp"
#include <iostream>

LaneKeepingAssistant::LaneKeepingAssistant(LaneDetectionAlgorithm* detector)
    : laneDetector(detector) {}

double LaneKeepingAssistant::processSensorData(const std::vector<int>& sensorData) {
    double laneOffset = laneDetector->detectLaneOffset(sensorData);
    // Adjust steering based on lane offset
    std::cout << "Adjusting steering based on lane offset: " << laneOffset << std::endl;
    return laneOffset; // Return for testing purposes
}
