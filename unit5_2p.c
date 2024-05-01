#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
	pid_t pid=fork();
	if(pid<0) perror("fork() error");
	else if(pid==0){
		//Child Process 
		printf("child process PID: %d\n",getpid());
		sleep(2);
		printf("child process, My parent PID: %d\n",getppid());
	}else{
		printf("Parent process PID: %d\n",getpid());
		printf("Parent process Termenating.....\n");
	}
	return 0;
}
