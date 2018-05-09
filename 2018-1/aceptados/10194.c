#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Programa hecho completamente por cuenta prpia. (se nota en lo largo que quedo) */

/* Creamos una estructura que almacena los datos de cada pais */

struct countryStats{
	char name[33];
	int games;
	int wins;
	int ties;
	int losses;
	int goalScor;
	int goalAng;
};

struct countryStats* gameScan(struct countryStats *cs);
char* lineScan(char*);
void swap(int *a, int *b);
int* gameSort(struct countryStats *cs, int N, int *rank);
void killUpCase(char *word);

int main (){
	int N, T, G, i, j, k;
	char line[101];
	scanf("%d", &N);
	char tournament[N][101];
	for(i=0;i<N;++i){
		strcpy(tournament[i], lineScan(line));
		printf("%s\n", tournament[i]);
		scanf("%d", &T);
		int ranks[T];
		struct countryStats countries[T];

		/* En este ciclo se escanea el nombre de cada pais, y asignamos los
		valores iniciales de cada uno de los datos de la estructura a 0. */

		for(j=0;j<T;++j){
			strcpy(countries[j].name, lineScan(line));
			countries[j].goalScor=0;
			countries[j].goalAng=0;
			countries[j].ties=0;
			countries[j].wins=0;
			countries[j].losses=0;
		}
		scanf("%d", &G);

		/* Escaneamos cada juego. */

		while(G--)
			gameScan(countries);

		/* Creamos un vector que almacenara las posiciones de los equipos
		que luego se manda a una funcion que ordena estas posiciones de la
		manera que se cumplan las criterias de los equipos ganadores. */

		for(j=0;j<T;++j)
			ranks[j]=j;
		gameSort(countries, T, ranks);
		for(j=0;j<T;++j){
			k=ranks[j];
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", j+1,
				countries[k].name,
				countries[k].wins*3+countries[k].ties,
				countries[k].wins+countries[k].ties+countries[k].losses,
				countries[k].wins, countries[k].ties, countries[k].losses,
				countries[k].goalScor-countries[k].goalAng,
				countries[k].goalScor, countries[k].goalAng);
		}

		/* Si se trata del ultimo caso no se imprime un salto de linea. */

		if(i!=N-1)
			printf("\n");
	}
	return 0;
}

/* Esta funcion escanea una linea de texto la cual se la asigna a un array. */

char* lineScan(char *line){
	int i;
	char c;
	for(i=0;c=getc(stdin);++i){
		if(i==0 && c=='\n'){
			--i;
			continue;
		}
		if(c=='\n' || c==EOF){
			line[i]='\0';
			break;
		}
		line[i]=c;
	}
	return line;
}

/* Esta funcion escanea la informacion de los juegos, primero escanea el pais, y se lo
asigna a un array, luego cuando se llega a '#' significa que se acabo el nombre del pais
asi que asignamos al final del array el vector nulo, luego se escanea el numero de goles
que metio y se le asigna al pais escaneado anteriormente. Cuando se llega al '@' significa
que empieza la informacion del siguiente caso (firstCase=0), pero en este caso los datos
vienen en distinto orden, asi que escaneamos los goles metidos por el segundo pais y lo
guardamos, cuando se llega a '#' empezamos con "i=0", para asignar un array con el nombre
del siguiente pais, luego le asignamos su respectiva cantidad de goles de cada tipo a cada
pais, y luego comparamos la cantidad de goles para ver si alguno gano o alguno empato. */

