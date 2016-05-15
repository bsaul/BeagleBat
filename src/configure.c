/* -----------------------------------------------------------
   Read and set beaglebat configuration from beaglebat.cfg
----------------------------------------------------------- */

#include <include/beaglebat.h>

int configureBeaglebat()
{
    config_t cfg, *cf;
    config_setting_t * hardware_config;
    long long *llrate;

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

    if (config_lookup_bool(cf, "enabled", &bbconfig->enabled))
        printf("Enabled: %s\n", bbconfig->enabled ? "Yep" : "Nope");
    else 
        printf("Enabled is not defined\n");

    config_lookup_string(cf, "deployment.project_id", &bbconfig->project_id);
// not sure why this isn't working...
//   if (config_lookup_int64(cf, "hardware.rate", llrate))
//        printf("Sampling rate: %lli\n", llrate);
//    else
//      	printf("Sampling rate not defined");

    config_destroy(cf);

  //  &bbconfig->rate = (unsigned int) llrate;

    return(EXIT_SUCCESS);
}