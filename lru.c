#include <stdio.h>

int main() {
    int pages[100], frames[10], recent[10];
    int n, f, i, j, k, faults = 0, time = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page reference string: ");
    for(i = 0; i < n; i++) scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) 
	frames[i] = -1;

    for(i = 0; i < n; i++) {
        int hit = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                hit = 1;
                recent[j] = time++;
                break;
            }
        }

        if(!hit) {
            int lru = 0;
            for(j = 1; j < f; j++)
                if(recent[j] < recent[lru]) 
			lru = j;

            frames[lru] = pages[i];
            recent[lru] = time++;
            faults++;
        }
    }

    printf("Page Faults: %d\n", faults);
    printf("Page Hits: %d\n", n - faults);
    return 0;
}

