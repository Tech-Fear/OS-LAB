#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	pid_t p2,p3,p4,p5;
	printf("Parent Process PID: %d\n",getpid());
	p2=fork();
	if(p2==0){
		printf("Child Process P2 PID: %d Parent PID: %d\n",getpid(),getppid());
		p4=fork();
		if(p4==0){
			printf("Child Process P4 PID: %d Parent PID: %d\n",getpid(),getppid());
			p5=fork();
			if(p5==0){
				printf("Child Process P5 PID: %d Parent PID: %d\n",getpid(),getppid());
				return 0;
			}else if(p5>0){
				wait(NULL);
				return 0;
			}else{
				perror("Fork Error");
				return 1;
			}
		}else if(p4>0){
			wait(NULL);
			return 0;
		}else{
			perror("Fork Error");
			return 1;
		}
	}else if(p2>0){
		p3=fork();
		if(p3==0){
			printf("Child Process P3 PID: %d Parent PID: %d\n",getpid(),getppid());
			return 0;
		}else if(p3>0){
			wait(NULL);
			return 0;
		}else {
			perror("Fork error");
			return 1;
		}
	}else{
		perror("Fork Error");
	}
	return 0;
}
