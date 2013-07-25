#include<stdio.h>

/* Work as concatening the two variable X and Y */

/* 

The ## in # ## # acts like an escape sequence in this expression. 
It concatenates the leftmost and the rightmost # to finally produce 
the token ##. Simply defining the macro as ## would cause an error 
since the concatenation operator expects two operands.

*/

/*
Function macro definitions accept two special operators (# and ##) 
in the replacement sequence:
If the operator # is used before a parameter is used in the 
replacement sequence, that parameter is replaced by a string literal 
(as if it were enclosed between double quotes)

#define str(x) #x
cout << str(test);
This would be translated into:
cout << "test";

The operator ## concatenates two arguments leaving no 
blank spaces between them:

#define glue(a,b) a ## b
glue(c,out) << "test";

This would also be translated into:
cout << "test";

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
