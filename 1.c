#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(void){
int n;
pid_t child_pid;
printf("Enter the number of forks: ");
scanf("%d",&n);
for(int i=0;i<n;i++){
	child_pid=fork();
	if(child_pid==0){
		printf("Child process %d\n",getpid());
	}
}
for(int i=0;i<n;i++){
	wait(NULL);
}
return 0;
}
