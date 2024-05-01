#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
void encrypt(char buffer[],int size,int shift){
	for(int i=0;i<size;i++){
	if(buffer[i]>='a' && buffer[i]<='z'){
		buffer[i]=(((buffer[i]-'a')+shift)%26)+'a';
	}else if(buffer[i]>='A' && buffer[i]<='Z'){
		buffer[i]=(((buffer[i]-'A')+shift)%26)+'A';
	}
	}
}
int main(void){
	int rfd=open("File1.txt",O_RDONLY);
	int wfd=open("File2.txt",O_CREAT|O_RDWR,0644);
	if(rfd==-1){
		perror("File1.txt error");
		return 1;
	}
	if(wfd==-1){
		perror("File2.txt error");
		return 1;
	}
	off_t fileSize=lseek(rfd,0,SEEK_END);
	lseek(rfd,0,SEEK_SET);
	char buffer[fileSize];
	ssize_t totalBytesRead=read(rfd,buffer,fileSize);
	if(totalBytesRead==-1){
		perror("read() error");
		return 1;
	}
	int shift;
	printf("Enter the number of shifts: ");
	scanf("%d",&shift);
	encrypt(buffer,totalBytesRead,shift);
	lseek(wfd,0,SEEK_SET);
	write(wfd,buffer,fileSize);
	printf("your encrypted data is: %s\n",buffer);
	close(rfd);
	close(wfd);
	return 0;
}
