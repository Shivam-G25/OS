#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, head, total_movement = 0;

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int request[n];

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("\nSequence of head movement:\n%d", head);

    for (i = 0; i < n; i++) {
        total_movement += abs(request[i] - head);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal head movement = %d\n", total_movement);

    return 0;
}