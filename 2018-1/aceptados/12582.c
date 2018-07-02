#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Programa hecho sin ayuda.

int cmpfunc (const void * a, const void * b);

// Almacena la informacion de los sprinklers.

struct sprinkler{
	int paths;
	char label;
};

int main(){
	int T, len, i, j, pathCount, sprinklersCount, ends[10000], skip;
	char data[10000], pathTo=0;
	scanf("%d", &T);
	int max=T;
	while(T--){
		scanf("%s", data);
		len=strlen(data);
		int n=len/2;
		struct sprinkler sprin[n];

		// Con estos ciclos calculamos los caminos de cada sprinkler.

		for(i=0, sprinklersCount=0;i<len;++i){
			skip=0;

			// Revisamos si volvio al mismo sprinkler.

			for(j=0;j<sprinklersCount;++j){
				if(ends[j]==i){
					skip=1;
					break;
				}
			}
			if(skip) continue;

			// Si es un camino nuevo, se ejecta este ciclo que analiza si se le suman caminos
			// a los sprinklers.

			for(j=i+1, pathCount=0;j<len;++j){
				if(data[j]==data[i]) break;
				if(i==0 && j==1) --pathCount;
				if(!pathTo) pathTo=data[j];
				else if(pathTo==data[j]) pathTo=0, ++pathCount; 
			}
			ends[sprinklersCount]=j;
			sprin[sprinklersCount].label=data[i];
			sprin[sprinklersCount].paths=pathCount+1;
			++sprinklersCount;
		}

		// Ordenamos los sprinkler por orden alfabetico y los imprimimos.

		printf("Case %d\n", max-T);
		qsort(sprin, sprinklersCount, sizeof(struct sprinkler), cmpfunc);
		for(i=0;i<sprinklersCount;++i) printf("%c = %d\n", sprin[i].label, sprin[i].paths);
	}
	return 0;
}

// Funcion usada para ordenar los sprinkler en orden alfabetico.

int cmpfunc(const void *a, const void *b){
	struct sprinkler *c=(struct sprinkler *)a, *d=(struct sprinkler *)b;
	int dif=c->label - d->label;
	return dif;
}