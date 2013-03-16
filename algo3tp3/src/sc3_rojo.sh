#/bin/sh

cd jugadores
make
cd ..
echo "Jugando scorer3 de local contra $1"
for i in {1..10}
	do
	for j in {1..5}
	do
		echo "Probando con un adyacente de $i y un exponente de $j"
		./judge 20 ./jugadores/scorer3 $i $j -- ./jugadores/$1 2>>/dev/null
	done
done
