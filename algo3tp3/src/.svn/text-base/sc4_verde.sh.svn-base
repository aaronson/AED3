#/bin/sh

cd jugadores
make
cd ..
for j in {1..10}
do
	for k in {1..5}
	do
		echo -ne "$2,$j,$k "
		./judge 20 ./jugadores/$1 ./jugadores/scorer4 $2 $j $k 2>>/dev/null

	done
done
