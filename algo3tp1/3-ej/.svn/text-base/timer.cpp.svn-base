#include <stdlib.h> 
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <math.h>

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
double ops = 0;


int main() {
	char a, actualkey;
	string line;
	charls alfrest;
	int dist;
	bool relacion = false;
	set <char> alfabeto;
	rel insertpar;
	while(true){
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
				if (a > actualkey){
					insertpar.first = actualkey;
					ops++;
					insertpar.second = a;
					ops++;
					rls.insert(insertpar);
					ops+=log(rls.size());
				}else{
					insertpar.first = a;
					ops++;
					insertpar.second = actualkey;
					ops++;
					rls.insert(insertpar);
					ops+=log(rls.size());
				}
				alfabeto.insert(a);
				ops+=log(alfabeto.size());
			}else{
				actualkey = a;
				ops++;
				alfabeto.insert(a);
				ops+=log(alfabeto.size());
			}
		}
		set<char>::iterator its;
		for (its = (alfabeto.begin()); its != alfabeto.end(); its++){
			alfrest.push_back((*its));
		}
		dist = backtracking(alfrest);
		//imprimir(dist);
		ops =0;
		candidatos.clear();
		rls.clear();
		alfrest.clear();
		relacion = false;
		
	}

}

int backtracking (charls alfrest){
	if (alfrest.empty()){
		int res = podar(0);
		cout << "Se hicieron " << (long) ops << " operaciones" << endl;
		return res;
	}else{
		generar(alfrest.front(), alfrest.size());
		ops++;
		//cout << "Hay " << candidatos.size() << " candidatos" << endl;
		alfrest.pop_front();
		ops++;
		podar(alfrest.size());
		ops++;
		backtracking(alfrest);
	}
	return 0;
}


void generar (char proximo, int tam){
	charlsls candvieja= candidatos;
	ops+=candidatos.size()*tam;
	candidatos.clear();
	ops++;
	charlsls::iterator itls;
	ops++;
	int x = 0;
	ops++;
	int i = 0;
	ops++;
	int j;
	ops++;
	charlsls finales;
	ops++;
	if (candvieja.empty()){
		ops++;
		charls inicial;
		inicial.push_back(proximo);
		candidatos.push_back(inicial);
		ops++;
	}else{
		ops++;
		for (itls = (candvieja.begin()); itls != candvieja.end(); itls++){
			ops++;
			charls::iterator itc;
			ops++;
			j= candvieja.front().size()+1;
			ops++;
			i=0;
			ops++;
			for(itc = (*itls).end(); i<j; itc--){
				ops++;
				(*itls).insert(itc, proximo);
				ops++;
				if (i == j-1){
					ops++;
					finales.push_back ((*itls));
					ops+=(*itls).size();
				}else{
					ops++;
					candidatos.push_back((*itls));
					ops+=(*itls).size();
				}
				itc--;
				ops++;
				(*itls).erase(itc);
				ops++;
				i++;
				ops++;
				x++;
			}
			x=0;
			ops++;
		}  
		while (!finales.empty()){
			ops++;
			candidatos.push_back (finales.front());
			ops+=finales.size();
			finales.pop_front();
			ops++;
		}
	}
}


int podar(int restante){
	charlsls::iterator itcls;
	list<int> distmax;
	int n;
	for (itcls = (candidatos.begin()); itcls != candidatos.end(); itcls++){
		ops++;
		n = calcular_dist(*itcls);
		ops++;
		distmax.push_back(n);
		ops++;
	}
	list<int>::iterator itin;
	int mindist;
	if (!distmax.empty()){
		ops++;
		mindist = distmax.front();
		ops++;
	}
	for (itin = (distmax.begin()); itin != distmax.end(); itin++){
		ops++;
		if (*itin < mindist){
			mindist = *itin;
			ops++;
		}
		ops++;
	}
	itcls = candidatos.begin();
	ops++;
	for (itin = (distmax.begin()); itin != distmax.end(); itin++){
		ops++;
		if (*itin > mindist+restante){
			ops++;
			itcls = candidatos.erase(itcls);
			ops++;
		}else{
			ops++;
			itcls++;
			ops++;
		}
	}
	return mindist;
}


int calcular_dist(charls cl){
	int maxdist = 0;
	ops++;
	charls::iterator itc, itc2;
	int i = 1;
	ops++;
	int j= 1;
	ops++;
	rel par;
	for (itc= (cl.begin()); itc != cl.end(); itc++){
		ops++;
		itc2 = cl.begin();
		ops++;
		advance (itc2, i);
		ops+=i;
		for ( ; itc2 !=cl.end(); itc2++){
			ops++;
			if ((*itc) > (*itc2)){
				ops++;
				par.first = *itc2;
				ops++;
				par.second = *itc;
				ops++;
			}else{
				ops++;
				par.first = *itc;
				ops++;
				par.second = *itc2;
				ops++;
			}
			if (rls.count(par) > 0){
				ops++;
				if (j > maxdist) maxdist = j;
				ops++;
			}
			j++;
			ops++;
		}
		i++;
		j=1;
		ops++;
		ops++;
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
