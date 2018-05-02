#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct countryStats{
	char name[33];
};

char* lineScan(char*);

int main (){
	int N, T, i, j;
	char line[101];
	scanf("%d", &N);
	char tournament[N][101];
	for(i=0;i<N;++i){
		strcpy(tournament[i], lineScan(line));
		printf("%s\n", tournament[i]);
		scanf("%d", &T);
		printf("%d", T);
		struct countryStats countries[T];
		for(j=0;j<T;++j){
			strcpy(countries[j].name, lineScan(line));
			printf("%s\n", countries[j].name);
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