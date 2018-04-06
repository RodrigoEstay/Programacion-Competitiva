#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Codigo hecho por mi cuenta excepto por el algoritmo para encontrar factores comunes,
para el cual me ayudaron un poco para hacerlo eficiente. */

int commonFactor(int a, int b);

int main (){
	int N, i, data[50], ncf, j, pairs;
	double aproxPi;

	/* Escaneamos un N hasta que este sea 0 o se llegue al final del archivo. */

	while(scanf("%d", &N)!=EOF && N){
		pairs=0;
		ncf=0;
		for(i=0;i<N;++i)
			scanf("%d", &data[i]);

		/* Aqui buscamos pares de numeros con los numeros escaneados y cada par lo mandamos a 
		la funcion commonFactor, si esta funcion retorna 1 significa que los pares de numeros
		no tienen factores comunes (ncf es "No Common Factor"). */

		for(i=0;i<N-1;++i){
			for(j=i+1;j<N;++j, ++pairs){
				if(commonFactor(data[i], data[j]))
					++ncf;
			}
		}

		/* Aqui revisamos si es que se encontraron factores comunes. */

		if(ncf){
			aproxPi=sqrt((double) 6*pairs/ncf);
			printf("%.6lf\n", aproxPi);
		}
		else 
			printf("No estimate for this data set.\n");
	}
	return 0;
} 

/* Esta funcion contiene un algoritmo que primero dividen los numeros y
luego se divide el divisor por el resto anterior hasta que se obtenga un resto
igual a 0, en el caso de que el ultimo divisor fue 1 significa que estos
numeros no tenian factores comunes. */

int commonFactor(int a, int b){
	int temp;
	while(a%b){
		temp=b;
		b=a%b;
		a=temp;
	}
	if(b==1)
		return 1;
	else
		return 0;
}