struct countryStats* gameScan(struct countryStats *cs){
	int i, sc1=0, sc2=0, posC1, posC2, firstCase=1, num=0;
	char c, country1[33], country2[33];
	for(i=0;c=getc(stdin);++i){
		if(i==0 && c=='\n'){
			--i;
			continue;
		}
		if(c=='@'){
			sc1=num;
			num=0;
			firstCase=0;
			continue;
		}
		if(c=='#'){
			if(firstCase)
				country1[i]='\0';
			else{
				sc2=num;
				i=-1;
			}
			continue;
		}
		if(c=='\n' || c==EOF){
			country2[i]='\0';
			break;
		}
		if(c>='0' && c<='9'){
			num=num*10+c-'0';
			continue;
		}
		if(firstCase){
			country1[i]=c;
			}
		else
			country2[i]=c;
	}
	for(i=0;strcmp(country1,cs[i].name);++i);
	posC1=i;
	for(i=0;strcmp(country2,cs[i].name);++i);
	posC2=i;
	cs[posC1].goalScor+=sc1;
	cs[posC1].goalAng+=sc2;
	cs[posC2].goalScor+=sc2;
	cs[posC2].goalAng+=sc1;
	if(sc1==sc2){
		cs[posC1].ties+=1;
		cs[posC2].ties+=1;
	}
	else if(sc1>sc2){
		cs[posC1].wins+=1;
		cs[posC2].losses+=1;
	}
	else{
		cs[posC2].wins+=1;
		cs[posC1].losses+=1;
	}
	return cs;
}

/* Aqui ordenamos a los equipos por las criterias especificadas, comprobamos si algun pais
deberia tener el puesto del pais que se esta escaneando, si es que si, los cambiamos de posicion,
si es que no, comprobamos si la criteria a revisar es igual en ambos paises, si es que si son
iguales, seguimos con la siguiente criteria aplicando la misma metodologia, si es que no son
iguales es porque el orden en los dos paises comparados esta correcto, y no se hace nada. */

int* gameSort(struct countryStats *cs, int N, int *rank){
	int i, j;
	for(i=0;i<N;++i){
		for(j=i+1;j<N;++j){
			if((cs[rank[i]].wins*3+cs[rank[i]].ties)<(cs[rank[j]].wins*3+cs[rank[j]].ties))
				swap(&rank[i], &rank[j]);
			else if((cs[rank[i]].wins*3+cs[rank[i]].ties)==(cs[rank[j]].wins*3+cs[rank[j]].ties)){
				if(cs[rank[i]].wins<cs[rank[j]].wins)
					swap(&rank[i], &rank[j]);
				else if(cs[rank[i]].wins==cs[rank[j]].wins){
					if((cs[rank[i]].goalScor-cs[rank[i]].goalAng)<(cs[rank[j]].goalScor-cs[rank[j]].goalAng))
						swap(&rank[i], &rank[j]);
					else if((cs[rank[i]].goalScor-cs[rank[i]].goalAng)==(cs[rank[j]].goalScor-cs[rank[j]].goalAng)){
						if(cs[rank[i]].goalScor<cs[rank[j]].goalScor)
							swap(&rank[i], &rank[j]);
						else if(cs[rank[i]].goalScor==cs[rank[j]].goalScor){
							if((cs[rank[i]].wins+cs[rank[i]].losses+cs[rank[i]].ties)>(cs[rank[j]].wins+cs[rank[j]].losses+cs[rank[j]].ties))
								swap(&rank[i], &rank[j]);
							else if((cs[rank[i]].wins+cs[rank[i]].losses+cs[rank[i]].ties)==(cs[rank[j]].wins+cs[rank[j]].losses+cs[rank[j]].ties)){
								char lowcase[2][33];
								strcpy(lowcase[0], cs[rank[i]].name);
								strcpy(lowcase[1], cs[rank[j]].name);
								killUpCase(lowcase[0]);killUpCase(lowcase[1]);
								int t=strcmp(lowcase[0], lowcase[1]);
								if(t>0)
									swap(&rank[i], &rank[j]);
							}
						}
					}
				}
			}
		}
	}
	return rank;
}

/* Esta funcion intercambia los datos de dos variables.
(Esta funcion es ocupada en "gameSort"). */

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

/* Esta funcion transforma las letras mayusculas de un array a minusculas
(ocupada en la ultima criteria de la funcion "gameSort"). */

void killUpCase(char *word){
	int i;
	for(i=0;word[i]!='\0';i++){
		if(word[i]>='A' && word[i]<='Z')
			word[i]=(word[i]-'A')+'a';
	}
}