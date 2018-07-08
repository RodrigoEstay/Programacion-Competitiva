#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, i, countSquare, countRound;
	char par[129], c;
	scanf("%d", &n);
	getchar();
	while(n--){
		countRound=0, countSquare=0, i=0;
		while(1){
			c=getchar();
			if(c=='\n' || c==EOF) break;
			par[i]=c;
			++i;
		}
		par[i]='\0';
		for(i=0;par[i]!='\0';++i){
			if(par[i]=='(') ++countRound;
			else if(par[i]==')') --countRound;
			else if(par[i]=='[') ++countSquare;
			else if(par[i]==']') --countSquare;
		}
		if(!countRound && !countSquare) printf("Yes\n");
		else printf("No %s %d %d\n", par, countRound, countSquare);
	}
	return 0;
}