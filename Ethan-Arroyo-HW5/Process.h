/*
** Header file defining the `Process` class.
** Responsibilities:
** 1. Represent a single process with attributes such as:
**    - ProcessID
**    - Arrival Time
**    - Burst Duration
**    - Priority
** 2. Provide constructors and utility methods for accessing and modifying process attributes.
** 3. Encapsulate process data for use in scheduling algorithms.
*/

#ifndef PROCESS_H
#define PROCESS_H

#include <string>

class Process {
public:
    int pid;             // Process ID
    int arrivalTime;     // Arrival Time
    int burstTime;       // Burst Duration
    int priority;        // Priority (not used in FCFS, but included for compatibility)

    // Metrics
    int startTime;       // Time at which the process starts execution
    int completionTime;  // Time at which the process completes execution
    int turnaroundTime;  // Completion Time - Arrival Time
    int waitingTime;     // Start Time - Arrival Time

    // Constructor
    Process(int id = 0, int arrival = 0, int burst = 0, int prio = 0)
        : pid(id), arrivalTime(arrival), burstTime(burst), priority(prio),
          startTime(0), completionTime(0), turnaroundTime(0), waitingTime(0) {}

    // Utility method to reset metrics (optional)
    void resetMetrics() {
        startTime = 0;
        completionTime = 0;
        turnaroundTime = 0;
        waitingTime = 0;
    }
};

#endif // PROCESS_H