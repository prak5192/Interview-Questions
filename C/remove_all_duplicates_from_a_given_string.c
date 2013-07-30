/*
    Remove all duplicates from the input string.
    Time Complexity: O(n)

*/
#if 0

METHOD 2 (Use Hashing )

Algorithm:

1: Initialize:
    str  =  "test string" /* input string */
    ip_ind =  0          /* index to  keep track of location of next
                             character in input string */
    res_ind  =  0         /* index to  keep track of location of
                            next character in the resultant string */
    bin_hash[0..255] = {0,0, ….} /* Binary hash to see if character is 
                                        already processed or not */
2: Do following for each character *(str + ip_ind) in input string:
              (a) if bin_hash is not set for *(str + ip_ind) then
                   // if program sees the character *(str + ip_ind) first time
                         (i)  Set bin_hash for *(str + ip_ind)
                         (ii)  Move *(str  + ip_ind) to the resultant string.
                              This is done in-place.
                         (iii) res_ind++
              (b) ip_ind++
  /* String obtained after this step is "te sringng" */
3: Remove extra characters at the end of the resultant string.
  /*  String obtained after this step is "te sring" */

#endif

# include <stdio.h>
# include <stdlib.h>
# define NO_OF_CHARS 256
# define bool int
 
/* Function removes duplicate characters from the string
   This function work in-place and fills null characters
   in the extra space left */
char *removeDups(char *str)
{
  bool bin_hash[NO_OF_CHARS] = {0};
  int ip_ind = 0, res_ind = 0;
  char temp;   
 
  /* In place removal of duplicate characters*/ 
  while(*(str + ip_ind))
  {
    temp = *(str + ip_ind);
    if(bin_hash[temp] == 0)
    {
        bin_hash[temp] = 1;
        *(str + res_ind) = *(str + ip_ind);
        res_ind++;        
    }
    ip_ind++;
  }     
 
  /* After above step string is stringiittg.
     Removing extra iittg after string*/       
  *(str+res_ind) = '\0';  
   
  return str;
}
 
/* Driver program to test removeDups */
int main()
{
    char str[] = "geeksforgeeks";
    printf("%s", removeDups(str));
    getchar();
    return 0;
} 
