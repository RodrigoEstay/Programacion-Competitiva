#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Coidgo hehco por mi cuenta a excepxion del algoritmo para ordenar alfabeticamente
(basicamente el uso de qsort y strcmp) que fueron investigados en internet. */

/* La siguiente funcion es solo un cambio de tipo de variable de la entrada de strcmp
ya que esta sera usada mas adelante como criteria de ordenamiento en qsort, la cual
le dara una entrada de tipo const void*, pero strcmp recive el tipo de variable
const char*, asi que solo hacemos un cambio de variable y todo arreglado. */ 

int cmpstr(const void* a, const void* b) { 
    const char* aa = (const char*)a;
    const char* bb = (const char*)b;
    return strcmp(aa, bb);
}

int main (){
	char countries[2000][75], names[75];
	int n, i, count;
	scanf("%d", &n);

	/* Escaneamos la primera palabra con un string para saltarnos el espacio blanco
	y luego escaneamos el resto de la linea hasta llegar al final de la linea para
	asegurarnos que en la siguiente iteracion se tenga al siguiente pais como primera
	palabra. */

	for(i=0;i<n;++i){
		scanf("%s", countries[i]);
		scanf("%[^\n]", names);
	}

	/* Ocupamos la funcion qsort para ordenar nuestros paises, con una modificacion
	de cmpstr por el motivo explicado anteriormente. */

	qsort(countries, n, 75*sizeof(char), cmpstr);

	/* en este for se revisa si el pais en el que se va es igual al pais anterior, asi
	contamos hasta que no sea igual, entonces imprimimos el pais y el contador, se empieza
	de i=1 para que pueda comparar con el pais anterior, este algoritmo funciona hasta llegar
	al ultimo pais, aqui no funciona ya que no se ejecutara el else, por eso ponemos un if
	para revisar si es el ultimo pais, en ser asi imprimimos el pais y su cantidad correspondiente,
	este algoritmo siempre funciona ya que los paises del arreglo ya estan ordenados alfabeticamente. */

	for(i=1, count=1;i<n;++i){
		if(strcmp(countries[i], countries[i-1])==0)
			++count;
		else{
			printf("%s %d\n", countries[i-1], count);
			count=1;
		}
		if(i==n-1)
			printf("%s %d\n", countries[i], count);
	}
	return 0;
}