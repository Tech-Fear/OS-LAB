#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
int shared = 1;
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void *fun1(){
	pthread_mutex_lock(&mutex);
	int x=shared;
	x++;
	sleep(1);
	shared=x;
	pthread_mutex_unlock(&mutex);
}
void *fun2(){
	pthread_mutex_lock(&mutex);
	int y=shared;
	y--;
	sleep(1);
	shared=y;
	pthread_mutex_unlock(&mutex);
}
int main(){
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,fun1,NULL);
	pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_mutex_destroy(&mutex);
	printf("Final value of shared is : %d\n",shared);
	return 0;
}
