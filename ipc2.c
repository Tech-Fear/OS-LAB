#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main()
{
FILE *rd;
char buffer[1000];
rd=popen("ls","rw"); //pipe opened in reading mode
fread(buffer, 1, 80, rd); //will read only 50 characters
printf("%s\n", buffer);
pclose(rd);
}

