#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda

//  Se realiza un BFS que modifica el grafo dependiendo del nodo fuente incial, asi
// teniendo todas las distancias totales a todos los nodos desde el fuente.

void BFS(int** graph, int start){
	int origin, current, it;
	int *visited = new int[100]();
	queue<pair<int,int> > toExplore;
	pair<int,int> aux;
	visited[start] = 1;
	origin = start;
	toExplore.push(make_pair(start,1));
	while(!toExplore.empty()){
		aux = toExplore.front();
		toExplore.pop();
		current = aux.first;
		it = aux.second;
		for(int i=0 ; i<100 ; ++i){
			if(graph[current][i] != 1 || visited[i]) continue;
			visited[i] = 1;
			toExplore.push(make_pair(i,it+1));
			graph[origin][i] = it;
		}
	}
	delete[] visited;
}

int main(){
	int a, b, sum, cases, combinations, cont;
	int ** graph;
	graph = new int*[100];
	cases = 1;
	while(1){
		cont = 0;
		for(int i=0 ; i<100 ; ++i){
			graph[i] = new int[100]();
		}
		while(1){
			cin >> a >> b;
			if(!a && !b) break;
			graph[a-1][b-1] = 1;
			cont++;
		}
		if(!cont) break;
		for(int i=0 ; i<100 ; ++i){
			BFS(graph, i);
		}
		sum = 0;
		combinations = 0;

		// Se observa cuantos caminos se encontraron y se suman sus largos.

		for(int i=0 ; i<100 ; ++i){
			for(int j=0 ; j<100 ; ++j){
				if(graph[i][j]){
					sum += graph[i][j];
					combinations++;
				}
			}
		}
		printf("Case %d: average length between pages = %.3f clicks\n", cases, ((float)sum)/((float)combinations));
		for(int i=0 ; i<100 ; ++i){
			delete[] graph[i];
		}
		cases++;
	}
	for(int i=0 ; i<100 ; ++i){
		delete[] graph[i];
	}
	delete[] graph;
	return 0;
}