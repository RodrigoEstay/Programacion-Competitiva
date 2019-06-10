#include <bits/stdc++.h>

using namespace std;

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