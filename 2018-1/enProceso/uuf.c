#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct line{
	int num[1000];
	int len;
};

struct line lineScan(void);

int main(){
	struct line first=lineScan(), second=lineScan();
	int *c=first.num, lenc=first.len, *x=second.num, lenx=second.len, i, j;
	printf("c= ");
	for(i=0;i<lenc;++i)
		printf("%d ", *(c+i));
	printf("\nx= ");
	for(i=0;i<lenx;++i)
		printf("%d ", *(x+i));
	printf("\n");
	return 0;
}

struct line lineScan(){
	char input[10000];
	int i, j, num, c[1000], neg=0;
	scanf("%[^\n]", input);
	printf("%s\n", input);
	for(i=0;;++i){
		printf("hola\n");
		if(input[i]=='-')
			neg=1;
		else if(input[i]>='0' && input[i]<='9')
			num=10*num+input[i]-'0';
		else{
			if(neg){
				num=-num;
				neg=0;
			}
			c[j]=num;
			++j;
			if(input[i]=='\0')
				break;
		}
	}
	struct line r={*c,j};
	return r;
}