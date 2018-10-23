#include<bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	int N, Q, query, tempSize;
	vector<int> sizes;
	bool foundShorter, foundTaller;
	cin >> N;

	// Escaneamos las alturas de las monas.

	while(N--){
		cin >> tempSize;
		sizes.push_back(tempSize);
	}
	cin >> Q;

	// Escaneamos las alturas de "query" e imprimimos las alturas pedidas.

	while(Q--){
		foundShorter=false;
		foundTaller=false;
		cin >> query;

		//	 Recorremos el vector de alturas de las monas imprimiendo las que cumplan
		// los requisitos

		for(vector<int>::iterator it=sizes.begin() ; it!=sizes.end() ; it++){

			// 	Si aun no se encuentra la mona mas alta de las mas bajas que el playboy y ademas
			// la mona actual es mas o igual de alta que el playboy, entonces la mona anterior
			// la mona mas alta de las bajas, pero si no hay interior se imprime una X.

			if(!foundShorter && *it>=query){
				if(it==sizes.begin()) cout << "X ";
				else cout << *(it-1) << " ";
				foundShorter=true;
			}

			//  Si se encuentro la mona mas alta de las mas bajas que el playboy y la mona actual
			// es mas alta que el playboy, entonces se trata de la mona mas baja de las mas altas que
			// el mono playboy.

			if(foundShorter && *it>query){
				cout << *it << "\n";
				foundTaller=true;
				break;
			}
		}
		// Si no se encontro una mas alta de las mas bajas que el playboy, esta era la ultima.
		if(!foundShorter) cout << sizes.back() << " ";
		// Si no se encontro una mas baja de las mas altas qie el playboy, se imprime X.
		if(!foundTaller) cout << "X\n";
	}
	return 0;
}