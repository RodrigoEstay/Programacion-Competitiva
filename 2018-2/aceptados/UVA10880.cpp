#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	vector<long long int> divisors;
	int N;
	cin >> N;
	long long int C, R;

	//  El encontrar las galletas que se podrían comer cada persona es lo mismo que
	// encontrar todos los divisibles de las galletas comidas (ya que se consideran
	// distinto número de personas que atendieron), pero eso toma mucho tiempo, asi
	// que calculamos todos los factores del mismo número, y luego vemos si el
	// número dividido el factor es divisor del número. Ocupamos vetores ya que
	// desconocemos el numero total de divisores, y tambien es mas facil de ordenar.

	for(int i=0;i<N;++i){
		cin >> C >> R;
		printf("Case #%d:", i+1);

		// Ciclo para encontrar divisores.

		for(int j=1 ; j <= sqrt(C-R) ; ++j){
			if( (C-R)%j == 0){ // Encuentra factores.
				if(j > R) divisors.push_back(j); 
				int alt=((C-R)/j); // Encuentra divisores relacionados al factor.
				if( ((C-R)%alt == 0) && alt != j && alt > R) divisors.push_back(alt);
			}
		}

		// Ordenamos e imprimimos.

		sort(divisors.begin(), divisors.end());
		for(vector<long long int>::const_iterator k=divisors.begin() ; k != divisors.end() ; ++k){
			if(k == divisors.begin()) cout << " ";
			cout << *k;
			if(k != divisors.end()-1) cout << " ";
		}
		if(R == C) cout << " " << 0;
		cout << "\n";
		divisors.clear(); // Limpiamos el vector.
	}
	return 0;
}