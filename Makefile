CC = gcc
CFLAGS= -O2 -march=native -Wall -g

bf: bf.c
	$(CC) -o bf $(CFLAGS) bf.c

clean:
	rm -f bf

test:
	@./testcase.sh

.PHONY: test clean
