#include <iostream>
#include <vector>
#include <cstdlib>
#include <signal.h>
#include <list>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cassert>


using namespace std;

struct jugada{
	int fila;
	int col;
	int orient;
};


struct jugvalor{
	jugada jug;
	int puntaje;
};


struct puntajes{
	int rojo;
	int verde;
};

template<class T>
class vector2 : public vector<T> {
public:
	vector2() {}
	vector2(int n, const T& v) : vector<T>(n,v) {}
	const T& operator[](int i) const {
		assert(0 <= i && i < (int)this->size());
		return vector<T>::operator[](i);
	}
	T& operator[](int i) {
		if(0 <= i && i < (int)this->size()){
			return vector<T>::operator[](i);
		}else{
			cerr << "Esto es un error   " << i << " " << this->size() << " " << sizeof(T) << endl;
			assert(false);
		}
			
	}
};

typedef vector2<int> vint;
typedef vector2<vint> vvint;
typedef vector<jugada> vjug;
typedef list<jugada> ljug;
typedef pair<int, int> pint;




#define enrango(a,x,b) ((a) <= (x) && (x) < (b))
#define forn(i,n) for(int i=0; i < (int)(n); ++i)
#define VALOR_MAXIMO (n*n*n*n+1)
#define VALOR_MINIMO -(n*n*n*n+1)


int ddi[4] = {-1, 1, 0, 0};
int ddj[4] = {0, 0, -1, 1};

vvint marc;
vvint tbl;


int n;
int c;
jugada jugada_actual;
int plies = 0;
int plies_original;
int profund;

int valorady;
int valorexp;
int valorficha;
bool entre = false;


pint hay_vacio_adyacente (int i, int j){
	if (i-1>=0 && tbl[i-1][j] == -1 && marc[i-1][j] == 0) return (make_pair(i-1,j));
	if (j-1>=0 && tbl[i][j-1] == -1 && marc[i][j-1] == 0) return (make_pair(i,j-1));
	if (i+1<n && tbl[i+1][j] == -1 && marc[i+1][j] == 0) return (make_pair(i+1,j));
	if (j+1<n && tbl[i][j+1] == -1 && marc[i][j+1] == 0) return (make_pair(i,j+1));
	return (make_pair(-1,-1));
}

//int puedo_poner_adyacente (int i, int j){
	//int cant = 0;
	//if (i-1>=0 && tbl[i-1][j] == -1 && hay_vacio_adyacente (i-1,j)){
		//cant+= 1;
	//}
	//if (j-1>=0 && tbl[i][j-1] == -1 && hay_vacio_adyacente (i,j-1)){
		//cant+= 1;
	//}
	//if (i+1<n && tbl[i+1][j] == -1 && hay_vacio_adyacente (i+1,j)){
		//cant+= 1;
	//}
	//if (j+1<n && tbl[i][j+1] == -1 && hay_vacio_adyacente (i,j+1)){
		//cant+= 1;
	//}
	//return cant;
//}
	

int bfs (int color, list<pint> pend){
	int score =0;
	while (!pend.empty()){
		score+=valorficha;
		int i = pend.front().first;
		int j = pend.front().second;
		//cerr << "i" << i << " " << "j" << j << endl;
		pend.pop_front();

		if (i-1>=0 && tbl[i-1][j] == color && marc[i-1][j] == 0){
			pend.push_back(make_pair(i-1,j));
			marc[i-1][j] = 1;
		}

		if (j-1>=0 && tbl[i][j-1] == color && marc[i][j-1] == 0){
			pend.push_back(make_pair(i,j-1));
			marc[i][j-1] = 1;
		}
		

		if (i+1<n && tbl[i+1][j] == color && marc[i+1][j] == 0){
			pend.push_back(make_pair(i+1,j));
			marc[i+1][j] = 1;
		}
		if (j+1<n && tbl[i][j+1] == color && marc[i][j+1] == 0){
			pend.push_back(make_pair(i,j+1));
			marc[i][j+1] = 1;
		}
		if (i-1>=0 && tbl[i-1][j] == -1){
			pint val = hay_vacio_adyacente (i-1,j);
			if (val.first != -1){
				score+= valorady*2;
				marc[i-1][j] = 1;
				marc[val.first][val.second] = 1;
			}
		}

		if (j-1>=0 && tbl[i][j-1] == -1){
			pint val = hay_vacio_adyacente (i,j-1);
			if (val.first != -1){
				score+= valorady*2;
				marc[i][j-1] = 1;
				marc[val.first][val.second] = 1;
			}
		}
		
		if (i+1<n && tbl[i+1][j] == -1){
			pint val = hay_vacio_adyacente (i+1,j);
 			if (val.first != -1){
				score+= valorady*2;
				marc[i+1][j] = 1;
				marc[val.first][val.second] = 1;
			}

		}
		
		if (j+1<n && tbl[i][j+1] == -1 ){
			pint val = hay_vacio_adyacente (i,j+1);
			if (val.first != -1){
				score+= valorady*2;
				marc[i][j+1] = 1;
				marc[val.first][val.second] = 1;
			}

		}
		
	}
		
	//cerr << score << endl;
	return score;
}


