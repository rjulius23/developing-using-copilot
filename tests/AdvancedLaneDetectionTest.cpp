#include <gtest/gtest.h>
#include "../include/AdvancedLaneDetection.hpp"
#include <vector>

class AdvancedLaneDetectionTest : public ::testing::Test {
protected:
    AdvancedLaneDetection detector;
};

TEST_F(AdvancedLaneDetectionTest, EmptyInput) {
    std::vector<int> emptyData;
    EXPECT_DOUBLE_EQ(0.0, detector.detectLaneOffset(emptyData));
}

TEST_F(AdvancedLaneDetectionTest, SingleElement) {
    std::vector<int> singleData = {5};
    EXPECT_DOUBLE_EQ(5.0, detector.detectLaneOffset(singleData));
}

TEST_F(AdvancedLaneDetectionTest, MultipleElements) {
    std::vector<int> multiData = {1, 2, 3, 4, 5};
    // Expected result: (1*1 + 2*2 + 3*3 + 4*4 + 5*5) / (1 + 2 + 3 + 4 + 5) = 70 / 15 ≈ 4.6666667
    EXPECT_NEAR(4.6666667, detector.detectLaneOffset(multiData), 0.0000001);
}

TEST_F(AdvancedLaneDetectionTest, NegativeValues) {
    std::vector<int> negativeData = {-2, -1, 0, 1, 2};
    // Expected result: (-2*1 + -1*2 + 0*3 + 1*4 + 2*5) / (1 + 2 + 3 + 4 + 5) = 10 / 15 ≈ 0.6666667
    EXPECT_NEAR(0.6666667, detector.detectLaneOffset(negativeData), 0.0000001);
}
