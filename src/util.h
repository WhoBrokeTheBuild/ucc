#ifndef UCC_UTIL_H
#define UCC_UTIL_H

#include <stdlib.h>
#include <string.h>

#define SAFE_FREE(PTR) \
    free(PTR); \
    PTR = NULL

char * strdup(const char * str);
char * strndup(const char * str, size_t n);

#endif // UCC_UTIL_H
