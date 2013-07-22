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

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[100],b[100],c[100],choice;
    int length=0,n,k,sum1=0,sum2=0,i,j,l;

    printf("\nenter the required string to compute:\n");
    gets(a);
    length=strlen(a);
    printf("the length is %d:",length);
    printf("\ndo u want to continue:\n",choice);
    scanf("%c",&choice);

    if(choice=='y')
    {
        if(length%2==0)
        {
            printf("\nthe string length is even:perform the operation\n");
        }
    }
    else
    {
        printf("\nthe string length is ODD:so cannot perform\n");
        exit(1 );
    }

    n=length/2;
    l=n-1;
    printf("\nthe first half will be from 0 to %d\n",(n-1));

    k=n;
    printf("the value of k:%d",k);
    printf("\nthe second half will be from %d to %d\n",k,(length-1));

    for(j=0;j<=(n-1);j++)
    {
        b[0]=a[j];
        b[1]='\0';

        sum1=(sum1+(atoi(b)));

    }
    printf("\nthe sum1 is :%d\n",sum1);


    for(i=k;i<=(length-1);i++)
    {
        c[0]=a[i];
        c[1]='\0';


        sum2=(sum2+(atoi(c)));
    }
    printf("\nthe sum2 is :%d\n",sum2);

    if(sum1==sum2)
    {
        if(sum1==length)
        {
            printf("\nthe longest string==the sum of the half of the substring\n");
        }

    }
    else
    {
        printf(" \nthe longest string is not equal to the sum of the half of the substring\n");
    }

    return 0;
}


