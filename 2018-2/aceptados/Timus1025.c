#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

int cmpfnc(const void* a, const void* b);

int main(){
	int k, i, supp=0;
	scanf("%d", &k);
	int groups[k];
	for(i=0;i<k;++i) scanf("%d", &groups[i]);

	// Ordenamos de menor a mayor.

	qsort(groups, k, sizeof(int), cmpfnc);

	// 	Sumamos las mitades de la primera mitad de los elementos(aproximado a la unidad), 
	// obteniendo asi el minimo solicitado.

	for(i=0;i<=k/2;++i) supp+=groups[i]/2+1;
	printf("%d\n", supp);
	return 0;
}

// Funcion de comparacion para el qsort.

int cmpfnc(const void* a, const void* b){
	return *(int*)a-*(int*)b;
}