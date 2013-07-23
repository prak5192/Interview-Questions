// http://www.careercup.com/question?id=15877680
/* 

Complete the function getEqualSumSubstring, which takes a 
single argument. The single argument is a string s, which contains 
only non-zero digits.
This function should print the length of longest contiguous 
substring of s, such that the length of the substring is 2*N 
digits (maximum length of the string is 49) and the sum of the 
leftmost N digits is equal to the sum of the rightmost N digits.
If there is no such string, your function should print 0.

Sample Test Cases:

Input #00:
123231

Output #00:
6

Explanation:
1 + 2 + 3 = 2 + 3 + 1.
The length of the longest substring = 6 where the sum of 
1st half = 2nd half


Input #01:
986561517416921217551395112859219257312

Output #01:
36

*/

/*
Possible nontested solution 
*/

#include<cstdio>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

int getEqualSumSubstring(string s) {
    int i = 0, j = i, foundLength = 0;
    for(i = 0 ; i < s.length() ; i++)
    {   
        for(j = i ; j < s.length() ; j++)
        {   
            int temp = j - i + 1;

            /* Take the strings in pair */
            if( (temp % 2) == 0)
            {   
                int leftSum = 0 , rightSum = 0;
                string tempString = s.substr( i, temp);
                cout << tempString << " Length -> " << tempString.length()<< endl;
                for(int k = 0 ; k < temp/2 ; k++)
                {   
                    leftSum = leftSum + tempString[k] - 48; 
                    rightSum = rightSum + tempString[k+(temp/2)] - 48; 
                }   

                if((leftSum == rightSum) && (leftSum != 0)) {
                    /* If previous found lengh is less than the 
                        current tempString lengh */
                    if( tempString.length() > foundLength ) { 
                        /* Update the found string length */
                        foundLength = tempString.length(); 
                    }   
                }   
            }   
        }   

    }   
    return( foundLength );
}



int main()
{
    char a[100];
    int length=0,n,k,sum1=0,sum2=0,i,j,l;

    printf("\nenter the required string to compute:\n");
    gets(a);

    int ret =  getEqualSumSubstring(a);
    if(ret){
        printf("Length %d\n", ret);
    } else {
        printf("NO string found\n");
    }
    return 0;
}
