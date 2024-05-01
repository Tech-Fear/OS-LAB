#include<stdio.h>
#include<unistd.h>
int main(){
		pid_t chid;
		chid=fork();
		if(chid<0) perror("Fork() error");
		else if(chid>0) printf("Parent section with chid %d and parent id %d\n",chid,getppid());
		else printf("Child section with pid %d\n",getpid());
		return 0;
}
