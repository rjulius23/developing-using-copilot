#include "AdvancedLaneDetection.hpp"

double AdvancedLaneDetection::detectLaneOffset(const std::vector<int>& sensorData) {
    std::cout << "Advanced lane detection algorithm processing sensor data." << std::endl;
    // Advanced logic: calculate the weighted average
    if (sensorData.empty()) return 0.0;
    double weightedSum = 0.0;
    double totalWeight = 0.0;
    for (size_t i = 0; i < sensorData.size(); ++i) {
        double weight = i + 1; // Weight increases with index
        weightedSum += sensorData[i] * weight;
        totalWeight += weight;
    }
    return weightedSum / totalWeight;
}
