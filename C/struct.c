/* Struct hack technique */

/*
http://www.geeksforgeeks.org/archives/22677
*/

#include<stdio.h>
#include<string.h>

struct employee
{
    int emp_id;
    int name_len;
    char name[0];
};

int main(void){

    struct employee A;
    strcpy(A.name, "prakash");
    printf("Sizeof struct employee is %d\n", sizeof(A));
    printf("Name  %s\n", A.name);
    return 0;
}
