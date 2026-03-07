#include "string.h"
#include <string.h>
#include <stdio.h>

int main(void)
{
    /* TESTS */

    char str[] = "Something";
    char buf1[] = "Apples are red, violets are blue";
    char buf2[] = "Apples are red, roses are red too lol";

    printf("Size str mylib: %d\nSize str lib: %d\n", _strlen(str), strlen(str) );

    printf("Reverse str mylib: %s\n", (_strrev(str)) );

    printf("Memchr str mylib: %s\nMemchr str lib: %s\n", _memchr(buf1, 'v', _strlen(buf1)), memchr(buf1, 'v', strlen(buf1)) );

    int result = _memcp(buf1, buf2, sizeof(buf2));
    
    if (result == 0)
    {
        printf("buffer1 is equal buffer2");
    }
    else if (result < 0)
    {
        printf("buffer1 is less than buffer2");
    }
    else 
    {
        printf("buffer1 is greater than buffer2\n");
    }

    return 0;
}
