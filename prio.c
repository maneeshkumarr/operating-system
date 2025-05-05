#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], priority[n];
    int ct[n], tat[n], wt[n], completed[n];
    float total_tat = 0, total_wt = 0;
    int time = 0, completed_count = 0;

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time, Burst Time and Priority for Process %d: ", pid[i]);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        completed[i] = 0;  // Mark as not completed
    }

    // Scheduling Logic
    while (completed_count < n) {
        int idx = -1;
        int highest_priority = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0) {
                if (priority[i] < highest_priority) {
                    highest_priority = priority[i];
                    idx = i;
                }
                // If priority is same, use arrival time as tie-breaker
                else if (priority[i] == highest_priority && at[i] < at[idx]) {
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            ct[idx] = time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            total_tat += tat[idx];
            total_wt += wt[idx];
            completed[idx] = 1;
            time = ct[idx];
            completed_count++;
        } else {
            time++; // Idle CPU
        }
    }

    // Output
    printf("\nP\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n", pid[i], at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time   : %.2f\n", total_wt / n);

    return 0;
}