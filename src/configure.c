/**
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

unsigned int configureBeaglebat()
{
    config_t cfg, *cf;
    config_setting_t *hardware_config;
    long long int llrate;
    unsigned int rate;
    int enabled;

    cf = &cfg;
    config_init(cf);

    if (!config_read_file(cf, "beaglebat.cfg")) {
        fprintf(stderr, "%s:%d - %s\n",
            config_error_file(cf),
            config_error_line(cf),
            config_error_text(cf));
        config_destroy(cf);
        return(EXIT_FAILURE);
    }

    if (config_lookup_bool(cf, "enabled", &enabled))
        printf("Enabled: %s\n", enabled ? "Yep" : "Nope");
    else 
        printf("Enabled is not defined\n");

    if (config_lookup_int64(cf, "hardware.rate", &llrate))
        printf("Sampling rate: %lli\n", llrate);
    else
    	printf("Sampling rate not defined");

    config_destroy(cf);

    rate = (unsigned int) llrate;

    return(rate);
    //exit(0);
}