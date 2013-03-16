CC=g++
CFLAGS=-g 
SOURCES= 3-ej.cpp rangen.cpp timer.cpp

all: 3-ej rangen timer

%: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f 3-ej rangen timer
