#include <bits/stdc++.h>

using namespace std;

//  Codigo hecho con la ayuda de un foro... Ya que el problema esta mal planteado.
// En el problema se explica que por cada estudiante que quiere ir de A a B debe
// existir otro que quiera ir de B a A, con esta logica se puede ocupar greedy para
// encontrar para cada par encontrar otro par que sea igual pero inverso, el problema
// es que lo anterior toma dos ciclos anidados, llevando a TLE.
//
//  Y he aqui lo que descubri en internet, que no es necesario que para cada par (A,B)
// debe haber un (B,A), si no que un (X,A), donde X es cualquier numero, entonces me di
// cuenta que el problema se resume a que la secuencia de todas las A ordenadas, debe ser
// igual a todas las B ordenadas.
//
//  Un ejemplo que segun lo planteado en el enunciado se deberia imprimir "NO" pero en
// realidad se imprime "YES" es:
//
// 3
// 1 3
// 3 2
// 2 1
//
//  Notar que para (1,3) no existe (3,1), para (3,2) no existe (2,3) y para (2,1) no existe
// (1,2), pero aun asi debe imprimir "YES".
//
// (fin del desahogo).

int main(){
	int n, a, b;
	vector<int> candA, candB;
	while(1){
		cin >> n;
		candA.clear();
		candB.clear();
		if(!n) break;
		for(int i=0 ; i<n ; ++i){
			cin >> a >> b;
			candA.push_back(a);
			candB.push_back(b);
		}
		if(n%2){
			cout << "NO\n";
			continue;
		}
		sort(candA.begin(), candA.end());
		sort(candB.begin(), candB.end());
		if(candA == candB) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}