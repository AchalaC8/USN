//Develop a C program to simulate Bankers Algorithm for DeadLock Avoidance
#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int available[MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int work[MAX_RESOURCES];
int finish[MAX_PROCESSES];

int nProcesses, nResources;

// Function declarations
void initialize();
void input();
void display();
int isSafe();
void requestResource(int processNumber);
void releaseResource(int processNumber);

int main() {
    initialize();
    input();
    display();

    if (isSafe()) {
        printf("\nSystem is in safe state.\n");

        // Example: Request and release resources
        int processNumber = 0;
        requestResource(processNumber);
        display();

        releaseResource(processNumber);
        display();
    } else {
        printf("\nSystem is in unsafe state.\n");
    }

    return 0;
}

void initialize() {
    printf("Enter the number of processes: ");
    scanf("%d", &nProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &nResources);

    printf("Enter the available resources:\n");
    for (int j = 0; j < nResources; ++j) {
        scanf("%d", &available[j]);
    }

    for (int i = 0; i < nProcesses; ++i) {
        printf("Enter the maximum resources for process %d:\n", i);
        for (int j = 0; j < nResources; ++j) {
            scanf("%d", &maximum[i][j]);
        }
    }
}

void input() {
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < nProcesses; ++i) {
        for (int j = 0; j < nResources; ++j) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
        finish[i] = 0;
    }
}

void display() {
    printf("\nAvailable Resources:\n");
    for (int j = 0; j < nResources; ++j) {
        printf("%d ", available[j]);
    }

    printf("\n\nMaximum Resources:\n");
    for (int i = 0; i < nProcesses; ++i) {
        for (int j = 0; j < nResources; ++j) {
            printf("%d ", maximum[i][j]);
        }
        printf("\n");
    }

    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < nProcesses; ++i) {
        for (int j = 0; j < nResources; ++j) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }
}

int isSafe() {
    for (int j = 0; j < nResources; ++j) {
        work[j] = available[j];
    }

    int count = 0;
    while (count < nProcesses) {
        int found = 0;
        for (int i = 0; i < nProcesses; ++i) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < nResources; ++j) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == nResources) {
                    for (int k = 0; k < nResources; ++k) {
                        work[k] += allocation[i][k];
                    }
                    finish[i] = 1;
                    found = 1;
                    ++count;
                }
            }
        }
        if (found == 0) {
            break;
        }
    }

    return (count == nProcesses);
}

void requestResource(int processNumber) {
    printf("\nEnter the resource request for process %d:\n", processNumber);
    for (int j = 0; j < nResources; ++j) {
        int request;
        scanf("%d", &request);

        if (request <= need[processNumber][j] && request <= available[j]) {
            allocation[processNumber][j] += request;
            need[processNumber][j] -= request;
            available[j] -= request;
        } else {
            printf("\nInvalid request. Process must wait.\n");
            break;
        }
    }
}

void releaseResource(int processNumber) {
    printf("\nEnter the resource release for process %d:\n", processNumber);
    for (int j = 0; j < nResources; ++j) {
        int release;
        scanf("%d", &release);

        if (release <= allocation[processNumber][j]) {
            allocation[processNumber][j] -= release;
            need[processNumber][j] += release;
            available[j] += release;
        } else {
            printf("\nInvalid release. Process must wait.\n");
            break;
        }
    }
}

/*Expected Output
Enter the number of processes: 5
Enter the number of resources: 4
Enter the available resources:
1
2
1
1
Enter the maximum resources for process 0:
1
1
1
1
Enter the maximum resources for process 1:
2
2
2
2
Enter the maximum resources for process 2:
4
5
5
3
Enter the maximum resources for process 3:
4
1
1
1
Enter the maximum resources for process 4:
1
1
1
1
Enter the allocation matrix:
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1
1

Available Resources:
1 2 1 1

Maximum Resources:
1 1 1 1
2 2 2 2
4 5 5 3
4 1 1 1
1 1 1 1

Allocation Matrix:
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

System is in safe state.*/
