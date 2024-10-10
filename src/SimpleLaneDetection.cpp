#include "SimpleLaneDetection.hpp"

double SimpleLaneDetection::detectLaneOffset(const std::vector<int>& sensorData) {
    std::cout << "Simple lane detection algorithm processing sensor data." << std::endl;
    // Simple logic: calculate the average of sensor data
    if (sensorData.empty()) return 0.0;
    double sum = 0.0;
    for (int data : sensorData) {
        sum += data;
    }
    return sum / sensorData.size();
}