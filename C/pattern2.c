/* 
    Suppose you have a string like-I am a king ,
in this string you have to write code to count 
the total number of words which have only single 
alphabet .for this string answer sholud be 2. 

*/

/* 
Explanation 
assign each space char as operation +
each char as a value = 1
we need to convert the string into a numerical expression 
where a multiple char numerical value = 0
When a multiple characters string is found, its value would 
be str[0]-str[1], ignoring remaining characters in building 
expression
So the string "I am a king" will become
1+(1-1)+1+(1-1) = 2 //replace space with + and while scanning 
a multichar string, just scan first two chars
Complexity = O(n)
*/

