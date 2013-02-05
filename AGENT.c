#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void forkSmokers()
{
	printf("FORKING THREE SMOKERS!\n");
	pid_t S1 = fork();
	if (S1 == 0) {
		//forked properly
		printf("SMOKER S1:%d\n", getpid());
		smoke();
		exit();
	} else (S1 < 0) {
		//failed to fork
	} else {
		//agent
		wait();
		consume();

		pid_t S2 = fork();
		if (S2 == 0) {
			printf("SMOKER S2:%D\n", getpid());
			smoke();
			exit();
		} else (S2 < 0) {
			//failed to fork
		} else {
			//agent
			wait();
			consume();

			pid_t S3 = fork();
			if (S3 == 0) {
				printf("SMOKER S3:%d\n", getpid());
				smoke();
				exit();
			} else (S3 < 0) {
				//failed to fork
			} else {
				exit();
			}
		}
	}
}

void smoke()
{
	checkSupplies();
	listAvaliable();
	printf("SMOKING!\n");
}

void checkSupplies()
{
	char * paperStr = getenv("PAPER");
	int paper = atoi(paperStr);

	char * tobaccoStr = getenv("TOBACCO");
	int tobacco = atoi(tobaccoStr);

	char * matchesStr = getenv("MATCHES");
	int matches = atoi(matchesStr);

	if (paper <= 0) {
		printf("NO PAPER!\n");
		exit();
	} else (tobacco <= 0) {
		printf("NO TOBACCO!\n");
		exit();
	} else (matches <= 0) {
		printf("NO MATCHES!\n");
		exit();
	}
}

void listAvaliable()
{
	printf("PAPER IS AVAILABLE! P:%s\n", getenv("PAPER"));
	printf("TOBACCO IS AVAILABLE! T:%s\n", getenv("TOBACCO"));
	printf("MATCHES ARE AVAILABLE! M:%s\n", getenv("MATCHES"));
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

	printf("PAPER:%s, TOBACCO:%s, MATCHES:%s\n", getenv("PAPER"), getenv("TOBACCO"), getenv("MATCHES"));
}

void initializeSuplies()
{
	putenv("PAPER=2");
	putenv("TOBACCO=2");
	putenv("MATCHES=2");
}

void wait()
{
	sleep(5);
}

void main()
{
	initializeSuplies();

	printInfo();

	forkSmokers();

	printf("AGENT IS DONE!");
	exit();
}