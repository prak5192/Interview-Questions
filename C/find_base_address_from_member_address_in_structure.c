#if 0

Write the logic to find the 
the base address of the structure 
by using the address of the element 
of the structure..


#endif

#include<stdio.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct A{
    int a;
    char b;
    int c;
}my_struct;



int foo(int *ptr)
{
    long int offset;
    my_struct *base_address;
 

    printf("Offset calculated by the offsetof macro\n");   
    long int value = (long)offsetof(my_struct,c); 
    printf("Offset value %ld\n",value);

    printf("Offset calculated manually\n");   
    offset = (char *)&(((my_struct *)0)->c) - ((char *)(my_struct *)0);
    printf("Offset value %ld\n",value);


    printf("ptr = %p\n",ptr);
    base_address = (my_struct *) ((long int)ptr - offset);
    printf("base_address = %p\n",base_address);

    printf("The value in structure in foo function\n");
    printf("a = %d\t b = %c\t c = %d\n",base_address->a, base_address->b, base_address->c);
    
    base_address->a = 60;
    base_address->b = 'P';
    base_address->c = 100;
    
    return 0;
}

int main(void)
{
    my_struct hello = {20,'Z',34};

    int ret = foo(&hello.c);
    printf("The value in structure after calling modification function\n");
    printf("a = %d\t b = %c\t c = %d\n",hello.a, hello.b, hello.c);
    
    return 0;
}
