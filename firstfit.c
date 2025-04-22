#include <stdio.h>

int main() {
    int block_size[10], process_size[10], block_no[10];
    int i, j, nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    printf("Enter size of each block:\n");
    for (i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block_size[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter size of each process:\n");
    for (i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process_size[i]);
    }

    for (i = 0; i < np; i++) {
        block_no[i] = -1;
        for (j = 0; j < nb; j++) {
            if (block_size[j] >= process_size[i]) {
                block_no[i] = j;
                block_size[j] -= process_size[i]; 
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, process_size[i]);
        if (block_no[i] != -1)
            printf("%d\n", block_no[i] + 1); 
        else
            printf("Not Allocated\n");
    }

    return 0;
}