#include <iostream>
#include <vector>
#include <cstdlib>
#include <signal.h>
#include <list>
#include <stdio.h>
#include <string.h>



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
	
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<jugada> vjug;
typedef list<jugada> ljug;


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
int plies = 0;
int plies_original;


int game_score() {
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
	int result = scores[0]-scores[1];
    if (plies%2) result *=-1;
    return result;	
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


int calcular_hacia_abajo (int alfa, int beta){

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
	if (jugposibles.empty()){
		int res = game_score();
		//cerr << res << " ";
		return res;
	}
	forn(i,jugposibles.size()){
		jugada jug_a_probar = (jugposibles[i]);
		aplica_movida(jug_a_probar.fila, jug_a_probar.col, jug_a_probar.orient, plies%2);
		plies++;
		//cerr << plies;
		int score = -calcular_hacia_abajo(-beta, -alfa);

		if (score > alfa && plies == plies_original+1){
			jugada_actual = jug_a_probar;
		}
		alfa = max (score, alfa);
		quita_movida(jug_a_probar.fila, jug_a_probar.col, jug_a_probar.orient);
		plies--;
		if (beta <= alfa){
			break;
		}
	}
	
	return alfa;
	
	
	
	
}

void juega_movida(int k) {
	//board_show();	
	plies_original = plies;
	calcular_hacia_abajo(VALOR_MINIMO, VALOR_MAXIMO);
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


	
