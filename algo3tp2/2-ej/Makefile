CC=g++
CFLAGS=-g 
SOURCES= 2-ej.cpp timer.cpp

all: 2-ej timer

%: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f 2-ej timer
