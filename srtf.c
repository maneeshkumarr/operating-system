#include <stdio.h>

int main() {
    int n;
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n], ct[n], wt[n], tat[n];
    int completed[n];
    int time = 0, completed_count = 0;
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT and BT for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];  // remaining time
        completed[i] = 0;
    }

    while (completed_count < n) {
        int idx = -1, min_rt = 9999;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0 && rt[i] < min_rt && rt[i] > 0) {
                min_rt = rt[i];
                idx = i;
            }
        }

        if (idx != -1) {
            rt[idx]--;
            time++;

            if (rt[idx] == 0) {
                completed[idx] = 1;
                completed_count++;
                ct[idx] = time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                totalWT += wt[idx];
                totalTAT += tat[idx];
            }
        } else {
            time++;  // no process is ready, increment time
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