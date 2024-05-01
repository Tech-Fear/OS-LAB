#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int shared=1;
sem_t s;
void *fun1(){
	sem_wait(&s);
	int x=shared;
	x++;
	sleep(1);
	shared=x;
	sem_post(&s);
}
void *fun2(){
	sem_wait(&s);
	int y=shared;
	y--;
	sleep(1);
	shared=y;
	sem_post(&s);
}
int main(){
	pthread_t thread1,thread2;
	sem_init(&s,0,1);
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	sem_destroy(&s);
	printf("Final value of shared : %d\n",shared);
	return 0;
}
