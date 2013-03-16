#include <stdlib.h> 
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

typedef list<char> charls;
typedef list<charls> charlsls;
typedef pair<char,char> rel;
typedef	set<rel> diccionario;



charlsls candidatos;
diccionario rls;

int backtracking (charls alfrest);
void generar (char proximo, int tam);
int podar(int restante);
int calcular_dist(charls cl);
void imprimir(int dist);


int main() {
	char a, actualkey;
	string line;
	charls alfrest;
	int dist;
	bool relacion = false;
	set <char> alfabeto;
	rel insertpar;
	while(true){
	/// Levantamos las listas dadas por teminal
		getline(cin,line);
		istringstream iss(line);
		candidatos.clear();
		rls.clear();
		alfabeto.clear();
		alfrest.clear();
		while (iss >> a){
			if (a == '#'){
				return 0;
			}
			if (a == ';'){
				relacion = false;
			}else if (a == ':'){
				relacion = true;
			}else if(relacion){
			// Insertamos la relacion en el diccionario
				if (a > actualkey){
					insertpar.first = actualkey;
					insertpar.second = a;
					rls.insert(insertpar);
				}else{
					insertpar.first = a;
					insertpar.second = actualkey;
					rls.insert(insertpar);
				}
				alfabeto.insert(a);
			}else{
				actualkey = a;
				alfabeto.insert(a);
			}
		}
		set<char>::iterator its;
		for (its = (alfabeto.begin()); its != alfabeto.end(); its++){
			alfrest.push_back((*its)); // armamos la lista de alfrest con las claves del dicc
		}
		dist = backtracking(alfrest); 
		imprimir(dist);
		candidatos.clear();
		rls.clear();
		alfrest.clear();
		relacion = false;
		
	}

}

int backtracking (charls alfrest){
	if (alfrest.empty()){
		//cout << "Hay " << candidatos.size() << " candidatos" << endl;
		return podar(0); // uando entra por este caso devuelve lo dado por el podar
	}else{
		generar(alfrest.front(), alfrest.size()); // geneamos caso posible con las letras dadas y a partir de los candidatos que nos quedan
		charlsls::iterator itlsls;
		charls:: iterator itls;
		
		
		alfrest.pop_front();
		podar(alfrest.size()); // podamos la posible lista de candidatos a traves de la poda elegida
		
		backtracking(alfrest); // hacemos recursion con una lera menos en el diccionario
	}
	return 0;
}


void generar (char proximo, int tam){
	charlsls candvieja= candidatos; // copiamos la lista de candidatos a una lista auxiliar
	candidatos.clear();
	charlsls::iterator itls;
	int x = 0;
	int i = 0;
	int j;
	charlsls finales;
	if (candvieja.empty()){ // En caso de que sea la primer letra, pusheamos el candidato directamente
		charls inicial;
		inicial.push_back(proximo);
		candidatos.push_back(inicial);
	}else{
	// sino vamos iterando la posicion de la nueva letra dentro de la lista de los candidatos existentes
		for (itls = (candvieja.begin()); itls != candvieja.end(); itls++){
			charls::iterator itc;
			j= candvieja.front().size()+1; // para saber el tamaño de la lista de candidatos que teniamos, basta con agarrar el primero xq tienen mismo size todos
			i=0;
			for(itc = (*itls).end(); i<j; itc--){ // avanzamos con el iterador en forma reversa para lograr que queden en orden alfabetico
				(*itls).insert(itc, proximo); // agregamos la nueva letra en la posicion del iterador
				if (i == j-1){
					finales.push_back ((*itls)); //Pusheamos la lista de candidatos
				}else{
					candidatos.push_back((*itls)); // Agregamos un nuevo candidato
				}
				itc--;
				(*itls).erase(itc);
				i++;
				x++;
			}
			x=0;
		}  
		while (!finales.empty()){
			candidatos.push_back (finales.front());
			finales.pop_front();
		}
	}
}


int podar(int restante){
	charlsls::iterator itcls;
	list<int> distmax;
	int n;
	for (itcls = (candidatos.begin()); itcls != candidatos.end(); itcls++){
		n = calcular_dist(*itcls); 
		distmax.push_back(n); // pushemaamos la distancia en distmax
	}
	list<int>::iterator itin;
	int mindist;
	if (!distmax.empty()){
		mindist = distmax.front();  // si distmax tiene valores ponemos en mindist el primer valor
	}
	for (itin = (distmax.begin()); itin != distmax.end(); itin++){
		if (*itin < mindist){
			mindist = *itin; // si alguna de las distancias de la lista es menor a la distancia minima, actualizamos mindist
		}
	}
	itcls = candidatos.begin();
	for (itin = (distmax.begin()); itin != distmax.end(); itin++){
		if (*itin > mindist+restante){ // si es un caso que no se puede corregir a futuro ya que nunca sera un caso menor
			itcls = candidatos.erase(itcls); // lo borramos de la lista de candidatos
		}else{
			itcls++;
		}
	}
	return mindist;
}


int calcular_dist(charls cl){
// Calculamos las distancias recorriendo con dos iteradores entre los posibles candidatos
	int maxdist = 0;
	charls::iterator itc, itc2;
	int i = 1;
	int j= 1;
	rel par;
	for (itc= (cl.begin()); itc != cl.end(); itc++){
		itc2 = cl.begin();
		advance (itc2, i);
		for ( ; itc2 !=cl.end(); itc2++){
			if ((*itc) > (*itc2)){ // ubicamos en par segun si el valor del primer iterador es mayor al segundo o no
		 		par.first = *itc2;
				par.second = *itc;
			}else{
				par.first = *itc;
				par.second = *itc2;
			}
			if (rls.count(par) > 0){ // nos fijamos en el diccionario de candidatos
				if (j > maxdist) maxdist = j; //si j es mayor a la dist maxima actualizamos este valor
			}
			j++;
		}
		i++;
		j=1;
	}
	return maxdist;
}

void imprimir(int dist){
	charls res = candidatos.front();
	int distres = calcular_dist(res);
	while (!res.empty()){
		cout << res.front() << " ";
		res.pop_front();
	}
	cout << "-> " << distres << endl;
}
