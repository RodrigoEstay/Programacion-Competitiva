#include <stdlib.h>
#include <stdio.h>

int main (){
	int i, j, cycle, maxCycle, temp, j1, i1;
	unsigned long long int n;

	/* Escaeamos hasta el final del archivo. */

	while(scanf("%d %d", &i, &j)!=EOF){
		j1=j, i1=i;

		/*si i es mayor a j hacemos un intercambio de variables. */

		if(i>j){
			temp=j;
			j=i;
			i=temp;
		}
		for(maxCycle=0;i<=j;i++){
			n=i;
			for(cycle=1;n!=1;cycle++){
				if(n%2==1)
					n=3*n+1;
				else
					n=n/2;
			}

			/* Revisamos cual es el ciclo mas alto. */

			if(cycle>maxCycle)
				maxCycle=cycle;
		}
		printf("%d %d %d\n", i1, j1, maxCycle);
		fflush(stdout);
	}
	return 0;
}