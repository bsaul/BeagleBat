/**
 * beaglebat include file
 */

/* -----------------------------------------------------------
   Read and set beaglebat configuration from beaglebat.cfg
----------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

typedef struct
{
    int buffer_size;
    int enabled;
    long long srate;
    unsigned int sampling_rate;
    const char * project_id;
}bbconf;

bbconf *bbconfig;

int configureBeaglebat();

// int record(unsigned int rate);

