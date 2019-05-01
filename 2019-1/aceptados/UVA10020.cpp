#include "bits/stdc++.h"

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	int tests, M, aux1, aux2, maxDist, currentPos, bestPos;
	vector<pair<int,int> > lines, path;
	cin >> tests;
	while(tests--){
		path.clear();
		lines.clear();
		cin >> M;

		// Nos aseguramos que el primer valor sea menor.

		while(1){
			cin >> aux1 >> aux2;
			if(!aux1 && !aux2) break;
			if(aux1 < aux2) lines.push_back(make_pair(aux1, aux2));
			else lines.push_back(make_pair(aux2, aux1));
		}
		currentPos = 0;

		// 	Ocupamos greedy para buscar el primer par que empieze antes de la posicion
		// en la que vamos y que recorra la mayor distancia. El while se detiene una
		// vez que se alcanzo M o que no se encuentra una distancia mayor a 0.

		do{
			maxDist = 0;
			for(int i=0 ; i<lines.size() ; ++i){
				if(lines[i].first <= currentPos && lines[i].second > currentPos){
					if(maxDist < lines[i].second - currentPos){
						maxDist = lines[i].second - currentPos;
						bestPos = i;
					}
				}
			}
			if(maxDist){
				path.push_back(lines[bestPos]);
				lines.erase(lines.begin()+bestPos);
			}
			currentPos += maxDist;
		}while(maxDist && currentPos < M);

		// Se imprime lo deseado dependiendo si se alcanzo la meta o no.

		if(currentPos >= M){
			cout << path.size() << endl;
			for(int i=0 ; i<path.size() ; ++i)
				cout << path[i].first << " " << path[i].second << endl;
		}
		else cout << "0\n";
		if(tests) cout << endl;
	}
	return 0;
}