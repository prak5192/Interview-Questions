1. What is the difference between a string copy (strcpy) and a memory copy 
	(memcpy)? When should each be used?

The strcpy() function is designed to work exclusively with strings. It copies 
each byte of the source string to the destination string and stops when the 
terminating null character (\0) has been moved. On the other hand, the memcpy() 
function is designed to work with any type of data.

Because not all data ends with a null character, you must provide the memcpy() 
function with the number of bytes you want to copy from the source to the 
destination. The following program shows examples of both the strcpy() and the memcpy() functions:


#include <stdio.h>
#include <string.h>
typedef struct cust_str {
     int  id;
     char last_name[20];
     char first_name[15];
} CUSTREC;
void main(void);
void main(void)
{
     char*   src_string = "This is the source string";
     char    dest_string[50];
     CUSTREC src_cust;
     CUSTREC dest_cust;
     printf("Hello!  I'm going to copy src_string into dest_string!\n");
     /* Copy src_string into dest_string. Notice that the destination
        string is the first argument. Notice also that the strcpy()
        function returns a pointer to the destination string. */
     printf("Done! dest_string is: %s\n",
            strcpy(dest_string, src_string));
     printf("Encore! Let's copy one CUSTREC to another.\n");
     printf("I'll copy src_cust into dest_cust.\n");
     /* First, initialize the src_cust data members. */
     src_cust.id = 1;
     strcpy(src_cust.last_name, "Strahan");
     strcpy(src_cust.first_name, "Troy");
     /* Now, use the memcpy() function to copy the src_cust structure to
        the dest_cust structure. Notice that, just as with strcpy(), the
        destination comes first. */
     memcpy(&dest_cust, &src_cust, sizeof(CUSTREC));
     printf("Done! I just copied customer number #%d (%s %s).",
               dest_cust.id, dest_cust.first_name, dest_cust.last_name);
}



