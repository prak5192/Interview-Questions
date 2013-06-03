#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *ptr ; 
	ptr = (int *) malloc( sizeof(int ) * 1);
	if (ptr == NULL){
		perror("Malloc error\n");
		exit(1);
	} else {
		printf("Success: malloc\n");
	}
	
	free(ptr);
}



	*ptr = 77;
	free(ptr);
	

	
	
