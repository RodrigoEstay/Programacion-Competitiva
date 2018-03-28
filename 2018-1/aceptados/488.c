#include <stdio.h>
#include <stdlib.h>

int main (){
	int cases, ampl, freq, i, j, k, wave;
	scanf("%d", &cases);
	for(i=0;i<cases;i++){
		scanf("%d%d", &ampl, &freq);
		for(j=0;j<freq;j++){
			for(wave=1;wave<=ampl;wave++){
				for(k=0;k<wave;k++)
					printf("%d", wave);
				printf("\n");
			}
			for(wave=ampl-1;wave>0;wave--){
				for(k=0;k<wave;k++)
					printf("%d", wave);
				printf("\n");
			}
			if(i<cases-1 || j<freq-1)
				printf("\n");
		}
	}
	return 0;
}