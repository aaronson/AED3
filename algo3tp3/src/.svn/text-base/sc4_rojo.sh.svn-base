#/bin/sh

cd jugadores
make
cd ..
for i in {1..5}
do
	for j in 2
	do
		echo -ne "$i,1,$j "
		./judge 11 ./jugadores/scorer4 $i 1 $j -- ./jugadores/scorer4 $1 $2 $3  2>>/dev/null
	done
done