puntajes game_score_otro(){
	int scores[2];
	scores[0] = 0; scores[1]=0;
	//marc = vvint(n, vint(n, 0));
	forn(i,n) forn(j,n) marc[i][j] = 0;
	list<pint> pend;
	forn(i,n) forn(j,n){
		if (marc[i][j] == 0 && !(tbl[i][j] == -1)){
			marc[i][j] = 1;
			pend.push_back(make_pair(i,j));
			int color = tbl[i][j];
			int isla = bfs(color, pend);
			scores[color] += isla*isla;
			pend.clear();
		}
	}
	return ((puntajes){scores[0], scores[1]});
}

int puntuar_movida(){
	puntajes valor = game_score_otro();
	int scores[2];
	scores[0] = valor.rojo;
	scores[1] = valor.verde;
	////cerr << "Sabi: " << scores[0] << " " << scores[1] << " Nos: " << valor2.rojo << " " << valor2.verde << endl;
	////cerr << scores[0] << " " << scores [1] << endl;
	//forn(i,n){ 
		//forn(j,n){
			//if (tbl[i][j] == c){
				//scores[c] += pow(puedo_poner_adyacente(i,j), valorexp);
			//}else if (tbl[i][j] == !c){
				//scores[!c] += pow(puedo_poner_adyacente(i,j), valorexp);
			//}
		//}
	//}
	int res = scores[0] - scores[1];
	if (plies%2) res *= -1;
	return res;
}


/* Función para mostrar el tablero en stderr */
void board_show() {
	forn(i,n) { forn(j,n) cerr << ".#X"[tbl[i][j]+1]; cerr << endl; }
}

void aplica_movida(int i, int j, int d, int k) {
	tbl[i][j] = k;
	tbl[i+d][j+1-d] = k;
}

void quita_movida(int i, int j, int d) {
	tbl[i][j] = -1;
	tbl[i+d][j+1-d] = -1;
}

void lee_movida(int k) {
	int i,j,d;
	cin >> i >> j >> d; i--; j--;
	/* No es necesario checkear que la jugada sea válida, estamos seguros */
	aplica_movida(i,j,d,k);
	plies++;
}

int hay_movida() {
	forn(i,n) forn(j,n-1) if (tbl[i][j] == -1 && tbl[i][j+1] == -1) return true;
	forn(i,n-1) forn(j,n) if (tbl[i][j] == -1 && tbl[i+1][j] == -1) return true;
	return false;
}


int calcular_hacia_abajo (int alfa, int beta, int arbolrest){

	vjug jugposibles;
	forn(i,n) forn(j,n-1) {
		if (tbl[i][j] == -1 && tbl[i][j+1] == -1) {
			
			jugposibles.push_back((jugada){i,j,0});
		}
	}
	forn(i,n-1) forn(j,n){
		if (tbl[i][j] == -1 && tbl[i+1][j] == -1){ 
			jugposibles.push_back((jugada){i,j,1});
		}
	}
	if (jugposibles.empty() || arbolrest == 0){
		int res = puntuar_movida();
		//cerr << res << " ";
		return res;
	}
	forn(i,jugposibles.size()){
		jugada jug_a_probar = (jugposibles[i]);
		aplica_movida(jug_a_probar.fila, jug_a_probar.col, jug_a_probar.orient, plies%2);
		plies++;
		//cerr << plies;
		int score = -calcular_hacia_abajo(-beta, -alfa, arbolrest-1);

		if (score > alfa && plies == plies_original+1){
			entre = true;
			//cerr << "entre" << endl;
			jugada_actual = jug_a_probar;
		}
		alfa = max (score, alfa);
		quita_movida(jug_a_probar.fila, jug_a_probar.col, jug_a_probar.orient);
		plies--;
		if (beta <= alfa){
			break;
		}
	}
	if (!entre && plies == plies_original){
		//cerr << "No entre!!!!!!!!!!!!!!!!!!!" << endl;
		jugada_actual = jugposibles[0];
	}

	
	
	return alfa;
	
	
	
	
}

void juega_movida(int k) {
	//board_show();	
	plies_original = plies;
	calcular_hacia_abajo(VALOR_MINIMO, VALOR_MAXIMO, profund);
	entre = false;
	aplica_movida(jugada_actual.fila,jugada_actual.col,jugada_actual.orient,k);
	plies++;
	cout << jugada_actual.fila+1 << " " << jugada_actual.col+1 << " " << jugada_actual.orient << endl; return;
	
}

/* Cuando se reciba un SIGTERM se ejecutará esta función. No es necesario
 * hacer nada acá, pero si alguno lo necesita puede hacer alguna tarea acá,
 * como guardar estadísticas del juego, etc. */
void terminar(int) {
	cerr << "Uy!, se acabó el partido!" << endl;
	//free(&marc);
	//free (&tbl);
	exit(0);
}

int main(int argc, char* argv[]) {
	signal(SIGTERM, terminar);
	profund = atoi (argv[1]);
	valorficha = atoi (argv[2]);
	valorady = atoi(argv[3]);
	valorexp = atoi(argv[4]);
	cin >> n >> c;
	tbl = vvint(n, vint(n, -1));
	//marc.resize(n);
	//forn(i,n) marc[i].resize(n);
	marc = vvint(n, vint(n, 0));
	/* Si c==1, arrancamos leyendo una jugada del otro */
	if (n>1 && c) lee_movida(!c);
	while (hay_movida()) {
		juega_movida(c);
		// Si no hay movida para hacer se cuelga leyendo, pero el judge nos mata el proceso con SIGTERM
		lee_movida(!c); 
	}
	return 0;
}


	

