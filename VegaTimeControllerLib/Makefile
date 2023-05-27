CC ?= gcc
CFLAGS = -Wall -std=gnu11 -pthread -fPIC

all:	VegaTimeController

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

VegaTimeController: main.o	
	$(CC) -o $@ main.o $(CFLAGS) -ldl
	@echo VegaTimeController Compiled Successfully!
clean:
	rm -fr VegaTimeClient $(OBJS)
