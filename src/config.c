#include "config.h"

#include "util.h"

void
init_config(config_t * conf)
{
    conf->in_files = NULL;
    conf->out_file = NULL;

    conf->preprocess = true;
    conf->compile    = true;
    conf->assemble   = true;
}

void
free_config(config_t * conf)
{
    int i;

    if (conf->in_files != NULL)
    {
        i = 0;
        while (conf->in_files[i] != NULL)
        {
            free(conf->in_files[i]);
            ++i;
        }
        SAFE_FREE(conf->in_files);
    }

    SAFE_FREE(conf->out_file);
}
