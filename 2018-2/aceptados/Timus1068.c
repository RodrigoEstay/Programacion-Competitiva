#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

// Simplemente consideramos los dos casos posibles, menor o igual a 1 y mayor a 1.

int main(){
	int N, sum=0, i;
	scanf("%d", &N);
	if(N>=1) for(i=1;i<=N;++i) sum+=i;
	else for(i=1;i>=N;--i) sum+=i;
	printf("%d\n", sum);
	return 0;
}