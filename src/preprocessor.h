#ifndef UCC_PREPROCESSOR_H
#define UCC_PREPROCESSOR_H

#include <stdbool.h>

char * skip_whitespace(char * str);
bool run_preprocessor(const char * filename);

#endif // UCC_PREPROCESSOR_H
