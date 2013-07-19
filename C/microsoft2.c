/*

Given a BST, how would you return the nth smallest element. 
The code had to cover all the edge cases and was expected 
to write a logn solution.

*/

/* 

Explanation:
    Solution does not exist. For a log(n) solution, you 
need to visit each level a constant number of times 
without traversing all the nodes, effectively eliminating 
as you go. Elimination is not possible in this case.

At the beginning, you are at the root and you can't have 
any idea where to go. You pick left or right. Without 
traversing all the nodes in that subtree, you can't even 
know if you are in the correct subtree. Getting the number 
of nodes there is already O(n). That's why Log(N) is impossible.

I think this question was meant to be asked for a complete BST.

*/
