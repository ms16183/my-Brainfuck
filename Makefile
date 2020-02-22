CC = gcc
CFLAGS= -O2 -march=native -Wall -g

bf: bf.c
	$(CC) -o bf $(CFLAGS) bf.c

clean:
	rm -f bf

.PHONY: test clean
