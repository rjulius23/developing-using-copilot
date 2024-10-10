#include "SimpleLaneDetection.hpp"
#include "AdvancedLaneDetection.hpp"
#include "LaneKeepingAssistant.hpp"
#include <vector>

int main() {
    // Simulated sensor data
    std::vector<int> sensorData = {2, 3, 4, 5, 6};

    // Use simple lane detection algorithm
    SimpleLaneDetection simpleDetector;
    LaneKeepingAssistant assistant1(&simpleDetector);
    assistant1.processSensorData(sensorData);

    // Use advanced lane detection algorithm
    AdvancedLaneDetection advancedDetector;
    LaneKeepingAssistant assistant2(&advancedDetector);
    assistant2.processSensorData(sensorData);

    return 0;
}
