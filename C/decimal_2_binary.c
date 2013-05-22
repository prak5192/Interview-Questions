/* Write a c program to convert decimal number to binary number */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void getBin(int num, char *str);

int main(void){
    int number = 0;
    char array[10];
    printf("enter a number of till 255\n");
    scanf("%d", &number);
    
    /*converting the number into binary */

    getBin(number,array);

    int i;
    for(i = 0; i<10; i++)
    {
        printf("%c\t",array[i]);
    }
    printf("\n");
    return 0;
}

void getBin(int num, char *str)
{
  *(str+8) = '\0';
  int mask = 0x80; 
  while(mask >>= 1)
    *str++ = !!(mask & num) + '0';
} 
    









