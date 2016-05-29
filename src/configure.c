/* -----------------------------------------------------------
   Read and set beaglebat configuration from beaglebat.cfg
----------------------------------------------------------- */

#include <include/beaglebat.h>

int configureBeaglebat()
{
    config_t cfg, *cf;
    config_setting_t * hardware_config;
    long long llrate;

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

    printf("Project ID: ");
    if (config_lookup_string(cf, "deployment.project_id", &bbconfig->project_id))
        printf("%s\n", bbconfig->project_id);
    else
        printf("not defined \n");

    printf("Deployment type: ");
    if (config_lookup_string(cf, "deployment.type", &bbconfig->deployment_type))
        printf("%s\n", bbconfig->deployment_type);
    else
        printf("not defined \n");

    printf("Sampling rate: ");
    if (config_lookup_int64(cf, "hardware.sampling_rate", &llrate)){
        bbconfig->sampling_rate = (unsigned int) llrate;
        printf("%u\n", bbconfig->sampling_rate);
    }
    else
      	printf("not defined \n");


    config_destroy(cf);


    return(EXIT_SUCCESS);
}