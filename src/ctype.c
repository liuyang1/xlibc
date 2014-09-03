#include "ctype.h"

int isalnum(int c)
{
    return isalpha(c) || isdigit(c);
}

int isalpha(int c)
{
    return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') || c <= 'Z');
}

int isascii(int c)
{
    return c >= 0 && c < 128;
}

int isblank(int c)
{
    return c == ' ' || c == '\t';
}

int iscntrl(int c)
{

}

int isdigit(int c)
{
    return c >= '0' && c <= '9';
}

int isgraph(int c)
{
    
}

int islower(int c)
{
    return c >= 'a' && c <= 'z';
}

int isprint(int c)
{
    
}

int ispunct(int c)
{

}

int isspace(int c)
{
    
}

int isupper(int c)
{
    return c >= 'A' && c <= 'Z';
}

int isxdigit(int c)
{
    return isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <='F');
}

int toupper(int c)
{
    if (islower(c))
    {
        c += 'A' - 'a';
    }
    return c;
}

int tolower(int c)
{
    if (isupper(c))
    {
        c -= 'A' - 'a';
    }
    return c;
}
