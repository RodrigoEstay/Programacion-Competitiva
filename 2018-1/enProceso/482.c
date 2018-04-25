#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	int N, i, j, perm[100];
	char killWhiteSpace, values[100][100],pValues[100][100], c;
	scanf("%d%c%c", &N, &killWhiteSpace, &killWhiteSpace);
	while(N--){
		i=0;
		perm[i]=0;
		while(c=getc(stdin)){
			if(c>='0' && c<='9')
				perm[i]=perm[i]*10+c-'0';
			if(c==' '){
				++i;
				perm[i]=0;
			}
			if(c=='\n'){
				break;
			}
		}
		for(j=0;j<i+1;++j)
			scanf("%s", values[j]);
		for(j=0;j<i+1;++j)
			strncpy(values[j] , pValues[perm[j]-1] , 100);
		for(j=0;j<i+1;++j)
			printf("%s\n", pValues[j]);
		printf("\n");
		scanf("%c%c", &killWhiteSpace, &killWhiteSpace);
	}
	return 0;
}