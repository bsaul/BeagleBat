/**
 * main file for beaglebat application
 */

#include <include/beaglebat.h>

int main(int argc, char *argv[])
{
	bbconfig = (bbconf*) malloc(sizeof(bbconf));
    char areccmd[1024];
    char duration[16];

    if(configureBeaglebat() == EXIT_FAILURE)
        return 0;

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[12];
    char time[12];
    strftime(date, sizeof(date), "%F", tm);
    strftime(time, sizeof(time), "%T", tm);


    /* This is a dumb way of handling command line arguments, but for now...*/
    if (strcmp("record", argv[1]) == 0) {
    	if(argc > 2){
    		snprintf(duration, sizeof duration, "-d %s", argv[2]);
    	} else {
    		snprintf(duration, sizeof duration, " ");
    	}

    	snprintf(areccmd, sizeof areccmd, "arecord -D plughw:1,0 %s -r %u %s/%s-%s.wav", 
    		duration,
    		bbconfig->sampling_rate,
    		bbconfig->storage_dir,
    		date,
    		time);

    	printf("BeagleBat began recording at %s %s\n", date, time);

    	system(areccmd);
    	/*system("arecord -D plughw:1,0 -d 15 -r 192000 test.wav");*/
     	/*record(bbconfig->sampling_rate); */
    }
    
	return(1);
}