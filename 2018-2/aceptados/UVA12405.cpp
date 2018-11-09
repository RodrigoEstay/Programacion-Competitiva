#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	int T, N, scarecrows, safeCount, needScare;
	string farm;
	cin >> T;

	//  Lo que ocurre en este ciclo es que declaramos que el tamano de la zona
	// segura maxima es de 3, lo cual es cierto, entonces avanzamos por la granja
	// hasta que encontramos un '.' entonces decimos de que es necesario que se 
	// ponga un espanta pajaros, asi que contamos 3 espacios y se suma un espanta-
	// pajaros y luego reestablecemos la zona segura.

	for(int i=0 ; i<T ; ++i){

		// Valores iniciales y escaneo, no se usa el N, se escanea la granja como string.

		scarecrows=0;
		safeCount=3;
		cin >> N;
		cin >> farm;

		// Recorremos el string.

		for(string::iterator it=farm.begin() ; it<farm.end() ; it++){
			// Si se acaba la zona segura se suma un espantapajaros y se reinicia la zona.
			if(!safeCount) scarecrows++, safeCount=3;
			//  Si la zona segura es del tamano maximo significa que hace poco se puso un
			// éspantapajaros o recien se empezo, asi que no hay necesidad de poner uno aun.
			if(safeCount==3) needScare=0;
			// Si se escanea un '.' se necesita un espantapajaros.
			if(*it=='.') needScare=1;
			// Se va reduciendo la zona segura por cada espacio que se avance desde un '.'.
			if(needScare) safeCount--;
		}
		//  Si se termina el ciclo y se quedo un espacio al final que necesitaba un espantapajaros
		// pero no se alcanzo a poner, aqui se pone.
		if(needScare) scarecrows++;
		cout << "Case " << i+1 << ": " << scarecrows << "\n";
	}
	return 0;
}