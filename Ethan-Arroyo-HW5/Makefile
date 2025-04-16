# Makefile for Scheduler project

CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = Scheduler
SRC = Scheduler.c

all: $(TARGET)

$(TARGET): Scheduler.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) Scheduler.cpp

clean:
	rm -f $(TARGET)
