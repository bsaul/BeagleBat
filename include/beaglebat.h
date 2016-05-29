/**
 * beaglebat include file
 */

/* -----------------------------------------------------------
   Read and set beaglebat configuration from beaglebat.cfg
----------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>
#include <time.h>

typedef struct
{
    int buffer_size;
    int enabled;
    unsigned int sampling_rate;
    const char * project_id;
    const char * deployment_type;
}bbconf;

bbconf *bbconfig;

int configureBeaglebat();

// int record(unsigned int rate);

