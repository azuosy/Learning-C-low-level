#include "string.h"

char *my_strrev(char *str)
{
    /* Reverse a string */

    char *start = str;
    char *end = str;

    while (*end) {end++;}
    end--; /* '\0' */

    while (start < end)
    {
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    return str;
}

size_t my_strlen(const char *str)
{
    /* Size of a string */

    const char *ptr = str;

    while (*ptr) {ptr++;}

    return (size_t)(ptr - str);

    /* 
       I discovered that performing operations
       with pointers results in a number
    */
} 
