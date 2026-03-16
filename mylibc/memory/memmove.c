#include "../include/my_memory.h"

void *_memmove(void *dest, const void *src, size_t count)
{
    /* copy count bytes of src for dest */
    /* support overlap */

    unsigned char *ptr_dest = (unsigned char*) dest;
    const unsigned char *ptr_src = (const unsigned char *) src;

    while (count-- > 0)
    {
        if (dest < src)
        {

        }
    }
}
