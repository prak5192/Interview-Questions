#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 10 
#define POP 2
#define PUSH 1
#define DISPLAY 3
#define EXIT 4
#define PASS 1 
#define FAIL 0

int rear1 = -1;
int front1 = -1;
int rear2 = -1;
int front2 = -1;
int queue1[MAX_SIZE];
int queue2[MAX_SIZE];

int insert1(int item)
{
    if(rear1 == MAX_SIZE - 1){
        return FAIL;
    } else {
        queue1[rear1 + 1] = item;
        rear1++;
    }
    return PASS;
}

int delete1()
{
	int ret = 0;
    if((rear1 == -1) || (front1 == rear1)){
        return FAIL;
    } else {
        front1++;
        ret =  queue1[front1];
		queue1[front1] = 0;
		return ret;
    }
}

void display1()
{
    int i =0 ;
    for(i = 0; i< MAX_SIZE ; i++){
        printf("a1[%d] => %d\n",i,queue1[i]);
    }
}

int insert2(int item)
{
    if(rear2 == MAX_SIZE - 1){
        return FAIL;
    } else {
        queue2[rear2 + 1] = item;
        rear2++;
    }
    return PASS;
}

int delete2()
{
	int ret = 0;
    if((rear2 == -1) || (front2 == rear2)){
        return FAIL;
    } else {
        front2++;
        ret = queue2[front2];
		queue2[front2] = 0;
		return ret;
    }
    
}

void display2()
{
    int i =0 ;
    for(i = 0; i< MAX_SIZE ; i++){
        printf("a2[%d] => %d\n",i,queue2[i]);
    }
}


int main(void)
{
    printf("\n====== Simple stack Program using two queue ======\n\n");
    int switch_option = 0;
    int true = 1;
    int ret = 1;
	int item = 0;
    do{
        printf("Enter the choice:-\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        scanf("%d",&switch_option);
        switch(switch_option){
            case PUSH:
				printf("Enter the item you want to push\n");
				scanf("%d",&item);
                ret = insert1(item);
                if(ret == PASS){
                    printf("Success in insertion process\n");
                } else {
                    printf("Error in insertion process\n");
                }
                break;   
            case POP:
				ret = PASS;
   				if((front1 - rear1) == -1){
                	ret = delete1();
				    printf("Popped item is %d\n",ret);
				} else {	
				   	while(ret != FAIL){
				   		ret = delete1();
				   		ret = insert2(ret);
				   		printf("Front1 = %d, rear1 = %d\n",front1,rear1);
				   		if((front1 - rear1) == -1){
				   			ret = delete1();
				   			printf("Popped item is %d\n",ret);
				   			front1 = -1;
				   			rear1 = -1;
				   			break;
				   		}
				   	}

				   	ret = PASS;
				   	while(ret != FAIL){
				   		ret = delete2();
				   		if(ret == FAIL){
				   			front2 = -1;
				   			rear2 = -1;
				   			break;
				   		}
				   		ret = insert1(ret);
				    }
				}
				break;
            case DISPLAY:
                display1();
				printf("\n");
				display2();
                break;
            case EXIT:
                return 0;
                break;
            default:
                printf("The entered swicth option is out of range\n");
                break;
        }
        printf("Enter 1 if you want to continue\n");
        scanf("%d",&true);
   }while(true == 1); 
}
