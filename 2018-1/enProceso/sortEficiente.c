#include <stdio.h>
#include <stdlib.h>

int main (){
	int N, min, max, temp;
	scanf("%d", &N);
	int v[N], i, j;
	for(i=0;i<N;++i)
		scanf("%d", &v[i]);
	for(i=0;i<N/2;++i){
		for(j=i;j<N-i;++j){
			max=i;
			min=i;
			if(v[j]>v[max]){
				max=j;
			}
			if(v[j]<v[min]){
				min=j;
			}
		}
		printf("%d %d\n", min, max);
		temp=v[max];
		v[max]=v[i];
		v[i]=temp;
		temp=v[min];
		v[min]=v[N-i-1];
		v[N-i-1]=temp;
	}
	for(i=0;i<N;++i)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}