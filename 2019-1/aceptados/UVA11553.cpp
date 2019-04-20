#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int maxCandies(int n, int** M, int it, vector<int> v);

// Se escanean todos los datos y se ocupa la funcion maxCandies para resolver el problema.

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int **M;
		vector<int> v;
		M = new int*[n];
		for(int i=0 ; i<n ; ++i){
			M[i] = new int[n];
		}
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<n ; ++j){
				cin >> M[i][j];
			}
		}
		cout << maxCandies(n, M, 0, v) << endl;
	}
	return 0;
}

// Se ocupa busqueda exhaustiva. Luego de analizar el problema conclui que solo
// depende de Bob cuantos caramelos se intercambian, de esta manera se busca la combinacion
// que mas le daria caramelos a Bob, es decir, la que le quite mas caramelos a Alice.

int maxCandies(int n, int** M, int it, vector<int> v){
	if(it == n) return 0;
	int min, x;
	bool exit;
	min = INT_MAX;
	for(int i=0 ; i<n ; ++i){
		exit = false;
		for(int j=0 ; j<it ; ++j){
			if(v[j] == i){
				exit = true;
				break;
			}
		}
		if(exit) continue;
		v.push_back(i);
		x = maxCandies(n, M, it+1, v) + M[it][i];
		if(min > x) min = x;
		v.pop_back();
	}
	return min;
}