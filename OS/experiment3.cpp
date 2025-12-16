// Develop a C program to simulate producer-consumer problem using semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t mutex, empty, full;

void *producer(void *arg) {
    int item = 1;

    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);

        // Produce item
        buffer[in] = item;
        printf("Produced item %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        item++;

        sem_post(&mutex);
        sem_post(&full);

        sleep(1); // Simulate production time
    }

    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int item;

    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        // Consume item
        item = buffer[out];
        printf("Consumed item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);

        sleep(2); // Simulate consumption time
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

/*In this program:

mutex semaphore is used to provide mutual exclusion while accessing the buffer.
empty semaphore is used to track the number of empty slots in the buffer.
full semaphore is used to track the number of filled slots in the buffer.
The producer waits on empty semaphore before producing an item and signals full semaphore after producing an item.
The consumer waits on full semaphore before consuming an item and signals empty semaphore after consuming an item.
sleep() functions are used to simulate production and consumption time.*/
