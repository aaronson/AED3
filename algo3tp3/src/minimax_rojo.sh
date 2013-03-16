#/bin/sh

cd jugadores
make
cd ..
echo "#Jugando timer_minimax de local contra labi"
./judge 4 ./jugadores/timer_minimax ./jugadores/labi #2>>/dev/null

echo "#Jugando scorer4 de local contra wabi"
./judge 4 ./jugadores/timer_minimax ./jugadores/wabi #2>>/dev/null

echo "#Jugando timer_minimax de local contra fixed"
./judge 4 ./jugadores/timer_minimax ./jugadores/fixed #2>>/dev/null
	
echo "#Jugando timer_minimax de local contra heur"
./judge 4 ./jugadores/timer_minimax ./jugadores/heur #2>>/dev/null
	
echo "#Jugando timer_minimax de local contra heurb"
./judge 4 ./jugadores/timer_minimax ./jugadores/heurb #2>>/dev/null

echo "#Jugando timer_minimax de local contra rand"
./judge 4 ./jugadores/timer_minimax ./jugadores/rand #2>>/dev/null

echo "#Jugando timer_minimax de local contra scorer3"
./judge 4 ./jugadores/timer_minimax ./jugadores/scorer3 1 2 #2>>/dev/null



