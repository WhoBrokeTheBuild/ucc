#include "util.h"

char *
strdup(const char * str)
{
    char * newstr = (char *) malloc(strlen(str) + 1);
    if (newstr)
        strcpy(newstr, str);
    return newstr;
}

char *
strndup (const char * str, size_t n)
{
    size_t len = strlen(str);
    if (n < len)
        len = n;

    char * newstr = (char *) malloc(len + 1);
    if (!newstr)
        return NULL;

    newstr[len] = '\0';
    return (char *) memcpy(newstr, str, len);
}
