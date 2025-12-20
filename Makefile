# Makefile for dependency-test.cpp

# Compiler
CXX = gcc
# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = dependency-test
# Source files
SRC = dependency-test.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
