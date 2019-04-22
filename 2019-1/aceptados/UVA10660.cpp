#include <bits/stdc++.h>

using namespace std;

int placeOffices(vector<int> people, int* off, int it, int pos);
int distances(vector<int>, int* off);

// Solo se escanean los datos y se imprimen lo pedido.

int main(){
	vector<int> people;
	people.resize(25);
 	int n, t, off[5], row, col, am;
	cin >> t;
	while(t--){
		for(int i=0 ; i<25 ; ++i)
			people[i] = 0;
		cin >> n;
		while(n--){
			cin >> row >> col >> am;
			people[row*5+col] = am;
		}
		int aux = placeOffices(people, off, 0, 0);
		for(int i=0 ; i<5 ; ++i){
			if(i != 4) cout << off[i] << " ";
			else cout << off[i] << endl;
		}
	}
	return 0;
}

// Genera todas las posiciones posibles de las oficinas.

int placeOffices(vector<int> people, int* off, int it, int pos){
	if(it == 5) return distances(people, off);
	int min, aux, auxOff[5];
	min = INT_MAX;
	for(int i=0 ; i<5 ; ++i)
		auxOff[i] = off[i];
	for(int i=pos ; i<25 ; ++i){
		auxOff[it] = i;
		aux = placeOffices(people, auxOff, it+1, i+1);
		if(aux < min){
			min = aux;
			for(int j=0 ; j<5 ; ++j)
				off[j] = auxOff[j];
		}
	}
	return min;
}

// Calcula las distancias totales para una secuencias de oficinas.

int distances(vector<int> people, int* off){
	int min, sum, x, aux;
	sum = 0;
	int minPos;
	for(int i=0 ; i<25 ; ++i){
		if(!people[i]) continue;
		min = INT_MAX;
		for(int j=0 ; j<5 ; ++j){
			if(off[j] == i){
				min = 0;
				minPos = off[j];
				break;
			}
			aux = abs(i/5 - off[j]/5) + abs(i%5 - off[j]%5);
			if(aux < min){
				minPos = off[j];
				min = aux;
			}
		}
		sum += min*people[i];
	}
	return sum;
}