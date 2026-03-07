#ifndef STRING_H
#define STRING_H

#define NULL ((void *)0)

typedef unsigned long size_t;

void *_memchr(const void *buf, int c, size_t count);
int _memcp(const void *buf1, const void *buf2, size_t count);
char *_strrev(char *str);
size_t _strlen(const char *str);

#endif 
