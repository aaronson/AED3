#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main ()
{
	int num;

  srand ( time(NULL) );

	for (int i = 0; i < 100000 ; i++){
    	num = rand() % 1000;
    	cout << num << endl;
	}
  return 0;
}
