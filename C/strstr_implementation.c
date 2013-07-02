#include <stdio.h>
#include <string.h>

char* my_strstr(char *s2, char *s1)
{
    int i, j, k;
    int flag = 0;

    if ((s2 == NULL || s1 == NULL)){ 
        return NULL;
    }
    for( i = 0; s2[i] != '\0'; i++){
        if (s2[i] == s1[0]){
            for (j = i, k = 0; ; j++, k++){
                if (s1[k] == '\0'){ 
                    flag = 1; break;
                }
                if (s2[j] == s1[k]) { 
                    continue;
                } else { 
                    break;
                }
            }
            if (flag == 1) { 
                break;
            }
        }
    }

    if (flag) { 
        return (s2+i);
    } else {
        return NULL;
    }
}

int main()
{
    char s2[] = "This is the statement";
    char s1[] = "hello";
    char *temp;

    temp = my_strstr(s2,s1);

    if(temp == NULL ){
        printf("[%s] is not subset of [%s]\n", s1, s2);
    } else {
        printf("[%s] is a subset of [%s]\n", s1, s2);
        printf("%s\n",temp);
    }
    strcpy(s1, "the");
    temp = my_strstr(s2,s1);

    if(temp == NULL ){
        printf("[%s] is not subset of [%s]\n", s1, s2);
    } else {
        printf("[%s] is a subset of [%s]\n", s1, s2);
        printf("%s\n",temp);
    }

    return 0;
}


