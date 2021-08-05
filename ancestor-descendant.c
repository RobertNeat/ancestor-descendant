#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

const int MSG_LENGTH=80;
int main() 
{
    pid_t child_pid, my_pid,parent_pid;
    char message[MSG_LENGTH];
    int count;

    child_pid = fork();
    parent_pid = getppid();
    my_pid = getpid();

    printf("Till now worked one proccess.\n");

switch (child_pid) {
    case -1:
        perror("Forking didnt worked.\n");
        exit(1);
    case 0:
        snprintf(message,MSG_LENGTH,"I am child, child PID = %d, my PID=%d, parent PID =%d",\
        child_pid,my_pid,parent_pid);
        count = 5;
    break;
    default:
        snprintf(message,MSG_LENGTH,"I am parent, child PID =%d, my PID=%d, parent PID =%d",\
        child_pid,my_pid,parent_pid);
        count = 5;
    break;
}
for (; count > 0; count--) {
    puts(message);
    sleep(1);
}}