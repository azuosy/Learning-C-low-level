#include "../include/my_memory.h"

void *_memchr(const void *buf, int c, size_t count)
{
    /* search the first count bytes of buf 'c' */

    const unsigned char *p = (const unsigned char *) buf;
    /*
     *      u cant see what have inside a (void *), so do a cast, pointer need a size recognized
     *      (unsigned char have always 1 byte), unsigned garants byte value (0 : 255)
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
