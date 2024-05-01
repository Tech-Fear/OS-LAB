#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(){
int fd; //declaring var to store file descriptor
char buf[50]; //creating char buffer
fd=open("txt.txt",O_RDONLY); //open file and save the file descriptor to fd
read(fd,buf,10); //read from file to buffer
write(1,buf,10); //Display
}
