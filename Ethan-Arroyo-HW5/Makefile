# Makefile for compiling the project
# Responsibilities:
# 1. Define build rules for compiling and linking all source files.
# 2. Include targets such as `all`, `clean`, and `test`.
# 3. Use the provided Makefile conventions from the assignment.
# Note: This file must be included in the submission.
CC = g++
CFLAGS = -Wall -std=c++17
OBJ = Scheduler.o FCFS.o SJF.o PriorityScheduling.o
TARGET = Scheduler

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)