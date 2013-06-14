#if 0
Question: How would you find the number 
of bit swaps required to convert integer A 
to integer B?

#endif

#include<stdio.h>

int bit_swap_required (int a, int b)
{
    unsigned int count = 0;
    unsigned int c = a^b;
    while (c)
    {
        c = c & (c - 1);
        count++;
    }
    return count;
}


int main(void){
    int a = 2;
    int b = 4;
    int count  = bit_swap_required(a,b);
    printf("%d\n", count);
    return 0;
}
