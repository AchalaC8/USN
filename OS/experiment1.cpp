//1. Develop a c program to implement the Process system calls (fork (), exec(), wait(), create process, terminate process)
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        // Error handling for fork failure
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process\n");
        // Use exec() to execute another program
        execl("/bin/ls", "ls", "-l", NULL);
    } else {
        // Parent process
        printf("Parent process\n");
        // Wait for the child process to finish
        wait(NULL);
        printf("Child process finished\n");
    }

    return 0;
}

