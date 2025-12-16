//Develop a C program to simulate page replacement algorithms: a) FIFO b) LRU
#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100
#define MAX_FRAMES 10

void fifo(int pages[], int n, int frames) {
    int pageFaults = 0;
    int frame[MAX_FRAMES];
    bool isPresent[MAX_PAGES] = {false};
    int rear = -1;

    printf("Page\tFrame\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);

        if (!isPresent[pages[i]]) {
            pageFaults++;
            if (rear < frames - 1) {
                rear++;
            } else {
                rear = 0;
            }
            frame[rear] = pages[i];
            isPresent[pages[i]] = true;
        }

        for (int j = 0; j < frames; j++) {
            if (j <= rear) {
                printf("%d ", frame[j]);
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

void lru(int pages[], int n, int frames) {
    int pageFaults = 0;
    int frame[MAX_FRAMES];
    bool isPresent[MAX_PAGES] = {false};
    int leastUsed[MAX_FRAMES] = {0};
    int count = 0;

    printf("Page\tFrame\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);

        if (!isPresent[pages[i]]) {
            pageFaults++;
            if (count < frames) {
                frame[count] = pages[i];
                isPresent[pages[i]] = true;
                leastUsed[count] = i;
                count++;
            } else {
                int index = 0;
                for (int j = 1; j < frames; j++) {
                    if (leastUsed[j] < leastUsed[index]) {
                        index = j;
                    }
                }
                isPresent[frame[index]] = false;
                frame[index] = pages[i];
                isPresent[pages[i]] = true;
                leastUsed[index] = i;
            }
        } else {
            for (int j = 0; j < frames; j++) {
                if (frame[j] == pages[i]) {
                    leastUsed[j] = i;
                    break;
                }
            }
        }

        for (int j = 0; j < frames; j++) {
            if (isPresent[pages[i]] && j < count) {
                printf("%d ", frame[j]);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES];
    int n, frames;
    char choice;

    printf("Enter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the pages: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Choose a page replacement algorithm:\n");
    printf("a) FIFO\n");
    printf("b) LRU\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'a':
            fifo(pages, n, frames);
            break;
        case 'b':
            lru(pages, n, frames);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

/*Expected Output
Enter the number of pages: 5
Enter the pages: 1
1
2
4
5
Enter the number of frames: 2
Choose a page replacement algorithm:
a) FIFO
b) LRU
Enter your choice: a
Page    Frame
1       1 -
1       1 -
2       1 2
4       4 -
5       4 5
Total Page Faults: 4
*/


