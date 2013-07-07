/*AIM:
 A program where we a create a  10 child process 
and we have to print the process in syncronous order */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main (int argc, char *argv[]) {
    int i;
    pid_t pid;

    if( argc != 2 ){
        printf("Usage: ./a.out <number of process>\n");
        exit(0);
    }
    for (i = 1; i <= atoi(argv[1]); i++) {
        pid = fork();
        if (pid == -1) {
           perror("Fork()\n");
           return;
        }
        if (pid == 0) {
           printf("I am a child2: %d PID: %d\n",i, getpid());
            /*
                TODO: have to create some 
                synchronization method between these two process
            */
        
           sleep (2);
           return;
        }
    }
    return 0;
}
