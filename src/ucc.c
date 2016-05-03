#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "version.h"
#include "util.h"

int main(int argc, char ** argv)
{
    char * out_file = NULL;

    static struct option long_opts[] =
    {
        {"version",     no_argument,        0, 0},
        {"help",        no_argument,        0, 0},
        {0,             required_argument,  0, 'o'},
        {0, 0, 0, 0}
    };

    int optind = 0;

    for (;;)
    {
        int opt = getopt_long(argc, argv, "o:", long_opts, &optind);

        if (opt == -1)
            break;

        switch (opt)
        {
        case 0:
            if (long_opts[optind].flag != 0)
                break;

            if (strcmp(long_opts[optind].name, "version") == 0)
            {
                puts(UCC_VERSION_STR);
            }
            else if (strcmp(long_opts[optind].name, "help") == 0)
            {
                puts(UCC_HELP_STR);
            }

            break;
        case 'o':

            out_file = strdup(optarg);

            break;
        }
    }

    if (out_file)
    {
        printf("Out File: %s\n", out_file);
    }

    free(out_file);

    return 0;
}
