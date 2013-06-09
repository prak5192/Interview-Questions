/* 
Program to convert little endian to big endian.
*/

#include<stdio.h>
#include<arpa/inet.h>

/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
         printf(" %.2X", start[i]);
    printf("\n");
}

int main(void){
	int little_endian_num = 0x12345678;
	int big_endian_num;
	big_endian_num = (( little_endian_num & 0xFF000000) >> 24 ) | 
					 (( little_endian_num & 0x00FF0000) >> 8 ) | 
					 (( little_endian_num & 0x0000FF00) << 8 ) | 
					 (( little_endian_num & 0x000000FF) << 24 );


    printf("Little endian:");
    show_mem_rep((char*)&little_endian_num,sizeof(little_endian_num));
    printf("Big endian:");
    show_mem_rep((char*)&big_endian_num,sizeof(big_endian_num));

    printf("\nBy using htonl() function\n");
    big_endian_num = htonl(little_endian_num);
    printf("Big endian:");
    show_mem_rep((char*)&big_endian_num,sizeof(big_endian_num));
	return 0;
}
