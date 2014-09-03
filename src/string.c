#include "base.h"
#include "ctype.h"

#define ENDOFSTR        '\0'

inline int notend(const char c)
{
    return c != ENDOFSTR;
}
size_t strlen(const char* s)
{
    size_t l = 0;
    while (notend(*s)) {
        s++;
        l++;
    }
    return l;
}

int strcmp(const char* s1, const char* s2)
{
    for (; notend(*s1) && notend(*s2); s1++, s2++) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
    }
    return *s1 - *s2;
}

int strncmp(const char* s1, const char* s2, size_t n)
{
    size_t i;
    for (i = 0; notend(*s1) && notend(*s2) && i < n; s1++, s2++, n++) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
    }
    return *s1 - *s2;
}

int strcasecmp(const char* s1, const char* s2)
{
    for (; notend(*s1) && notend(*s2); s1++, s2++) {
        if (!((*s1 == *s2) || (*s1 == toupper(*s2) || toupper(*s1) == *s2))) {
            return *s1 - *s2;
        }
    }
    return *s1 - *s2;
}

int strncasecmp(const char* s1, const char* s2, size_t n)
{
    size_t i;
    for (i = 0; notend(*s1) && notend(*s2) && i < n; s1++, s2++, i++) {
        if (!((*s1 == *s2) || (*s1 == toupper(*s2) || toupper(*s1) == *s2))) {
            return *s1 - *s2;
        }
    }
    return *s1 - *s2;
}

char*strcpy(char* dest, const char* src)
{
    char* origin = dest;
    while (notend(*src)) {
        *dest++ = *src++;
    }
    *dest = ENDOFSTR;
    return origin;
}

char*strncpy(char* dest, const char* src, size_t n)
{
    char* origin = dest;
    size_t i;
    for (i = 0; i < n && notend(*src); i++) {
        *dest++ = *src++;
    }
    if (i < n) {
        *dest = ENDOFSTR;
    }
    return origin;
}
int bcmp(const void* s1, const void* s2, size_t n)
{
    const unsigned char* p1 = s1;
    const unsigned char* p2 = s2;
    for (size_t i = 0; i < n; i++) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
    }
    return *p1 - *p2;
}

int (* memcmp)(const void*, const void*, size_t) = bcmp;
