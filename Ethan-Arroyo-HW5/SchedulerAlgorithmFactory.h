#ifndef SCHEDULER_ALGORITHM_FACTORY_H
#define SCHEDULER_ALGORITHM_FACTORY_H

#include <string>
#include <memory>
#include "SchedulerAlgorithm.h"
#include "FCFS.cpp" // Include FCFS implementation

class SchedulerAlgorithmFactory {
public:
    // Factory method to create scheduling algorithm instances
    static std::unique_ptr<SchedulerAlgorithm> createAlgorithm(const std::string& algorithmName) {
        if (algorithmName == "FCFS") {
            return std::make_unique<FCFS>();
        }
        // Future algorithms can be added here
        // else if (algorithmName == "Priority") {
        //     return std::make_unique<PriorityScheduling>();
        // }

        // If the algorithm is not recognized, return nullptr
        return nullptr;
    }
};

#endif // SCHEDULER_ALGORITHM_FACTORY_H