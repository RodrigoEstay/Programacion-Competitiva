#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxState 1<<12
#define maxN 12

//  Codigo obtenido de internet:
//  https://github.com/morris821028/UVa/blob/master/volume104/10496%20-%20Collecting%20Beepers.cpp

// Se trata de un problema de Traveling Sales Person.

// DP almacena las distancias de todos los estados posibles, estos estados estan dados en bits, donde cada
// bit representa si el nodo fue visitado o no, es decir que si visitamos 3 y 0 en bits sera 1001 lo cual en entero es
// 9, y en la otra dimension se indica el ultimo nodo visitado. map es el mapa entregado por el problema.

int DP[maxState][maxN], map[20][20];

// Funcion que retorna el camino mas corto, recibe el estado a revisar, el ultimo nodo visitado y
// la cantidad de nodos. El nodo que nos interesa es el de estado 2^(n+1)-1, ya que se considera
// que donde parte el robot es un nodo (de alli el +1) y el numero anterior indica el entero que
// en bits se traduce a que visitamos todos los nodos. Y el last que nos interesa es el 0, que en
// este caso se refiere al punto de partida. En resumen se le pide el camino mas corto que visite todos
// los nodos y termine en el punto de partida.
// Se resuelve recursivamente donde se va llenando DP hasta poder llenar la posicion de DP[2^(n+1)-1][ultimo nodo].

int TSP(int state, int last, int n) {
	if(state == 0 && last != 0)	return 0xfffff;
	if(DP[state][last] != -1)	return DP[state][last];
	int i, min = 0xfffff, tmp;
	for(i = 0; i <= n; i++) {
		if((state&(1<<i)) != 0) {
			tmp = TSP(state-(1<<i), i, n);
			tmp += map[i][last];
			if(min > tmp)	min = tmp;
		}
	}
	DP[state][last] = min;
	return DP[state][last];
}

// Se escanean los valores y se imprime lo deseado.

int main() {
	int T, x[20], y[20];
	int sizex, sizey, n, i, j;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &sizex, &sizey);
		scanf("%d %d", &x[0], &y[0]);
		scanf("%d", &n);
		for(i = 1; i <= n; i++)
			scanf("%d %d", &x[i], &y[i]);
		for(i = 0; i <= n; i++)
			for(j = 0; j <= n; j++)
				map[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
		memset(DP, -1, sizeof(DP));
		DP[0][0] = 0;
		printf("The shortest path has length %d\n", TSP((1<<(n+1))-1, 0, n));
	}
    return 0;
}
