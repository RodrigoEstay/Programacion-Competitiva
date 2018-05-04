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

int main (){
	int N, T, G, i, j;
	char line[101];
	scanf("%d", &N);
	char tournament[N][101];
	for(i=0;i<N;++i){
		strcpy(tournament[i], lineScan(line));
		scanf("%d", &T);
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
			printf("%s %d %d %d %d %d\n", countries[j].name, countries[j].goalScor, countries[j].goalAng, countries[j].ties, countries[j].wins, countries[j].losses);
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
	for(i=0;i<4;++i)
		printf("%s %d %d %d %d %d\n", cs[i].name, cs[i].goalScor, cs[i].goalAng, cs[i].ties, cs[i].wins, cs[i].losses);
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
		if(c>='0' || c<='9'){
			num=num*10+c-'0';
		}
		else{
			if(firstCase){
				country1[i]=c;
			}
			else
				country2[i]=c;
		}
	}
	for(i=0;strcmp(country1,cs[i].name);++i);
	posC1=i;
	printf("%d ", posC1);
	for(i=0;strcmp(country2,cs[i].name);++i);
	posC2=i;
	printf("%d\n", posC2);
	cs[posC1].goalScor+=sc1;
	cs[posC1].goalAng+=sc2;
	cs[posC2].goalScor+=sc2;
	cs[posC2].goalAng+=sc1;
	if(sc1==sc2){
		cs[posC1].ties+=1;
		cs[posC2].ties*=1;
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