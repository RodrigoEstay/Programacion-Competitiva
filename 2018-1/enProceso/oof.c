#include <stdio.h>
#include <stdlib.h>

int main(){
	char c[100000];
	int num=0, i, neg=0, start=-1, fin=0;
	scanf("%[^EOF]", c);
	printf("%s\n", c);
	while(1){
		for(i=start+1;c[i]!='\n';++i){
			if(c[i]=='-')
				neg=1;
			else if(c[i]>='0' && c[i]<='9')
				num=num*10+c[i]-'0';
			else{
				if(neg)
					num=-num;
				printf("%d\n", num);
				num=0;
				neg=0;
				if(c[i]=='\0'){
					return 0;
				}
			}
		}
		start=i;
		if(neg)
			num=-num;
		printf("%d\n", num);
		num=0;
		neg=0;
		printf("\n");
		if(fin)
			return 0;
	}
	return 0;
}