#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
	pid_t p2,p3;
	printf("Parent Process(p1) PID: %d\n",getpid());
	p2=fork();
	if(p2==0){
		printf("Child Process(p2) with PID: %d and Parent PID: %d\n",getpid(),getppid());
		p3=fork();
		if(p3==0){
			printf("Process(p3) with PID: %d and Parent PID: %d\n",getpid(),getppid());
			return 0;
		}else if(p3>0){
			wait(NULL);
			return 0;
		}else{
			perror("Error in Fork p3");
			return 1;
		}
	}else if(p2>0){
		wait(NULL);
		return 0;
	}else{
		perror("Error in fork p2");
	}
	return 0;
}
