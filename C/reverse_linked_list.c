#if 0
    
Explanation of the reversing linked list by recursion
=====================================================
Consider the list:

   1  ->  2  ->  3  ->  4 -> NULL
   ^      ^
   |      |
 first   rest

Where first points to the first node and rest points to the
node next to first.

Since the list is not empty and list does not contain one node 
we make recursive call to reverse to reverse the list pointed 
to by rest. This is how the list looks after reversing the rest 
of the list:

   1  ->  2  <-  3  <-  4
   ^      |             ^
   |     NULL           |
 first                 rest

As seen rest now points to the reversed list which has 4 at the
beginning and 2 at the end of list. The next pointer of node 2 
is NULL.

Now we need to append the first node to the end of the reversed-rest
list. To append anything to the end of the list we need to have 
access to the last node of the list. In this case we need to have 
access to the last node of the reversed-rest list. Look at the 
diagram, first -> next points to the last node reversed-rest list. 
Therefore first -> next -> next will be next pointer of the last node 
of the reversed-rest list. Now we need to make it point to first so we do:

first -> next -> next = first;

After this step the list looks like:

   1  <-  2  <-  3  <-  4
   ^  ->                ^
   |                    |
 first                 rest

Now the next field of the last node of the list must be NULL. But it 
is not the case now. The next field of the last node ( node 1) is 
pointing to the node before it ( node 2). To fix this we do:

first -> next = NULL;

After this the list looks like:

NULL <- 1  <-  2  <-  3  <-  4
        ^                    ^
        |                    |
      first                 rest

As seen the list is now correctly reversed with rest pointing to 
the head of the reversed list.

We need to return the new head pointer so the that changes are 
reflected in the calling function. But this is a void function and 
head is passed as double pointer so changing the value of *head 
will make the calling function see the changed head:

*head = rest;

#endif



#include <stdio.h>

typedef struct Node {
  char data;
  struct Node* next;
} Node;


void print_list(Node* root) {
  while (root) {
    printf("%c ", root->data);
    root = root->next;
  }
  printf("\n");
}


Node* reverse_recursive(Node* head)
{
      Node * temp = NULL;

      if ( head == NULL)
          return NULL;
      if ( head->next == NULL )
         return head;

      temp = reverse_recursive( head->next );
      head->next->next = head;
      head->next = NULL;
      return temp;
}


Node* reverse(Node* root) {
  Node* new_root = 0;
  while (root) {
    Node* next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

int main() {
    Node d = { 'd', 0 };
    Node c = { 'c', &d };
    Node b = { 'b', &c };
    Node a = { 'a', &b };

    Node* root = &a;
    print_list(root);
    root = reverse(root);
    print_list(root);
    root = reverse_recursive(root);
    print_list(root);
    

  return 0;
}
