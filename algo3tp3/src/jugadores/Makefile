CC=g++
CFLAGS=-g 

all: fixed rand heur heurb labi wabi minimax alfabeta timer_minimax timer_alfabeta scorer1 scorer2 scorer3 scorer4 jfin1 jfin2 jfin3 jfin4 jfin5
	
fixed: jugs_varios.cpp
	g++ jugs_varios.cpp -DJUGADOR=JUGADOR_FIJO -O2 -o fixed

rand: jugs_varios.cpp
	g++ jugs_varios.cpp -DJUGADOR=JUGADOR_RANDOM -O2 -o rand

heur: jugs_varios.cpp
	g++ jugs_varios.cpp -DJUGADOR=JUGADOR_HEURISTICO -O2 -o heur

heurb: jugs_varios.cpp
	g++ jugs_varios.cpp -DJUGADOR=JUGADOR_HEURISTICO_MEJOR -O2 -o heurb

%: %.cpp Makefile
	$(CC) $(CFLAGS) $< -o $@

labi: jug_labi.cpp
	g++ jug_labi.cpp -O2 -o labi

wabi: jug_wabi.cpp
	g++ jug_wabi.cpp -O2 -o wabi

clean:
	rm -f fixed rand heur heurb labi wabi minimax alfabeta timer_minimax timer_alfabeta scorer1 scorer2 scorer3 scorer4 jfin1 jfin2 jfin3 jfin4 jfin5
