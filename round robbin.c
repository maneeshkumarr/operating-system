#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    printf("Enter the Time Quantum: ");
    scanf("%d", &tq);

    int pid[n], at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    int completed[n];
    int time = 0, completed_count = 0;
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT and BT for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i]; // initialize remaining time
        completed[i] = 0;
    }

    int flag = 0;
    while (completed_count < n) {
        flag = 0;
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (rt[i] <= tq) {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    totalWT += wt[i];
                    totalTAT += tat[i];
                    completed[i] = 1;
                    completed_count++;
                } else {
                    rt[i] -= tq;
                    time += tq;
                }
                flag = 1;
            }
        }

        if (flag == 0) {
            time++; // if no process is ready, idle time
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turn Around Time: %.2f\n", totalTAT / n);

    return 0;
}
