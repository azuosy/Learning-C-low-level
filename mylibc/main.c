#include <string.h>
#include <stdio.h>
#include "my_memory.h"
#include "my_string.h"

// gcc main.c string/*.c memory/*.c -I include -o main


int main(void)
{
    /* TESTS */

    char str[] = "Something";
    char buf1[] = "Apples are red, violets are blue";
    char buf2[] = "Apples are red, violets are gray";

    printf("Size str mylib: %zu\nSize str lib: %lu\n", _strlen(str), strlen(str) );

    printf("Reverse str mylib: %s\n", (_strrev(str)) );

    printf("Memchr str mylib: %s\nMemchr str lib: %s\n", (char*) _memchr(buf1, 'v', _strlen(buf1)), (char*) memchr(buf1, 'v', strlen(buf1)) );

    int result = _memcmp(buf1, buf2, sizeof(buf2));
    
    if (result == 0)
    {
        printf("buffer1 is equal buffer2\n");
    }
    else if (result < 0)
    {
        printf("buffer1 is less than buffer2\n");
    }
    else 
    {
        printf("buffer1 is greater than buffer2\n");
    }

    printf("Before my memcpy: target is %s\n", buf1);
    _memcpy(buf1, buf2, sizeof(buf2));
    printf("After my memcpy: target is %s\n", buf1);

    return 0;
}
