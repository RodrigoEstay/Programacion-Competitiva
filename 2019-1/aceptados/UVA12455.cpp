#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda el semestre pasado.

int main(){
	int t, n, p, bars[20], sum, max;
	cin >> t;

	// 	Lo que se hace es calcular la suma de todas las combinaciones
	// posibles de barras para ver si es igual a la deseada, para
	// crear estas combinaciones ocupamos un numero que va desde el 0
	// hasta el numero formados por p bits seguidos con el valor 1 que
	// llamamos max, luego revisamos si en cada bit si hay un 1, si lo
	// hay se suma el largo de la barra almacenado en el arreglo en la
	// misma posicion que el bit analizado.

	while(t--){
		cin >> n >> p;
		max=0;

		// Se escanean las barras y se define el valor max.

		for(int i=0 ; i<p ; ++i){
			cin >> bars[i];
			max+=(1<<i);
		}

		// Creamos todos los valores de 0 hasta max.

		for(int i=0 ; i<=max ; ++i){
			sum=0;

			// 	Si la posicion analizada tiene un 1, se suma a sum el
			// largo de la barra de la misma posicion en bars.

			for(int j=0 ; j<p ; ++j){
				if(i & (1<<j)) sum+=bars[j];
			}
			if(sum==n){
				cout << "YES\n";
				break;
			}
		}
		if(sum!=n) cout << "NO\n";
	}
}