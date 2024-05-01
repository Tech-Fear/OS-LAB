#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;
    const char *dir_name = "Dir_Personal";
    if (mkdir(dir_name, 0755)) {
        perror("mkdir() error");
        return 1;
    }else{
    	printf("Directory Created\n");
    }
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        strcat(cwd, "/Dir_Personal");
    } else {
        perror("getcwd() error");
        return 1;
    }
    if(chdir(cwd)==0){
    	printf("Directory changed to %s\n",cwd);
    } else {
    	perror("chdir() error");
    }
    int fd1 = open("1.txt", O_CREAT, 0644);
    if (fd1 == -1) {
        perror("Error creating 1.txt");
        return 1;
    }
    int fd2 = open("2.txt", O_CREAT, 0644);
    if (fd2 == -1) {
        perror("Error creating 2.txt");
        return 1;
    }
    dir = opendir(cwd);
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}

