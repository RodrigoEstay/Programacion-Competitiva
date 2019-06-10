#include <bits/stdc++.h>

using namespace std;

int longestTrain(int pos, vector<int> weights, int** rep){
	if(pos == weights.size()) return 0;
}

int main(){
	int tests, n, **rep;
	cin >> tests;
	while(tests--){
		cin >> n;
		rep = new int*[n];
		for(int i=0 ; i<n ; ++i)
			rep[i] = new int[n](0);
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<n ; ++j)
				cout << rep[i][j] << " ";
			cout << endl;
		}

		for(int i=0 ; i<n ; ++i)
			delete[] rep[i];
		delete[] rep;
	}
	return 0;
}