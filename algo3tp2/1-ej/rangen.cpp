#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main ()
{
	int cajas, x, y;

  	srand ( time(NULL) );

	cin >> cajas;
	cout << cajas << endl;

	for (int i = 0; i < cajas ; i++){
    	x = rand() % 100;
	y = rand() % 100;
    	cout << x << " " << y << endl;
	}
	cout << 0 << endl;
  return 0;
}
