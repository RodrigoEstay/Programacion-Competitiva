#include <stdlib.h>
#include <stdio.h>

/* Programa hecho completamente por cuenta propia. */

int main (){

	/* Hacemos un diccionario con los caracteres romanos y sus respectivos valores. */

	int sum=0, prev=8, roman=0, i, values[7]={1, 5, 10, 50, 100, 500, 1000};
	char c, letter[7]={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	while(c=getc(stdin)){

		/* Si se llega a un salto de linea o el final del documento, entonces imprimimos
		el caso del que se trato en esa linea. */

		if(c=='\n' || c==EOF){

			/* Si se trataba del caso de un numero romano, imprimimos el numero que representaba. */

			if(roman){
				printf("%d", sum);
			}

			/* Si no transformamos el numero arabico a romano. */

			else{

				/* Avanzamos por cada unas de las letras del diccionario, desde el final para atras
				separamos los posibles casos en 3 casos, cuando la letra es mayor a C, mayor a X y
				mayor a I. cada uno en dos subcasos, cuando el numero es mayor al valor de la letra
				a analizar, o si se encuentra entre el rango de la letra restado el valor que puede
				preceder la letra analizada. En caso de cumplirse algun caso, imprimimos las letras
				que se tratan y le restamos el valor de esta al numero. El ++i en algunos ciclos for
				es implementado debido al error que se provocaba al imprimir mas de 3 veces la misma
				letra pero no juntas (como en XXXIX para 39). Este ciclo se acaba cuando el numero
				llega a 0 debido a las restas. */ 

				for(i=6;i>=0 && sum;--i){
					if(i>4){
						if(sum>=values[i]){
							for(;sum>=values[i];sum-=values[i])
								printf("%c", letter[i]);
							++i;
						}
						else if(sum>=(values[i]-values[4])){
							printf("%c%c", letter[4], letter[i]);
							sum=sum-values[i]+values[4];
						}
					}
					else if(i>2){
						if(sum>=values[i]){
							for(;sum>=values[i];sum-=values[i])
								printf("%c", letter[i]);
							++i;
						}
						else if(sum>=(values[i]-values[2])){
							printf("%c%c", letter[2], letter[i]);
							sum=sum-values[i]+values[2];
						}
					}
					else if(i>0){
						if(sum>=values[i]){
							for(;sum>=values[i];sum-=values[i])
								printf("%c", letter[i]);
							++i;
						}
						else if(sum>=(values[i]-values[0])){
							printf("%c%c", letter[0], letter[i]);
							sum=sum-values[i]+values[0];
						}
					}
					else{
						for(;sum>=values[i];sum-=1)
							printf("I");
					}
				}
			}

			/* Reiniciamos los valores con los que se comparan en cada caso, e imprimimos un salto
			de linea si no se trata del ultimo caso. */

			roman=0;
			prev=8;
			sum=0;
			if(c==EOF)
				break;
			else
				printf("\n");
			continue;
		}

		/* Si en esta linea se encuentran numeros, los vamos asignando a sum, para luego ser tratado
		como se indico anteriormente. */

		if(c>='0' && c<='9')
			sum=sum*10+c-'0';

		/* Si no se trata de numeros arabicos, se trata de numeros romanos, por ende lo que se hace es
		que a sum (que vale 0 inicialmente) le vamos sumando los valores de cada letra que se encuentran 
		de iquierda a derecha, y guardamos la posicion de la letra escaneada, si la posicion de la letra
		escaneada anteriormente es menor a la que se esta escaneando en el momento, significa que se trata
		de una resta al valor, asi que sumamos el valor de la letra escaneada y restamos dos veces el valor
		anterior, ya que antes ya lo habiamos sumado. */

		else{
			roman=1;
			for(i=0;i<7;++i){
				if(c==letter[i])
					break;
			}
			if(prev<i)
				sum=sum+values[i]-2*values[prev];
			else
				sum+=values[i];
			prev=i;
		}
	}
	return 0;
}