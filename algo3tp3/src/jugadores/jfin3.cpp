#include <iostream>
#include <vector>
#include <cstdlib>
#include <signal.h>
#include <list>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>


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
	
	
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<jugada> vjug;
typedef list<jugada> ljug;
typedef pair <int, int> pint;


#define enrango(a,x,b) ((a) <= (x) && (x) < (b))
#define forn(i,n) for(int i=0; i < (int)(n); ++i)
#define VALOR_MAXIMO (n*n*n*n+1)
#define VALOR_MINIMO -(n*n*n*n+1)


int ddi[4] = {-1, 1, 0, 0};
int ddj[4] = {0, 0, -1, 1};

vvint tbl;
int n;
int c;
jugada jugada_actual;
vjug jugadas_finales;

int plies = 0;
int plies_original;
int profund;

int valorady;
int valorexp;



puntajes game_score() {
	int d, ci, cj;
	int*q = (int*)malloc(sizeof(int)*n*n*2);
	int*mp = (int*)malloc(sizeof(int)*n*n);
	memset(mp, 0, sizeof(int)*n*n);
	int scores[2];
	scores[0] = 0; scores[1] = 0;
	forn(ci, n) forn(cj, n) if (!mp[ci*n+cj] && (tbl[ci][cj] != -1)) {
		int cs = 0;
		int qp = 0, qe = 0, cu = tbl[ci][cj]%2;
		#define pone(i,j) { mp[(i)*n+(j)]=1; q[qe++] = (i); q[qe++] = (j); }
		pone(ci,cj)
		while (qp < qe) {
			int i = q[qp++], j = q[qp++];
			cs++;
			forn(d,4) {
				int ii = i+ddi[d], jj = j+ddj[d];
				if (enrango(0,ii,n) && enrango(0,jj,n) && tbl[ii][jj] != -1 && tbl[ii][jj]%2 == cu && !mp[ii*n+jj]) { pone(ii,jj); }
			}
		}
		scores[cu] += cs*cs;
		#undef pone
	}
	free(q);
	free(mp);
	puntajes valor = ((puntajes){scores[0], scores[1]});
	return valor;
}

bool hay_vacio_adyacente (int i, int j){
	return ((i-1>=0 && tbl[i-1][j] == -1) || (j-1>=0 && tbl[i][j-1] == -1) || (i+1<n && tbl[i+1][j] == -1) || (j+1<n && tbl[i][j+1] == -1));
}

int puedo_poner_adyacente (int i, int j){
	int cant = 0;
	if (i-1>=0 && tbl[i-1][j] == -1 && hay_vacio_adyacente (i-1,j)){
		cant+= valorady;
	}
	if (j-1>=0 && tbl[i][j-1] == -1 && hay_vacio_adyacente (i,j-1)){
		cant+= valorady;
	}
	if (i+1<n && tbl[i+1][j] == -1 && hay_vacio_adyacente (i+1,j)){
		cant+= valorady;
	}
	if (j+1<n && tbl[i][j+1] == -1 && hay_vacio_adyacente (i,j+1)){
		cant+= valorady;
	}
	return cant;
}
	
int puntuar_movida(){
	puntajes valor = game_score();
	int scores[2];
	scores[0] = valor.rojo;
	scores[1] = valor.verde;
	//cerr << scores[0] << " " << scores [1] << endl;
	forn(i,n){ 
		forn(j,n){
			if (tbl[i][j] == c){
				scores[c] += pow(puedo_poner_adyacente(i,j), valorexp);
			}else if (tbl[i][j] == !c){
				scores[!c] += pow(puedo_poner_adyacente(i,j), valorexp);
			}
		}
	}
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
		int score;
		//if (plies == plies_original+1){
			//score = -calcular_hacia_abajo(-beta, VALOR_MINIMO, arbolrest-1);
		//}else{
			score = -calcular_hacia_abajo(-beta, -alfa, arbolrest-1);
		//}
		if (score >= alfa && plies == plies_original+1){
			if (score > alfa){
				jugadas_finales.clear();
			
			}
            //if(jugadas_finales.size()< 10){			
			jugadas_finales.push_back(jug_a_probar);
			//}
		}
		alfa = max (score, alfa);
		quita_movida(jug_a_probar.fila, jug_a_probar.col, jug_a_probar.orient);
		plies--;
		if (beta <= alfa){
			break;
		}
	}
	if (plies == plies_original){
		cerr << jugadas_finales.size() << " " <<jugposibles.size() << endl;
	} 
	
	return alfa;
	
	
	
	
}

void juega_movida(int k) {
	//board_show();	
	plies_original = plies;
	calcular_hacia_abajo(VALOR_MINIMO, VALOR_MAXIMO, profund);
	int posrand = rand() % (jugadas_finales.size());
	//cerr << jugadas_finales.size() << " " << posrand << endl;
	jugada_actual = jugadas_finales[posrand];
	forn (i, jugadas_finales.size()){
		//cerr << jugadas_finales[i].fila+1 << " " << jugadas_finales[i].col+1 << " " << jugadas_finales[i].orient << endl;
	}
	jugadas_finales.clear();
	aplica_movida(jugada_actual.fila,jugada_actual.col,jugada_actual.orient,k);
	plies++;
	cout << jugada_actual.fila+1 << " " << jugada_actual.col+1 << " " << jugada_actual.orient << endl; return;
	
}

/* Cuando se reciba un SIGTERM se ejecutará esta función. No es necesario
 * hacer nada acá, pero si alguno lo necesita puede hacer alguna tarea acá,
 * como guardar estadísticas del juego, etc. */
void terminar(int) {
	cerr << "Uy!, se acabó el partido!" << endl;
	exit(0);
}

int main(int argc, char* argv[]) {
	signal(SIGTERM, terminar);
	srand (time(NULL));
	profund = atoi (argv[1]);
	valorady = atoi (argv[2]);
	valorexp = atoi (argv[3]);
	cin >> n >> c;
	tbl = vvint(n, vint(n, -1));
	/* Si c==1, arrancamos leyendo una jugada del otro */
	if (n>1 && c) lee_movida(!c);
	while (hay_movida()) {
		juega_movida(c);
		// Si no hay movida para hacer se cuelga leyendo, pero el judge nos mata el proceso con SIGTERM
		lee_movida(!c); 
	}
	return 0;
}


	

