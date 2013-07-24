#include "stdio.h"
#include "unistd.h"
void main()
{
        printf("Max child   :%ld\n",sysconf(_SC_CHILD_MAX));
        printf("Page Size   :%ld\n",sysconf(_SC_PAGESIZE));
        printf("Stream max  :%ld\n",sysconf(_SC_STREAM_MAX));
}
