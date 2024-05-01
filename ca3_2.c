#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
typedef struct {
    int n1;
    int n2;
} Data;
void *sum(void *args) {
    Data *data = (Data *)args;
    int *su = (int *)malloc(sizeof(int));
    *su = data->n1 + data->n2;
    pthread_exit(su);
}
int main() {
    pthread_t thId;
    Data data;
    printf("Enter first number: ");
    scanf("%d", &data.n1);
    printf("Enter second number: ");
    scanf("%d", &data.n2);
    pthread_create(&thId, NULL, sum, (void *)&data);
    int *su;
    pthread_join(thId, (void **)&su);
    printf("Sum of entered numbers is: %d\n", *su);
    free(su);
    return 0;
}

