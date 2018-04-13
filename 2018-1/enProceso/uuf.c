#include <stdlib.h>
#include <stdio.h>

int main (){
	char tictactoe[3][4];
	int n, i, k, j;
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%s%s%s", tictactoe[0], tictactoe[1], tictactoe[2]);
		for(j=0;j<3;++j){
			for(k=0;k<3;++k)
				printf("%c", tictactoe[j][k]);
			printf("\n");
		}
	}
	return 0;
}
