#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "config.h"
#include "header.h"

#ifndef CONIOD_DEFAULT_CONFIGFILE
#define CONIOD_DEFAULT_CONFIGFILE "/etc/coniod.conf"
#endif /** CONIOD_DEFAULT_CONFIGFILE **/

int main(int argc, char **argv)
{
	int opt;
	char *configfile=0;

	while((opt=getopt(argc,argv,"c:h")) != -1)
	{
		switch(opt)
		{
			case 'c':
				{
					int len=strlen(optarg);
					configfile=malloc(len+1);
					if(!configfile)
					{
						perror("main: configfile malloc");
					}
					memcpy(configfile,optarg,len);
				}
				break;
			default:
				exit(EXIT_FAILURE);
				break;
		}
	}

	if(!configfile)
	{
		int len=strlen(CONIOD_DEFAULT_CONFIGFILE);
		configfile=malloc(len+1);
		if(!configfile)
		{
			perror("main: configfile malloc");
		}
		memcpy(configfile,CONIOD_DEFAULT_CONFIGFILE,len);
	}

	printf("configfile: %s\n",configfile);

	free(configfile);
	return 0;
}

