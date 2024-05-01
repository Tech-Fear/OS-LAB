#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int fd[2],n;
	char buffer[100];
	pid_t p;
	pipe(fd); 
	p=fork();
	if(p==0)
	{	
		printf("Child passing value to Parent\n");
		write(fd[1],"testing passing pipe()\n",22);
	}
	else
	{
		wait(NULL);
		printf("Parent printing received value, passed data is: \n");
		n=read(fd[0],buffer,sizeof(buffer));
		write(1,buffer,n);
		printf("\n");
	}
	return 0;
}
