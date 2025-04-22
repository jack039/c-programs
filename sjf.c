#include <stdio.h>

int main() {
    int n, i, j;
    int pid[10], bt[10], wt[10], tat[10], temp;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter burst time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sort by burst time (SJF)
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                // Swap burst times
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                // Swap process IDs
                temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
            }
        }
    }

    // Waiting time for first process is 0
    wt[0] = 0;

    // Calculate waiting time
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Output
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
