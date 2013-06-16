#include<stdio.h>
#include<string.h>

int main(void){
    int i;
    char dummy_char;
    char name[20];

    memset(name, 0, sizeof(name));
    printf("Enter the number:\n");
    scanf("%d",&i);
    printf("%d\n", i);
    printf("Enter the name\n");
    int count;
    int c;
    
    scanf("%c",&dummy_char);
    while ((c = getchar()) != '\n' && c != EOF){
        name[count++] = c;
        if(count == 20 ){
            break;
            count--;
            name[count] = NULL;
        }
    }
    printf("The name entered: %s\n", name);
    for( i=0; i< count ; i++){
        printf("%X\t", name[i]);
    }
    printf("\n");

    return 0;
}
    
