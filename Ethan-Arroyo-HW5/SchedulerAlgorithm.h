/*
** Header file for declaring the abstract base class `SchedulerAlgorithm`.
** Responsibilities:
** 1. Define a common interface for all scheduling algorithms.
** 2. Provide pure virtual methods such as:
**    - `void schedule(const std::vector<Process>& processes);`
**    - `void calculateMetrics();` (to compute average turnaround time, waiting time, and throughput).
** 3. Allow for polymorphism when implementing specific algorithms.
*/