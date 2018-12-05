#include <bits/stdc++.h>

using namespace std;

// 	Ocupe ayuda de internet buscando como generar todas las permutaciones en este lenguaje,
// con lo cual averigue la existencia de next_permutation() en c++.

int main(){
	int n, m, cont, constr[20][3], fir, sec;
	vector<int> group;
	bool valid;

	// Ciclo que se ejecuta hasta que n y m sean 0,

	while(1){
		cont=0;
		group.clear();
		cin >> n >> m;
		if(!n & !m) break;

		// 	Se confecciona el orden del grupo inicial que es de menor a mayor (de 0 a n-1) y se
		// escanean las restricciones y se almacenan en constr.

		for(int i=0 ; i<n ; ++i) group.push_back(i);
		for(int i=0 ; i<m ; ++i) cin >> constr[i][0] >> constr[i][1] >> constr[i][2];

		// Ciclo que crea todas las permutaciones posibles.

		do{

			// 	Se comprueban todas las restricciones en la permutacion actual, asumiendo
			// inicialmente que si cumple con todas las restricciones.

			valid=true;
			for(int i=0 ; i<m ; ++i){
				fir=-1;
				sec=-1;

				// Se recorre la permutacion actual para ver si cumple la restriccion actual.

				for(int j=0 ; j<n ; ++j){
					if(fir==-1 && sec==-1){
						if(group[j]==constr[i][0]) fir=j;
						else if(group[j]==constr[i][1]) sec=j;
					}
					else if(fir!=-1 && group[j]==constr[i][1]) sec=j;
					else if(sec!=-1 && group[j]==constr[i][0]) fir=j;
					if(fir!=-1 && sec!=-1){
						if(constr[i][2]>0 && abs(fir-sec)>constr[i][2]) valid=false;
						else if(constr[i][2]<0 && abs(fir-sec)<-constr[i][2]) valid=false;
						break;
					}
				}

				// Si ya no cumple una restriccion, no sirve comprobar las demas restricciones.

				if(!valid) break;
			}

			// 	Si nunca se comprobo que no cumple alguna restriccion, entonces es valida y se aumenta
			// el contador.

			if(!m || valid) ++cont;
		}while(next_permutation(group.begin(),group.end()));
		cout << cont << "\n";
	}
	return 0;
}