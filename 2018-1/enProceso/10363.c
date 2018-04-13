#include <stdlib.h>
#include <stdio.h>

int main (){
	int N, cases, i, j, contX, contO, winX, winO;
	char tictac[3][4];
	scanf("%d", &N);
	for(cases=0;cases<N;++cases, winO=0, winX=0, contX=0, contO=0){
		scanf("%s%s%s", tictac[0], tictac[1], tictac[2]);
		for(i=0;i<3;++i){
			for(j=0;j<3;++j){
				if(tictac[i][j]=='X')
					++contX;
				else if(tictac[i][j]=='O')
					++contO;
			}
		}
		if(contX-contO<0 || contX-contO>=2){
			printf("no\n");
			continue;
		}
		for(i=0;i<3;i++){
			if(tictac[i][0]==tictac[i][1] && tictac[i][0]==tictac[i][2]){
				if(tictac[i][0]=='X')
					++winX;
				else if(tictac[i][0]=='O')
					++winO;
			}
			if(tictac[0][i]==tictac[1][i] && tictac[0][i]==tictac[2][i]){
				if(tictac[0][i]=='X')
					++winX;
				else if(tictac[0][i]=='O')
					++winO;
			}
		}
		if(tictac[0][0]==tictac[1][1] && tictac[0][0]==tictac[2][2] || tictac[0][2]==tictac[1][1] && tictac[0][2]==tictac[2][0]){
			if(tictac[1][1]=='X')
				++winX;
			else if(tictac[1][1]=='O')
				++winO;
		}
		if(winX+winO>1){
			printf("no\n");
			continue;
		}
		if(winO==1 && contX!=contO){
			printf("no\n");
			continue;
		}
		if(winX==1 && contO+1!=contX){
			printf("no\n");
			continue;
		}
		printf("yes\n");
	}
	return 0;
}