#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Programa hecho totalmente por mi. */

int main(){
	char c[7000000];
	int num=0, i, neg=0, start=-1, doubleScan, constants[2000], x[2000], cCont, xCont, end=0, j, k;
	long long int sum;
	scanf("%[^EOF]", c);
	while(1){

		/* En esta parte escaneamos hasta el cambio de linea y luego lo asignamos al vector de c o
		al vector de x, (dependiendo si es el primer escaneo o el segundo). */

		for(doubleScan=0, xCont=0, cCont=0;doubleScan<2;++doubleScan){
			for(i=start+1;;++i){
				if(c[i]=='-')
					neg=1;
				else if(c[i]>='0' && c[i]<='9')
					num=num*10+c[i]-'0';
				else{
					if(neg)
						num=-num;
					if(doubleScan==0){
						constants[cCont]=num;
						++cCont;
					}
					else if(doubleScan==1){
						x[xCont]=num;
						++xCont;
					}
					num=0;
					neg=0;

					/* Si es que se llega a un cambio de linea, salimos del ciclo, si se llega al final del documento, hacemos
					que end=1 para que luego termine el programa. */

					if(c[i]=='\n')
						break;
					if(c[i]=='\0'){
						end=1;
						break;
					}
				}
			}
			
			/* Definimos de donde seguir escaneando el siguiente par (de donde termino este). */

			start=i;
		}

		/* Revisamos si debe terminar el programa. */

		if(end)
			return 0;

		/* Trabajamos con los numeros escaneados en sus respectivos vectores. 
		Y en el caso de que es el ultimo numero a imprimir, no imprimimos un espacio. */

		for(j=0;j<xCont;++j){
			if(cCont==1){
				printf("%d", constants[0]);
				if(j!=xCont-1)
					printf(" ");
				continue;
			}
			for(k=0, sum=0;k<cCont;++k){
				sum=sum+constants[cCont-k-1]*(long long int)pow(x[j],k);
			}
			printf("%lld", sum);
			if(j!=xCont-1)
				printf(" ");
		}

		printf("\n");
	}
	return 0;
}