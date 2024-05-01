#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *graceful_thread(void *args) {
    printf("Graceful thread started\n");
    for (int i = 0; i < 5; i++) {
        printf("Graceful thread: Working %d\n", i);
        sleep(1);
    }
    printf("Graceful thread: Cleaning up resources...\n");
    sleep(2);
    printf("Graceful thread: Resources cleaned up\n");
    pthread_exit(NULL);
}

void *abrupt_thread(void *args) {
    printf("Abrupt thread started\n");
    for (int i = 0; i < 5; i++) {
        printf("Abrupt thread: Working %d\n", i);
        sleep(1);
    }
    printf("Abrupt thread: Cleaning up resources...\n");
    sleep(2);
    printf("Abrupt thread: Resources cleaned up\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thGraceful, thAbrupt;
    pthread_create(&thGraceful, NULL, graceful_thread, NULL);
    pthread_create(&thAbrupt, NULL, abrupt_thread, NULL);
    pthread_join(thGraceful, NULL);
    pthread_cancel(thAbrupt);
    pthread_join(thAbrupt, NULL);
    printf("Main thread exiting\n");
    return 0;
}

