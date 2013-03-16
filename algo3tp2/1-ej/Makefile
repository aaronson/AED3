CC=g++
CFLAGS=-g 
SOURCES= 1-ej.cpp rangen.cpp timer.cpp

all: 1-ej rangen timer

%: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f 1-ej rangen timer
