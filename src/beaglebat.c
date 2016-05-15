/**
 * main file for beaglebat application
 */

#include <include/beaglebat.h>

int main(int argc, char *argv)
{

    bbconfig = (bbconf*) malloc(sizeof(bbconf));

    if(configureBeaglebat() == EXIT_FAILURE)
        return 0;

    printf("Enabled 2: %s\n", bbconfig->enabled ? "Yep" : "Nope");

    printf("Project ID: %c\n", bbconfig->project_id);

	//rate = ;
	//printf("%u\n", rate);

	//record(rate);
	return(0);
}