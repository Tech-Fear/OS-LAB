#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void) {
    int fd = open("Test.txt", O_CREAT | O_RDWR, 0644);
    if (fd == -1) {
        perror("Test.txt error");
        return 1;
    }
    char buffer[30];
    scanf("%s", buffer);
    write(fd, buffer, 30);
    close(fd);
    int fd2 = open("Test.txt", O_CREAT | O_RDWR, 0644);
    if (fd2 == -1) {
        perror("Test.txt during read error");
        return 1;
    }
    off_t fileSize = lseek(fd2, 0, SEEK_END);
    lseek(fd2, 0, SEEK_SET);
    ssize_t totalByteRead = read(fd2, buffer, 10);
    lseek(fd2, 0, SEEK_SET);
    write(1, buffer, 10);
    char buf[10];
    printf("\n");
    lseek(fd2, fileSize - 10, SEEK_SET);
    ssize_t bytes = read(fd2, buf, 10);
    write(1, buf, bytes);
    printf("\n");
    close(fd2);
    return 0;
}

