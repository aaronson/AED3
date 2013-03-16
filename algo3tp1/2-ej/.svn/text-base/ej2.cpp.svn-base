#include <stdlib.h> 
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <queue>

#define print(x) cout << (x) << endl

using namespace std;

int resolver (list<int >);
void printlist (list<int > );
list<int > hallarMedianas (list<int >); 

int main(void)
{
  string line;
  //ifstream entrada ("input.txt");
  //ofstream salida;
  //salida.open ("output.txt");
  list <int > ls;
  list<int > res;
  int a;
  //if (entrada.is_open())
  //{
    // Leo los valores del archivo input.txt
    while (cin >> a) {
        ls.push_back(a);
      }

    res = hallarMedianas(ls);       // Funcion que resuelve el problema luego de obtener los datos
    
    // Escribo la lista obtenida en res, en el archivo output.txt, con el formato correspondiente
    while (!res.empty()) {
    	cout << res.front() << endl;
    	res.pop_front();
 	}
}

list<int > hallarMedianas (list<int > ls) {
  // inicializo variables
	list<int> res;
	list<int>::iterator it; 
	priority_queue<int> maxh;
	priority_queue<int, vector <int>, greater<int> > minh;
	int medio = 0, cant = 0, prom;
  
	for (it = ls.begin(); it != ls.end(); it++){
		cant++;
    // tratamos los casos que la cantidad de elementos es par
		if (cant % 2 == 0){
      // si el numero es mayor al medio, lo ponemos en el min heap y el medio en el max heap
			if (*it > medio){
				maxh.push (medio);
				minh.push(*it);
				medio = 0;
				prom = (maxh.top() + minh.top())/2;
				res.push_back(prom);
      // si el numero es menor o igual al medio lo ponemos en el max heap y el medio en el min heap
			}else {
				minh.push(medio);
				maxh.push(*it);
				medio = 0;
				prom = (maxh.top() + minh.top())/2;
				res.push_back(prom);
			}
    // tratamos los casos que la cantidad de elementos es impar
		}else{
      // caso solo un elemento
			if (cant == 1){
				medio = *it;
				res.push_back(medio);
			}else{
        // si el tope del min heap es menor al valor entonces este tope es la media
				if (minh.top() < *it){
					medio = minh.top();
					minh.pop();
					minh.push(*it);
					res.push_back(medio);
        // si el tope del max heap es mayor al valor, entonces este tope es la media
				}else if(maxh.top() > *it){
					medio = maxh.top();
					maxh.pop();
					maxh.push(*it);
					res.push_back(medio);
				}else{
					medio = *it;
					res.push_back(medio);
				}
			}			
		}
	}
  return res;
}

void printlist (list<int > ls) {
  while (!ls.empty()) {
    print(ls.front());
    ls.pop_front();
  }
}
