#include <iostream>
using namespace std;

void calcular_boxes (int c);

/* empezamos leyendo los parametros del problema */
int main() {
	int cantCajas;
	cin >> cantCajas;
	while (!cantCajas == 0){
		calcular_boxes(cantCajas);
		cin >> cantCajas;
	}
	return 0;
}

/* Inicializamos una matriz con todos los valores en -1 */
void calcular_boxes (int c){
	int matrix[c][c];
	int peso, capac, x;
	for (int i = 0;  i < c; ++ i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j]=-1;
		}
	}

	cin >> peso >> capac;

/* recorremos la matriz en base a sus diagonales invertidas y
 * calculamos los valores de cada celda utilizando resultados obtenidos previamente */
	matrix[0][0] = capac;
	for (int i = 1; i < c; ++i) {
		cin >> peso >> capac;
		x = i;
		for (int j =0; j <= i; j++){
			if (j == 0){
				if (matrix[x-1][j] >= peso){
					matrix[x][j] = min ((matrix[x-1][j] - peso), capac);
				}else{
					matrix[x][j] = -1;
				}
			}else if (x == 0){
					matrix[x][j]= max (matrix[x][j-1], capac);
			}else{
				if (!(matrix[x-1][j] - peso < 0)){
						matrix[x][j] =  max (matrix[x][j-1], (min ((matrix[x-1][j] - peso), capac)));
					}else{
						matrix[x][j] = matrix[x][j-1];
					}
			}
			x--;
		}
	}

/* una vez calculado el valor de toda la matriz,
 * recorremos una sola vez la diagonal invertida
 * de la matriz y obtenemos el primer valor distinto de -1 */
	x = c-1;
	int y= 0;
	while (matrix[x][y] == -1  && y >= 0){
		x--;
		y++;
	}
	 //for (int i = 0;  i < c; ++ i) {
		 //for (int j = 0; j < c; ++j) {
			 //cout << matrix[i][j] << " ";
		 //}
		 //cout << endl;
	 //}
	cout << x+1 << endl;
}

