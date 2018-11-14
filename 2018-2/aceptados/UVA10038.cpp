#include<bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	char lastChar; 
	int currentValue, lastValue, n, i, dif;
	bool isJolly;
	map<int,int> difsMap;

	// Ciclo infinito que se detiene si se llega a EOF.

	while(1){
		isJolly=true;
		difsMap.clear();
		cin >> n;

		// 	Se lee la secuencia y se calculan diferencias, si la diferencia es
		// menor a 1 o mayor a n-1, no pertenece a una secuencia Jolly ya que
		// las diferencias deben ir desde 1 a n-1. En caso contrario se suma uno
		// a la key "dif" en nuestro mapa.

		for(i=0 ; i<n ; ++i){
			cin >> currentValue;
			if(isJolly && i!=0){
				dif=abs(currentValue-lastValue);
				if(dif<1 || dif>=n) isJolly=false;
				else difsMap[dif]++;
			}
			lastValue=currentValue;
		}

		//  Al recorrer el mapa  por las keys desde 1 hasta n-1 se deberian encontrar
		// solo unos, ya que cada diferencia debe aparecer una vez, en caso contrario
		// no es Jolly.

		if(!isJolly) cout << "Not jolly";
		else{
			for(i=1 ; i<n ; ++i){
				if(difsMap[i]!=1){
					isJolly=false;
				}
			}
			if(isJolly) cout << "Jolly";
			else cout << "Not jolly";
		}
		lastChar=getchar();
		if(lastChar==EOF) break;
		else cout << "\n";
	}
	return 0;
}