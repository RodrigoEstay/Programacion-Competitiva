#include <stdio.h>
#include <stdlib.h>

int main (){
	int n, i, k, pos, feo;
	for(n=1,pos=1; pos<=11; n++){
		k=0;
		for(i=1;i<n;i++){
			if(i==2 || i==3 || i==5 || i==1){
				continue;
			}
			else if(n%i==0){
				k++;
			}
		}
		if(!k){
			feo=n;
			pos++;
		}
	}
	printf("\nThe 1500'th ugly number is %d.\n", feo);
	return 0;
}