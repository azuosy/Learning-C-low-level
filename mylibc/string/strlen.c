#include "../include/my_string.h"

size_t _strlen(const char *str)
{
    /* Size of a string */

    const char *ptr = str;

    while (*ptr) {ptr++;}

    return (size_t)(ptr - str);

    /*
     *       I discovered that performing operations
     *       with pointers results in a number
     */
}
