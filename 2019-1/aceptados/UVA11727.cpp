#include <bits/stdc++.h>

using namespace std;

// Codigo hecho solo.

// 	Simplemente creamos un vector que almacena los datos y los ordena, luego se imprime
// el que este en la posicion 1.

int main(){
	int T, temp;
	vector<int> sal;
	cin >> T;
	for(int i=0 ; i<T ; ++i){
		sal.clear();
		for(int i=0 ; i<3 ; ++i){
			cin >> temp;
			sal.push_back(temp);
	    }
		sort(sal.begin(), sal.end());
		printf("Case %d: %d\n", i+1, sal[1]);
	}
	return 0;
}