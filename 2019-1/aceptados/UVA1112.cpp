#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

// Funcion ocupada por Dijkstra.

bool allVisited(int* visited, int size){
	bool a = true;
	for(int i=1 ; i<size ; ++i){
		if(!visited[i]){
			a = false;
			break;
		}
	}
	return a;
}

// Algoritmo de Dijkstra generico.

void dijkstra(int** graph, int size, int node, int* distance){
	int min, minPos;
	int *visited = new int[size];
	for(int i=1 ; i<size ; ++i){
		if(graph[node][i]) distance[i] = graph[node][i];
		else distance[i] = INT_MAX;
		visited[i] = 0;
	}
	distance[node] = 0;
	visited[node] = 1;
	while(!allVisited(visited, size)){
		min = INT_MAX;
		for(int i=1 ; i<size ; ++i){
			if(visited[i]) continue;
			if(distance[i] <= min){
				min = distance[i];
				minPos = i;
			}
		}
		visited[minPos] = 1;
		if(distance[minPos] == INT_MAX) continue;
		for(int i=1 ; i<size ; ++i){
			if(!graph[minPos][i]) continue;
			if(distance[i] > distance[minPos]+graph[minPos][i]) distance[i] = distance[minPos]+graph[minPos][i];
		}
	}
	delete[] visited;
}

//  Solo se crea un grafo tal como lo especifica el problema y luego se realiza Dijkstra en cada
// nodo y luego se revisa la distancia que existe desde aquel nodo hasta la salida segun dijkstra
// y se suma el raton si el tiempo es menor al entregado.

int main(){
	int cases, n, e, t, m, a, b, time, contMices;
	cin >> cases;
	int **graph;
	while(cases--){
		contMices = 0;
		cin >> n >> e >> t >> m;
		graph = new int*[n+1];
		for(int i=0 ; i<=n ; ++i){
			graph[i] = new int[n+1]();
		}
		while(m--){
			cin >> a >> b >> time;
			graph[a][b] = time;
		}
		int *distance = new int[n+1]();
		for(int i=1 ; i<=n ; ++i){
			dijkstra(graph, n+1, i, distance);
			if(distance[e] <= t) contMices++;
		}
		cout << contMices << endl;
		if(cases) cout << endl;
		for(int i=0 ; i<=n ; ++i){
			delete[] graph[i];
		}
		delete[] graph;
	}
	return 0;
}