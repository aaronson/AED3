#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main ()
{
	int players, internetes, x, y;

  	srand ( time(NULL) );

	cin >> internetes;
	cin >> players;
	cout << 1 << endl;
	cout << internetes << " " << players<<endl;

	for (int i = 0; i < players ; i++){
    	x = rand() % 10000;
	y = rand() % 10000;
    	cout << x << " " << y << endl;
	}
  return 0;
}
