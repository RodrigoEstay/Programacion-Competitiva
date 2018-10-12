#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	int N, aux;
	long long int cost, sum;
	vector<int> values;
	while(true){
		cin >> N;
		if(N == 0) break;

		// Escaneamos los números.

		while(N--){
			cin >> aux;
			values.push_back(aux);
		}
		cost=0;

		// Vamos sumando los numeros más pequeños y la suma la devolvemos
		// al vector, luego se vuelve a ordenar el vector y nuevamente se
		// suman los más pequeños, hasta que quede solo un valor, todas las
		// sumas se agregan a cost.

		while(values.size()!=1){
			sort(values.begin() , values.end());
			sum=values.front();
			values.erase(values.begin());
			sum+=values.front();
			values.erase(values.begin());
			values.push_back(sum);
			cost+=sum;
		}
		cout << cost << '\n';
		values.clear();
	}
	return 0;
}