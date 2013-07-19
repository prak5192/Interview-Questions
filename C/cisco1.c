/*
Given a big string (str1) find (s1) and replace by (s2).

Example :
str = "Hi i am abc and i am in abc"
s1 = "abc"
s2 = "pqrstuv"

So final o/p :
str1 = "Hi i am pqrstuv in pqrstuv"

*/


void *strrp(char *src,char *sub,char *rp,char *p)
{
    int sub_len=strlen(sub);
    char *po=NULL,*q=src;
    while((po=strstr(q,sub))!=NULL)
    {
        strncat(p,q,po-q);
        strcat(p,rp);
        q+=po-q+sub_len;
    }
    strcat(p,q);
}
