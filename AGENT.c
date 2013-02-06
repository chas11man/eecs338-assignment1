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
		printf("NO PAPER!\n\n");
		fflush(stdout);
		exit(0);
	} else if (tobacco <= 0) {
		printf("NO TOBACCO!\n\n");
		fflush(stdout);
		exit(0);
	} else if (matches <= 0) {
		printf("NO MATCHES!\n\n");
		fflush(stdout);
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
	char hostName[256];
	gethostname(hostName, sizeof(hostName));
	printf("HOSTNAME:%s\n", hostName);
	printf("PID:%d\n", getpid());
	printf("UID:%d\n", getuid());

	time_t now;
	time(&now);
	printf("TIME:%s\n", ctime(&now));

	printf("PAPER:%s, TOBACCO:%s, MATCHES:%s\n", getenv("PAPER"), getenv("TOBACCO"), getenv("MATCHES"));
}

void initializeSuplies(int paper, int tobacco, int matches)
{
	char paperBuffer[10];
	snprintf(paperBuffer, 10, "%d", paper);
	setenv("PAPER", paperBuffer, 1);

	char tobaccoBuffer[10];
	snprintf(tobaccoBuffer, 10, "%d", tobacco);
	setenv("TOBACCO", tobaccoBuffer, 1);

	char matchesBuffer[10];
	snprintf(matchesBuffer, 10, "%d", matches);
	setenv("MATCHES", matchesBuffer, 1);
}

void consume()
{
	char *paperStr = getenv("PAPER");
	int paper = atoi(paperStr) - 1;
	char paperBuffer[10];
	snprintf(paperBuffer, 10, "%d", paper);
	setenv("PAPER", paperBuffer, 1);

	char *tobaccoStr = getenv("TOBACCO");
	int tobacco = atoi(tobaccoStr) - 1;
	char tobaccoBuffer[10];
	snprintf(tobaccoBuffer, 10, "%d", tobacco);
	setenv("TOBACCO", tobaccoBuffer, 1);

	char *matchesStr = getenv("MATCHES");
	int matches = atoi(matchesStr) - 1;
	char matchesBuffer[10];
	snprintf(matchesBuffer, 10, "%d", matches);
	setenv("MATCHES", matchesBuffer, 1);
}

void wait()
{
	sleep(2);
}

void smoke()
{
	checkSupplies();
	listAvaliable();
	printf("SMOKING!\n\n");
}

void forkSmokers()
{
	printf("FORKING THREE SMOKERS!\n\n");
	pid_t S1 = fork();
	if (S1 == 0) {
		//forked properly
		printf("SMOKER S1:%d\n", getpid());
		smoke();
		fflush(stdout);
		exit(0);
	} else if (S1 < 0) {
		perror("Failed to fork");
	} else {
		wait();
		consume();

		pid_t S2 = fork();
		if (S2 == 0) {
			printf("SMOKER S2:%d\n", getpid());
			smoke();
			fflush(stdout);
			exit(0);
		} else if (S2 < 0) {
			perror("Failed to fork");
		} else {
			wait();
			consume();

			pid_t S3 = fork();
			if (S3 == 0) {
				printf("SMOKER S3:%d\n", getpid());
				smoke();
				fflush(stdout);
				exit(0);
			} else if (S3 < 0) {
				perror("Failed to fork");
			}
		}
	}
}

void smokeScenario(int paper, int tobacco, int matches)
{
	initializeSuplies(paper, tobacco, matches);
	printInfo();
	forkSmokers();
	wait();
	printf("AGENT IS DONE!\n-----\n");
}

int main()
{
	printf("Scenario 1\n");
	smokeScenario(2, 2, 2);

	printf("Scenario 2\n");
	smokeScenario(1, 1, 1);

	printf("Scenario 3\n");
	smokeScenario(2, 2, 1);

	printf("Scenario 4\n");
	smokeScenario(2, 1, 0);

	fflush(stdout);
	exit(0);

	return 0;
}