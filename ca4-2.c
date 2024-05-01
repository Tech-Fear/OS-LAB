#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include<unistd.h>
#define NUM_READERS 3
#define NUM_WRITERS 1
pthread_mutex_t mutex;
sem_t rw_mutex;
int data = 0;
int readers_count = 0;

void *reader(void *arg) {
    int id = *((int *)arg);
    while (1) {
        pthread_mutex_lock(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_mutex);
        }
        pthread_mutex_unlock(&mutex);
        
        printf("Reader %d read data: %d\n", id, data);
        
        pthread_mutex_lock(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&rw_mutex);
        }
        pthread_mutex_unlock(&mutex);
        
        sleep(10);
    }
    return NULL;
}

void *writer(void *arg) {
    int id = *((int *)arg);
    while (1) {
        sem_wait(&rw_mutex);
        
        data++;
        printf("Writer %d wrote data: %d\n", id, data);
        
        sem_post(&rw_mutex);
        
        sleep(30);
    }
    return NULL;
}

int main() {
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];
    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&rw_mutex, 0, 1);

    for (int i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    pthread_exit(NULL);
    return 0;
}

