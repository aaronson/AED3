#include <stdlib.h> 
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main () {
  string line;
  ifstream entrada ("input.txt");
  int times, tope;
  vector <pair <int, int> > vec;
  pair <int, int> itv;
  if (entrada.is_open())
  {
    while (! entrada.eof() )
    {
      getline (entrada,line);
      //cout << line << endl;
      times = atoi(line.c_str());
      cout << "Tengo que hacer " << times << " operaciones" << endl;
      getline (entrada, line);
      int i = 0;
      while (times > 0){
			getline (entrada,line);
			tope = atoi (line.c_str());
			
			while (line != ""){
				getline (entrada, line);
				itv.first = atoi (line.c_str());
				cout << line << "end" << endl;
				//cout << itv.first << endl;
				vec.push_back(itv);
				cout << vec[i].first << endl;
				i++;
				
			}
			times--;
		}
    }
    entrada.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}

