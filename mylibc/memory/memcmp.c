#include "../include/my_memory.h"

int _memcmp(const void *buf1, const void *buf2, size_t count)
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
