#include <stdlib.h>
#include <stdio.h>

int main (){
	long long int n=2, div1, div2;
	int pos=0, esFactorPrimo, k;
	printf("1 ");
	while(pos<20){
		k=1;
		printf("%lld ", n);
		for(div1=2;div1<=n;div1++){
			if(n%div1==0){
				esFactorPrimo=1;
				for(div2=2;div2<=n/2+1;div2++){
					if(div1%div2==0){
						esFactorPrimo=0;
					}
				}
				if(esFactorPrimo==1){
					printf("%lld ", div1);
					if(div1!=2 && div1!=3 && div1!=5)
						k=0;
					}
			}
		}
		if(k){
			pos++;
			printf("SE\n");
		}
		else
			printf("NO\n");
		n++;
	}
	return 0;
}