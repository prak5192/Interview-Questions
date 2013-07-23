/*
    Write a program to print string in the following pattern -
If i/p is 'abc' then o/p should be 'abbccccccbba'.

*/


#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

char *pattern_convertion(char *str)
{
    char *ret = NULL;
    int l = strlen(str);
    if(l == 0) {
        return NULL;
    }
    ret = malloc( (2* l * sizeof(char)) + 1);
    if( ret == NULL){
        return NULL;
    }
    
    int c = 0, i,j;
    for(i = 0; i<l; i++)
    {
        for(j = 0; j < i + 1; j++, c++)
            ret[c] = str[i];
    }

    int latest = j -1 ;
    for(i = l-1; i >= 0; i--)
    {
        for(j = latest ; j >= 0; j--, c++){
            ret[c] = str[i];
        }
        latest = latest - 1;
    }
    ret[c] = '\0';
    return ret;

}

int main(void)
{
    char a[100];
    char *b = NULL;
    int length=0,n,k,sum1=0,sum2=0,i,j,l;

    printf("\nenter the required string to compute:\n");
    gets(a);

    b = pattern_convertion(a);
    if( b != NULL){
        printf("Converted string : %s\n", b);
    } else {
        printf("b is equal to NULL\n");
    }
    return 0;;

}

