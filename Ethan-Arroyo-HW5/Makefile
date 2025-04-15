# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Target executable
TARGET = Scheduler

# Source files
SRCS = Scheduler.cpp FCFS.cpp

# Header files
HEADERS = Process.h SchedulerAlgorithm.h SchedulerAlgorithmFactory.h

# Object files (replace .cpp with .o in SRCS)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean