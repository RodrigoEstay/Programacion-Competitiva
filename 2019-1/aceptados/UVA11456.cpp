#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

// Esta funcion recibe los pesos de los autos y retorna la secuencia mas larga posible.

int longestTrain(vector<int> weights){

	// Si el total de autos es 0 se retorna 0, y si es 1 se retorna 1.

	if(weights.empty()) return 0;
	if(weights.size() == 1) return 1;

	//  lenInc es un vector de pares de enteros, donde el primer entero almacena el largo de su
	// longest increasing subsequence (LIS), y el segundo es la posicion del menor valor de la secuencia
	// anterior.
	// lenDec es un vector de enteros que almacena el largo de su longest decreasing subsequence (LDS).

	vector<pair<int,int> > lenInc;
	vector<int> lenDec;
	for(int i=0 ; i<weights.size() ; ++i){
		lenInc.push_back(make_pair(1,-1));
		lenDec.push_back(1);
	}

	// Llenamos lenDec.

	for(int i= weights.size()-2 ; i>=0 ; --i){
		for(int j=weights.size()-1 ; j>i ; --j){
			if(weights[j] < weights[i] && lenDec[i] < lenDec[j]+1) lenDec[i] = lenDec[j]+1;
		}
	}

	//  Llenamos lenInc, donde se obtienen los largos de la LIS de manera tradicional pero tomando
	// en cuenta los largos de las LDS para observar que valores tendra en los pares.

	int pos1, pos2;
	for(int i=1 ; i<weights.size() ; ++i){
		pos1 = i;
		for(int j=0 ; j<i ; ++j){
			if(lenInc[j].second == -1) pos2 = j;
			else pos2 = lenInc[j].second;
			if(weights[j] < weights[i] && lenInc[i].first+lenDec[pos1]-1 < lenInc[j].first+lenDec[pos2]){
				lenInc[i].first = lenInc[j].first+1;
				lenInc[i].second = pos2;
				pos1 = pos2;
			}
		}
	}
	
	//  Buscamos la mayor suma del largo de la LIS y el largo de la LDS del menor valor de la LIS
	// menos 1 (por el valor repetido) y lo retornamos.

	int max, auxMax;
	if(lenInc[0].second == -1) max = lenInc[0].first + lenDec[0] - 1;
	else max = lenInc[0].first + lenDec[lenInc[0].second] - 1;
	for(int i=1 ; i<weights.size() ; ++i){
		if(lenDec[lenInc[i].second] == -1) auxMax = lenInc[i].first + lenDec[i] - 1;
		else auxMax = lenInc[i].first + lenDec[lenInc[i].second] - 1;
		if(auxMax > max) max = auxMax;
	}
	return max;
}

// Solo se leen los datos y se imprime lo deseado.

int main(){
	int tests, n, aux;
	vector<int> weights;
	cin >> tests;
	while(tests--){
		cin >> n;
		while(n--){
			cin >> aux;
			weights.push_back(aux);
		}
		cout << longestTrain(weights) << endl;
		weights.clear();
	}
	return 0;
}