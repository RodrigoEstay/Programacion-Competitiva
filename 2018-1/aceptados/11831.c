#include <stdlib.h>
#include <stdio.h>

// Programa hecho sin ayuda.

char changeDirection(char current, char command);

int main(){
	int N, M, S, i=0, j, exit, posx, posy, stickerCount;
	while(1){
		scanf("%d%d%d", &N, &M, &S);
		// Si se encuentran con los 0, se termina el programa.
		if(N==0 && M==0 && S==0) break;
		// Como vamos a escanear la tabla como string, le agregamos un 1 por la derecha para el '\0'
		char grid[N][M+1], command;
		for(i=0;i<N;++i)
			scanf("%s", grid[i]);
		exit=0;
		// El siguiente ciclo es para encontrar donde se encuentra el robor, almacenamos su posicion.
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
		getchar(); // para no escanear un salto de linea.
		stickerCount=0;
		// Escaneamos los comandos, y observamos si el comando es para rotar o avanzar.
		for(i=0;i<S;++i){
			scanf("%c", &command);
			// Si es para rotar, cambiamos hacia donde apunta.
			if(command=='E' || command=='D') grid[posy][posx]=changeDirection(grid[posy][posx],command);
			// Si es para ir hacia adelante, lo separamos en 4 casos posibles, los 4 son semejantes asi que
			// solo explicare uno.
			else if(command=='F'){
				if(grid[posy][posx]=='N'){
					// Si se sale del "mapa" seguimos con el siguiente comando, manteniendo su posicion.
					if(posy-1==-1) continue;
					// Si alfrente hay un pilar, seguimos manteniendo su posicion.
					if(grid[posy-1][posx]=='#') continue;
					// Si el siguiente es un sticker, aumentamos el conteo de stickers.
					if(grid[posy-1][posx]=='*') ++stickerCount;
					// Cambiamos la posicion del robot con la siguiente, manteniendo su orientacion, y luego
					// dejamos una linea, la cual fue usada para una mejor viualizacion del recorrido del robot
					// cuando se hizo este programa.
					grid[posy-1][posx]='N';
					grid[posy][posx]='-';
					posy-=1;
				}
				else if(grid[posy][posx]=='S'){
					if(posy+1==N) continue;
					if(grid[posy+1][posx]=='#') continue;
					if(grid[posy+1][posx]=='*') ++stickerCount;
					grid[posy+1][posx]='S';
					grid[posy][posx]='-';
					posy+=1;
				}
				else if(grid[posy][posx]=='O'){
					if(posx-1==-1) continue;
					if(grid[posy][posx-1]=='#') continue;
					if(grid[posy][posx-1]=='*') ++stickerCount;
					grid[posy][posx-1]='O';
					grid[posy][posx]='-';
					posx-=1;
				}
				else if(grid[posy][posx]=='L'){
					if(posx+1==M) continue;
					if(grid[posy][posx+1]=='#') continue;
					if(grid[posy][posx+1]=='*') ++stickerCount;
					grid[posy][posx+1]='L';
					grid[posy][posx]='-';
					posx+=1;
				} 
			}
		}
		printf("%d\n", stickerCount);
	}
	return 0;
}

// Esta funcion recive la orientacion actual del robot, y el comando de rotacion, luego retorna
// la orientacion que deberia tener el robot despues de ejecutar su comando.
char changeDirection(char current, char command){
	if(command=='D'){
		if(current=='N') return 'L';
		if(current=='O') return 'N';
		if(current=='S') return 'O';
		if(current=='L') return 'S';
	}
	if(command=='E'){
		if(current=='N') return 'O';
		if(current=='O') return 'S';
		if(current=='S') return 'L';
		if(current=='L') return 'N';
	}
}