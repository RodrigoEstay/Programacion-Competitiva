#include <stdio.h>
#include <stdlib.h>

int main()
{
	int k=0, i[300] ,j[300], maxCycle, cycle, n;
	while(scanf("%d%d",&i[k],&j[k])!=EOF){
		a=i[k];	
		printf("%d %d ", i[k], j[k]);
		for(maxCycle=0;i<=j;i++){
			n=i, cycle=0;
			while(n!=1){
				if(n%2==1){
					n=3*n+1;
				}else{
					n=n/2;
				}
				cycle++;
			}
			if(cycle>maxCycle){
				maxCycle=cycle;
			}
		}
		printf("%d\n", maxCycle+1);
		k++;
	}
	return 0;
}