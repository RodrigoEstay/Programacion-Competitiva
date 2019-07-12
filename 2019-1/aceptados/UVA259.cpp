#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

// Funcion recursiva para encontrat un camino DFS.

void DFSRec(int** graph, int* parent, int* visited, int start){
	for(int i=0 ; i<38 ; ++i){
		if(!graph[start][i] || visited[i]) continue;
		visited[i] = 1;
		parent[i] = start;
		DFSRec(graph, parent, visited, i);
	}
}

// Funcion que prepara el DFS, luego redirige al DFS recursivo.

void DFS(int** graph, int* parent){
	int *visited = new int[38]();
	parent[0] = -1;
	parent[37] = -1;
	visited[0] = 1;
	DFSRec(graph, parent, visited, 0);
	delete[] visited;
}

// Se busca el máximo flujo de programas que pueden correr, donde el 0 es el source y 37 el sink.

int fordFulkenson(int** graph){
	int *parent = new int[38]();
	int current, bottleNeck, maxFlow;
	maxFlow = 0;
	DFS(graph, parent);
	while(parent[37] != -1){
		bottleNeck = INT_MAX;
		current = 37;
		while(parent[current] != -1){
			if(bottleNeck > graph[parent[current]][current]) bottleNeck = graph[parent[current]][current];
			current = parent[current];
		}
		current = 37;

		// Combinamos el grafo recibido con el residual.

		while(parent[current] != -1){
			graph[parent[current]][current] -= bottleNeck;
			graph[current][parent[current]] += bottleNeck;
			current = parent[current];
		}
		maxFlow += bottleNeck;
		delete[] parent;
		parent = new int[38]();
		DFS(graph, parent);
	}
	return maxFlow;
}

int main(){
	string run;
	char app;
	int amount, maxFlow, total;
	bool finish = false;

	//  Nodo 0 es el source, nodo 1 al 26 son las apps de la A a la Z, nodos 27 a 36 son los
	// computadores del 0 al 9, y nodo 37 es el sink.

	int **graph = new int*[38];
	for(int i=0 ; i<38 ; ++i){
		graph[i] = new int[38]();
	}
	while(1){

		//  Se borra el grafo anterior y se inicializa uno nuevo en 0.

		for(int i=0 ; i<38 ; ++i){
			delete[] graph[i];
		}
		for(int i=0 ; i<38 ; ++i){
			graph[i] = new int[38]();
		}

		//  Todos los computadores estan conectados al sink con un flujo maximo de 1.

		for(int i=27 ; i<37 ; ++i){
			graph[i][37] = 1;
		}
		total = 0;

		//  Se lee la aplicacion a correr, si se lee un salto de linea signifaca que termino el caso, si se lee
		// un EOF, terminaron los casos.

		while(1){
			app = getc(stdin);
			if(app == '\n') break;
			if(app == EOF){
				finish = true;
				break;
			}
			cin >> amount >> run;
			getc(stdin);
			total += amount;
			graph[0][app-'A'+1] = amount;

			// Conectamos las apps con los computadores que lo pueden correr.

			for(int i=0 ; i<run.length()-1 ; ++i){
				graph[app-'A'+1][run[i]-'0'+27] = 1;
			}
			run.clear();
		}

		// Se busca el maximo flujo.

		maxFlow = fordFulkenson(graph);
		bool haveProgram;

		// Si el maximo flujo es menor a la cantidad de programas, no es posible ejecutarlos.

		if(maxFlow < total) cout << "!" << endl;

		//  En caso contrario, podemos revisar el grafo para ver que app se ejecuta en cada
		// computador, ya que el grafo lo habra transformado el fordFulkenson, ya que este
		// lo combina con el grafo residual, asi que solo revisamos a que app se encuentra
		// conectada cada computador.

		else{
			for(int i=0 ; i<10 ; ++i){
				haveProgram = false;
				for(int j=1 ; j<27 ; ++j){
					if(graph[27+i][j]){
						cout << (char)('A'+j-1);
						haveProgram = true;
						break;
					}
				}
				if(!haveProgram) cout << "_";
			}
			cout << endl;
		}
		if(finish) break;
	}
	return 0;
}