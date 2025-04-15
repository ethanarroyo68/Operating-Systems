/*
** This is the main file for the project.
** Responsibilities:
** 1. Parse command-line arguments to get the input file name.
** 2. Read the input file containing process information.
** 3. Call the appropriate scheduling algorithms (FCFS, SJF, Priority).
** 4. Output the performance metrics (average turnaround time, average waiting time, throughput).
** 5. Manage the overall flow of the program.
** Note: This file must follow the naming convention and be named "Scheduler.cpp".
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Process.h"
#include "SchedulerAlgorithm.h"
#include "SchedulerAlgorithmFactory.h" // Include the factory class
#include <memory>

// Function to read processes from the input file
std::vector<Process> readProcessesFromFile(const std::string& filename) {
    std::vector<Process> processes;
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return processes;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);
        std::string token;
        Process process;

        // Read ProcessID, Arrival Time, Burst Duration, and Priority
        std::getline(stream, token, ',');
        process.pid = std::stoi(token);

        std::getline(stream, token, ',');
        process.arrivalTime = std::stoi(token);

        std::getline(stream, token, ',');
        process.burstTime = std::stoi(token);

        std::getline(stream, token, ',');
        process.priority = std::stoi(token);

        processes.push_back(process);
    }

    inputFile.close();
    return processes;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_filename> <algorithm_name>\n";
        return 1;
    }

    std::string inputFilename = argv[1];
    std::string algorithmName = argv[2];
    std::vector<Process> processes = readProcessesFromFile(inputFilename);

    if (processes.empty()) {
        std::cerr << "Error: No processes found in the input file.\n";
        return 1;
    }

    // Create the scheduling algorithm using the factory
    std::unique_ptr<SchedulerAlgorithm> scheduler = SchedulerAlgorithmFactory::createAlgorithm(algorithmName);
    if (!scheduler) {
        std::cerr << "Error: Unknown scheduling algorithm \"" << algorithmName << "\".\n";
        return 1;
    }

    // Run the selected scheduling algorithm
    scheduler->schedule(processes);

    return 0;
}