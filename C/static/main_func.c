#if 0

Shows the static keyword characteristic
1. A variable/file defined static in 
a file is not visible in other file.
To check this functionality, delete 
comment the "int static a = 30"
line in main variable.

To compile the code:
$ gcc file1.c file2.c main_func.c -o exe
To run it:
$./exe

#endif

#include<stdio.h>
int static a = 30;
int main(void){
	print1();
	print2();
	printf("From main function %d\n",a);
	return 0;
}

