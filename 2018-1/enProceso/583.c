#include <stdio.h>
#include <stdlib.h>

int main (){
	int num, div1, div2, isPrime, primes[100], i, j;
	while(scanf("%d", &num)!=EOF){
		i=0;
		printf("%d = ", num);
		if(num<0){
			printf("-1 x ");
			num=abs(num);
		}
		for(div1=2;div1<=num;div1++){
			if(num%div1==0){
				isPrime=1;
				for(div2=2;div2<div1/2;div2++){
					if(div1%div2==0)
						isPrime=0;
				}
				if(isPrime){
					primes[i]=div1;
					i++;
				}
			}
		}
		for (j=0;j<i;j++){
			if(j!=i-1)
				printf("%d x ", primes[j]);
			else
				printf("%d", primes[j]);
		}
		printf("\n");
	}
	return 0;
}