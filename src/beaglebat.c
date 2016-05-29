/**
 * main file for beaglebat application
 */

#include <include/beaglebat.h>

int main(int argc, char *argv)
{

    bbconfig = (bbconf*) malloc(sizeof(bbconf));

    if(configureBeaglebat() == EXIT_FAILURE)
        return 0;

	record(bbconfig->sampling_rate);
    
	return(1);
}