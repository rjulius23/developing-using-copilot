---FILEPATH Makefile
---FIND


---REPLACE
```
# Makefile

CC = g++
CFLAGS = -g -Wall

# Directories
INCLUDE_DIR = include
SRC_DIR = src
TEST_DIR = tests

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)

# Executables
EXECUTABLE = main
TEST_EXECUTABLE = test

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^

test: $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_FILES)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -o $@ $^ -lgtest -lgtest_main

.PHONY: clean

clean:
	rm -f $(EXECUTABLE) $(TEST_EXECUTABLE)
```
---COMPLETE