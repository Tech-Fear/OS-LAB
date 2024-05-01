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
	char *ch="Hello! I am from LPU";
	shmid=shmget((key_t)1234,2048,0666 | IPC_CREAT);
	shm=shmat(shmid,NULL,0);
	strncpy((char *)shm, ch, strlen(ch));
	printf("Data shared in shared memory from process PID: %d\n ",getpid());
	return 0;
}
