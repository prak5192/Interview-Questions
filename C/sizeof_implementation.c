#include<stdio.h>

#define size_var(var) ((size_t)(&(var) + 1 ) - ((size_t)&(var)))


struct A  {
	int *a;
	int b;
	char c;
};

int main(void){
	int a;
	char b;
	float c;
	long d;
	double e;
	struct A f;
	
	printf("Size of int 	%lu\t , sizeof() = %lu\n", size_var(a), sizeof(a));
	printf("Size of char 	%lu\t , sizeof() = %lu\n", size_var(b), sizeof(b));
	printf("Size of float 	%lu\t , sizeof() = %lu\n", size_var(c), sizeof(c)); 
	printf("Size of long 	%lu\t , sizeof() = %lu\n", size_var(d), sizeof(d));  
	printf("Size of double 	%lu\t , sizeof() = %lu\n", size_var(e), sizeof(e));   
	printf("Size of Struct 	%lu\t , sizeof() = %lu\n", size_var(f), sizeof(f));   
	return 0;
}

