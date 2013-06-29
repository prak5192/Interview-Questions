#include<stdio.h>

#define TEST(X,Y) X#Y

int main(void)
{
    int a = 10;
    int b = 30;
    printf("%d\n", TEST(a,b));
    return 0;
}
