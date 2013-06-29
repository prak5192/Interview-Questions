#include<stdio.h>

int main(void){
    int ret = system("ifconfig");
    if(ret == -1){
        printf("Error on system call\n");
    }
    return 0;
}
