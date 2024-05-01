#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int shared = 1;

void *fun1() {
    int x;
    x = shared;
    x++;
    sleep(1);
    shared = x;
}

void *fun2() {
    int y;
    y = shared;
    y--;
    sleep(1);
    shared = y;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread1, NULL);
    printf("Final Value of shared: %d\n", shared);
    return 0;
}

