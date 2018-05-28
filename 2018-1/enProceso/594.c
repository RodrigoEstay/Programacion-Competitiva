#include <stdlib.h>
#include <stdio.h>

int main(){
	char c;
	int num=0, num2, bytes[4], i, neg=0;
	while(1){
		c=getc(stdin);
		if(c==EOF || c=='\n'){
			if(neg)
				num=-num;
			num2=num;
			for(i=0;i<4;++i){
				bytes[i]=(char)num2;
				num2=num2>>8;
			}
			num2=(bytes[0]<<24)+(bytes[1]<<16)+(bytes[2]<<8)+(bytes[3]);
			printf("%d %d\n", num, num2);
			num=0, neg=0;
			if(c==EOF)
				return 0;
		}
		else if(c>='0' && c<='9')
			num=num*10+(c-'0');
		else if(c=='-')
			neg=1;
		printf("%d\n", num);
	}
}