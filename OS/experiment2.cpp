//2. Simulate the following CPU scheduling algorithms to find turnaround time and waiting time a) FCFS  b) SJF c) Round Robin d) Priority
#include<stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
  
    for (int i = 1; i < n ; i++ )
        wt[i] = bt[i-1] + wt[i-1];
}

// Function to find the turnaround time for all processes
void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
  
    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt);
  
    // Function to find turnaround time for all processes
    findTurnaroundTime(processes, n, bt, wt, tat);
  
    // Display processes along with their waiting time and turnaround time
    printf("\nProcess   Burst Time   Waiting"
           " Time   Turn-Around Time\n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d ", (i + 1));
        printf("       %d ", bt[i]);
        printf("       %d", wt[i]);
        printf("       %d\n", tat[i]);
    }
  
    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turn-around time = %.2f", (float)total_tat / (float)n);
}

// Function to implement FCFS scheduling algorithm
void FCFS(int processes[], int n, int bt[]) {
    findAverageTime(processes, n, bt);
}

// Function to implement SJF scheduling algorithm
void SJF(int processes[], int n, int bt[]) {
    // Sort processes based on burst time
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (bt[j] > bt[j+1]) {
                // Swap the processes
                int temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
    
    findAverageTime(processes, n, bt);
}

// Function to implement Round Robin scheduling algorithm
void RoundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];

    // Initialize waiting time and turnaround time arrays
    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
    }

    int time = 0; // Current time

    // Run until all processes are completed
    while (1) {
        int done = 1;

        // Traverse all processes
        for (int i = 0; i < n; i++) {
            // If burst time is greater than 0, process i is not done
            if (bt[i] > 0) {
                done = 0;

                // If remaining burst time is less than or equal to quantum, finish the process
                if (bt[i] <= quantum) {
                    time += bt[i];
                    wt[i] = time - bt[i];
                    bt[i] = 0;
                } else {
                    // Reduce the burst time by the quantum time
                    time += quantum;
                    bt[i] -= quantum;
                }
            }
        }

        // If all processes are done, exit the loop
        if (done == 1)
            break;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    // Display processes along with their waiting time and turnaround time
    printf("\nProcess   Burst Time   Waiting"
           " Time   Turn-Around Time\n");
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d ", (i + 1));
        printf("       %d ", bt[i]);
        printf("       %d", wt[i]);
        printf("       %d\n", tat[i]);
    }

    printf("\nAverage waiting time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage turn-around time = %.2f", (float)total_tat / (float)n);
}

// Function to implement Priority scheduling algorithm
void Priority(int processes[], int n, int bt[], int priority[]) {
	
	printf("Enter the priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Priority for Process %d: ", i + 1);
        scanf("%d", &priority[i]);
    }   
    // Sort processes based on priority
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (priority[j] > priority[j+1]) {
                // Swap the processes
                int temp = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }

    findAverageTime(processes, n, bt);
}

int main() {
    int n; // Number of processes

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n]; // Array to store process IDs
    int bt[n]; // Array to store burst times
    int priority[n]; // Array to store priority values

    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }
 


     // FCFS Scheduling
     // RoundRobin(processes, n, bt,3);
      FCFS(processes, n, bt);
      //SJF(processes, n, bt);
    
}
/* FCFS Scheduling - Expected Output for FCFS
Enter the number of processes: 3
Enter the burst times for each process:
Burst time for Process 1: 5
Burst time for Process 2: 1
Burst time for Process 3: 2

Process   Burst Time   Waiting Time   Turn-Around Time
 1        5        0       5
 2        1        5       6
 3        2        6       8

Average waiting time = 3.67
Average turn-around time = 6.33

