#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
	int p2,p3;
	printf("This is Parent, its PID is %d\n",getpid());
	p2=fork();
	if(p2==0){
		printf("This is process p2 id %d and parent id %d\n",getpid(),getppid());
		p3=fork();
		if(p3==0){
			printf("This is process p3 id %d and parent id %d\n",getpid(),getppid());
		}
	}
	wait(NULL);
return 0;
}

