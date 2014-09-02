#include "outputbuf.h"

OutputBuf_t* openbuf(const int bufsize)
{
    OutputBuf_t* p = (OutputBuf_t*)malloc(sizeof(OutputBuf_t));
    assertNULL(p);

    p->cursor = 0;
    if (bufsize <= 2) {
        fprintf(stderr, "bufsize max greater than 2, reset to 2\n");
        p->size = 2;
    } else {
        p->size = bufsize;
    }
    p->buf = (char*)malloc(sizeof(char) * (p->size));
    assertNULL(p->buf);
    return p;
}

inline void setchar(OutputBuf_t* p, char c)
{
    p->buf[p->cursor] = c;
    p->cursor++;
}

inline void outputbuf(OutputBuf_t* p)
{
    setchar(p, '\0');
    puts(p->buf);
    p->cursor = 0;
}
void putbuf(OutputBuf_t* p, char c)
{
    setchar(p, c);
    if (p->cursor == p->size - 1 || c == '\n')
    {
        outputbuf(p);
    }
}

void closebuf(OutputBuf_t* p)
{
    outputbuf(p);
    if (p != NULL && p->buf != NULL)
    {
        free(p->buf);
    }
    if (p != NULL)
    {
        free(p);
    }
}

void strputbuf(OutputBuf_t* p, char* str) {
    while(*str != '\0') {
        putbuf(p, *str++);
    }
}
void test_putbuf()
{
    OutputBuf_t* p = openbuf(16);
    char* str = "abc";
    size_t i;
    for (i = 0; i < strlen(str); ++i)
    {
        putbuf(p, str[i]);
    }
    closebuf(p);
}

void test_strputbuf()
{
    OutputBuf_t* p = openbuf(16);
    char *str = "abc";
    strputbuf(p, str);
    closebuf(p);
}
void test_all_outputbuf()
{
    test_putbuf();
    test_strputbuf();
}
