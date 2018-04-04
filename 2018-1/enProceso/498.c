#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (){
	int num, c[500], i, j, sum, p;
	char in, in1;
	while(1){
		for(i=0;in=fgetc(stdin)!='\n';){
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
		while(in1=fgetc(stdin)!='\n'){
			sum=0;
			if(in1>='0' && in1<='9')
				num=num*10+(in1-'0');
			else{
				for(j=0;j<i;++j){
					if(j==0)
						sum+=c[j];
					p=(int) pow(num,j);
					sum+=(c[j]*p);
				}
				printf("%d", num);
			}
		}
	printf("\n");
	}
}
