# if 0
Problematic program: 
========================
When it is executed only the first scanf stops for the prompt. 
The program does not stop for the next scanf s. But if the 
format string is changed from "%[^\n]" to " %[^\n]" (note 
the blank space before %), then it works okay. Does some 
existing newline character from the previous input buffer 
is automatically accepted ? But flushing stdin does not 
solve this.

int main (void)
{
  char str1[128], str2[128], str3[128];

  printf ("\nEnter str1: ");
  scanf ("%[^\n]", str1);
  printf ("\nstr1 = %s", str1);

  printf ("\nEnter str2: ");
  scanf ("%[^\n]", str2);
  printf ("\nstr2 = %s", str2);

  printf ("\nEnter str3: ");
  scanf ("%[^\n]", str3);
  printf ("\nstr2 = %s", str3);

  printf ("\n");
  return 0;
}

Solution: 
See below.
#endif

#include <stdio.h>

int main (void)
{
	char str1[128], str2[128], str3[128];
 	char* fmt = "%[^\n]%*c";

  	printf ("\nEnter str1: ");
  	scanf (fmt, str1);
  	printf ("\nstr1 = %s", str1);

  	printf ("\nEnter str2: ");
  	scanf (fmt, str2);
  	printf ("\nstr2 = %s", str2);

  	printf ("\nEnter str3: ");
  	scanf (fmt, str3);
  	printf ("\nstr2 = %s", str3);

  	printf ("\n");
}
