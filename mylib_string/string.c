#include "string.h"

void *_memchr(const void *buf, int c, size_t count)
{
    /* search the first count bytes of buf 'c' */

    const unsigned char *p = (const unsigned char *) buf; 
    /* 
       u cant see what have inside a (void *), so do a cast, pointer need a size recognized
       (unsigned char have always 1 byte), unsigned garants byte value (0 : 255)
    */
    
    while (count-- > 0) 
    {
        if (*p == (unsigned char) c) /* if u pass a big number like 513, cast garants only the last 8 bits are usage on search*/ 
        {
            return (void *) p;
        }
        p++;
    }
    return NULL;
}

int _memcp(const void *buf1, const void *buf2, size_t count)
{
    /* compare the first count bytes of buf1 and buf2 */

    const unsigned char *p1 = (const unsigned char *) buf1; 
    const unsigned char *p2 = (const unsigned char *) buf2;
    
    /* cast for arithmetic */

    while (count-- > 0)
    {
        if (*p1 != *p2) 
        {
            return *p1 - *p2;
        }

        p1++; p2++;
    }

    return 0;

}


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

size_t _strlen(const char *str)
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
