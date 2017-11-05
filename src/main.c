#include <err.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"
#include "coniod.h"

#ifndef CONIOD_DEFAULT_CONFIGFILE
#define CONIOD_DEFAULT_CONFIGFILE "/etc/coniod.conf"
#endif /** CONIOD_DEFAULT_CONFIGFILE **/

char *progname=0;

void usage()
{
	printf("Usage: %s [OPTION]...\n",progname);
	printf("%s",
		"Start processes and connect them as specified in " PACKAGE_NAME " configfile." "\n"
		"\n"
		"  " "-h, --help" "    " "display this help and exit" "\n"
		"  " "-V, --version" " " "output version information and exit" "\n"
		"  " "-c, --config" "  " "configfile to use, default: " CONIOD_DEFAULT_CONFIGFILE "\n"
	);
}

void version()
{
	printf("%s\n",PACKAGE_STRING);
}

int main(int argc,char **argv)
{
	progname=*argv;
	int ch;
	int configfile=-1;
	int verbose=0;

	struct option longopts[]=
		{
			{ "help"
			, no_argument
			, NULL
			, 'h'
			},
			{ "version"
			, no_argument
			, NULL
			, 'V'
			},
			{ "config"
			, required_argument
			, NULL
			, 'c'
			},
			{ NULL
			, 0
			, NULL
			, 0
			},
		};

	while((ch=getopt_long(argc,argv,"hVc:",longopts,NULL)) != -1)
	{
		switch(ch)
		{
			case 'c':
				if((configfile=open(optarg,O_RDONLY,0)) == -1)
				{
					err(EXIT_FAILURE,"unable to open configfile %s",optarg);
				}
				break;
			case 'V':
				version();
				exit(EXIT_SUCCESS);
				break;
			case 'h':
				usage();
				exit(EXIT_SUCCESS);
				break;
			default:
				usage();
				exit(EXIT_FAILURE);
				break;
			case 0:
				break;
		}
	}
	argc-=optind;
	argv+=optind;

	if(argc > 0)
	{
		warnx("additional %d arguments ignored",argc);
	}

	if(configfile != -1)
	{
		if((configfile=open(CONIOD_DEFAULT_CONFIGFILE,O_RDONLY,0)) == -1)
		{
			err(EXIT_FAILURE,"unable to open default configfile %s",CONIOD_DEFAULT_CONFIGFILE);
		}
	}

	return 0;
}

