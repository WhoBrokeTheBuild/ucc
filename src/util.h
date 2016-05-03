#ifndef UCC_UTIL_H
#define UCC_UTIL_H

#include <stdlib.h>
#include <string.h>

char * strdup(const char * str)
{
    if (str == NULL)
        return NULL;

    char * dup = malloc(strlen(str) + 1);
    if (dup == NULL)
        return NULL;

    strcpy(dup, str);
    return dup;
}

#endif // UCC_UTIL_H
