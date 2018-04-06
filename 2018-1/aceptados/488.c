#include <stdio.h>
#include <stdlib.h>

int main (){
	int cases, ampl, freq, i, j, k, wave;

	/* Escaneamos el numero de casos, amplitudes y frecuencias. */

	scanf("%d", &cases);
	for(i=0;i<cases;i++){
		scanf("%d%d", &ampl, &freq);
		for(j=0;j<freq;j++){

			/* Con estos ciclos imprimimos las lineas de la ola que van subiendo. */

			for(wave=1;wave<=ampl;wave++){
				for(k=0;k<wave;k++)
					printf("%d", wave);
				printf("\n");
			}

			/* Con estos ciclos imprimimos las lineas de la ola que van descendiendo. */

			for(wave=ampl-1;wave>0;wave--){
				for(k=0;k<wave;k++)
					printf("%d", wave);
				printf("\n");
			}

			/* Este if es para asegurar que cuando termina un caso, no se imprima un salto de
			linea extra. */

			if(i<cases-1 || j<freq-1)
				printf("\n");
		}
	}
	return 0;
}