/*
** Implementation file for the `First Come First Serve` (FCFS) scheduling algorithm.
** Responsibilities:
** 1. Implement the scheduling logic for FCFS (non-preemptive).
** 2. Calculate the performance metrics (average turnaround time, waiting time, throughput).
** 3. Extend the `SchedulerAlgorithm` base class.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Process.h"
#include "SchedulerAlgorithm.h"

class FCFS : public SchedulerAlgorithm {
public:
    // Schedule processes using FCFS
    void schedule(const std::vector<Process>& processes) override {
        if (processes.empty()) {
            std::cerr << "No processes to schedule.\n";
            return;
        }

        std::vector<Process> scheduledProcesses = processes;

        // Sort processes by arrival time
        std::sort(scheduledProcesses.begin(), scheduledProcesses.end(),
                  [](const Process& a, const Process& b) { return a.arrivalTime < b.arrivalTime; });

        int currentTime = 0;
        double totalTurnaroundTime = 0;
        double totalWaitingTime = 0;

        std::cout << "--- FCFS Scheduling ---\n";

        for (auto& process : scheduledProcesses) {
            if (currentTime < process.arrivalTime) {
                currentTime = process.arrivalTime;  // Wait for process to arrive
            }

            process.startTime = currentTime;
            process.completionTime = process.startTime + process.burstTime;
            process.turnaroundTime = process.completionTime - process.arrivalTime;
            process.waitingTime = process.startTime - process.arrivalTime;

            totalTurnaroundTime += process.turnaroundTime;
            totalWaitingTime += process.waitingTime;

            currentTime += process.burstTime;

            // Output details for each process
            std::cout << "Process " << process.pid
                      << ": StartTime=" << process.startTime
                      << ", CompletionTime=" << process.completionTime
                      << ", TurnaroundTime=" << process.turnaroundTime
                      << ", WaitingTime=" << process.waitingTime << "\n";
        }

        // Calculate and display average metrics
        double avgTurnaroundTime = totalTurnaroundTime / scheduledProcesses.size();
        double avgWaitingTime = totalWaitingTime / scheduledProcesses.size();
        double throughput = static_cast<double>(scheduledProcesses.size()) / currentTime;

        std::cout << "Average Turnaround Time: " << std::fixed << std::setprecision(2) << avgTurnaroundTime << "\n";
        std::cout << "Average Waiting Time: " << std::fixed << std::setprecision(2) << avgWaitingTime << "\n";
        std::cout << "Throughput: " << std::fixed << std::setprecision(2) << throughput << "\n";
    }
};