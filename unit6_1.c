#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
typedef struct{
	char *c;
	char *s;	
}string;
void *th_func(void* args){
 	string *input = (string *)args;
 	char *conc=(char *)malloc(sizeof(input->c)+sizeof(input->s));
 	strcpy(conc,input->c);
 	strcat(conc,input->s);
	printf("%s\n",conc);
	pthread_exit(conc); 
}
int main(){
	string *sc=(string *)malloc(sizeof(string));
	sc->c=(char *)malloc(sizeof(char));
	sc->s=(char*)malloc(sizeof(char));
	scanf("%s",sc->c);
	scanf("%s",sc->s);
	pthread_t th_id;
	pthread_create(&th_id,NULL,th_func,(void*)sc);
	char *returnValue;
	pthread_join(th_id,(void**)&returnValue);
	printf("From main, returned Value: %s\n",(char*)returnValue);
return 0;}
