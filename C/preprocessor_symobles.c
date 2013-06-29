#include<stdio.h>

/* Work as concatening the two variable X and Y */

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
