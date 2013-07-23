#include <stdio.h>
#include <string.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void insert(node **head_ref, int val)
{
    node *curr;
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
    curr = *head_ref;
    if (curr == NULL)
    {
        *head_ref = temp;
        return;
    }
    else
    {
        while(curr->next!= NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        return;
    }
}

void display(node **head_ref)
{
    node *temp = NULL;
    temp = *head_ref;
    if(temp == NULL)
    {
        printf("Sorry list is empty");
        return;
    }
    else
    {
        while(temp!= NULL)
        {
            printf("The value is: %d\n", temp->data);
            temp = temp->next;
        }
        return;
    }
}

int hashtab(int *hash_ref, int *val)
{
    int key;
    key = (int)val%7;
    if(hash_ref[key] == 0)
    {
        hash_ref[key] = *val;
        return 0;
    }
    else
    {
        while(hash_ref[key]!= 0)
        {
            if(hash_ref[key] == *val)
                return 1;
            if(hash_ref[key] == 0)
                hash_ref[key] = *val;
            key = key+1;
            return 0;.
        }
    }
}

int searchhash(int *hash_ref, int *val)
{
    int key;
    key = (int)val%7;
    if(hash_ref[key] == 0)
    {
        return 0;
    }
    else
    {
        while(hash_ref[key]!= 0)
        {
            if(hash_ref[key] == *val)
                return 1;
            key = key+1;
            return 0;
        }
    }
}

void intersection(node **head_ref1, node **head_ref2)
{
    node *temp1 = *head_ref1;
    node *temp2 = *head_ref2;.
    int ret;.
    int val;.
    int i, j;.
    int hash[10];.
    for(i = 0;i <10; i++).
    {.
    hash[i] = 0;.
    }.
    for(i = 0;i <10; i++).
    {.
    printf("the hash is:%d.\n", hash[i]);.
    }.
    if(NULL == temp1).
    {.
    printf("The list is empty.\n");.
    return;.
    }.
    else.
    {.
    while(temp1!=NULL).
    {.
    hashtab(hash, temp1);.
    temp1= temp1->next;.
    //printf("What.\n");.
    }.
    while(temp2!=NULL).
    {.
    val=hashtab(hash, temp2);.
    if(val == 1).
    {.
    printf("Intersection occur at:%d.\n", temp2->data);.
    return;.
    }.
    temp2= temp2->next;.
    //printf("What.\n");.
    }.
    printf("In the else.\n");.
    }.
    return;.
}
main()
{
    /*.
    Create two linked lists.
    1st 3->6->9->15->30.
    2nd 10->15->30.
    15 is the intersection point.
    */.
    struct node* newNode;.
    struct node* head1 =.
    (struct node*) malloc(sizeof(struct node));.
    head1->data = 10;.
    struct node* head2 =.
    (struct node*) malloc(sizeof(struct node));.
    head2->data = 3;.
    newNode = (struct node*) malloc (sizeof(struct node));.
    newNode->data = 6;.
    head2->next = newNode;.
    newNode = (struct node*) malloc (sizeof(struct node));.
    newNode->data = 9;.
    head2->next->next = newNode;.
    newNode = (struct node*) malloc (sizeof(struct node));.
    newNode->data = 15;.
    head1->next = newNode;.
    newNode = (struct node*) malloc (sizeof(struct node));.
    newNode->data = 30;.
    head1->next->next= newNode;.
    head2->next->next->next = newNode;.
    head1->next->next->next = NULL;.
    printf("First linklist.\n");.
    display(&head1);.
    printf("Second linklist.\n");.
    display(&head2);.
    //printf("\n The node of intersection is %d \n",
    intersection(&head1, &head2);.
}
