#include "../include/my_string.h"

char *_strrev(char *str)
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
