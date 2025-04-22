#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int *buffer;         
int in = 0;             
int out = 0;             
int MAX_BUFFER_SIZE;     
int MAX_ITEMS;           

sem_t empty;   
sem_t full;   
sem_t mutex; 

void* producer(void* param) {
    int item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        item = rand() % 100;

        sem_wait(&empty);

        sem_wait(&mutex);

        buffer[in] = item;
        printf("Produced: %d at index %d\n", item, in);

        in = (in + 1) % MAX_BUFFER_SIZE;

        sem_post(&mutex);

        sem_post(&full);

        sleep(rand() % 3);
    }
    return NULL;
}

void* consumer(void* param) {
    int item;
    for (int i = 0; i < MAX_ITEMS; i++) {
        sem_wait(&full);

        sem_wait(&mutex);

        item = buffer[out];
        printf("Consumed: %d from index %d\n", item, out);

        out = (out + 1) % MAX_BUFFER_SIZE;

        sem_post(&mutex);

        sem_post(&empty);

        sleep(rand() % 3);
    }
    return NULL;
}

int main() {
    printf("Enter buffer size: ");
    scanf("%d", &MAX_BUFFER_SIZE);

    printf("Enter number of items to produce/consume: ");
    scanf("%d", &MAX_ITEMS);

    buffer = (int*)malloc(MAX_BUFFER_SIZE * sizeof(int));
    if (buffer == NULL) {
        printf("Error allocating memory for the buffer\n");
        return -1;
    }

    sem_init(&empty, 0, MAX_BUFFER_SIZE); 
    sem_init(&full, 0, 0);              
    sem_init(&mutex, 0, 1); 

    pthread_t prod_thread, cons_thread;

    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    free(buffer);

    return 0;
}
