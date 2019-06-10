#include <bits/stdc++.h>

using namespace std;

int main(){
	int tests, N, **torus, ****rep;
	cin >> tests;
	while(tests--){
		cin >> N;
		*torus = new int[N];
		for(int i=0 ; i<N ; ++i)
			torus[i] = new int[N];
		for(int i=0 ; i<N ; ++i){
			for(int j=0 ; j<N ; ++j)
				cin >> torus[i][j];
		}

		//Llamar a la funcion magica.
		for(int i=0 ; i<N ; ++i)
			delete[] torus[i];
		delete[] torus;
	}
	return 0;
}