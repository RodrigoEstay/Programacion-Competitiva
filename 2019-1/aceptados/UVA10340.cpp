#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	int cont;
	string s, t;

	//  Simplemente buscamos los caracteres de s en t en orden revisando si coinciden,
	// si se encuentra un caracter en s que coincide en t, se avanza en un caracter 
	// en s y en t se sigue desde la posicion que iba.
	//  Si al final no se alcanzo a revisar todo s, entonces el string s no se encontraba
	// dentro de t.

	while(1){
		s.clear();
		t.clear();
		cin >> s >> t;
		cont = 0;
		for(int i=0 ; i<t.length() ; ++i){
			if(t[i] == s[cont]) cont++;
			if(cont >= s.length()) break;
		}
		if(getc(stdin) == EOF) break;
		if(cont == s.length()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}