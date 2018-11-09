#include <bits/stdc++.h>

using namespace std;

// codigo hecho sin ayuda.

int main(){
	int t, n, currentSerial, maxBagSize, i, limit;
	vector<int> serials;
	map<int,int> check;
	cin >> t;

	//  Este codigo se hizo un poco a la fuerza... Lo que se hace es hacer un
	// vector y un mapa, el mapa revisa si se repitio algun valor mientras que
	// el vector solo almacena los valores, si no se repite un valor, el mapa
	// almacena la posicion del vector, si es que el valor ya tiene almacenada
	// una posicion significa que este se repitio, asi que limpiamos el mapa y
	// empezamos a repetir el proceso pero empezando desde el valor siguiente
	// al que se repitio, todo este tiempo revisando si el largo que se obtuvo
	// es mayor que el maximo anterior.

	while(t--){
		check.clear();
		serials.clear();
		maxBagSize=0;
		limit=0;
		cin >> n;
		while(n--){
			cin >> currentSerial;
			serials.push_back(currentSerial);
		}
		for(i=0 ; i<serials.size() ; ++i){
			if(check[serials[i]]){
				if(maxBagSize<i-limit) maxBagSize=i-limit;
				i=check[serials[i]]-1;
				limit=i+1;
				check.clear();
				continue;
			}
			check[serials[i]]=i+1;
		}
		if(maxBagSize<i-limit) maxBagSize=i-limit;
		cout << maxBagSize << "\n";
	}
	return 0;
}