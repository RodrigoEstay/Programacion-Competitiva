#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

//  Tenemos que a las latas que les falto disparar a cada uno es igual al numero
// de latas que el otro le disparo menos una lata que es a la que los dos le
// dispararon a la vez.

int main (){
	int h, l;
	scanf("%d%d", &h, &l);
	printf("%d %d\n", l-1, h-1);
	return 0;
}