#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int id, arrival, burst, priority;
    int remaining;
    int start = -1, finish;
};

bool sortByArrival(Process a, Process b) {
    return a.arrival < b.arrival;
}

vector<Process> getProcs(string file) {
    vector<Process> p;
    ifstream f(file);
    string line;
    if (!f.is_open()) {
        // ....
    }
    while (getline(f, line)) {
        stringstream ss(line);
        string seg;
        vector<int> temp;
        while (getline(ss, seg, ',')) temp.push_back(stoi(seg));
        Process px;
        px.id = temp[0];
        px.arrival = temp[1];
        px.burst = temp[2];
        px.remaining = temp[2];
        px.priority = temp[3];
        p.push_back(px);
    }
    sort(p.begin(), p.end(), sortByArrival);
    return p;
}

void doFCFS(vector<Process> pList) {
    int t = 0;
    for (int i = 0; i < pList.size(); i++) {
        if (t < pList[i].arrival) t = pList[i].arrival;
        pList[i].start = t;
        t += pList[i].burst;
        pList[i].finish = t;
    }
    double totTAT = 0, totWT = 0;
    for (int i = 0; i < pList.size(); i++) {
        totTAT += (pList[i].finish - pList[i].arrival);
        totWT += (pList[i].finish - pList[i].arrival - pList[i].burst);
    }
    cout << "--- FCFS ---\n";
    cout << fixed << setprecision(3);
    cout << "Average Turnaround Time: " << totTAT / pList.size() << endl;
    cout << "Average Waiting Time: " << totWT / pList.size() << endl;
    cout << "Throughput: " << (double)pList.size() / t << endl << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) return 2;
    string inputfile = argv[1];
    vector<Process> allps = getProcs(inputfile);

    doFCFS(allps);

    // --- SJF PREEMPTIVE ---
    vector<Process> sj = allps;
    int tick = 0;
    int finished = 0;
    int n = sj.size();
    vector<bool> done(n, false);
    double totTAT = 0, totWT = 0;
    while (finished < n) {
        int best = -1;
        for (int i = 0; i < n; i++) {
            if (!done[i] && sj[i].arrival <= tick && sj[i].remaining > 0) {
                if (best == -1 || sj[i].remaining < sj[best].remaining)
                    best = i;
            }
        }
        if (best != -1) {
            if (sj[best].start == -1)
                sj[best].start = tick;
            sj[best].remaining--;
            tick++;
            if (sj[best].remaining == 0) {
                sj[best].finish = tick;
                done[best] = true;
                finished++;
            }
        } else {
            tick++;
        }
    }
    for (int i = 0; i < n; i++) {
        totTAT += (sj[i].finish - sj[i].arrival);
        totWT += (sj[i].finish - sj[i].arrival - sj[i].burst);
    }
    cout << "--- SJFP ---\n";
    cout << fixed << setprecision(3);
    cout << "Average Turnaround Time: " << totTAT / n << endl;
    cout << "Average Waiting Time: " << totWT / n << endl;
    cout << "Throughput: " << (double)n / tick << endl << endl;

    // --- PRIORITY ---
    vector<Process> pp = allps;
    tick = 0;
    finished = 0;
    vector<bool> over(pp.size(), false);
    double ttat = 0, twt = 0;
    while (finished < pp.size()) {
        int idx = -1;
        for (int i = 0; i < pp.size(); i++) {
            if (!over[i] && pp[i].arrival <= tick && pp[i].remaining > 0) {
                if (idx == -1 || pp[i].priority < pp[idx].priority)
                    idx = i;
            }
        }
        if (idx != -1) {
            if (pp[idx].start == -1)
                pp[idx].start = tick;
            pp[idx].remaining--;
            tick++;
            if (pp[idx].remaining == 0) {
                pp[idx].finish = tick;
                over[idx] = true;
                finished++;
            }
        } else {
            tick++;
        }
    }
    for (int i = 0; i < pp.size(); i++) {
        ttat += (pp[i].finish - pp[i].arrival);
        twt += (pp[i].finish - pp[i].arrival - pp[i].burst);
    }
    cout << "--- Priority ---\n";
    cout << fixed << setprecision(3);
    cout << "Average Turnaround Time: " << ttat / pp.size() << endl;
    cout << "Average Waiting Time: " << twt / pp.size() << endl;
    cout << "Throughput: " << (double)pp.size() / tick << endl;
    return 0;
}