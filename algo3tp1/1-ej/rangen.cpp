#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main ()
{
	int num, num2, cant;

 	srand ( time(NULL) );

	cout << 10 << endl << endl;
	for (int i =0 ; i< 10; i++){
		num = rand() % 50;
		cout << num << endl;
		cant = 30; 
		num2 = rand() % 50;
		cout << 0 << " " << num2 << endl;
		for (int j = 0; j< cant; j++){
			num = rand() % 60;
			num2 = rand() % 60 + num;
			cout << num << " " << num2 << endl;
		}
		cout << "0 0" << endl << endl;
	}	
  	//for (int i = 0; i < 100; i++){
    	//num = rand() % 1000;
    	//cout << num << endl;
	//}
  return 0;
}
