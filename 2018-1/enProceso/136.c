#include <stdio.h>
#include <stdlib.h>

int main (){
	int esFactor, esFeo, pos;
	long long int n, div1, div2;
	pos=0;
	n=1;
	while(pos<1500){
		esFeo=1;
		for(div1=2;div1<=n;div1++){
			if(n%div1==0){
				esFactor=1;
				for(div2=2;div2<div1;div2++){
					if(div1%div2==0)
						esFactor=0;
				}
				if(esFactor){
					if(div1!=2 && div1!=3 && div1!=5)
						esFeo=0;
				}
			}
		}
		if(esFeo)
			pos++;
		n++;
	}
	printf("%lld\n", n-1);
	return 0;
}