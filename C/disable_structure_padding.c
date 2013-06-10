#if 0

Program which shows usage of prgama keyword in C

#endif




#include<stdio.h>

#pragma pack(push)
#pragma pack(1)


struct A {
    int  ptr;
    char array[10];
    int a;
    short int b;
};


#pragma pack(pop)

struct B {
    int ptr;
    char array[10];
    int a;
    short int b;
};


int main(void){
    printf("Size with packing (Pragma)\n");
    printf("%ld\n", sizeof(struct A));
    
    printf("Size without packing (Pragma) \n");
    printf("%ld\n", sizeof(struct B));

    return 0;
}
    
