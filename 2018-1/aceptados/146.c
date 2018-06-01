#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Programa hecho sin ayuda. */

char difPos(char *word);
void Successor(char pos, char *word);
void swap(char *a, char *b);

int main(){
	char word[51], pos;
	while(1){ // Escaneamos hasta encontrar un #.
		scanf("%s", word);
		if(!strcmp(word,"#")) break;
		pos=difPos(word);
		if(pos) printf("No Successor\n"); // Si retorna un numero distinto a 0, no hay sucesor.
		else printf("%s\n", word); // Caso contrarii imprimimos el sucesor.
	}
	return 0;
}

/* La siguiente funcion revisa si el arreglo esta ordenado inversamente alfabeticamente, si es
asi, signfica que el arreglo no presenta sucesor, en caso contrario transformamos el arreglo
a su sucesor, mandado el dato de la posicion en donde no se cumplia la criteria anterior. */

char difPos(char *word){
	char i;
	for(i=strlen(word)-1;i>0;--i){
		if(*(word+i-1)<*(word+i)){
			Successor(i-1,word);
			return 0;
		}
	}
	return 1;
}

/* El sucesor sera la siguiente combinacion del arreglo, al hacer una lista de todas las combinaciones
si la ordenamos alfabeticamente, el sucesor sera el siguiente de la posicion del arreglo. Asi el sucesor
sera el que tome la siguiente posicion alfabetica del arreglo. Para obtener este arreglo hacemos lo siguiente:
Primero, la funcion anterior nos da la posicion de donde no se cumple el orden inverso, esta posicion debe
ser reemplazada por el siguiente caracter que haya despues que sea mayor y mas cercano, luego los siguientes
caracteres se ubican en orden alfabetico. */

void Successor(char pos, char *word){
	char i, j, minPos, nextLetterPos=-1, n=strlen(word);
	for(i=pos+1;i<n;++i){
		if(word[i]>word[pos]){
			if(nextLetterPos==-1) nextLetterPos=i;
			else if((word[i]-word[pos])<(word[nextLetterPos]-word[pos])) nextLetterPos=i;
		}
	}
	swap(&word[pos],&word[nextLetterPos]);
	for(i=pos+1;i<n-1;++i){
		for(j=i+1,minPos=i;j<n;++j){
			if(*(word+j)<*(word+minPos)) minPos=j;
		}
		swap(&word[i],&word[minPos]);
	}
}

/* Esta es una simple funcion swap */

void swap(char *a, char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}