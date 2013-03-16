#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <math.h>
#include <cstdio>
using namespace std;

typedef vector<string> wvec;

int times;

void hallar_dists();
bool relacionadas (string a, string b);
int search (string a, string b, map<string, int>&  referencias, list<int>* adyacentes);
double ops;

int main(){
	//int times;
	cin >> times;
	while (times > 0){
		hallar_dists();
		times--;
	}	
}

void hallar_dists(){
	ops = 0;
	string palabra;
	cin >> palabra;
	wvec lista;
	while (palabra != "*"){
		lista.push_back(palabra);
		cin >> palabra;
	}
	//wvec diccionario [longmax];
	unsigned int tam = lista.size();
	ops++;
	map<string, int>  referencias;
	for (unsigned int i = 0; i <tam; i++){
		referencias.insert(pair<string, int> (lista[i],i));
		ops+=log(tam) * lista[i].size();

	}
	list<int> adyacentes [tam];
	for (unsigned int i = 0; i < lista.size(); i++){
		for (unsigned int j = i+1; j < lista.size(); j++){
			if (lista[i].length() == lista[j].length() && relacionadas(lista[i], lista[j])){
				int posi, posj;
				posi = referencias[lista[i]];
				posj = referencias[lista[j]];
				ops+=2*log(tam)*lista[i].size();
				adyacentes[posi].push_back(posj);
				adyacentes[posj].push_back(posi);
				ops+=2;
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
	 string palabra1, palabra2;
	 char st = cin.get();
	 st = cin.peek();
	 while (st != EOF && st != '\n'){
	 	cin >> palabra1;
	 	cin >> palabra2;
	 	search(palabra1, palabra2, referencias, adyacentes);
	 	st = cin.get();
	 	st = cin.peek();
	}
	cout << "Se hicieron " << (long) ops << " operaciones" << endl;

}

bool relacionadas (string a, string b){
	unsigned int tam = a.length();
	unsigned int coincidencias = 0;
	ops++;
	for (unsigned int i= 0; i < tam; i++){
		if (a[i] == b[i]) coincidencias++;
		ops+=2;
	}
	return (coincidencias >= tam-1);
}

int search (string a, string b, map<string, int>&  referencias, list<int>* adyacentes){
	queue <pair <int, int> > cola;
	vector<bool> marcados (referencias.size(), false);
	int refa = referencias[a];
	ops+=log(referencias.size())*a.length();
	int refb = referencias[b];
	ops+=log(referencias.size())*b.length();
	int dist = 0;
	cola.push(pair<int, int> (refa, 0));
	marcados[refa] = true;
	bool noencontre = (a != b);
	ops+=4;
	while (!cola.empty() && noencontre){
		dist = cola.front().second +1;
		ops+=2;
		for (list<int>::iterator it = adyacentes[cola.front().first].begin(); it != adyacentes[cola.front().first].end(); it++){
			if (!marcados[*it]){
			  	cola.push(pair<int,int> (*it, dist));
			  	marcados[*it]= true;
			  	ops+=3;
			}
			if (*it == refb){
				noencontre = false;
				break;
				ops+=2;
			}
		}
		//cout << cola.front().first << " " << cola.front().second << endl;
		cola.pop();
		ops++;
	}
	return dist;
}
