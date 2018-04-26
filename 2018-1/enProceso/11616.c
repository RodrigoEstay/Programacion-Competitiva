#include <stdlib.h>
#include <stdio.h>

/* El error esta en que en el caso de numeros como 3999 399 389 379 369 339 329 319. */

int main (){
	int sum=0, prev=8, roman=0, i, values[7]={1, 5, 10, 50, 100, 500, 1000};
	char c, letter[7]={'I', 'V', 'X', 'L', 'C', 'D', 'M'};
	while(c=getc(stdin)){
		if(c=='\n' || c==EOF){
			if(roman){
				printf("%d\n", sum);
			}
			else{
				for(i=6;i>=0 && sum;--i){
					if(i>4){
						if(sum>=values[i]){
							for(;sum>=values[i];sum-=values[i])
								printf("%c", letter[i]);
						}
						else if(sum>=(values[i]-values[4])){
							printf("%c%c", letter[4], letter[i]);
							sum=sum-values[i]+values[4];
						}
					}
					else if(i>2){
						if(sum>=values[i]){
							for(;sum>=values[i];sum-=values[i])
								printf("%c", letter[i]);
						}
						else if(sum>=(values[i]-values[2])){
							printf("%c%c", letter[2], letter[i]);
							sum=sum-values[i]+values[2];
						}
					}
					else if(i>0){
						if(sum>=values[i]){
							for(;sum>=values[i];sum-=values[i])
								printf("%c", letter[i]);
						}
						else if(sum>=(values[i]-values[0])){
							printf("%c%c", letter[0], letter[i]);
							sum=sum-values[i]+values[0];
						}
					}
					else{
						for(;sum>=values[i];sum-=1)
							printf("I");
					}
				}
				printf("\n");
			}
			roman=0;
			prev=8;
			sum=0;
			if(c==EOF)
				break;
			continue;
		}
		if(c>='0' && c<='9')
			sum=sum*10+c-'0';
		else{
			roman=1;
			for(i=0;i<7;++i){
				if(c==letter[i])
					break;
			}
			if(prev<i)
				sum=sum+values[i]-2*values[prev];
			else
				sum+=values[i];
			prev=i;
		}
	}
	return 0;
}