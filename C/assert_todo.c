#if 0

What is assert and when i would use it 

#endif

/*
It is a macro, defined in <assert.h>, for testing ``assertions''. 
An assertion essentially documents an assumption being made by the 
programmer, an assumption which, if violated, would indicate a serious 
programming error. For example, a function which was supposed to 
be called with a non-null pointer could write
assert(p != NULL);
A failed assertion terminates the program. Assertions should not be 
used to catch expected errors, such as malloc or fopen failures. 

*/

#include <stdio.h>
#include <assert.h>
 
int main() {
    int a, b;
 
    printf("Input two integers to divide\n");
    scanf("%d%d", &a, &b);
 
    assert(b != 0);
 
    printf("%d/%d = %.2f\n", a, b, a/(float)b);
 
    return 0;
}
