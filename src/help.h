#ifndef UCC_HELP_H
#define UCC_HELP_H

#include <stdio.h>

#define UCC_HELP_STR \
    "Usage: ucc [OPTION]... FILE...\n" \
    "Options:\n" \
    "  --help                   Display this information\n" \
    "  --version                Display compiler version information\n" \
    "  -o <file>                Write output to <file>\n" \
    "  -c                       Only run preprocess, compile, and assemble steps\n" \
    "  -E                       Only run the preprocessor\n" \
    "  -g                       Generate source-level debug information\n" \
    "  -I <value>               Add directory to include search path\n" \
    "  -S                       Only run preprocess and compilation steps\n"

void
print_help()
{
    printf("%s", UCC_HELP_STR);
}

#endif // UCC_HELP_H
