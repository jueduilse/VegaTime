#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <dlfcn.h>
#include <string.h>
#include "VegaTimeController.h"

#define VegaTimeLib "./VegaTimeController.so.1"
typedef int (*VegaTimeAPI)(const char * interface,const unsigned int cPort, const unsigned int debugLevel, const char * logPath);

static struct option longopts[]=
{
		{"interface",required_argument,NULL,'i'},
		{"port",required_argument,NULL,'p'},
		{"debug",required_argument,NULL,'d'},
		{"help",no_argument,NULL,'h'}
};

static void usage(void)
{
	fprintf(stderr,"usage:\n");
	fprintf(stderr,"VegaTimeController --interface [nic] --port [Controller Port] --debug [level]\n");
}

int main(int argc, char **argv)
{
	printf("Welcome to VegaTime System!\n");
	unsigned int cport=10551;
	char interface[20]="";
	printf("argc=%d\n",argc);
	int c,narg=argc;
	unsigned int debugLevel = 3;
	if(argc < 5)
	{
		usage();
		return EXIT_FAILURE;
	}
	while((c = getopt_long(argc,argv,"i:c:p:d:h",longopts,NULL)) != -1)
	{
		switch(c)
		{
		case 'i':
			printf("c=%c,optarg=%s\n",c,optarg);
			strcpy(interface,optarg);
			break;
		case 'p':
			printf("c=%c,optarg=%s\n",c,optarg);
			cport = (unsigned int)atoi(optarg);
			break;
		case 'd':
			printf("c=%c,optarg=%s\n",c,optarg);
			debugLevel = (unsigned int)atoi(optarg);
			break;
		case 'h':
		default:
			usage();
			return EXIT_FAILURE;
		}
	}
	void *handle;
	VegaTimeAPI fun = NULL;
	handle = dlopen(VegaTimeLib,RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr, "Failed to open library %s error: %s\n",VegaTimeLib,dlerror());
		return EXIT_FAILURE;
	}
	else
		printf("Open library %s success: %p\n",VegaTimeLib,handle);

	dlerror();

	fun = (VegaTimeAPI) dlsym(handle,"RunController");
	if(!fun)
	{
		fprintf(stderr,"can not find function RunController error: %s\n",dlerror());
		dlclose(handle);
		return EXIT_FAILURE;
	}

	fun(interface,cport,debugLevel,"/tmp/");
	dlclose(handle);
	return 0;
}
