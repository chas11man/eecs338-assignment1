#include <time.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
	initializeSuplies();

	printInfo();

	printf("AGENT IS DONE!");
	exit();
}

forkSmokers()
{
	printf("FORKING THREE SMOKERS!\n");
	fork();
	printf("SMOKER S1:%d\n", gitpid());
	fork();
	printf("SMOKER S2:%d\n", gitpid());
	fork();
	printf("SMOKER S3:%d\n", gitpid());
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

	printf("PAPER:%d, TOBACCO:%d, MATCHES:%d\n", PAPER, TOBACCO, MATCHES);
}

initializeSuplies()
{
	putenv("PAPER=1");
	putenv("TOBACCO=0");
	putenv("MATCHES=2");
}