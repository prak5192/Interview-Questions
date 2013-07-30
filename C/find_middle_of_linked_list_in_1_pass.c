/*
    How do you find the middle of the linked list in one pass?
*/

/* 

Explanation:
     To answer this programming question I would say you start 
with simple solution on which you traverse the LinkedList until 
you find the tail of linked list where it points to null to find 
the length of linked list  and then reiterating till middle. 
After this answer interviewer will ask you find the middle element 
in single pass and there you can explain that by doing space-time 
tradeoff you can use two pointers one incrementing one step at a 
time and other incrementing two step a time, so when first pointer 
reaches end of linked second pointer will point to the middle element.

*/
