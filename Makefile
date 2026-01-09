# Makefile for dependency-test.cpp

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = hyprthemes
SRC = main.cpp

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	./$(TARGET)
	
# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
