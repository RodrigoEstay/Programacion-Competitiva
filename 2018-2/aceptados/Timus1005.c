#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

int main(){
	int n, i, j, minDif=-1, dif, comp;
	scanf("%d", &n);
	int stones[n];
	for(i=0;i<n;++i) scanf("%d", &stones[i]);

	//  En los siguientes ciclo se forman todas las combinaciones posibles de dos pilas
	// de rocas, se hace a traves del manejo de bits, primero partimos con una secuencia
	// de bits de largo n de solo unos, a excepcion del ultimo bit que sera un 0 (ya que
	// no nos intereza la combinacion que todas las piedras estan en una sola pila), luego
	// le restamos 1 al numero que forma la secuencia de bits para terminar formando tods
	// las secuencias posibles de bits de ese largo.
		
	//  Luego en el siguiente ciclo recorremos esta secuencia con la operacion & para ver
	// si el bit analizado es un 0 o 1, luego si es 1 se suma a la diferencia de las pilas,
	// en el caso contrario se restan.

	for(i=(1<<n)-2;i>0;--i){
		dif=0;
		for(j=0, comp=1;j<n;comp=comp<<1, ++j){
			if(comp&i) dif+=stones[j];
			else dif-=stones[j];
		}
		if(minDif==-1 || abs(dif)<minDif) minDif=abs(dif);
		if(minDif==0) break;
	}

	// Excluimos el caso de n=1 ya que con ese valor no se ejecutan los ciclos anteriores.

	if(n==1) printf("%d\n", stones[0]);
	else printf("%d\n", minDif);
	return 0;
}
