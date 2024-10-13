# Compiler and linker
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11 -Iinclude -MMD -MP
LDFLAGS := -pthread

# Directories
SRC_DIR := src
INCLUDE_DIR := include
TEST_DIR := tests
OBJ_DIR := obj
OBJ_DIR_SRC := $(OBJ_DIR)/src
OBJ_DIR_TEST := $(OBJ_DIR)/tests
BIN_DIR := bin

# Files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_SOURCES := $(wildcard $(TEST_DIR)/*.cpp)

OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR_SRC)/%.o,$(SOURCES))
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR_TEST)/%.o,$(TEST_SOURCES))

# All object files
ALL_OBJS := $(OBJS) $(TEST_OBJS)

# Executables
TEST_EXEC := $(BIN_DIR)/runTests

# Default target
all: $(TEST_EXEC)

# Create necessary directories
$(OBJ_DIR_SRC):
	mkdir -p $(OBJ_DIR_SRC)

$(OBJ_DIR_TEST):
	mkdir -p $(OBJ_DIR_TEST)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Pattern rules for compiling source files
$(OBJ_DIR_SRC)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR_SRC)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Pattern rules for compiling test files
$(OBJ_DIR_TEST)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR_TEST)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Linking the test executable
$(TEST_EXEC): $(ALL_OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(ALL_OBJS) -o $@ $(LDFLAGS) -lgtest -lgtest_main

# Run tests
test: $(TEST_EXEC)
	$(TEST_EXEC)

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Include dependency files
-include $(OBJS:.o=.d)
-include $(TEST_OBJS:.o=.d)