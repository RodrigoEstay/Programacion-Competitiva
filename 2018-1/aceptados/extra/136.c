#include <stdlib.h>
#include <stdio.h>
/* Este codigo fue inspirado por una version vista en internet, para optimizar
el tiempo de ejecucion. */

int isUgly (long long int n);

int main (){
	long long int n=2;
	int pos=0;
	printf("1\t%d\n", pos+1);
	pos++;
	while(pos<1500){
		if(isUgly(n)){
			printf("%lld\t%d\n", n, pos+1);
			pos++;
		}
		n++;
	}
	return 0;
}

/* La siguiente funcion recive el n a revisar si es feo, luego se les divide por
2, 3, o 5 todas las veces posibles siempre y cuando sean divisores de n. Luego,
si es que el numero resulta ser 1, significa que sus factores primos son 2 o 3 o 5
solamente, de esta manera si n=1 el numero es feo. */

int isUgly (long long int n){
	while(n%2==0)
		n/=2;
	while(n%3==0)
		n/=3;
	while(n%5==0)
		n/=5;
	if(n==1)
		return 1;
	else
		return 0;	
}