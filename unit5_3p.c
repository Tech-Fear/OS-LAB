#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	pid_t chid=fork();
	if(chid==0){
		printf("child Process, PID: %d\n",getpid());
	}else if(chid>0){
		printf("parent Process,PID: %d\n",getpid());
		printf("Parent process Cild PID: %d\n",chid);
		sleep(10);
		printf("Parent process Terminating...\n");
	}else{
		printf("Error in fork()");
	}
	return 0;
}
