# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Source files
SRC = main.cpp src/filesys.cpp
TARGET = hyprthemes

# Default target: build
all: $(TARGET)

# Build the binary
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) -lsimdjson
	chmod +x $(TARGET)

# Optional: install to /usr/bin
install: $(TARGET)
	sudo mv $(TARGET) /usr/bin/

# Optional: run binary from current directory
run: $(TARGET)
	./$(TARGET)

# Clean build artifacts
clean:
	rm -f $(TARGET)

.PHONY: all install run clean
