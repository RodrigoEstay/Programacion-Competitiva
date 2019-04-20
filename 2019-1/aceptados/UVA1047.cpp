#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int bestLocations(vector<int> towers, vector<pair<vector<int>, int > > common,
	int* best, int n, int it, int selected);
int checkOverlap(vector<pair<vector<int>, int > > common, int* best, int n);

//  El vector towers almacena las personas que se encuentran en cada ubicacion en orden ascendente,
// el vector de pares de vector de enteros y enteros (es el common, no estoy muy orgulloso de ello)
// almacena todas las intersecciones entre las torres y cuales zonas intersectan y cuantas personas
// se encuentran en esta interseccion.
// 	En el main solo escaneamos y almacenamos datos e imprimimos lo necesario.

int main(){
	int n, amount, aux, m, l, cont;
	cont=1;
	vector<int> towers;
	vector<pair<vector<int>, int > > common;
	vector<int> auxVec;
	while(1){
		cin >> n >> amount;
		int bestTowers[amount];
		if(n == 0 && amount == 0) break;
		for(int i=0 ; i<n ; ++i){
			cin >> aux;
			towers.push_back(aux);
		}
		cin >> m;
		for(int i=0 ; i<m ; ++i){
			cin >> l;
			for(int j=0 ; j<l ; ++j){
				cin >> aux;
				auxVec.push_back(aux);
			}
			cin >> aux;
			common.push_back(make_pair(auxVec, aux));
			auxVec.clear();
		}
		aux = bestLocations(towers, common, bestTowers, amount, 0, 0);
		printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended: ", cont, aux);
		for(int i=0 ; i<amount ; ++i){
			if(i != amount-1) cout << bestTowers[i] << " ";
			else cout << bestTowers[i] << endl << endl;
		}
		cont++;
		towers.clear();
		common.clear();
	}
	return 0;
}

//  Esta funcion crea todas las combinaciones de zonas y ve cual es la que ofrece el servicio al mayor
// numero de personas, luego modifica el arreglo best con la mejor combinacion y retorna el numero
// de personas a la que ofrece el servicio.

int bestLocations(vector<int> towers, vector<pair<vector<int>, int > > common,
	int* best, int n, int it, int selected){
	if(selected == n){
		int sum = 0;
		for(int i=0 ; i<selected ; ++i)
			sum += towers[best[i]-1];
		return sum - checkOverlap(common, best, n);
	}
	if(it == towers.size()) return 0;
	int people1, people2;
	int *auxBest = new int[n];
	for(int i=0 ; i<selected ; ++i)
		auxBest[i] = best[i];
	best[selected] = it+1;
	people1 = bestLocations(towers, common, best, n, it+1, selected+1);
	people2 = bestLocations(towers, common, auxBest, n, it+1, selected);
	if(people2 > people1){
		for(int j=0 ; j<n ; ++j)
			best[j] = auxBest[j];
		return people2;
	}
	return people1;
}

//  Esta funcion revisa cuantas intersecciones existen entre las zonas que recibe y devuelve
// la cantidad de personas que se hayan contado mas de una vez. 

int checkOverlap(vector<pair<vector<int>, int > > common, int* best, int n){
	int sum = 0;
	int cont;
	for(int i=0 ; i<common.size() ; ++i){
		cont = 0;
		for(int j=0 ; j<n ; ++j){
			if(binary_search(common[i].first.begin(), common[i].first.end(), best[j])){
				cont++;
				if(cont > 1) sum += common[i].second;
			}
		}
	}
	return sum;
}