//Develop a C program which demonstrates interprocess communication between a reader process and a writer process. Use mkfifo, open, read, write and close APIs in your program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 256

int main() {
    int fd;
    char message[BUFFER_SIZE];

    // Create the FIFO (named pipe)
    mkfifo(FIFO_NAME, 0666);

    // Writer process
    if (fork() == 0) {
        // Open the FIFO for writing
        fd = open(FIFO_NAME, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Write messages to the FIFO
        while (1) {
            printf("Enter message to send: ");
            fgets(message, BUFFER_SIZE, stdin);
            write(fd, message, strlen(message) + 1);
        }

        // Close the FIFO
        close(fd);
    }
    // Reader process
    else {
        // Open the FIFO for reading
        fd = open(FIFO_NAME, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Read messages from the FIFO
        while (1) {
            if (read(fd, message, BUFFER_SIZE) > 0) {
                printf("Received message: %s", message);
            }
        }

        // Close the FIFO
        close(fd);
    }

    return 0;
}

/*In this program:

We create a named pipe (FIFO) using mkfifo.
The writer process opens the FIFO for writing (O_WRONLY), writes messages entered by the user to the FIFO using write, and then closes the FIFO.
The reader process opens the FIFO for reading (O_RDONLY), reads messages from the FIFO using read, and prints them to the console.
The communication between the writer and reader processes is achieved through the named pipe. Each process can read from or write to the pipe independently.
The program continues running indefinitely until manually terminated.
Compile and run the program, and you can enter messages in the writer process, which will be read and displayed by the reader process.*/
