#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    int n;
    printf("Enter the number of forks: ");
    scanf("%d", &n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if ((child_pid = fork()) == 0) {
            printf("Child process with PID %d\n", getpid());
            return 0;
        } else if (child_pid > 0) {
            count++;
        } else {
            fprintf(stderr, "Fork failed\n");
            return 1;
        }
    }
    for (int i = 0; i < count; i++) {
        wait(NULL);
    }

    printf("Total executed process: %d\n", count);
    return 0;
}

