#include <stdlib.h>
#include <stdio.h>

void killWhiteSpace();

int main(){
	int cases, i, perm[1000], j, k;
	char values[1000][400], scan;
	scanf("%d", &cases);
	killWhiteSpace();
	while(cases--){
		i=0;
		perm[i]=0;
		k=0;
		do{
			scanf("%c", &scan);
			if(scan==' ')
				++k;
		}while(scan!='\n');
		for(i=0;i<k+1;++i){
			/*if(scan>='0' && scan<='9')
				perm[i]=perm[i]*10+scan-'0';
			else if(scan==' '){
				++i;
				perm[i]=0;
			}*/
		scanf("%d", &perm[i]);
		}
		for(j=0;j<i;++j)
			scanf("%s", values[j]);
		killWhiteSpace();
		for(j=0;j<i;++j)
			printf("%d\t", perm[j]);
		printf(" int\n");
		for(j=0;j<i;++j)
			printf("%s\t", values[j]);
		printf("string\n");
	}
	return 0;
}

void killWhiteSpace(){
	char c;
	do{
		scanf("%c", &c);
	}while(c!='\n');
}