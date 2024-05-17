#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

void sjf(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int n = processes.size();
    vector<int> completion_time(n);
    vector<int> waiting_time(n);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        currentTime = max(currentTime, processes[i].arrival_time);
        completion_time[i] = currentTime + processes[i].burst_time;
        waiting_time[i] = currentTime - processes[i].arrival_time;
        currentTime += processes[i].burst_time;
    }

    double total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
    }

    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t\t" << processes[i].arrival_time << "\t\t"
             << processes[i].burst_time << "\t\t" << completion_time[i] << "\t\t"
             << waiting_time[i] << endl;
    }

    cout << "Average Waiting Time: " << total_waiting_time / n << endl;
}

int main() {
    vector<Process> processes;
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int id, arrival_time, burst_time;
        cout << "Enter the details for process " << i+1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Arrival Time: ";
        cin >> arrival_time;
        cout << "Burst Time: ";
        cin >> burst_time;
        processes.push_back({id, arrival_time, burst_time});
    }
    sjf(processes);
    return 0;
}
