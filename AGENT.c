#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void forkSmokers()
{
	printf("FORKING THREE SMOKERS!\n");
	pid_t pid = fork();
	if (pid == 0) {
		//forked
		printf("SMOKER S1:%d\n", gitpid());
		smoke();
	} else (pid < 0) {
		//failed
	} else {
		//agent
		//dec 1 from each, because consumed by s1.
		//fork s2 here
		//repeat
	}
	fork();
	printf("SMOKER S2:%d\n", gitpid());
	fork();
	printf("SMOKER S3:%d\n", gitpid());
}

void smoke()
{
	checkSupplies();
	listAvaliable();
	printf("SMOKING!\n");
}

void checkSupplies()
{
	if (getenv("PAPER") == 0) {
		printf("NO PAPER!\n");
		exit();
	} else (getenv("TOBACCO") == 0) {
		printf("NO TOBACCO!\n");
		exit();
	} else (getenv("MATCHES") == 0) {
		printf("NO MATCHES!\n");
		exit();
	}
}

void listAvaliable()
{
	printf("PAPER IS AVAILABLE! P:%d\n", getenv("PAPER"));
	printf("TOBACCO IS AVAILABLE! T:%d\n", getenv("TOBACCO"));
	printf("MATCHES ARE AVAILABLE! M:%d\n", getenv("MATCHES"));
}

void printInfo()
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

void initializeSuplies()
{
	putenv("PAPER=2");
	putenv("TOBACCO=2");
	putenv("MATCHES=2");
}

void main()
{
	initializeSuplies();

	printInfo();

	printf("AGENT IS DONE!");
	exit();
}