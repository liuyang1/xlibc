#if !defined(STDDEF_H_V6QOQAU8)
#define STDDEF_H_V6QOQAU8

typedef unsigned int size_t;
typedef signed int ptrdiff_t;
typedef unsigned short wchar_t;

#define NULL        0

#define offsetof(type, member) \
    ((size_t) &(((type*)0)->member))

#define container_of(ptr, type, member) \
    ((type*)((char *)ptr - offsetof(type, member));)
#endif /* end of include guard: STDDEF_H_V6QOQAU8 */
