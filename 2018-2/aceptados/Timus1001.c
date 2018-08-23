#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Programa hecho sin ayuda.

int main(){

	// reservamos mucho mas que 256 kB de datos solo para asegurarse

	double *nums = (double*)malloc(sizeof(double)*256*1024);
	int i=0, f;

	// Mientras no se llegue al final del archivo se siguen escaneando flotantes.

	while(f=scanf("%lf", &nums[i])!=EOF) ++i;

	// Avanzamos por nuestro arreglo del final al principio imprimiendo sus raices.
	
	for(--i;i>=0;--i) printf("%.4lf\n", sqrt(nums[i]));
	return 0;
}