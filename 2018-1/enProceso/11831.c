#include <stdlib.h>
#include <stdio.h>

int main(){
	int N, M, S, i, j, exit, posx, posy;
	scanf("%d %d %d", &N, &M, &S);
	char grid[N][M], command;
	for(i=0;i<N;++i)
		scanf("%s", grid[i]);
	exit=0;
	for(i=0;i<N;++i){
		for(j=0;j<M;++j){
			if(grid[i][j]=='N' || grid[i][j]=='S' || grid[i][j]=='L' || grid[i][j]=='O'){
				posy=i, posx=j;
				exit=1;
				break;
			}
			if(exit) break;
		}
	}
	for(i=0;i<S;++i){
		scanf("%c", &command);
		if(c=='E' || c=='D') grid[posy][posx]=changeDirection(grid[posy][posx],command);
		else if(c=='F'){
			if(grid[posy][posx]=='N'){
				if(grid[posy])
			}
		}
	}
	return 0;
}

char changeDirection(char current, char command){
	if(command=='D'){
		if(command=='N') return 'L';
		if(command=='O') return 'N';
		if(command=='S') return 'O';
		if(command=='L') return 'S';
	}
	if(command=='E'){
		if(command=='N') return 'O';
		if(command=='O') return 'S';
		if(command=='S') return 'L';
		if(command=='L') return 'N';
	}
}