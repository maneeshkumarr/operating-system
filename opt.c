#include <stdio.h>

int main() {
    int pages[100], frames[10];
    int n, f, i, j, k, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        int hit = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                hit = 1;
                break;
            }
        }

        if(!hit) {
            int replace = -1, farthest = i + 1;

            for(j = 0; j < f; j++) {
                int found = 0;
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        if(k > farthest) {
                            farthest = k;
                            replace = j;
                        }
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    replace = j;
                    break;
                }
            }

            if(replace == -1)
                replace = 0;

            frames[replace] = pages[i];
            faults++;
        }
    }

    printf("Page Faults: %d\n", faults);
    printf("Page Hits: %d\n", n - faults);

    return 0;
}