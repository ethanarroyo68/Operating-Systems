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