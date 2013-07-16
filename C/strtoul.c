/* Example to show the strtoul function */


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void main(void)
{
     char* str  = "12345ascd";
     unsigned long num;
     char* leftover;
     num = strtoul(str, &leftover, 10);
     printf("Original string:      %s\n", str);
     printf("Converted number:     %lu\n", num);
     printf("Leftover characters:  %s\n", leftover);
}
