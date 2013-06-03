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
	callback ptr_my_callback = my_callback;
	// Register our call back function
	register_callback(ptr_my_callback);
	printf("Again into my main function\n");
	return 0;
}

void register_callback(callback ptr_callback_func){
	printf("Inside register callback function\n");// Calling our callback function
	(*ptr_callback_func)();
}

