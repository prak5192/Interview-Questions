#include <stdio.h>
int main()
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)   
       printf("Little endian");
   else
       printf("Big endian");

   return 0;
}
