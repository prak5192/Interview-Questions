#if 0
/*
    Write a program to print string in the following pattern -
If i/p is 'abc' then o/p should be 'abbccccccbba'.

*/

/* 
Non -tested solution 
* /
# endif

char *pattern_convertion(char *str)
{
    char *ret = NULL;
    int l = strlen(str);
    if(l == 0) return NULL;
    if((ret = (char *)malloc(l*sizeof(char))) == NULL) return NULL;
    
    int c = 0, i,j;
    for(i = 0; i<l; i++)
    {
        for(j = 0; j<i+1; j++, c++)
            ret[c] = str[i];
    }

    for(i = l-1; i>=0; i--)
    {
        for(j = 0; j<=l; j--, c++)
            ret[c] = str[i];
    }
    str[c] = '\0';
    return str;

}
