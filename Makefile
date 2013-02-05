CC=gcc
FLAGS=-std=c99 -g -Wall
OUT=AGENT
SRC=AGENT.c

$(OUT): $(SRC)
	$(CC) $(FLAGS) -o $@ $?

clean:
	@rm -f $(OUT)