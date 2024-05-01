#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main() {
    pid_t child;
    int fd;
    printf("This is Parent PID: %d\n", getpid());
    child = fork();
    if (child == 0) {
        printf("This is Child PID: %d and Parent PID: %d\n", getpid(), getppid());
        fd = open("Reation.txt", O_CREAT | O_RDWR, 0644);
        if (fd == -1) {
            perror("Relation.txt error");
            return 1;
        }
        close(fd);
        printf("File Created Successfully\n");
    } else if (child > 0) {
        wait(NULL);
        fd = open("Reation.txt",O_RDWR);
        char *ch = (char *)malloc(sizeof(char) * 100);
        printf("Enter the String : ");
        scanf("%[^\n]", ch);
        getchar();
        printf("Data to be written: %s\n", ch); // Added this line for debugging
        write(fd, ch, strlen(ch));
        printf("\n");
        printf("Data Written Successfully\n");
        close(fd);
    } else {
        printf("Fork error\n");
    }
    return 0;
}

