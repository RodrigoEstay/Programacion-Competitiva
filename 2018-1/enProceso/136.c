#include <stdlib.h>
#include <stdio.h>

int isUgly (long long int n);

int main (){
	long long int n=2;
	int pos=0;
	printf("1\t%d\n", pos+1);
	pos++;
	while(pos<1500){
		if(isUgly(n)){
			printf("%lld\t%d\n", n, pos+1);
			pos++;
		}
		n++;
	}
	return 0;
}

int isUgly (long long int n){
	while(n%2==0)
		n/=2;
	while(n%3==0)
		n/=3;
	while(n%5==0)
		n/=5;
	if(n==1)
		return 1;
	else
		return 0;	
}