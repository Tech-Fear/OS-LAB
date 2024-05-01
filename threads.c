#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *thread_function(){
	printf("Inside the thread!\n");
}
int main(){
	// pthread_create(1,2,3,4)
	// 1. Buffer or a variable that stores that store ID of thread
	// 2. NULL -> attributes of a thread
	// 3. name of function where the working of thread is stored 
	// 4. Parameter that is passed to the function in 3
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,thread_function,NULL);
	pthread_join(thread_id,NULL);
	return 0;
}
