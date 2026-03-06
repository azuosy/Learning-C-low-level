#include "string.h"

char *my_strrev(char *str)
{
    // Reverse a string

    char *start = str;
    char *end = str;

    while (*end) {end++;}
    end--; // '\0'

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
    size_t bytes = 0;
    const char *p = str;

    while (*p) {p++; bytes++;}

    return bytes;     
}
