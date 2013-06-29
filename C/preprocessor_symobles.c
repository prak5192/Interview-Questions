#include<stdio.h>

/* Work as concatening the two variable X and Y */

/* 

The ## in # ## # acts like an escape sequence in this expression. 
It concatenates the leftmost and the rightmost # to finally produce 
the token ##. Simply defining the macro as ## would cause an error 
since the concatenation operator expects two operands.

*/

#define hash_hash # ## #
#define mkstr(a) # a
#define in_between(a) mkstr(a)
#define join(c, d) in_between(c hash_hash d)

#define TEST(X,Y) X ## Y

int main(void)
{
    printf("%s\n", join("prakash","ranjan"));
    return 0;
}
