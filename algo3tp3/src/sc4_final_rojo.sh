#/bin/sh

cd jugadores
make
cd ..
echo -ne "Labi "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/labi 2>>/dev/null

echo -ne "Wabi "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/wabi 2>>/dev/null

echo -ne "Fixed "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/fixed 2>>/dev/null
	
echo -ne "Heur "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/heur 2>>/dev/null
	
echo -ne "Heurb "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/heurb 2>>/dev/null

echo -ne "Rand "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/rand 2>>/dev/null

echo -ne "Scorer3 "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/scorer3 1 2 2>>/dev/null

echo -ne "Scorer4 "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/scorer4 5 1 2  2>>/dev/null

echo -ne "Jfin4 "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/jfin4 3 5 1 2 2>>/dev/null

echo -ne "Jfin5 "
./judge 11 ./jugadores/scorer4 $1 $2 $3 -- ./jugadores/jfin5 30 4 11 5 1 2 2>>/dev/null
