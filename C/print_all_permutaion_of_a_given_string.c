/*
http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
    Print all permutation of agiven string in C.
    
Below are the permutations of string ABC.
ABC, ACB, BAC, BCA, CAB, CBA

Algorithm Paradigm: Backtracking
Time Complexity: O(n*n!)
*/

# include <stdio.h>
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   if (i == n)
     printf("%s\n", a);
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}
 
/* Driver program to test above functions */
int main()
{
   char a[] = "ABC"; 
   permute(a, 0, 2);
   return 0;
}

