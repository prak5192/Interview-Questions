
#if 0

What is a callback function ?
=============================

In computer programming, a callback is a piece of executable code 
that is passed as an argument to other code, which is expected to 
call back (execute) the argument at some convenient time. The 
invocation may be immediate as in a synchronous callback or it 
might happen at later time, as in an asynchronous callback.

                    OR

The simple answer to this first question is that a callback function 
is a function that is called through a function pointer. If you pass 
the pointer (address) of a function as an argument to another, when 
that pointer is used to call the function it points to, it is said 
that a call back is made.

#endif


#include<stdio.h>
#include<stdlib.h>
typedef void (*callback)();
void register_callback(callback ptr_callback_func);

void my_callback()
{
	printf("Inside callback function\n");
}

int main(void){
	printf("This is program demonstrating function call back\n");
	callback ptr_my_callback = &my_callback;
	// Register our call back function
	register_callback(ptr_my_callback);
	printf("Again into my main function\n");
	return 0;
}

void register_callback(callback ptr_callback_func){
	printf("Inside register callback function\n");// Calling our callback function
	ptr_callback_func();
}

