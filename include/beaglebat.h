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
    unsigned int rate;
    const char * project_id;
}bbconf;

bbconf *bbconfig;

int configureBeaglebat();

// unsigned int configureBeaglebat();
// int record(unsigned int rate);

