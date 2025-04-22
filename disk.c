#include <stdio.h>
#include <stdlib.h> // for abs()

int main() {
    int n, i, head, total = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int requests[n];

    printf("Enter disk request sequence: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // FCFS scheduling
    for(i = 0; i < n; i++) {
        total += abs(requests[i] - head);
        printf("Move from %d to %d (Distance = %d)\n", head, requests[i], abs(requests[i] - head));
        head = requests[i];
    }

    printf("Total head movement = %d\n", total);

    return 0;
}
