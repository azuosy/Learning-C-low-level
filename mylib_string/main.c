#include "string.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    /* TESTS */

    char str[] = "Something"; 

    printf("Size str mylib: %d\nSize str lib: %d\n", my_strlen(str), strlen(str));
    printf("Reverse str mylib: %s\n", (my_strrev(str)) );

    return 0;
}
