#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	int m, n, **matDp;
	vector<pair<int,int> > items;
	pair<int,int> aux;
	while(1){
		cin >> m >> n;

		// Separamos el caso de n=0 ya que no deja crear la matriz y da RE.
		
		if(!n){
			cout << 0 << endl;
			continue;
		}
		if(getc(stdin) == EOF) break;

		// Vemos si es posible tener un reembolso.

		if(m > 1800) m += 200;

		//  Creamos nuestra matriz de programacion dinamica, que almacenara todos
		// los maximos favores de cierta prenda hacia delante (fila) y cierta 
		// plata (columna). Es decir que si la fila es 0 entonces considera todas
		// las prendas, si es n-1 considera la ultima nomas.

		matDp = new int*[n];
		for(int i=0 ; i<n ; ++i){
			matDp[i] = new int[m+1]();
		}
		for(int i=0 ; i<n ; ++i){
			cin >> aux.first >> aux.second;
			items.push_back(aux);
		}
		int val1, val2, maxVal, newMoney;

		// Llenamos la matriz de dp cuando solo se trata la ultima prenda (n-1).

		for(int i=1 ; i<m+1 ; ++i){

			//  Separamos el caso de que el m ingresado (sin el reembolso considerado)
			// se encuentra entre 1800 < m < 2000, ya que aqui se puede comportar raro,
			// porque sabiendo que si m = 1900, nuestro presupuesto seria de 2100, pero
			// si llegamos a 1950 de gastado no nos dan reembolso, ya que no gastamos mas
			// de 2000. Aqui nos aseguramos que lo anterior no ocurra.

			if(m < 2200 && m > 2000){
				newMoney = i - items[n-1].first;
				if(newMoney < 0) newMoney = i;
				if((m - newMoney) <= 2000 && (m - newMoney) > (m - 200)) matDp[n-1][i] = INT_MIN;
				else if(i >= items[n-1].first) matDp[n-1][i] = items[n-1].second;
				else matDp[n-1][i] = 0;
			}

			// Para todos los demas m nos comportamos normales.

			else if(i >= items[n-1].first) matDp[n-1][i] = items[n-1].second;
			else matDp[n-1][i] = 0;
		}

		//  Llenamos la matriz para todas las demas columnas, reutilizando los valores de las
		// columnas ya calculadas.

		for(int i=n-2 ; i>=0 ; --i){
			for(int j=1 ; j<m+1 ; ++j){
				newMoney = j - items[i].first;
				if(newMoney >= 0) val1 = matDp[i+1][newMoney] + items[i].second;
				else val1 = INT_MIN;
				val2 = matDp[i+1][j];
				if(val1 > val2) maxVal = val1;
				else maxVal = val2;
 				matDp[i][j] = maxVal;
			}
		}
		cout << matDp[0][m] << endl;
		items.clear();

		// Liberamos memoria de la matriz.

		for(int i=0 ; i<n ; ++i){
			delete[] matDp[i];
		}
		delete[] matDp;
	}
	return 0;
}
