#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Programa hecho completamente por cuenta propia. */

/* Guardamos las expresiones en morse y sus respectivas traducciones en la misma posicion en distintos
string globaes para ser utilizados mas adelante en la funcion comp */

char tra[53]={'A', 'B', 'C','D','E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ',', '?', 39, '!', '/', '(', ')', '&', ':', ';', '=', '+', '-', '_', '"', '@'};
char mor[53][7]={".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", ".--.-."};

int comp(char *);

int main (){
	char  word[2001], killWhiteSpace;
	int T, i, j, pos;

	/* Escaneamos "T" y con "killWhiteSpace" nos comemos el salto de line despues del primer numero. */

	scanf("%d%c", &T, &killWhiteSpace);
	for(j=0;j<T;++j){
		printf("Message #%d\n", j+1);
		for(i=0;;++i){
			scanf("%c", &word[i]);

			/* Mientras vamos escaneando el morse, si llegamos al salto de linea significa
			que se trata del ultimo caracter, asi imprimimos el ultimo caracter y luego dos
			saltos de linea, o uno si se trata del ultimo mensaje. */

			if(word[i]=='\n'){
				word[i]='\0';
				pos=comp(word);
				if(pos!=-1)
					printf("%c", tra[pos]);
				printf("\n");
				if(j<T-1)
					printf("\n");
				break;
			}

			/* Si llegamos a un espacio en blanco significa que se termino la expresion
			del caracter en morse, asi que enviamos este caracter a la funcion "comp", la
			cual nos devolvera la posicion en "tra" de la traduccion de esta expresion
			enviada, en caso de que "comp" devuelva un -1, significa que se trata de un
			espacio y no una expresion en morse. */

			if(word[i]==' '){
				word[i]='\0';
				pos=comp(word);
				if(pos==-1)
					printf(" ");
				else
					printf("%c", tra[pos]);
				i=-1;
			}
		}
		
	}
	return 0;
}

/* Esta funcion compara cada expresion en morse recivida con las expresiones almacenadas al
principio del programa, asi si se llega a encontrar que es igual a alguna, devolvemos la posicion
de la expresion encontrada en "mor", donde dicha posicion en "tra" sera su traduccion.
En el caso de no encontrar alguna epresion igual se tratara de un espacio, asi que devolvemos
un -1. */

int comp(char *word){
	int i;
	for(i=0;i<53;++i){
		if(!(strcmp(word, mor[i])))
			return i;
	}
	return -1;
}