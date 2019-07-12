#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

//  En esta función se realiza un BFS en el grafo creado donde la primera palabra
// entregada (de los pares) es el nodo en el que se parte, cuando se llega al nodo
// que es el objetivo (la otra palabra del par) se detiene el algoritmo y calcula
// la distancia con los padres.

int BFS(int start, int obj, vector<vector<int> > adyList){
	queue<int> q;
	int* visit = new int[adyList.size()]();
	int* parent = new int[adyList.size()]();
	q.push(start);
	visit[start] = 1;
	parent[start] = -1;
	int curr;
	while(!q.empty()){
		curr = q.front();
		if(curr == obj) break;
		q.pop();
		for(int i=0 ; i<adyList[curr].size() ; ++i){
			if(!visit[adyList[curr][i]]){
				visit[adyList[curr][i]] = 1;
				q.push(adyList[curr][i]);
				parent[adyList[curr][i]] = curr;
			}
		}
	}
	int cont, p;
	p = parent[obj];
	cont = 0;
	while(1){
		if(p == -1) break;
		p = parent[p];
		cont++;
	}
	delete[] visit;
	delete[] parent;
	return cont;
}

int main(){
	int N, dif;
	vector<vector<int> > adyList;
	adyList.resize(201);
	vector<string> dict;
	string aux, str1, str2;
	char in;
	cin >> N;
	while(N--){

		// Creamos una lista de adyacencia, la limpiamos aca.

		for(int i=0 ; i<201 ; ++i){
			adyList[i].clear();
		}
		dict.clear();

		while(1){
			cin >> aux;
			if(aux == "*") break;
			dict.push_back(aux);
		}

		//  Si es que dos palabras son del mismo largo y varian solo un caracter,
		// estas se encuentran conectadas en el grafo. Cada nodo del grafo es la
		// posición de la palabra en el dictionario.

		for(int i=0 ; i<dict.size()-1 ; ++i){
			for(int j=i+1 ; j<dict.size() ; ++j){
				dif = 0;
				if(dict[i].length() != dict[j].length()) continue;
				for(int k=0 ; k<dict[i].length() ; ++k){
					if(dict[i][k] != dict[j][k]) dif++;
					if(dif > 1) break;
				}
				if(dif < 2){
					adyList[i].push_back(j);
					adyList[j].push_back(i);
				}
			}
		}

		//  Se buscan los pares en el diccionario para encontrar su valor de posicion
		// y se envian a hacer BFS.

		while(1){
			getc(stdin);
			in = getc(stdin);
			str1.clear();
			str2.clear();
			if(in == '\n' || in == EOF) break;
			str1.push_back(in);
			cin >> aux;
			str1 += aux;
			cin >> str2;
			int obj, start;
			for(int i=0 ; i<dict.size() ; ++i){
				if(dict[i] == str1) start = i;
				if(dict[i] == str2) obj = i;
			}
			cout << str1 << " " << str2 << " " << BFS(start, obj, adyList) << endl;
		}
		if(N) cout << endl;
	}
	return 0;
}