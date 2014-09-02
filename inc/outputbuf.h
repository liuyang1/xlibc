#ifndef _OUTPUTBUF_H_
#define _OUTPUTBUF_H_

#include "errno.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

inline void assertNULL(void* p) {
    if (p == NULL) {
        perror("null pointer");
        exit(errno);
    }
}
typedef struct OutputBuf_t {
    char* buf;
    int cursor;
    int size;
} OutputBuf_t;

#endif
