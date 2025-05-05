#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], bt[n], ct[n], tat[n], wt[n];
    float total_tat = 0, total_wt = 0;

    // Input Burst Times
    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Burst Time for Process %d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // FCFS Logic
    ct[0] = bt[0];
    tat[0] = ct[0]; // Since AT = 0
    wt[0] = 0;

    total_tat += tat[0];
    total_wt += wt[0];

    for(int i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
        tat[i] = ct[i]; // Since AT = 0
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Output
    printf("\nP\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", total_tat / n);
    printf("\nAverage Waiting Time   : %.2f\n", total_wt / n);

    return 0;
}