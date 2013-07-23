#include<stdio.h>
#include<stdarg.h>

int myprintf( const char * format, ... )
{
    int rtn = 0;

    va_list args;

    va_start( args, format );

    rtn = vprintf( format, args );

    va_end( args );

    return rtn;
}

main(void)
{
    myprintf("Vaibhav %d %d %c %s ", 10, 15, 'A', "prakash");
    getchar();
    return(0);
}
