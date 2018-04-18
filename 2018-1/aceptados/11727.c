#include <stdlib.h>
#include <stdio.h>

/* Programa hecho completamente por cuenta propia. */

int main (){
	int T, min, j, i, max, salaries[3];
	scanf("%d", &T);
	for(i=0, max=0, min=0;i<T;++i){

		/* Escaneamos los salarios y los almacenamos en un arreglo, luego recorremos el arreglo
		para encontrar la posicion del valor maximo y minimo, (asumimos que la posicion de estos
		es 0 inicialmente). */

		scanf("%d%d%d", &salaries[0], &salaries[1], &salaries[2]);
		for(j=0;j<3;++j){
			if(salaries[max]<salaries[j])
				max=j;
			if(salaries[min]>salaries[j])
				min=j;
		}

		/* Luego la posicion del salario intermedio, no va a ser ni el de la posicion maxima ni el
		de la minima, asi la posicion del salario itermedio va a ser la de 3-max-min, por ejemplo,
		si el minimo es el 2 y el maximo es el 0, entonces la posicion del intermedio sera 3-2-0=1,
		lo cual es cierto. nose porque funciona exactamente, se me ocurrio pensando como hacer
		este programa mas eficiente. */

		printf("Case %d: %d\n", i+1, salaries[3-max-min]);
	}
	return 0;
}