CC ?= gcc
CFLAGS = -Wall -std=gnu11 -pthread -fPIC

all:	VegaTimeClient

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

VegaTimeClient: main.o	
	$(CC) -o $@ main.o $(CFLAGS) -ldl
	@echo VegaTimeClient Compiled Successfully!
clean:
	rm -fr VegaTimeClient $(OBJS)
