#include <math.h>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <stdio.h>

#define MAXDIST 14142.14

using namespace std;

typedef pair< int, int> coord;
typedef pair< int, int> eje;
typedef pair< float, eje> ejedist;
typedef priority_queue<ejedist, vector <ejedist>, greater<ejedist> > colaPriori;
typedef vector< vector<float> > matrizFloat;

void dungeons_dragons();
int times;
bool sirve_para_prim (ejedist cant, vector<bool>& marcados);
float distancia(coord n, coord m);
void agregarAristas(colaPriori& candidatos,int k, vector<bool>& marcados, matrizFloat& distancias, int players);

int main(){
	cin >> times;
	while (times > 0){
		dungeons_dragons();
		times--;
	}
}

void dungeons_dragons(){
	int players, internetes, x, y;
	cin >> internetes >> players;
	/*Filtramos los casos borde:
	 * 0 o 1 player
	 * mas intenets que players*/
	if ((internetes >= players) || players < 2){
		cout << "0.00" << endl;
		return;
	}

	vector<coord> posiciones;
	for (int i = 0; i < players; i++){
		cin >> x >> y;
		posiciones.push_back(coord(x,y));
	}
	
	matrizFloat distancias(players, vector<float>(players,0.0));
	for (int i = 0; i < players; i++){
		for (int j = i; j < players; j++){
			float distx = pow((float) posiciones[i].first - posiciones[j].first , 2);
			float disty = pow((float) posiciones[i].second - posiciones[j].second , 2);
			distancias[i][j] = distancias[j][i] = sqrt(distx+disty);
		}
	}
	
	vector<bool> marcados(players,false);
	marcados[0]=true;
	colaPriori candidatos;
	for (int i = 1; i < players; i++){
		candidatos.push(ejedist(distancias[0][i], eje(0,i)));
	}
	int aristasFaltantes = players-1;
	vector <float> dagm;

	while(aristasFaltantes > 0){
		ejedist cand = candidatos.top();
		while (marcados[cand.second.second]){
			candidatos.pop();
			cand = candidatos.top();
		}
		/*podemos considerar que siempre la primera coordenada del eje 
		 * que cand representa esta marcado, ya que solo agregamos a 
		 * esta cola de prioridad los que esten relacionados con el nodo
		 *  que encontramos*/
		int k = cand.second.second;
		marcados[k]=true;
		dagm.push_back(cand.first);
		/*metemos todas las adyacencias del nodo nuevo marcado al heap
		 * de candidatos*/
		agregarAristas(candidatos,k,marcados,distancias,players);
		aristasFaltantes--;
	}
	sort (dagm.begin(), dagm.end(), greater<float>());
	
	internetes = max(1,internetes);
	/*Si hay 0 internetes cae en el mismo caso que 1 internet*/
	printf("%.2lf\n", dagm[internetes-1]);
}

float distancia(coord n, coord m){
	float distx = pow((float) n.first - m.first , 2);
	float disty = pow((float) n.second - m.second , 2);
	return sqrt(distx+disty);
}

void agregarAristas(colaPriori& candidatos,int k, vector<bool>& marcados, matrizFloat& distancias, int players){
	for (int j = 0; j < players; j++){
		if(!marcados[j]){
			candidatos.push(ejedist(distancias[k][j],eje(k,j)));
		}
	}
}
