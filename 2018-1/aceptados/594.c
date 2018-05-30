#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

int main(){
	char c;
	int num=0, num2, bytes[4], i, neg=0;

	// Escaneamos hasta EOF de la manera clasica mientras vamos armando el entero.

	while(1){
		c=getc(stdin);
		if(c==EOF || c=='\n'){
			if(neg) // Revisamos si se trataba de un negativo.
				num=-num;
			num2=num;
			for(i=0;i<4;++i){ // Separamos los 4 bytes del entero.
				bytes[i]=num2&255;
				num2=num2>>8;
			}
			num2=(bytes[0]<<24)+(bytes[1]<<16)+(bytes[2]<<8)+(bytes[3]); // Concatenamos los bytes anteriores.
			printf("%d converts to %d", num, num2);
			num=0, neg=0;
			if(c==EOF) // Si se llega al final se termina el programa.
				return 0;
			else
				printf("\n");
		}
		else if(c>='0' && c<='9')
			num=num*10+(c-'0');
		else if(c=='-') // Si se escanea un - es porque es negativo.
			neg=1;
	}
}