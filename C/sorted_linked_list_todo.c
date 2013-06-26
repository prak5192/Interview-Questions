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
            name[i] = '\0';
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
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
    if (temp == NULL){
        printf("List is empty!!");
    } else {
        while (temp != NULL){
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
    } else {
        if (new->age < temp->age) {
            new->next = temp;
            *head = new;
        } else {
            while (temp->next != NULL && temp->next->age < new->age) {
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
    
    if (current == NULL){
        printf("List empty! Nothing to sort!");
        return;
    } else {
        while (current != NULL) {
            next = current->next;
            SortedInsert(&head1,current);
            current = next;
        }
    }
    printf("SORTED LIST:\n");
    Print(&head1);
}


void save_to_file(person **head)
{
    FILE *fp;
    int ret = 0;
    fp = fopen("./linked_list_DB.txt","w+");
    if(fp == NULL){
        printf("File opening gets failed\n");
        exit(0);
    }
    int i = 0;
    person * temp = *head;
    while( temp != NULL){
        printf("i    ==========> %d\n", i);
        ret = fwrite(temp,sizeof(person),1,fp);
        if(ret == 0){
            break;
        }
        i++;
        temp = temp->next;
    }
    fclose(fp);
}

void read_from_file(person **head)
{
    printf("reading from file\n");
    person *head1 = *head;
    person *temp = NULL;
    FILE *fp = NULL;
    int ret = 0;
    int i =0;
    fp = fopen("./linked_list_DB.txt","r+");
    if(fp == NULL){
        printf("Error in opening the file\n");
        exit(0);
    }

    temp = *head;
    person *f = NULL;
    while(!feof(fp)){
        f = calloc(1,sizeof(person));  
        if(f == NULL){
            printf("Calloc_fails\n");
            exit(0);
        }
        ret = fread(f,sizeof(person), 1, fp);
        if(ret == 0){
            break;
        }
        f->next = NULL;
        printf("The value from file is %s\n",f->name); 
        if(temp == NULL){
            *head= f;
            temp = *head;
            printf("i = %d, value %s\n",i, temp->name);
            i++;
        }else{
            while(temp->next != NULL){
                printf("i = %d, value %s\n",i, temp->name);
                i++;
                temp = temp->next;
            }
        temp->next = f;
        }
    }
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
        printf("\n 4.) Save_to_file");
        printf("\n 5.) Read_from_file");
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
            case 4: 
                save_to_file(&head);
                break;
            case 5:
                read_from_file(&head);
                break;
            case 0:
                exit(0);
            default:
                printf("\nWRONG CHOICE");
        }
    } while (choice != 0);
     
    return 0;
}
