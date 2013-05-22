// compile this code using electric fence.
// If electric fence is not installed on your machine.
// Use the beloow command to install it
// sudo apt-get install electric-fence

// compilation : gcc heapcheck.c -g -lefence
// $ ulimit -c unlimited
// $ export EF_PROTECT_BELOW=1
// Run : gdb ./a.out


// Limitation of electric fence is it is configured for checking either upper boundry
// or lower boundry in the program, but not both at the same time

#include<stdio.h>
#include<stdlib.h>


int buggy_function(void)
{
	int *ptr;
	ptr = (int *) malloc(sizeof(int)*4);
	if(ptr == NULL){
		printf("Error in mallocing the memory\n");
		return 0;
	}
	int i;
	for(i = 0; i<2 ; i++){
		*ptr = i; // underrun violation
		ptr--;
	}
	return 0;
}

int main(void){
	int ret = buggy_function();
	return 0;
}
