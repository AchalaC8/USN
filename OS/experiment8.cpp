//Develop a C program to simulate SCAN disk scheduling algorithm.
#include <stdio.h>
#include <stdlib.h>
void SCAN(int *requests, int n, int head, char direction) {
    int total_movement = 0;
    int i, j;
    int min_index = 0;
    int max_index = 0;

    // Finding the min and max indexes in the request array
    for (i = 0; i < n; i++) {
        if (requests[i] < requests[min_index])
            min_index = i;
        if (requests[i] > requests[max_index])
            max_index = i;
    }

    if (direction == 'l') { // Left direction
        // Move the head to the minimum index first
        total_movement += abs(head - requests[min_index]);
        printf("%d -> ", requests[min_index]);
        head = requests[min_index];
        
        // Move towards the beginning of the disk
        for (i = min_index - 1; i >= 0; i--) {
            total_movement += abs(head - requests[i]);
            printf("%d -> ", requests[i]);
            head = requests[i];
        }

        // Move towards the end of the disk
        for (i = min_index + 1; i < n; i++) {
            total_movement += abs(head - requests[i]);
            printf("%d -> ", requests[i]);
            head = requests[i];
        }
    } else if (direction == 'r') { // Right direction
        // Move the head to the maximum index first
        total_movement += abs(head - requests[max_index]);
        printf("%d -> ", requests[max_index]);
        head = requests[max_index];
        
        // Move towards the end of the disk
        for (i = max_index + 1; i < n; i++) {
            total_movement += abs(head - requests[i]);
            printf("%d -> ", requests[i]);
            head = requests[i];
        }

        // Move towards the beginning of the disk
        for (i = max_index - 1; i >= 0; i--) {
            total_movement += abs(head - requests[i]);
            printf("%d -> ", requests[i]);
            head = requests[i];
        }
    }

    printf("\nTotal head movement: %d\n", total_movement);
}

int main() {
    int n, head, i;
    char direction;
    int *requests;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    requests = (int*)malloc(n * sizeof(int));

    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    printf("Enter the direction (l for left, r for right): ");
    scanf(" %c", &direction);

    printf("\nSCAN Schedule:\n");
    SCAN(requests, n, head, direction);

    free(requests);

    return 0;
}

/*Expected Output
Enter the number of requests: 10
Enter the requests: 10
20
30
40
50
60
70
80
90
1
Enter the initial position of the head: 0
Enter the direction (l for left, r for right): l

SCAN Schedule:
1 -> 90 -> 80 -> 70 -> 60 -> 50 -> 40 -> 30 -> 20 -> 10 ->
Total head movement: 170*/

