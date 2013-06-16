#if 0

http://cboard.cprogramming.com/c-programming/117911-sorted-linked-list.html

#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CHAR 20
 
/* DEFINE NODE*/
typedef struct node
{
    int age;
    char name[MAX_CHAR];
    struct node *next;
} person;
 
 
/* INPUTING A NODE INTO THE LIST*/
void Insert(person **head)
{
    person *new;
    new = malloc(sizeof(person));
    int i = 0; 
    char dummy_char;
    char name[20];
    int c;
    memset(name, 0, sizeof(name));
    
    printf("\nEnter name:\n");
    scanf("%c",&dummy_char);
    while ((c = getchar()) != '\n' && c != EOF){
        name[i] = c;
        i++;
        if(i == (MAX_CHAR -1) ){
            printf("Inside break statement i = %d\n", i);
            name[i] = '\0';
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
        printf("i = %d\n", i);
    }
    printf("Name entered: %s\n",name);
    memcpy(new->name , name, MAX_CHAR); 
    printf("Enter age: ");
    scanf("%d",&new->age);
    scanf("%c",&dummy_char);
    if (*head == NULL)
    {
        *head = new;
        new->next = NULL;
    }
    else
    {
        new->next = *head;
        *head = new;
   }
}
 
 
/* PRINT LIST*/
void Print(person **head)
{
    person *temp = *head;
    int i = 1;
     
    printf("\n\tLIST CONTENTS\n\n");
    if (temp == NULL) printf("List is empty!!");
    else
    {
        while (temp != NULL)
        {
            printf("No: %d\tNAME: %s\tAGE: %d\n", i, temp->name, temp->age);
            temp = temp->next;
            i++;
        }
    }
    printf("\n");
}
 

/* SORTED INPUT*/
void SortedInsert(person **head, person *o)
{
    person *temp = *head;
    person *new = o;
    
    if (*head == NULL)
    {
        *head = new;
        new->next = NULL;
    }
    else
    {
        if (new->age < temp->age)
        {
            new->next = temp;
            *head = new;
        }
        else
        {
            while (temp->next != NULL && temp->next->age < new->age)
            {
                temp = temp->next;
            }
            new->next = temp->next;
            temp->next = new;
        }
    }
}

/* SORT THE LIST*/
void SortList(person **head)
{
    person *head1 = NULL;
    person *current = *head;
    person *next;
    
    if (current == NULL) printf("List empty! Nothing to sort!");
    else
    {
        while (current != NULL)
        {
            next = current->next;
            SortedInsert(&head1,current);
            current = next;
        }
    }
    printf("SORTED LIST:\n");
    Print(&head1);
}

 
/* MAIN*/
int main (int argc, const char * argv[])
{
    person *head = NULL;
    int choice;
     
    do
    {
	    printf("\n***\tMENU\t***\n");
    	printf("\n 1.) Insert");
    	printf("\n 2.) Print");
    	printf("\n 3.) Sort");
    	printf("\n 0.) EXIT");
    	printf("\nChoose ---------> ");

        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                Insert(&head);
                break;
            case 2:
                Print(&head);
                break;
            case 3:
                SortList(&head);
                break;
            case 0:
                exit(0);
            default:
                printf("\nWRONG CHOICE");
        }
    } while (choice != 0);
     
    return 0;
}
