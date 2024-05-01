#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	pid_t p1,p2;
	printf("This is Parent PID: %d\n",getpid());
	p1=fork();
	if(p1==0){
		printf("This is Child p1 PID: %d and its parent's PID is : %d\n",getpid(),getppid());
	}else if(p1>0){
	wait(NULL);
		p2=fork();
	if(p2==0){
		printf("This is Child p2 PID: %d and its parent's PID is : %d\n",getpid(),getppid());
	}else if(p1>0){
		wait(NULL);
	}else{
		printf("Fork error\n");
	}
	}else{
		printf("Fork error\n");
	}
	return 0;
}
