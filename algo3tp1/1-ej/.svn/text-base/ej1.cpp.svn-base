#include <stdlib.h> 
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

typedef pair <int, int> interv;
typedef list <interv> linv;
typedef vector <interv> vinv;

pair <bool, linv> intervalos (linv ls, int tope);

int main () {
  string line;
  int times, tope;
  linv ls;
  interv itv;
  pair <bool, linv > resultado;
	/* INCIO LEVANTADA DE DATOS
	Levantamos los datos de entrada segun el formato indicado
	*/
      //getline (entrada,line); 
      cin >> times;
      //getline (entrada, line);
      int i = 0;
      while (times > 0){
			cin >> tope;
			while (true){
					cin >> itv.first;
					cin >> itv.second;
					if (itv.first == 0 && itv.second == 0){
						break;
					}
					ls.push_back(itv); // Guardamos en una lista una tupla de los datos internos  FIRST = Valor inicial, SECOND = Valor Final
					i++;
				   
			}
			
		// FIN LEVANTADA DE DATOS
			resultado = intervalos(ls, tope); // Mandamos a intervalos la lista 
		// INICIO ARMADO ARCHIVO DE SALIDA
			if (resultado.first){
				cout << resultado.second.size() << endl;
				while (!resultado.second.empty()){
					cout << resultado.second.front().first << " " << resultado.second.front().second << endl;
					resultado.second.pop_front();
				}
			}else{
				cout << "0" << endl;
			}
		
			ls.clear();
			while (!ls.empty()){
				ls.pop_back();
			}
			times--;
			if (times > 0){
				cout << endl;
			}
		}
		//FIN ARMADO ARCHIVO DE SALIDA	

  return 0;
}

pair <bool, linv> intervalos(linv ls, int tope) {
	ls.sort(); // Ordenamos por primer coordenada, en caso de igualdad ordena por segunda coordenada
	pair <bool, linv >  res;
	vinv vec;
	interv p = ls.front();
	/*INCIO  ELIMINACION DE REPETIDOS
	          Nos quedamos con aquellos intervalos cuya segunda coordenada sea la mayor entre los que repiten la primer coordenada
			  
	          Para hacer esto recorremos la lista de manera lineal ya que vamos en orden y y cada vez que reiniciamos el while descartamos aquellos que ya vimos xq ya fueron filtrados.
	*/
	while (!ls.empty()){
		while (ls.front().first == p.first){ // Mientras coincidan la primer coordenada
			if (ls.front().second > p.second) { // Nos quedamos con aquel que tiene la segunda coordenada mayor
				p = ls.front();
			}
			if (!ls.empty()){
				ls.pop_front();
			}else{
				break;
			}
		}
		vec.push_back(p);
		if (!ls.empty()){
			p = ls.front();
		} 
	}
	//FIN  ELIMINACION DE LOS REPETIDOS
	if (vec.empty() || vec[0].first > 0){ // Si la lista esta vacia o el primero vector arranca en un Nro Mayor a 0, no hay solucion al problema.
		res.first = false;
		return res;
	}
	
	unsigned int i= 0;
	unsigned int posmax = 0;
	int target = vec[0].second; // Fijamos como valor inicial del target a la segunda coordenada de la primer tupla del vector
	
	while (i < vec.size() && vec[i].first <= 0){  // Resolvemos para los casos negativos y para aquellos que empiecen con 0 para quedarnos con el mejor valor
		if (vec[i].second > vec[posmax].second){
			 	posmax = i;
		}
		i++;
	}
	ls.push_back(vec[posmax]); // Ponemos la mejor opcion que involucre el caso de [- X o 0 .....]
	if (vec[posmax].second >= tope){ // Si el valor mayor, de la posicion del maximo valor es mayor o igual al tope, termina el problema y devolvemos la solucion
		res.first = true;
		res.second = ls;
		return res;
	}
	target = vec[posmax].second;
	int cant = 0;
	bool entro = false;
	
	/*
	   Recorremos toda la lista de manera lineal, para ello  mientras la primer coordenada de la tupla de la posicion que nos encontramos es menor al target, chequeamos 
	   si la segunda coordenada es mayor a la que era la maxima en ese momento, cambiamos de valor de posicion maxima.
	    Cuando terminamos de recorrer todos los valores menores al target, pusheamos en la lista  la tupla de aquella posicion que es la que gurdamos en posMax
	*/
	while (i < vec.size()){ // Recorremos toda la lista
		entro = false;
		while (i < vec.size() && vec[i].first <= target){ // Recorremos internamente la lista para aquellos que tienen su primer coordenada menor que el target o sea mas grande que el tamaño
			if (vec[i].second > vec[posmax].second){ // Si la segunda coordenada es mayor a la segunda coordenada de la posicion maxima guardada 
			 	posmax =i; // Tomamos a i como nueva posicion maxima
			}
			i++;
			cant++;
			entro = true; // Indicamos que entro para evitar que luego saltee el proximo caso
		}
		ls.push_back(vec[posmax]); // Guardamos en la lista esta nueva tupla
		if (vec[posmax].second >= tope){ // Chequeamos que no haya cubierto con el valor del M dado, si es mas grande devolvemos el resultado
			res.first = true;
			res.second = ls;
			return res;
		}
		if(!entro){ // Avanzamos en la lista
			i++;
		}
		target =vec[posmax].second; // Almacenamos como target la segunda coordenada de la posicion maxima
		
		
	}
	res.first = false; // En caso de que llegue aca es xq no encontro resultados.
	return res;
}
