/*
** Header file for declaring the abstract base class `SchedulerAlgorithm`.
** Responsibilities:
** 1. Define a common interface for all scheduling algorithms.
** 2. Provide pure virtual methods such as:
**    - `void schedule(const std::vector<Process>& processes);`
**    - `void calculateMetrics();` (to compute average turnaround time, waiting time, and throughput).
** 3. Allow for polymorphism when implementing specific algorithms.
*/

#ifndef SCHEDULER_ALGORITHM_H
#define SCHEDULER_ALGORITHM_H

#include <vector>
#include "Process.h"

// Abstract Base Class for all scheduling algorithms
class SchedulerAlgorithm {
public:
    virtual ~SchedulerAlgorithm() = default;

    // Pure virtual method to schedule processes
    virtual void schedule(const std::vector<Process>& processes) = 0;
};

#endif // SCHEDULER_ALGORITHM_H