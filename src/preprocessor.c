#include "preprocessor.h"

#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include "util.h"

char *
skip_whitespace(char * str)
{
    int i = 0;
    while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
        ++i;
    if (str[i] == '\0')
        return NULL;
    return str + i;
}

bool
run_preprocessor(const char * filename)
{
    FILE * fp = NULL;
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Failed to open file %s\n", filename);
    }

    char * tmp = strdup(filename);
    char * dir = strdup(dirname(tmp));
    free(tmp);

    int line_num = 0;
    char line[1024];
    while (fgets(line, sizeof(line), fp))
    {
        ++line_num;
        if (strlen(line) == 0)
            continue;

        printf("%s", line);

        char * lineptr = line;

        lineptr = skip_whitespace(lineptr);
        if (!lineptr)
            continue;

        if (lineptr[0] == '#')
        {
            ++lineptr;

            lineptr = skip_whitespace(lineptr);
            if (!lineptr)
                continue;

            const char * include_stmt = "include";
            const int include_len = strlen(include_stmt);

            if (strncmp(lineptr, include_stmt, include_len) == 0)
            {
                lineptr += include_len;
                lineptr = skip_whitespace(lineptr);
                if (!lineptr)
                    continue;

                char * path = NULL;
                char * endptr = NULL;

                if (lineptr[0] == '"')
                {
                    ++lineptr;
                    endptr = strchr(lineptr, '"');
                }
                else if (lineptr[0] == '<')
                {
                    ++lineptr;
                    endptr = strchr(lineptr, '>');
                }
                else
                {
                    fprintf(stderr, "Invalid include '%s' on line %d\n", filename, line_num);
                }

                if (endptr)
                    path = strndup(lineptr, endptr - lineptr);

                if (path)
                {
                    char * full_path = malloc(strlen(dir) + 1 + strlen(path) + 1);
                    strcpy(full_path, dir);
                    full_path[strlen(dir)] = '/';
                    strcpy(full_path + strlen(dir) + 1, path);

                    run_preprocessor(full_path);

                    free(full_path);
                }

                free(path);
            }
        }
        else
        {

        }
    }

    free(dir);
    fclose(fp);

    return true;
}
