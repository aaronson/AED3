export LC_ALL=C
CC=gcc
CXX=g++
CFLAGS=-Wall -O2 -Werror -g -ggdb
CXXFLAGS=-Wall -O2 -Werror -g -ggdb
LDFLAGS=

OBJS=judge.o
BINS=judge

all: $(BINS)

judge: judge.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

judge.o: judge.c

clean:
	rm -f $(OBJS) $(BINS)
