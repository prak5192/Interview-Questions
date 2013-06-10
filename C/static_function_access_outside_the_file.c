#if 0
how to use static function defined in one file in another file is that
impposiible in 'c '

#endif
/* file b.c */
/* hidden function */
static int local_foo(int x) {
return x*x;
}

/* function with external linkage */
int foo(int x) {
return local_foo(x);
}

/* function pointer with external linkage */
int (*foop)(int) = local_foo;

/* file a.c */
#include <stdio.h>
int foo(int);
int (*foop)(int);

int main(void)
{
int x = 2;
printf("foo(%d) = ",x);
printf("%d\b", x = foo(x));
printf("foop(%d) = ",x);
printf("%d\b", x = foop(x));
return 0;
}

#if 0
[output]
foo(2) = 4
foop(4) = 16
    
#endif

