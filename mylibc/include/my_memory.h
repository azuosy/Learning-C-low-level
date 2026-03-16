#ifndef MYLIB_MEMORY_H
#define MYLIB_MEMORY_H

#include <stddef.h>

void *_memchr(const void *buf, int c, size_t count);
int _memcmp(const void *buf1, const void *buf2, size_t count);
void *_memcpy(void *dest, const void *src, size_t count);
void *_memmove(void *dest, const void *src, size_t count);

#endif
