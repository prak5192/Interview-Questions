/*
    Write a program to get shortest path between two given 
nodes in a binary tree.

*/

/* Explanation :
In order to find the shortest path between any two nodes you 
have to find the common parent between them that is the least 
common ancestor.
As it is not a binary search tree so just do a level order 
traversal and store them in a array then the indexing of the 
array would be such that for any node of array index n you will 
have parent at index (n-1)/2 .So for any two nodes just check 
if they have the same parent. If they have then it is the least 
common ancestor and the path length is 2 from 1st node to parent 
and then from parent to second node. If not then iterate upwards 
until you get a common parent and also increment a path count. 
I have also uploaded the code for it below.

This is the code for finding least common ancestor in a binary tree:
a. Store the nodes by doing a normal level order traversal
b. And then find the common parent of the node in the array

*/

#include <stdio.h>
#include <malloc.h>
typedef struct tree tree_t;
struct tree
{
    int data;
    tree_t *left;
    tree_t *right;
};
tree_t *newNode(int data)
{
    tree_t *n=(tree_t *)malloc(sizeof(tree_t));
    n->data=data;
    n->left=n->right=NULL;
    return n;
}
typedef struct queue q_t;
struct queue
{
    int front;
    int rear;
    int size;
    tree_t **array;
};
q_t *newQueue(int size)
{
    q_t *q=(q_t *)malloc(sizeof(q_t));
    q->front=q->rear=0;
    q->array=(tree_t **)malloc(q->size*sizeof(tree_t *));
    return q;
}
void enq(q_t *q,tree_t *t)
{
    q->array[q->rear++]=t;
}
tree_t *dequeue(q_t *q)
{
    q->front++;
    return q->array[q->front-1];
}
void printLca(int arr[],int *n,int n1,int n2)
{
    int i,parent1,parent2;
    int path=2;//path is obviously 2 if both the parents are same 
        
    for(i=0;i<*n;i++)
    {
        if(arr[i]==n1)
        {
            parent1=(i-1)/2;
        }
        else if(arr[i]==n2)
        {
            parent2=(i-1)/2;
        }
    }
    if(parent1==parent2)//if both the parents are same then it is the least common ancestor
    {
        printf(" The least common ancestor is %d and shortest path is %d",arr[parent1],path);
    }
    else//iterate until you find a common parent a parent for node n is (n-1)/2 its floor value and also increment the path
    {
        
        while(parent1!=parent2)
        {
            if(parent1<parent2)
            {
                parent2=(parent2-1)/2;
                path=path+1;
            }
            else if(parent2<parent1)
            {
                parent1=(parent1-1)/2;
                path=path+1;
            }
        }
        printf(" The least common ancestor is %d and shortest path is %d",arr[parent1],path);
    }
    
}
void lca(tree_t *t,int arr[],int n1,int n2,int *index)
{
    q_t *q=newQueue(20);
    tree_t *temp=t;
    while(temp)
    {
        arr[*index]=temp->data;
        (*index)++;
        if(temp->left)
            enq(q,temp->left);
        if(temp->right)
            enq(q,temp->right);
        temp=dequeue(q);
    }
    printLca(arr,index,n1,n2);
}
int main()
{
    tree_t *t=newNode(1);
    t->left=newNode(2);
    t->left->left=newNode(4);
    t->left->left->left=newNode(8);
    t->left->left->right=newNode(10);
    t->left->right=newNode(5);
    t->left->right->right=newNode(9);
    t->right=newNode(3);
    t->right->left=newNode(6);
    t->right->right=newNode(7);
    int arr[30],index=0;
    lca(t,arr,8,6,&index);
}
