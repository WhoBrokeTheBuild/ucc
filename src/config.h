#ifndef UCC_CONFIG_H
#define UCC_CONFIG_H

#include <stdbool.h>

struct config {
    char ** in_files;
    char *  out_file;
    bool preprocess;
    bool compile;
    bool assemble;
};
typedef struct config config_t;

void init_config(config_t * conf);
void free_config(config_t * conf);

#endif // UCC_CONFIG_H
