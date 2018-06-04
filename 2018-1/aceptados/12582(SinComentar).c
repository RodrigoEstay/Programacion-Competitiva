#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmpfunc (const void * a, const void * b);

struct sprinkler{
	int paths;
	char label;
};

int main(){
	int T, len, i, j, pathCount, sprinklersCount, ends[10000], skip;
	char data[10000], pathTo=0;
	scanf("%d", &T);
	int max=T;
	while(T--){
		scanf("%s", data);
		len=strlen(data);
		int n=len/2;
		struct sprinkler sprin[n];
		for(i=0, sprinklersCount=0;i<len;++i){
			skip=0;
			for(j=0;j<sprinklersCount;++j){
				if(ends[j]==i){
					skip=1;
					break;
				}
			}
			if(skip) continue;
			for(j=i+1, pathCount=0;j<len;++j){
				if(data[j]==data[i]) break;
				if(i==0 && j==1) --pathCount;
				if(!pathTo) pathTo=data[j];
				else if(pathTo==data[j]) pathTo=0, ++pathCount; 
			}
			ends[sprinklersCount]=j;
			sprin[sprinklersCount].label=data[i];
			sprin[sprinklersCount].paths=pathCount+1;
			++sprinklersCount;
		}
		printf("Case %d\n", max-T);
		qsort(sprin, sprinklersCount, sizeof(struct sprinkler), cmpfunc);
		for(i=0;i<sprinklersCount;++i) printf("%c = %d\n", sprin[i].label, sprin[i].paths);
	}
	return 0;
}


int cmpfunc(const void *a, const void *b){
	struct sprinkler *c=(struct sprinkler *)a, *d=(struct sprinkler *)b;
	int dif=c->label - d->label;
	return dif;
}