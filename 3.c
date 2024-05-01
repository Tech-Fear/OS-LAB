#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int p1, p2, p3, p4, p5;
    p1 = getpid();
    printf("This is Root/Parent, PID: %d\n", p1);
    p2 = fork();
    if (p2 == 0) {
        printf("This is child of parent P1, id: %d, parent: %d\n", getpid(), getppid());
        p4 = fork();
        if (p4 == 0) {
            printf("This is child of parent p2, id: %d, parent: %d\n", getpid(), getppid());
            p5 = fork();
            if (p5 == 0)
                printf("This is child of parent p4, id: %d, parent: %d\n", getpid(), getppid());
        }
        wait(NULL);
    } else {
        p3 = fork();
        if (p3 == 0) {
            printf("This is child of parent P1, id: %d, parent: %d\n", getpid(), getppid());
        }
        wait(NULL);
    }

    return 0;
}

