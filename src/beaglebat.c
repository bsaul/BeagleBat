/**
 * main file for beaglebat application
 */

#include <stdio.h>
#include <include/beaglebat.h>

int main(int argc, char *argv)
{
	unsigned int rate;
	//char *device = "hw:1,0";

	rate = configureBeaglebat();
	printf("%u\n", rate);

	record(rate);
	return(0);
}