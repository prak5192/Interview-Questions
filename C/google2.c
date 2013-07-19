/* 
Given a very very very large integer(with 1 million digits
, say), how would you convert this integer to an ASCII string


It's like :
input - 12345678........8798989887873124234....(1 million digits)
output - "12345678............8798989887873124234...."
basically an itoa() kinda function but here the input is a very 
very large integer
*/

/* 
Explanation:

I think doing % and / is not the correct approach to this, 
the algorithm basically work, but if we consider a number 
with millions of digits, the datatype should be some sort 
of linked list containing a single digit peer bucket, 
in that way the "big" number can grow to million digits, 
so in my opinion the correct way should be visit from back 
to beginning the linked list an put each digit into a string 
buffer then return it.

*/
