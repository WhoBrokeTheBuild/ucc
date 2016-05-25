#include <stdio.h>
#include <string.h>
#include <getopt.h>

#include "version.h"
#include "help.h"
#include "config.h"
#include "util.h"

int
main(int argc, char ** argv)
{
    config_t conf;
    init_config(&conf);

    static struct option long_opts[] =
    {
        {"version",     no_argument,        0, 0},
        {"help",        no_argument,        0, 0},
        {0,             required_argument,  0, 'o'}, // Output
        {0,             no_argument,        0, 'c'}, // Preprocess, Compile, & Assemble Only
        {0,             no_argument,        0, 'E'}, // Preprocess Only
        {0,             no_argument,        0, 'g'}, // Debug Symbols
        {0,             no_argument,        0, 'S'}, // Preprocess & Compile Only
        {0,             required_argument,  0, 'I'}, // Add Include Dir
        {0, 0, 0, 0}
    };

    int opt_index = 0;

    for (;;)
    {
        int opt = getopt_long(argc, argv, "o:", long_opts, &opt_index);

        if (opt == -1)
            break;

        switch (opt)
        {
        case 0:
            if (long_opts[optind].flag != 0)
                break;

            if (strcmp(long_opts[optind].name, "version") == 0)
            {
                print_version();
            }
            else if (strcmp(long_opts[optind].name, "help") == 0)
            {
                print_help();
            }
            break;

        case 'o':
            conf.out_file = strdup(optarg);
            break;

        case 'c':
            conf.preprocess = true;
            conf.compile = true;
            conf.assemble = true;
            break;

        case 'E':
            conf.preprocess = true;
            conf.compile = false;
            conf.assemble = false;
            break;

        case 'g':

            break;

        case 'S':
            conf.preprocess = true;
            conf.compile = true;
            conf.assemble = false;
            break;
        }
    }

    int num_in_files = argc - optind;

    if (num_in_files <= 0)
    {
        fprintf(stderr, "No input files\n");
        goto error;
    }

    conf.in_files = malloc((num_in_files + 1) * sizeof(char *));
    for (int i = 0; i < num_in_files; ++i)
    {
        conf.in_files[i] = strdup(argv[optind + i]);
    }
    conf.in_files[num_in_files] = NULL;

    if (conf.preprocess)
    {
    }

    free_config(&conf);
    return 0;

error:

    free_config(&conf);
    return 1;
}
