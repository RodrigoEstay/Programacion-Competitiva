#include <stdlib.h>
#include <stdio.h>

int main (){
	char tictactoe[3][4], i;
	int n;
	scanf("%d", &n);
	for(i=0;i<n;++i){
		scanf("%s%s%s", tictactoe[0], tictactoe[1], tictactoe[2]);
		printf("%s\n%s\n%s\n", tictactoe[0], tictactoe[1], tictactoe[2]);
	}
	return 0;
}
