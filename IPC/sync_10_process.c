/*AIM:
 A program where we a create a  10 child process 
and we have to print the process in syncronous order */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PROCESS 10

int main (int argc, char *argv[]) {
    int i, j;
    int status;
    pid_t pid[MAX_PROCESS] ;
    int ret;

    if( argc != 2 ){
        printf("Usage: ./a.out <number of process>\n");
        exit(0);
    }
    if( atoi(argv[1]) > 10 ){
        printf("Maximum process supporeted is 10\n");
        exit(0);
    }
    for (i = 1; i <= atoi(argv[1]); i++) {
        ret = fork();
        if (ret == -1) {
           perror("Fork()\n");
           return;
        }
        if (ret == 0) {
           printf("I am a child: %d PID: %d\n",i, getpid());
           pid[i] = getpid();
            /*
                TODO: have to create some 
                synchronization method between these two process
            */
        
           return;
        }
#if 0 
        else {
            for (j =0 ; j< atoi(argv[1]) ; j++){
                waitpid(pid[j],NULL,WUNTRACED);
            }
        }
#endif
            
    }
    return 0;
}
