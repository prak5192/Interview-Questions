1. What is the difference between a string copy (strcpy) and a memory copy 
	(memcpy)? When should each be used?

The strcpy() function is designed to work exclusively with strings. It copies 
each byte of the source string to the destination string and stops when the 
terminating null character (\0) has been moved. On the other hand, the memcpy() 
function is designed to work with any type of data.

Because not all data ends with a null character, you must provide the memcpy() 
function with the number of bytes you want to copy from the source to the 
destination. The following program shows examples of both the strcpy() and 
the memcpy() functions:


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

===============================================================================

2. How can I remove the trailing spaces from a string?

The C language does not provide a standard function that removes trailing spaces 
from a string. It is easy, however, to build your own function to do just this. 
The following program uses a custom function named rtrim() to remove the trailing 
spaces from a string. It carries out this action by iterating through the string 
backward, starting at the character before the terminating null character (\0) and 
ending when it finds the first nonspace character. When the program finds a nonspace 
character, it sets the next character in the string to the terminating null character 
(\0), thereby effectively eliminating all the trailing blanks. Here is how 
this task is performed:

#include <stdio.h>
#include <string.h>
void main(void);
char* rtrim(char*);
void main(void)
{
     char* trail_str = "This string has trailing spaces in it.               ";
     /* Show the status of the string before calling the rtrim()
        function. */
     printf("Before calling rtrim(), trail_str is '%s'\n", trail_str);
     printf("and has a length of %d.\n", strlen(trail_str));
     /* Call the rtrim() function to remove the trailing blanks. */
     rtrim(trail_str);
     /* Show the status of the string
        after calling the rtrim() function. */
     printf("After calling rtrim(), trail_str is '%s'\n", trail_str);
     printf("and has a length of %d.\n", strlen(trail_str));
}
/* The rtrim() function removes trailing spaces from a string. */
char* rtrim(char* str)
{
int n = strlen(str) - 1;     /* Start at the character BEFORE
                                     the null character (\0). */
     while (n>0)            /* Make sure we don't go out of bounds... */
     {
          if (*(str+n) != ' ')    /*  If we find a nonspace character: */
          {
               *(str+n+1) = '\0'; /* Put the null character at one
                                     character past our current
                                     position. */
               break;             /* Break out of the loop. */
          }
          else      /* Otherwise, keep moving backward in the string. */
               n--;
     }
     return str;                  /* Return a pointer to the string. */
}

===============================================================================

3. How do you print only part of a string?

The following program shows how to print only part of a string using the printf() 
function:

#include <stdio.h>
#include <string.h>
void main(void);
void main(void)
{
     char* source_str = "THIS IS THE SOURCE STRING";
     /* Use printf() to print the first 11 characters of source_str. */
     printf("First 11 characters: '%11.11s'\n", source_str);
     /* Use printf() to print only the
        last 13 characters of source_str. */
     printf("Last 13 characters: '%13.13s'\n",
                 source_str + (strlen(source_str) - 13));
}

This example program produces the following output:

First 11 characters: 'THIS IS THE'

Last 13 characters: 'SOURCE STRING'

The first call to printf() uses the argument "%11.11s" to force the printf() 
function to make the output exactly 11 characters long. Because the source 
string is longer than 11 characters, it is truncated, and only the first 11 
characters are printed. The second call to printf() is a bit more tricky. 
The total length of the source_str string is calculated (using the strlen() 
function). Then, 13 (the number of characters you want to print) is subtracted 
from the total length of source_str.

This gives the number of remaining characters in source_str. This number is then 
added to the address of source_str to give a pointer to an address in the source 
string that is 13 characters from the end of source_str. By using the argument 
"%13.13s", the program forces the output to be exactly 13 characters long, and 
thus the last 13 characters of the string are printed.

===============================================================================

Q. What are storage classes in C?
Ans. There are following storage classes which can be used in a C Program

    auto -> auto is the default storage class for all local variables.

    register -> register is used to define local variables that should be stored 
                in a register instead of RAM. This means that the variable has a 
                maximum size equal to the register size (usually one word) and 
                cant have the unary '&' operator applied to it (as it does not 
                have a memory location). This storage class is used for fast access 
                of the data.

    static -> static is the default storage class for global variables.
              static variables can be 'seen' within all functions in this source 
              file. At link time, the static variables defined here will not be seen 
              by the object modules that are brought in.
              static can also be defined within a function. If this is done the 
              variable is initalised at run time but is not reinitalized when the 
              function is called. This inside a function static variable retains its 
              value during vairous calls.

    extern -> extern is used to give a reference of a global variable that is visible 
              to ALL the program files. When you use 'extern' the variable cannot be 
              initalized as all it does is point the variable name at a storage 
              location that has been previously defined.
              When you have multiple files and you define a global variable or function 
              which will be used in other files also, then extern will be used in another 
              file to give reference of defined variable or function. Just for 
              understanding extern is used to decalre a global variable or function in 
              another files.
===============================================================================

