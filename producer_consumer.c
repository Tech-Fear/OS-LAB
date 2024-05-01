#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
int buffer_size=10;
int buffer[buffer_size];
int in=-1,out=-1;
sem_t full,empty;
pthread_mutex_t mutex;
void *producer(){
	int item=0;
	while(1){
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	item = rand()%100;
	in=(in+1)%buffer_size;
	}
}
int main(){
	pthread_t th1,th2;
	sem_init(&empty,0,buffer_size);
	sem_init(&full,0,0);
	pthread_mutex_init(&mutex,NULL);
	pthread_create(&th1,NULL,producer,NULL);
	pthread_create(&th2,NULL,consumer,NULL);
	
}
