CC=gcc
CFLAGS=-O2 -march=native -Wall -g
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)

bf: $(OBJS)
	$(CC) $(CFLAGS) -o bf $(OBJS)

clean:
	rm -f bf bf.exe bf.out bf.app src/*.o

test:
	@./testcase.sh

.PHONY: test clean
