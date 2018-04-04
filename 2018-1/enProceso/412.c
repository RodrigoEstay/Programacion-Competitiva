#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int commonFactor(int a, int b);
int smallerNumber(int a, int b);


int main (){
	int N, i, data[50], ncf, j, pairs;
	double aproxPi;
	while(scanf("%d", &N)!=EOF && N){
		pairs=0;
		ncf=0;
		for(i=0;i<N;++i)
			scanf("%d", &data[i]);
		for(i=0;i<N-1;++i){
			for(j=i+1;j<N;++j){
				if(commonFactor(data[i], data[j]))
					++ncf;
				++pairs;
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

int smallerNumber(int a, int b){
	if(a<b)
		return a;
	else
		return b;
}

int commonFactor(int a, int b){
	int i, maxDiv=smallerNumber(a,b);
	if(maxDiv<2)
		return 1;
	for(i=2;i<=maxDiv;++i){
		if(a%i==0 && b%i==0)
			return 0;
	}
	return 1;
}