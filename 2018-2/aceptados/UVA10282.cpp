#include <bits/stdc++.h>

using namespace std;

// programa hecho sin ayuda.

// 	En resumen se usa un mapa donde la key es la palabra en el idioma desconocido
// y el valor asociado a la key es la palabra en ingles.

int main(){
	map<string,string> wordsDictionary;
	string word1, word2, wordToTranslate, tempWord;
	char check;

	// 	En este ciclo se escanean dos palabras hasta llegar a una linea vacia
	// y se van agregando a nuestro mapa de la manera descrita anteriormente.

	while(true){
		word1.clear();
		word2.clear();
		check=getchar();
		if(check == '\n') break;
		word2.push_back(check);
		cin >> tempWord >> word1;
		word2.append(tempWord);
		wordsDictionary[word1]=word2;
		getchar();
	}

	// 	En este ciclo se escanea la palabra en el lenguaje desconocido y se imprime
	// la palabra asociada en nuestro mapa, y si no existe esa palabra en nuestro mapa
	// se imprime un "eh".

	map<string,string>:: iterator it;
	while(true){
		wordToTranslate.clear();
		check=getchar();
		if(check == EOF) break;
		wordToTranslate.push_back(check);
		cin >> tempWord;
		wordToTranslate.append(tempWord);
		if(wordsDictionary.find(wordToTranslate) == wordsDictionary.end()) cout << "eh\n";
		else cout << wordsDictionary[wordToTranslate] << "\n";
		getchar();
	}
}