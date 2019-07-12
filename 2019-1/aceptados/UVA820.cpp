#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

// DFS recursivo

void DFSRec(int** graph, int* parent, int* visited, int start, int size){
	for(int i=0 ; i<size ; ++i){
		if(!graph[start][i] || visited[i]) continue;
		visited[i] = 1;
		parent[i] = start;
		DFSRec(graph, parent, visited, i, size);
	}
}

// DFS que prepara valores y redirije a recursivo.

void DFS(int** graph, int* parent, int start, int end, int size){
	int *visited = new int[size]();
	parent[start] = -1;
	parent[end] = -1;
	visited[start] = 1;
	DFSRec(graph, parent, visited, start, size);
	delete[] visited;
}

// Se utilizó el algoritmo de Fford-Fulkenson.

int fordFulkenson(int** graph, int start, int end, int size){
	int *parent = new int[size]();
	int current, bottleNeck, maxFlow;
	maxFlow = 0;
	DFS(graph, parent, start, end, size);
	while(parent[end] != -1){
		bottleNeck = INT_MAX;
		current = end;
		while(parent[current] != -1){
			if(bottleNeck > graph[parent[current]][current]) bottleNeck = graph[parent[current]][current];
			current = parent[current];
		}
		current = end;

		// se anade el residuo al grafo recibido.

		while(parent[current] != -1){
			graph[parent[current]][current] -= bottleNeck;
			graph[current][parent[current]] += bottleNeck;
			current = parent[current];
		}
		maxFlow += bottleNeck;
		delete[] parent;
		parent = new int[size]();
		DFS(graph, parent, start, end, size);
	}
	return maxFlow;
}

//  Simplemente se representa el grafo como especifica el problema y se utiliza Fford-Fulkenson.
// Debido a que es un grafo no dirigido, lo trataremos como dirigido para el correcto funcionamiento
// del algoritmo de Fford-Fulkenson.

int main(){
	int n, s, t, c, node1, node2, band, totalBand, cont;
	int **graph;
	cont = 1;
	while(1){
		cin >> n;
		if(!n) break;
		graph = new int*[n];
		for(int i=0 ; i<n ; ++i){
			graph[i] = new int[n]();
		}
		cin >> s >> t >> c;

		//  Como puede existir mas de un camino entre dos nodos, se suman los anchos de bandas.

		while(c--){
			cin >> node1 >> node2 >> band;
			graph[node1-1][node2-1] += band;
			graph[node2-1][node1-1] += band;
		}
		totalBand = fordFulkenson(graph, s-1, t-1, n);
		cout << "Network " << cont << endl << "The bandwidth is " << totalBand << ".\n\n";
		for(int i=0 ; i<n ; ++i){
			delete[] graph[i];
		}
		delete[] graph;
		cont++;
	}
	return 0;
}