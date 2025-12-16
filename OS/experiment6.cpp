//Develop a C program to simulate the following contiguous memory allocation Techniques:  a) Worst fit b) Best fit c) First fit.

#include <stdio.h>
#define MAX_MEMORY_SIZE 1000
#define MAX_PROCESSES 10

typedef struct {
    int pid;      // Process ID
    int size;     // Process size
    int allocated; // Allocation status (1 for allocated, 0 for unallocated)
} Process;

void worstFit(Process processes[], int numProcesses, int memory[], int numMemoryBlocks) {
    for (int i = 0; i < numProcesses; i++) {
        int worstFitIndex = -1;

        for (int j = 0; j < numMemoryBlocks; j++) {
            if (memory[j] >= processes[i].size) {
                if (worstFitIndex == -1 || memory[j] > memory[worstFitIndex]) {
                    worstFitIndex = j;
                }
            }
        }

        if (worstFitIndex != -1) {
            // Allocate memory to the process
            processes[i].allocated = 1;
            memory[worstFitIndex] -= processes[i].size;
            printf("Process %d allocated to memory block %d using Worst Fit\n", processes[i].pid, worstFitIndex);
        } else {
            printf("Process %d cannot be allocated using Worst Fit\n", processes[i].pid);
        }
    }
}

void bestFit(Process processes[], int numProcesses, int memory[], int numMemoryBlocks) {
    for (int i = 0; i < numProcesses; i++) {
        int bestFitIndex = -1;

        for (int j = 0; j < numMemoryBlocks; j++) {
            if (memory[j] >= processes[i].size) {
                if (bestFitIndex == -1 || memory[j] < memory[bestFitIndex]) {
                	
                    bestFitIndex = j;
                }
            }
        }

        if (bestFitIndex != -1) {
            // Allocate memory to the process
            processes[i].allocated = 1;
            memory[bestFitIndex] -= processes[i].size;
            printf("Process %d allocated to memory block %d using Best Fit\n", processes[i].pid, bestFitIndex);
        } else {
            printf("Process %d cannot be allocated using Best Fit\n", processes[i].pid);
        }
    }
}

void firstFit(Process processes[], int numProcesses, int memory[], int numMemoryBlocks) {
    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numMemoryBlocks; j++) {
            if (memory[j] >= processes[i].size) {
                // Allocate memory to the process
                processes[i].allocated = 1;
                memory[j] -= processes[i].size;
                printf("Process %d allocated to memory block %d using First Fit\n", processes[i].pid, j);
                break;
            }
        }

        if (!processes[i].allocated) {
            printf("Process %d cannot be allocated using First Fit\n", processes[i].pid);
        }
    }
}

int main() {
    int memory[MAX_MEMORY_SIZE];
    Process processes[MAX_PROCESSES];

    int numProcesses, numMemoryBlocks;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numMemoryBlocks);

    printf("Enter the sizes of memory blocks:\n");
    for (int i = 0; i < numMemoryBlocks; i++) {
        scanf("%d", &memory[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < numProcesses; i++) {
        scanf("%d", &processes[i].size);
        processes[i].pid = i;
        processes[i].allocated = 0;
    }

    // Worst Fit
    worstFit(processes, numProcesses, memory, numMemoryBlocks);

    // Reset memory and processes allocation status
    for (int i = 0; i < numMemoryBlocks; i++) {
        memory[i] = MAX_MEMORY_SIZE;
    }
    for (int i = 0; i < numProcesses; i++) {
        processes[i].allocated = 0;
    }
    

    // Best Fit
    bestFit(processes, numProcesses, memory, numMemoryBlocks);

    // Reset memory and processes allocation status
    for (int i = 0; i < numMemoryBlocks; i++) {
        memory[i] = MAX_MEMORY_SIZE;
    }
    for (int i = 0; i < numProcesses; i++) {
        processes[i].allocated = 0;
    }

    // First Fit
    firstFit(processes, numProcesses, memory, numMemoryBlocks);

    return 0;
}

/*Expected Output 
Enter the number of memory blocks: 3
Enter the sizes of memory blocks:
10
25
1
Enter the number of processes: 2
Enter the sizes of processes:
1
20
Process 0 allocated to memory block 2 using Best Fit
Process 1 allocated to memory block 1 using Best Fit
*/
