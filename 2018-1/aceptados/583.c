#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Codigo hecho totalmente por mi cuenta. */

int main (){

	/* Tenemos que usar long long int ya que llega hasta 2^31 el input. */

	long long int num, div;
	while(scanf("%lld", &num)!=EOF){

		/* Terminamos el programa cuando se llega a 0. */

		if(num==0)
			return 0;
		printf("%lld = ", num);

		/* Si el numero es negativo imprimimos lo especificado y seguimos trabajando
		con el valor positivo del numero. */

		if(num<0){
			printf("-1 x ");
			num=abs(num);
		}

		/* Para asegurarnos de imprimir todos los factores, ocupamos un metodo en el cual
		avanzamos por un numero hasta que sea divisor de "num", si lo es lo imprimimos y
		el nuevo num sera el resultado de la division, esto continua hasta que no se encuentre
		divisores para "num", entonces el ultimo factor es el ultimo "num" obtenido. 

		El divisor avanza hasta la raiz cuadrada de "num" ya que es el ultimo factor que
		se puede encontrar. */

		for(div=2;div<=sqrt(num);++div){
			if(num%div==0){
				printf("%lld x ", div);
				num/=div;
				div=1;
			}
		}
		printf("%lld\n", num);
	}
	return 0;
}