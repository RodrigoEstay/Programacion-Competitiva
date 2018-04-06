#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	int N, data[50], ncf, pairs, i, j, div;
	float aproxPi;
	while(scanf("%d", &N)!=EOF){
		pairs=0;
		ncf=0;
		for(i=0;i<N-1;++i)
			scanf("%d", &data[i]);
		for(i=0;i<N-1;++i){
			for(j=i+1;j<N-1;++j,++pairs){
				for(div=2;div<(data[i]>data[j])?data[j]:data[i];div++){
					if(data[i]%div==0){
						if(data[j]%div==0)
							++ncf;
					}
				}
			}
		}
		if(ncf){
			aproxPi=sqrt((double) 6*pairs/ncf);
			printf("%.6lf\n", aproxPi);
		}
		else 
			printf("No estimate for this data set.\n");
	}
	return 0;
}