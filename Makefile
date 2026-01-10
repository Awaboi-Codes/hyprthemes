# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Target executable
TARGET = hyprthemes
SRC = main.cpp
OUTPUT_DIR = ~/.config/hyprthemes

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	mv $(TARGET) $(OUTPUT_DIR)

# Run target (optional)
run: $(TARGET)
	$(OUTPUT_DIR)/$(TARGET)

# Clean up build files
clean:
	rm -f $(OUTPUT_DIR)/$(TARGET)

.PHONY: all clean run
