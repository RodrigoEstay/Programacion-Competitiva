#include <stdlib.h>
#include <stdio.h>

int main (){
	int a[10000], i=0, size;
	char end;
	do{
		scanf("%d%c", &a[i], &end);
		i++;
		printf("hola\n");
	}while(end!='\n');
	for(size=0;size<i;size++)
		printf("%d hola ", a[size]);
	printf("\n");
	return 0;
}