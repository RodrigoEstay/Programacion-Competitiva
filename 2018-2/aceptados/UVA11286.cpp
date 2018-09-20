#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	map<string ,int> courses;
	int n, tempC[5], i, maxT, winners;
	ostringstream convert; // Usado para pasar de int a string.

	//  como debemos ver cual(es) es(son) el curso mas popular, el problema
	// se trata de un problema de mapas, donde la key sera la combinación única
	// de cursos, y su valor son la cantidad de personas que lo tomaron.

	while(1){
		cin >> n;
		if(n == 0) break;

		// Ciclo usado para calcular la cantidad de alumnos en cada combinacion de cursos.

		for(i=0 ; i<n ; ++i){
			convert.str(string()); // Vaciamos nuestro convertidor.
			cin >> tempC[0] >> tempC[1] >> tempC[2] >> tempC[3] >> tempC[4];
			sort(tempC, tempC+5); // Ordenamos los cursos para asegurarnos de que tengan la misma key.
			convert << tempC[0] << tempC[1] << tempC[2] << tempC[3] << tempC[4];
			courses[convert.str()]++; // Le añadimos un alumno a la combinacion de cursos.
		}
		maxT=0, winners=0;

		// Calculamos la cantidad mas alta de alumnos que tenga una combinacion de cursos.

		for(map<string,int>::iterator j=courses.begin() ; j!=courses.end() ; ++j)
			if(j->second > maxT) maxT=j->second;

		// Calculamos cuantos ganadores hay.

		for(map<string,int>::iterator j=courses.begin() ; j!=courses.end() ; ++j)
			if(j->second == maxT) winners+=j->second;
		cout << winners << "\n";
		courses.clear();
	}
	return 0;
}