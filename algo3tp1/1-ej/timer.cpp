#include <stdlib.h> 
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

typedef pair <int, int> interv;
typedef list <interv> linv;
typedef vector <interv> vinv;

pair <bool, linv> intervalos (linv ls, int tope);
double ops = 0;

int main () {
  string line;
  //ifstream entrada ("input1.txt"); // Indicamos  el archivo de entrada
  //ofstream salida;
  //salida.open ("output1.txt"); // Abrimos el archivo de salida
  int times, tope;
  linv ls;
  interv itv;
  //int fst, snd;
  pair <bool, linv > resultado;
  //if (entrada.is_open())
  //{
	/* INCIO LEVANTADA DE DATOS
	Levantamos los datos de entrada segun el formato indicado
	*/
      //getline (entrada,line); 
      cin >> times;
      //getline (entrada, line);
      int i = 0;
      //while (times > 0){
			//getline (entrada,line);
			cin >> tope;
			//getline (entrada, line, ' ');
			while (true){
					cin >> itv.first;
					cin >> itv.second;
					//itv.first = atoi (line.c_str());
					//getline (entrada, line);
					//itv.second = atoi (line.c_str());
					if (itv.first == 0 && itv.second == 0){
						break;
					}
					ls.push_back(itv); // Guardamos en una lista una tupla de los datos internos  FIRST = Valor inicial, SECOND = Valor Final
					i++;
					//getline (entrada, line, ' ');
				   
			}
			
		// FIN LEVANTADA DE DATOS
			resultado = intervalos(ls, tope); // Mandamos a intervalos la lista 
		// INICIO ARMADO ARCHIVO DE SALIDA
			//if (resultado.first){
				//cout << resultado.second.size() << endl;
				//while (!resultado.second.empty()){
					//cout << resultado.second.front().first << " " << resultado.second.front().second << endl;
					//resultado.second.pop_front();
				//}
			//}else{
				//cout << "0" << endl;
			//}
			cout << "Se hicieron " << (long) ops << " operaciones" << endl;
			//ls.clear();
			//while (!ls.empty()){
				//ls.pop_back();
			//}
			//times--;
			//if (times > 0){
				//cout << endl;
			//}
			//getline (entrada, line);
		//}
		//FIN ARMADO ARCHIVO DE SALIDA	
    //entrada.close();
    //salida.close();
  

  //else cout << "Unable to open file"; 

  return 0;
}

pair <bool, linv> intervalos(linv ls, int tope) {
	int tam = ls.size();
	ls.sort(); 
	ops += tam * log(tam);
	pair <bool, linv >  res;
	vinv vec;
	interv p = ls.front();
	ops++;

	while (!ls.empty()){
		ops++;
		while (ls.front().first == p.first){
			ops++;
			if (ls.front().second > p.second) {
				p = ls.front();
				ops++;
			}
			ops++;
			if (!ls.empty()){
				ls.pop_front();
				ops++;
			}else{
				break;
			}
			ops++;
		}
		vec.push_back(p);
		ops++;
		if (!ls.empty()){
			p = ls.front();
			ops++;
		} 
		ops++;
	}
	if (vec.empty() || vec[0].first > 0){
		res.first = false;
		ops+=2;
		return res;
		
	}
	ops++;

	
	unsigned int i= 0;
	unsigned int posmax = 0;
	int target = vec[0].second; 
	ops+=3;
	
	while (i < vec.size() && vec[i].first <= 0){ 
		ops++;
		if (vec[i].second > vec[posmax].second){
			 	posmax = i;
			 	ops++;
		}
		ops++;
		i++;
	}
	ls.push_back(vec[posmax]);
	ops++;
	if (vec[posmax].second >= tope){ 
		res.first = true;
		res.second = ls;
		return res;
		ops+=3;
	}
	ops++;
	target = vec[posmax].second;
	int cant = 0;
	bool entro = false;
	ops+=3;

	while (i < vec.size()){ 
		ops++;
		entro = false;
		ops++;
		while (i < vec.size() && vec[i].first <= target){ 
			ops++;
			if (vec[i].second > vec[posmax].second){ 
			 	posmax =i;
			 	ops++;
			}
			ops++;
			i++;
			cant++;
			entro = true; 
			ops+=3;
		}
		ls.push_back(vec[posmax]); 
		ops++;
		if (vec[posmax].second >= tope){ 
			ops++;
			res.first = true;
			res.second = ls;
			ops+=2;
			return res;
		}
		if(!entro){ 
			i++;
			ops++;
		}
		ops++;
		target =vec[posmax].second; 
		ops++;
		
		
	}
	res.first = false;
	ops++;
	return res;
}
