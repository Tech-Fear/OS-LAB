#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
void *th_func(void *args){
	char *str=(char *)args;
	int *returnVal=malloc(sizeof(int));
	*returnVal=strlen(str);
	pthread_exit(returnVal);
}
int main(){
	pthread_t tid;
  char c[100];
  scanf("%s",c);
  int *th_val=malloc(sizeof(int));
  pthread_create(&tid,NULL,th_func,(void*)c);
  pthread_join(tid,(void*)&th_val);
  printf("%d\n",*th_val);
  return 0;
}
