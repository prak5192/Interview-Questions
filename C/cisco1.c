/*
Given a big string (str1) find (s1) and replace by (s2).

Example :
str = "Hi i am abc and i am in abc"
s1 = "abc"
s2 = "pqrstuv"

So final o/p :
str1 = "Hi i am pqrstuv in pqrstuv"

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;

    char *a = "Hi  i am abc and i am in abc";
    char* b="abc";
    char* c="pqrstuv";
    int lenb=strlen(b);
    int lenc=strlen(c);
    char* ptrb = malloc(lenb);
    char* out;
    char* outtemp;

    out = malloc( 5*strlen(a) );
    outtemp = out;

    memset (out,0,strlen(a)+1);
    memset (ptrb,0,lenb);

    for (i =0 ; *a ; i++)
    {
        // Copy lenb characters into temporary array
        strncpy(ptrb, a, lenb);

        // Compare temporary array with reference b
        if (!strcmp(ptrb,b))
        {
            // If match, replace with other string.
            strncpy(out,c,lenc);
            out+=lenc;
            a+=lenb;
        }
        else
        {
            // Increment pointers
            *out++=*a++;
        }
    }

    // Print output
    *out='\0';
    fputs(outtemp,stdout);
    printf("\n");

    // Free temporary memory
    free(outtemp);
}
