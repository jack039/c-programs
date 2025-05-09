#include <stdio.h>

#define MAX 100

int main() {
    int pages[MAX], frames[MAX];
    int n, f, i, j, k = 0, pageFaults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }

    // FIFO algorithm
    for(i = 0; i < n; i++) {
        found = 0;

        // Check if page is already in a frame
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frames[k] = pages[i];
            k = (k + 1) % f; // Circular queue logic
            pageFaults++;
        }

        printf("Frames: ");
        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);
    return 0;
}
