#include <time.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
	initializeSuplies();
	
	printInfo();

	printf("PAPER:%d, TOBACCO:%d, MATCHES:%d\n", PAPER, TOBACCO, MATCHES);
	printf("FORKING THREE SMOKERS!\n");
	fork()

	printf("AGENT IS DONE!");
	exit();
}

printInfo()
{
	printf("AGENT INFO:\n");
	printf("HOSTNAME:%d\n", gethostname());
	printf("PID:%d\n", getpid());
	printf("UID:%d\n", getuid());

	time_t now;
	time(&now);
	printf("TIME:%s\n", ctime(&now));

	int PAPER = getenv("PAPER");
	int TOBACCO = getenv("TOBACCO");
	int MATCHES = getenv("MATCHES");
}

initializeSuplies()
{
	putenv("PAPER=1");
	putenv("TOBACCO=0");
	putenv("MATCHES=2");
}