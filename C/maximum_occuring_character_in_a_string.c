/*
    Write an efficient C function to return maximum occurring character 
    in the input string e.g., if input string is “test string” then 
    function should return ‘t’.
*/

/*
Algorithm:

Input string = “test”
1: Construct character count array from the input string.
  count['e'] = 1
  count['s'] = 1
  count['t'] = 2

2: Return the index of maximum value in count array (returns ‘t’).

Time Complexity: O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#define NO_OF_CHARS 256
 
int *getCharCountArray(char *);
char getIndexOfMax(int *, int);
 
/* Returns the maximum occurring character in
 the input string */
char getMaxOccuringChar(char *str)
{
    int *count = getCharCountArray(str);
    return getIndexOfMax(count, NO_OF_CHARS);
}
 
/* Returns an array of size 256 containg count
   of characters in the passed char array */
int *getCharCountArray(char *str)
{
    int *count = (int *)calloc(NO_OF_CHARS, sizeof(int));
    int i;
 
    for (i = 0; *(str+i);  i++)
        count[*(str+i)]++;
 
    return count;
}
 
char getIndexOfMax(int ar[], int ar_size)
{
    int i;
    int max_index = 0;
 
    for(i = 1; i < ar_size; i++)
        if(ar[i] > ar[max_index])
             max_index = i;
 
  /* free memory allocated to count */
    free(ar);
    ar = NULL;
 
    return max_index;
}
 
int main()
{
    char str[] = "sample string";
    printf("%c", getMaxOccuringChar(str));
 
    getchar();
    return 0;
}


