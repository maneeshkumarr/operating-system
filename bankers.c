#include <stdio.h>

int main() {
    int n, m; // n = number of processes, m = number of resources
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int finish[n], safeSeq[n];

    // Input Allocation Matrix
    printf("Enter Allocation Matrix (%d x %d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input Max Matrix
    printf("Enter Max Matrix (%d x %d):\n", n, m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input Available Resources
    printf("Enter Available Resources (%d values):\n", m);
    for(int j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    // Calculate Need Matrix
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
               need[i][j] = max[i][j] - alloc[i][j];
               printf("%d",need[i][j]);
            }
             printf("\n");
        }

    // Initialize finish[]
    for(int i = 0; i < n; i++)
        finish[i] = 0;

    // Banker's Algorithm
    int count = 0;
    while(count < n) {
        int found = 0;

        for(int i = 0; i < n; i++) {
            if(!finish[i]) {
                int j;
                for(j = 0; j < m; j++)
                    if(need[i][j] > avail[j])
                        break;

                if(j == m) {
                    for(int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found)
            break;
    }

    // Output
    if(count == n) {
        printf("System is in a safe state.\nSafe sequence: ");
        for(int i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
        printf("\n");
    } else {
        printf("System is NOT in a safe state.\n");
    }

    return 0;
}
