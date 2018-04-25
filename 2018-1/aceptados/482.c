#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	int N, i, j, perm[1000];
	char killWhiteSpace, values[1000][500],pValues[1000][500], c;

	/* Escaneamos el "N" y luego escaneamos dos caracteres para quitar los dos siguientes saltos
	de linea. */

	scanf("%d%c%c", &N, &killWhiteSpace, &killWhiteSpace);
	while(N--){
		i=0;
		perm[i]=0;

		/* Con este while escaneamos hasta encontrarse el salto de linea mientras vamos asignando
		los valores como entero al arreglo "perm" que contiene los valores de la permutacion. */

		while(c=getc(stdin)){
			if(c>='0' && c<='9')
				perm[i]=perm[i]*10+c-'0';
			if(c==' '){
				++i;
				perm[i]=0;
			}
			if(c=='\n'){
				break;
			}
		}

		/* Como sabemos que el numero de datos escaneados para "perm" tiene que ser igual al numero
		de datos a permutar, entonces escaneamos la misma cantidad de datos (ya que "i" es el numero
		de datos escaneados anteriormente, y como este empezaba de 0, le sumamos 1 para que se el 
		siguiente ciclo se ejecute las veces correctas), y los escaneamos como string para saltarnos
		el espacio en blanco y para no enredarnos con el numero de decimales. */

		for(j=0;j<i+1;++j)
			scanf("%s", values[j]);

		/* En el siguiente ciclo copiamos los string escaneados anteriormente en un nuevo arreglo que
		almacenara los datos ordenados como se deseaba por la permutacion anterior. */

		for(j=0;j<i+1;++j)
			strncpy(pValues[perm[j]-1] , values[j] , 100);
		for(j=0;j<i+1;++j)
			printf("%s\n", pValues[j]);

		/* Si se trataba del ultimo caso a tratar, no imprimimos salto de linea y no es necesario
		que matemos dos saltos de linea, solo uno. */

		if(N){
			scanf("%c", &killWhiteSpace);
			printf("\n");
		}
		scanf("%c", &killWhiteSpace);
	}
	return 0;
}