#include <stdio.h>

#define MAX 100

int main() {
    int pages[MAX], frames[MAX];
    int n, f, i, j, k = 0, pageFaults = 0, found;

    // Input number of pages
    printf("Enter number of pages: ");
    scanf("%d", &n);

    // Input page reference string
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input number of frames
    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames to -1 (empty)
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

        // If not found, replace using FIFO
        if(!found) {
            frames[k] = pages[i];
            k = (k + 1) % f; // Circular queue logic
            pageFaults++;
        }

        // Print current frame status
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
