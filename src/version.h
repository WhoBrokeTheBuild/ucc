#ifndef UCC_VERSION_H
#define UCC_VERSION_H

#define UCC_VERSION_MAJOR 0
#define UCC_VERSION_MINOR 0
#define UCC_VERSION_PATCH 1
#define UCC_VERSION_STR "0.0.1"

void
print_version()
{
    printf("ucc version %s\n", UCC_VERSION_STR);
}

#endif // UCC_VERSION_H
