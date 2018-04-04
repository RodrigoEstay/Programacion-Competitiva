#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (){
	int num, c[500], i, j, sum, p;
	char in, in1;
	while(1){
		for(i=0, num=0;in=fgetc(stdin)!='\n';){
			if(in==EOF)
				return 0;
			if(in>='0' && in<='9')
				num=num*10+(in-'0');
			else{
				c[i]=num;
				num=0;
				++i;
			}
		}
		for(i=0;c[i]!='\0';++i)
			printf("%d ", c[i]);
		printf("\n");
		/*
		num=0;
		while(in1=fgetc(stdin)!='\n'){
			if(in1>='0' && in1<='9')
				num=num*10+(in1-'0');
			else{
				sum=0;
				for(j=0;j<i;++j){
					if(j==0)
						sum+=c[j];
					p=(int) pow(num,j);
					sum+=(c[j]*p);
				}
				num=0;
				printf("%d", sum);
			}
		}
	printf("\n"); */
	}
	return 0;
}
