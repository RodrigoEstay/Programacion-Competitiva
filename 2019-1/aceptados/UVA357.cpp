#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	int n;

	// long long ya que llega a valores muy altos pasados los 20000.

	long long int coins[5] = {1, 5, 10, 25, 50};

	// 	En la siguiente matriz en la posicion i, j se almacena la distintas formas de
	// dar el cambio de i en monedas de j (del arreglo coins) hacia abajo. Es decir
	// que con i=17 y j=1 nos da las formas distintas de dar el cambio con monedas de
	// 5 y 1 nomas.

	long long int **comb = new long long int*[30001];
	for(int i=0 ; i<30001 ; ++i){
		comb[i] = new long long int[5]();
	}

	// Las formas de dar el cambio de 0 es 1 para que se cumpla la forma a llenar la matriz.

	for(int i=0 ; i<5 ; ++i){
		comb[0][i] = 1;
	}

	//  El numero de formas de dar el cambio i depende de las distintas formas que se pueden dar el
	// cambio usando cada moneda, y las formas de dar el cambio usando las monedas coins[j] es igual 
	// a las formas que se dio el cambio usando monedas coins[j] hacia abajo en la posicion i-coins[j]
	// (para que no ocurran combinaciones repetidas). De esta manera las maneras totales de dar el
	// cambio para i estara almacenado en comb[i][4].

	for(int i=1 ; i<30001 ; ++i){
		comb[i][0] = 1;
		for(int j=1 ; j<5 ; ++j){
			if(coins[j] > i) comb[i][j] = comb[i][j-1];
			else comb[i][j] = comb[i][j-1] + comb[i-coins[j]][j];
		}
	}

	//  Imprimimos lo que se nos pide.

	while(1){
		cin >> n;
		if(getc(stdin) == EOF) break;
		if(comb[n][4] == 1) cout << "There is only 1 way to produce " << n << " cents change.\n"; 
		else cout << "There are " << comb[n][4] << " ways to produce " << n << " cents change.\n";
	}
	return 0;
}