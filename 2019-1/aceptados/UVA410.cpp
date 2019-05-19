#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	int c, s, aux, sum, min, set;
	double imbalance, av;
	vector<int> masses, auxV;
	vector<double> imb;
	set = 1;
	while(cin >> c >> s){
		vector<vector<int> > cent(c);
		sum = 0;
		imbalance = 0;

		// Se guardan las masas y se calcula el total.

		for(int i=0 ; i<s ; ++i){
			cin >> aux;
			sum += aux;
			masses.push_back(aux);
		}

		// Se ordenan las masas y se calcula el promedio.

		sort(masses.begin(), masses.end());
		av = (double)sum / c;

		// 	Calculamos el imbalance inicial de cada chamber (en este imbalance
		// considero que pueden ser negativos).

		for(int i=0 ; i<c ; ++i){
			imb.push_back(-av);
		}

		// Se asignan las masas a los chambers.

		while(!masses.empty()){
			min = -1;

			//  Se busca el chamber de imbalance mas bajo, saltandose los que
			// ya tienen dos masas.

			for(int i=0 ; i<c ; ++i){
				if(cent[i].size() == 2) continue;
				if(min == -1) min = i;
				else if(imb[i] < imb[min]) min = i;
			}
			cent[min].push_back(masses.back());
			imb[min] += masses.back();
			masses.pop_back();
		}

		// Calculamos el imbalance verdadero e imprimimos.

		for(int i=0 ; i<c ; ++i){
			imbalance += abs(imb[i]);
		}
		cout << "Set #" << set << endl;
		set++;
		for(int i=0 ; i<c ; ++i){
			cout << " " << i << ":";
			while(!cent[i].empty()){
				cout << " " << cent[i].back();
				cent[i].pop_back();
			}
			cout << endl;
		}
		printf("IMBALANCE = %.5lf\n\n", imbalance);
		imb.clear();
		cent.clear();
	}
	return 0;
}