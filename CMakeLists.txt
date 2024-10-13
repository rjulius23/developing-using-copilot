cmake_minimum_required(VERSION 3.22.1)

# Project name
project(DemoCppProject)

# C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
file(GLOB SRC_FILES "src/*.cpp")
file(GLOB TEST_FILES "tests/*.cpp")

# Add the executable for the main program
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Find and add Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the executable for the tests
add_executable(${PROJECT_NAME}_test ${SRC_FILES} ${TEST_FILES})

# Link Google Test libraries
target_link_libraries(${PROJECT_NAME}_test ${GTEST_LIBRARIES} pthread)

# Enable testing
enable_testing()

# Add tests
add_test(NAME DemoTests COMMAND ${PROJECT_NAME}_test)