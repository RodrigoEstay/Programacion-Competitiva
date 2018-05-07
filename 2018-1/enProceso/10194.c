#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int main (){
	int N, T, G, i, j, k;
	char line[101];
	scanf("%d", &N);
	char tournament[N][101];
	for(i=0;i<N;++i){
		strcpy(tournament[i], lineScan(line));
		scanf("%d", &T);
		int ranks[T];
		struct countryStats countries[T];
		for(j=0;j<T;++j){
			strcpy(countries[j].name, lineScan(line));
			countries[j].goalScor=0;
			countries[j].goalAng=0;
			countries[j].ties=0;
			countries[j].wins=0;
			countries[j].losses=0;
		}
		scanf("%d", &G);
		while(G--)
			gameScan(countries);
		for(j=0;j<T;++j)
			ranks[j]=j;
		gameSort(countries, T, ranks);
		for(j=0;j<T;++j)
			printf("%d\n", ranks[j]);
		for(j=0;j<T;++j){
			printf("RANK) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
				countries[j].name,
				countries[j].wins*3+countries[j].ties,
				countries[j].wins+countries[j].ties+countries[j].losses,
				countries[j].wins, countries[j].ties, countries[j].losses,
				countries[j].goalScor-countries[j].goalAng,
				countries[j].goalScor, countries[j].goalAng);
		}
	}
	return 0;
}

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

int* gameSort(struct countryStats *cs, int N, int *rank){
	int i, j;
	for(i=0;i<N;++i){
		for(j=i+1;j<N;++j){
			if(cs[rank[i]].wins*3+cs[rank[i]].ties<cs[rank[j]].losses*3+cs[rank[j]].ties)
				swap(&rank[i], &rank[j]);
			else if(cs[rank[i]].wins*3+cs[rank[i]].ties==cs[rank[j]].losses*3+cs[rank[j]].ties){
				if(cs[rank[i]].wins<cs[rank[j]].wins)
					swap(&rank[i], &rank[j]);
				else if(cs[rank[i]].wins==cs[rank[j]].wins){
					if(cs[rank[i]].goalScor-cs[rank[i]].goalAng<cs[rank[j]].goalScor-cs[rank[j]].goalAng)
						swap(&rank[i], &rank[j]);
					else if(cs[rank[i]].goalScor-cs[rank[i]].goalAng==cs[rank[j]].goalScor-cs[rank[j]].goalAng){
						if(cs[rank[i]].goalScor<cs[rank[j]].goalScor)
							swap(&rank[i], &rank[j]);
						else if(cs[rank[i]].goalScor<cs[rank[j]].goalScor){
							if(cs[rank[i]].wins+cs[rank[i]].losses+cs[rank[i]].ties>cs[rank[j]].wins+cs[rank[j]].losses+cs[rank[j]].ties)
								swap(&rank[i], &rank[j]);
							else if(cs[rank[i]].wins+cs[rank[i]].losses+cs[rank[i]].ties==cs[rank[j]].wins+cs[rank[j]].losses+cs[rank[j]].ties){
								int t=strcmp(cs[rank[i]].name, cs[rank[j]].name);
								if(t<0){
									swap(&rank[i], &rank[j]);
									printf("HOLA\n");
								}
							}
						}
					}
				}
			}
		}
	}
	return rank;
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}