#include <stdio.h>
#include <stdlib.h>

int main(){
	char c;
	int num=0;
	while(c=fgetc(stdin)!='\n'){
		printf("%c %d ", c, (int)c);
		if(c>='0' && c<='9')
			num=num*10+c-'0';
		else{
			printf("%d\n", num);
			num=0;
		}
	}
	printf("\n");
	return 0;
}