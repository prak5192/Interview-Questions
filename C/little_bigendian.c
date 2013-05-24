#include<stdio.h>


int main(void){
	unsigned int little_endian_num = 0xABCDEFDE;
	unsigned int big_endian_num;

	big_endian_num = (( little_endian_num >> 24 ) & 0xFF)| 
					 (( little_endian_num >> 8 ) & 0xFF) | 
					 (( little_endian_num << 8 ) & 0xFF) | 
					 (( little_endian_num << 24 ) & 0xFF);

	printf("Little Endian : %X\n",little_endian_num);
	printf("Big Endian : %X\n",big_endian_num);

	return 0;
}
	
