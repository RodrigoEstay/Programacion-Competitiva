#include <stdlib.h>
#include <stdio.h>

int main(){
	int t, T, N, i, j, martians[50000][2], jumps, seen[50000], currentPos, exit, maxJumps, maxJumpsPos;
	scanf("%d", &T);
	for(t=0;t<T;++t){
		scanf("%d", &N);
		maxJumps=-1, maxJumpsPos=0;
		for(i=0;i<N;++i)
			scanf("%d %d", &martians[i][0], &martians[i][1]);
		for(i=0;i<N;++i){
			jumps=0, exit=0, currentPos=i;
			while(1){
				printf("jumps=%d pos=%d i=%d N=%d %d %d\n", jumps, currentPos, i, t, martians[currentPos][0], martians[currentPos][1]);
				for(j=0;j<jumps;++j){
					if(seen[j]==martians[currentPos][0]){
						exit=1;
						break;
					}
				}
				if(exit) break;
				seen[jumps]=martians[currentPos][0];
				for(j=0;j<N;++j){
					if(martians[currentPos][1]==martians[j][0]){
						currentPos=j;
						break;
					}
				}
				++jumps;
			}
			if(maxJumps<jumps) maxJumps=jumps, maxJumpsPos=i;
			else if(maxJumps==jumps && martians[i][0]<martians[maxJumpsPos][0]) maxJumpsPos=i;
		}
		printf("Case %d: %d\n", t+1, martians[maxJumpsPos][0]);
	}
	return 0;
}