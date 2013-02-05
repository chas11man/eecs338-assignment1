CC=gcc
CFLAGS=-std=c99 -g -Wall -O
default: AGENT.o
	$(CC) $(CFLAGS) AGENT.o
clean:
	rm -f AGENT AGENT.o