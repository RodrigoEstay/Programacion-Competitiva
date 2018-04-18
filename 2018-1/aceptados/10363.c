#include <stdlib.h>
#include <stdio.h>

/* Codigo hecho por mi cuenta. */

int main (){
	int N, cases, i, j, contX, contO, winX, winO;

	/* Ocupamos una matriz de 3x4 ya que almacenaremos las lineas escaneadas como string
	por lo tanto debe tener espacio para '\0'. */

	char tictac[3][4];
	scanf("%d", &N);
	for(cases=0;cases<N;++cases, winO=0, winX=0, contX=0, contO=0){
		scanf("%s%s%s", tictac[0], tictac[1], tictac[2]);

		/* Contamos el numero de X y de O. */

		for(i=0;i<3;++i){
			for(j=0;j<3;++j){
				if(tictac[i][j]=='X')
					++contX;
				else if(tictac[i][j]=='O')
					++contO;
			}
		}

		/* Si el numero de O es mayor que X, entonces el juego de gato no es posible,
		de la misma manera si el numero de X es mayor por dos unidades al numero de 
		O, tampoco es posible. */

		if(contX-contO<0 || contX-contO>=2){
			printf("no\n");
			continue;
		}

		/* Observamos si X o O ganan en alguna fila o columna, */

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

		/* Observamos si X o O ganan en diagonal. */

		if(tictac[0][0]==tictac[1][1] && tictac[0][0]==tictac[2][2] || tictac[0][2]==tictac[1][1] && tictac[0][2]==tictac[2][0]){
			if(tictac[1][1]=='X')
				++winX;
			else if(tictac[1][1]=='O')
				++winO;
		}

		/* Si O gano, se debe cumplir que el numero de X y O deben ser iguales, Si X gana
		el numero de X debe ser 1 mayor al numero de O. En casos contrarios el juego de gato
		no es posible. */ 

		if(winO==1 && contX!=contO){
			printf("no\n");
			continue;
		}
		if(winX==1 && contO+1!=contX){
			printf("no\n");
			continue;
		}

		/* Si no se cumplieron ninguna condicion anterior, entonces el juego de gato si es posible. */

		printf("yes\n");
	}
	return 0;
}