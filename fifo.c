#include <stdio.h>

int main() {
    int frames, pages, i, j, k, flag, fault = 0;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages], frame[frames];

    printf("Enter the page reference string:\n");
    for(i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    for(i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    int index = 0;

    printf("\nPage\tFrames\t\tPage Fault\n");

    for(i = 0; i < pages; i++) {
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                flag = 1; 
                break;
            }
        }

        if(flag == 0) { 
            frame[index] = page[i];
            index = (index + 1) % frames;
            fault++;
        }

        printf("%d\t", page[i]);
        for(k = 0; k < frames; k++) {
            if(frame[k] != -1)
                printf("%d ", frame[k]);
            else
                printf("- ");
        }

        printf(flag ? "\tNo\n" : "\tYes\n");
    }

    printf("\nTotal Page Faults = %d\n", fault);
    return 0;
}