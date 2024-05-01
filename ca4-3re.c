#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main(){
	void *shm;
	int shmid;
	char buf[100];
	shmid=shmget((key_t)1234,2097152,0666);
	shm=shmat(shmid,NULL,0);
	strcpy(buf,shm);
	printf("Data recieved in process :%d and Passes data is: %s\n",getpid(),buf);
	return 0;
}
