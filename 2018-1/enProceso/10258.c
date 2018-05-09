#include <stdlib.h>
#include <stdio.h>

int main(){
	int N, problem, time, i;
	char name[100], sol;
	scanf("%d", &N);
	while(N--){
		while(1){
			getchar();
			char c=getchar();
			if(c=='\n' || c==EOF)
				break;
			scanf("%s %d %d %c", name, &problem, &time, &sol);
			printf("%s %d %d %c\n", name, problem, time, sol);
		}
		printf("\n");
	}
	return 0;
}