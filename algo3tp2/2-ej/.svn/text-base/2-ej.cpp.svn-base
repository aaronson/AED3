#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <cstdio>
using namespace std;

typedef vector<string> wvec;

int times;

void hallar_dists();
bool relacionadas (string a, string b);
int search (string a, string b, map<string, int>&  referencias, list<int>* adyacentes);

int main(){
	cin >> times;
	while (times > 0){
		hallar_dists();
		times--;
	}	
}

/* leemos las palabras del diccionario y las guardamos en un vector de string */
void hallar_dists(){
	string palabra;
	cin >> palabra;
	wvec lista;
	while (palabra != "*"){
		lista.push_back(palabra);
		cin >> palabra;
	}

/* armamos un mapa con las adyacencias de cada palabra */
	unsigned int tam = lista.size();
	map<string, int>  referencias;
	for (unsigned int i = 0; i <tam; i++){
		referencias.insert(pair<string, int> (lista[i],i));
	}
	list<int> adyacentes [tam];
	for (unsigned int i = 0; i < lista.size(); i++){
		for (unsigned int j = i+1; j < lista.size(); j++){
			if (lista[i].length() == lista[j].length() && relacionadas(lista[i], lista[j])){
				int posi, posj;
				posi = referencias[lista[i]];
				posj = referencias[lista[j]];
				adyacentes[posi].push_back(posj);
				adyacentes[posj].push_back(posi);
			}
		}
	}
	//for (unsigned int i = 0;  i < tam; ++ i) {
		//cout << lista[i] << "\t\t";
		//for (list<int>::iterator it = adyacentes[i].begin();  it != adyacentes[i].end(); it++) {
			 //cout << *it << " ";
		 //}
		 //cout << endl;
	 //}

/* leemos las palabras las cuales debemos buscarle la cantidad de transforamciones,
 * y luego ejecutamos el BFS utilizando el mapa construido anteriormente */
	 string palabra1, palabra2;
	 char st = cin.get();
	 st = cin.peek();
	 while (st != EOF && st != '\n'){
	 	cin >> palabra1;
	 	cin >> palabra2;
	 	cout << palabra1 << " " << palabra2 << " " << search(palabra1, palabra2, referencias, adyacentes) << endl;
	 	st = cin.get();
	 	st = cin.peek();
	}
	if (times > 1) cout << endl;

}

/* funcion que chequea si dos palabras seran adyacentes o no,
 * compara la longitud de las palabras y la cantidad de coincidencias de letras */
bool relacionadas (string a, string b){
	unsigned int tam = a.length();
	unsigned int coincidencias = 0;
	for (unsigned int i= 0; i < tam; i++){
		if (a[i] == b[i]) coincidencias++;
	}
	return (coincidencias >= tam-1);
}

/* ejecutamos un BFS que nos dara el camino minimo desde a hasta b, mas informacion ver el informe */
int search (string a, string b, map<string, int>&  referencias, list<int>* adyacentes){
	queue <pair <int, int> > cola;
	vector<bool> marcados (referencias.size(), false);
	int refa = referencias[a];
	int refb = referencias[b];
	int dist = 0;
	cola.push(pair<int, int> (refa, 0));
	marcados[refa] = true;
	bool noencontre = (a != b);
	while (!cola.empty() && noencontre){
		dist = cola.front().second +1;
		for (list<int>::iterator it = adyacentes[cola.front().first].begin(); it != adyacentes[cola.front().first].end(); it++){
			if (!marcados[*it]){
			  	cola.push(pair<int,int> (*it, dist));
			  	marcados[*it]= true;
			}
			if (*it == refb){
				noencontre = false;
				break;
			}
		}
		cola.pop();	
	}
	return dist;
}
