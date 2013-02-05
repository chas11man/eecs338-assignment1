#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
		exit(0);
	} else if (tobacco <= 0) {
		printf("NO TOBACCO!\n");
		exit(0);
	} else if (matches <= 0) {
		printf("NO MATCHES!\n");
		exit(0);
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
	char* hostName[255];
	printf("HOSTNAME:%d\n", gethostname(&hostName, 255));
	printf("PID:%d\n", getpid());
	printf("UID:%d\n", getuid());

	time_t now;
	time(&now);
	printf("TIME:%s\n", ctime(&now));

	printf("PAPER:%s, TOBACCO:%s, MATCHES:%s\n", getenv("PAPER"), getenv("TOBACCO"), getenv("MATCHES"));
}

void initializeSuplies()
{
	setenv("PAPER", "2", 1);
	setenv("TOBACCO", "2", 1);
	setenv("MATCHES", "2", 1);
}

void consume()
{
	char *paperStr = getenv("PAPER");
	int paper = atoi(paperStr);
	paper++;
	setenv("PAPER", paper, 1);

	char *tobaccoStr = getenv("TOBACCO");
	int tobacco = atoi(tobaccoStr);
	tobacco++;
	setenv("TOBACCO", tobacco, 1);

	char *matchesStr = getenv("MATCHES");
	int matches = atoi(matchesStr);
	matches++;
	setenv("MATCHES", matches, 1);
}

void wait()
{
	sleep(5);
}

void smoke()
{
	checkSupplies();
	listAvaliable();
	printf("SMOKING!\n");
}

void forkSmokers()
{
	printf("FORKING THREE SMOKERS!\n");
	pid_t S1 = fork();
	if (S1 == 0) {
		//forked properly
		printf("SMOKER S1:%d\n", getpid());
		smoke();
		exit(0);
	} else if (S1 < 0) {
		//failed to fork
	} else {
		//agent
		wait();
		consume();

		pid_t S2 = fork();
		if (S2 == 0) {
			printf("SMOKER S2:%d\n", getpid());
			smoke();
			exit(0);
		} else if (S2 < 0) {
			//failed to fork
		} else {
			//agent
			wait();
			consume();

			pid_t S3 = fork();
			if (S3 == 0) {
				printf("SMOKER S3:%d\n", getpid());
				smoke();
				exit(0);
			} else if (S3 < 0) {
				//failed to fork
			}
		}
	}
}

int main()
{
	initializeSuplies();

	printInfo();

	forkSmokers();

	printf("AGENT IS DONE!");
	exit(0);
	return 0;
}