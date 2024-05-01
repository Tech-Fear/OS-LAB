#include<stdio.h>
#include<pthread.h>
void *thread_func(void *message){
	int m1=*((int*)message);
	int m2=*(((int*)message)+1);
	printf("Thread printing parameters: %d\n",m1+m2);
}
int main(){
	pthread_t thread_id;
	char ch[]="hello world";
	 int a[]={10,10};
	pthread_create(&thread_id,NULL,thread_func,(void*)(a));
	pthread_join(thread_id,NULL);
	return 0;
}
