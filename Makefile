# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = hyprthemes
SRC = main.cpp
OUTPUT_DIR = /usr/bin

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	sudo chmod u+x $(TARGET)
	sudo mv $(TARGET) $(OUTPUT_DIR)
	export PATH="$(PATH):$(OUTPUT_DIR)/$(TARGET)"

# Run target (optional)
run: $(TARGET)
	$(OUTPUT_DIR)/$(TARGET)

.PHONY: all clean run
