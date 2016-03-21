/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <libconfig.h>

int main(int argc, char **argv)
{
    config_t cfg, *cf;
    const config_setting_t *retries;
    int *rate, enabled;

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

    if (config_lookup_int(cf, "hardware.rate", &rate))
        printf("Sampling rate: %s\n", rate);

    config_destroy(cf);
    return 0;
}