CC=gcc
CFLAGS= -std=c99 -Wall -O2 -g
INCLUDE= -I./inc

.PHONY: all
all: gccerc

gccerc: src/main.c 
	$(CC) $(CFLAGS) $(INCLUDE) src/txtcolor.c src/main.c -o gccerc

.PHONY: clean
clean:
	rm -f gccerc
	rm -f *.o
