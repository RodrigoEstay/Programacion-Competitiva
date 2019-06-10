#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

//  Se analizan las apuestas desde el principio hasta el final, sumando todos los datos
// a gain, si gain llega a ser menor a 0, se iguala gain a 0. Todo el tiempo verificando si
// se encontro un maximo de ganancias. Se retorna el maximo de ganancias.

int winningStreak(vector<int> bets){
	int maxGain, gain;
	maxGain = 0;
	gain = 0;
	for(int i=0 ; i<bets.size() ; ++i){
		gain += bets[i];
		if(gain < 0) gain = 0;
		else if(gain > maxGain) maxGain = gain;
	}
	return maxGain;
}

//  Solo se leen los datos y se imprime lo pedido.

int main(){
	int N, aux, maxGain;
	vector<int> bets;
	while(1){
		cin >> N;
		if(!N) break;
		while(N--){
			cin >> aux;
			bets.push_back(aux);
		}
		maxGain = winningStreak(bets);
		if(maxGain > 0) cout << "The maximum winning streak is " << maxGain << ".\n";
		else cout << "Losing streak.\n";
		bets.clear();
	}
	return 0;
}