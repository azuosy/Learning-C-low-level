#include "../include/my_memory.h"

void *_memcpy(void *dest, const void *src, size_t count)
{
    /* copy count bytes of src for dest */
    /* dont support overlap */

    unsigned char *ptr_dest = (unsigned char *) dest;
    const unsigned char *ptr_src = (const unsigned char *) src;

    while (count-- > 0)
    {
        *ptr_dest = *ptr_src;
        ptr_dest++; ptr_src++;
    }

    return dest;
}
