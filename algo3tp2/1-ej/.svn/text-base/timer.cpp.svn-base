
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
	int ops;
	int matrix[c][c];
	int peso, capac, x;
	for (int i = 0;  i < c; ++ i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j]=-1;
			ops++;
		}
	}

	cin >> peso >> capac;

	matrix[0][0] = capac;
	ops++;
	for (int i = 1; i < c; ++i) {
		cin >> peso >> capac;
		x = i;
		ops+=2;
		for (int j =0; j <= i; j++){
			if (j == 0){
				ops++;
				if (matrix[x-1][j] >= peso){
					matrix[x][j] = min ((matrix[x-1][j] - peso), capac);
					ops+=2;
				}else{
					matrix[x][j] = -1;
					
				}
			}else if (x == 0){
				matrix[x][j]= max (matrix[x][j-1], capac);
				ops+=2;
			}else{
				ops++;
				if (!(matrix[x-1][j] - peso < 0)){
						matrix[x][j] =  max (matrix[x][j-1], (min ((matrix[x-1][j] - peso), capac)));
						ops+=2;
					}else{
						matrix[x][j] = matrix[x][j-1];
						ops+=2;
					}
			}
			x--;
			ops++;
		}
	}

	x = c-1;
	int y= 0;
	ops+=2;
	while (matrix[x][y] == -1  && y >= 0){
		x--;
		y++;
		ops+=3;
	}
	 //for (int i = 0;  i < c; ++ i) {
		 //for (int j = 0; j < c; ++j) {
			 //cout << matrix[i][j] << " ";
		 //}
		 //cout << endl;
	 //}
	cout << "Se hicieron " << ops << " operaciones" << endl;
}

