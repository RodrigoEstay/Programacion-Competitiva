#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Codigo hehco sin ayuda.

char changeDirection(char current, char command);
int lineScan(char *line);

int main(){
	int maxX, maxY, exit=0, i, j, robotInfo[3], num, spaceCont, countFallen=0, fallenPos[30000][2], safe, lost;
	char line[1000];
	scanf("%d%d", &maxX, &maxY);
	getchar(); // Para evitar el salto de linea.
	while(1){
		num=0, spaceCont=0, safe=0, lost=0;
		lineScan(line);
		// El siguiente ciclo es para asignar los valores de cada robot, su posicion en X, en Y y su orientacion.
		for(i=0;*(line+i)!='\0';++i){
			if(*(line+i)>='0' && *(line+i)<='9') num=num*10+*(line+i)-'0';
			if(*(line+i)=='W' || *(line+i)=='S' || *(line+i)=='E' || *(line+i)=='N') robotInfo[2]=*(line+i);
			if(*(line+i)==' '){
				if(spaceCont) robotInfo[1]=num;
				else{
					robotInfo[0]=num;
					num=0, spaceCont=1;
				}
			}
		}
		// Si al final de la linea de comandos, se encuentra un EOF, entonces mas adelante se saldra del programa.
		if(lineScan(line)) exit=1;
		// Ciclo para ejecutar los comandos de los robots.
		for(i=0;*(line+i)!='\0';++i){
			// Si esta en una casilla con la escencia de un robot que se callo, y ademas se le dice que avance
			// y ademas el comando anterior fue que avance, entonces este robot no se movera y seguira con el
			// siguiente comando. Si se le da un comando nuevo, entonces cambio su orientacion y ya no estara
			// seguro.
			if(safe){
				if(*(line+i-1)=='F' && *(line+i)=='F') continue;
				else safe=0;
			}
			// Si el comando es que rote, le asignamos al robot su nueva orientacion.
			if(*(line+i)=='R' || *(line+i)=='L') robotInfo[2]=changeDirection((char)robotInfo[2], *(line+i));
			// Si es que su comando no es una rotacion, entonces es que avance, ejecutamos el caso
			// correspondiente a una de las cuatro orientaciones posibles.
			else{
				if(robotInfo[2]=='N') robotInfo[1]+=1;
				else if(robotInfo[2]=='E') robotInfo[0]+=1;
				else if(robotInfo[2]=='S') robotInfo[1]-=1;
				else if(robotInfo[2]=='W') robotInfo[0]-=1;
			}
			// Si es que se sale del "mapa", se ejecuta el siguiente codigo.
			if(robotInfo[0]==-1 || robotInfo[0]==maxX+1 || robotInfo[1]==-1 || robotInfo[1]==maxY+1){
				// Hacemos que las cordenadas del robot vuelvan a ser las que tenia antes de caerse.
				if(robotInfo[0]<0) robotInfo[0]+=1;
				else if(robotInfo[0]==maxX+1) robotInfo[0]-=1;
				else if(robotInfo[1]<0) robotInfo[1]+=1;
				else if(robotInfo[1]==maxY+1) robotInfo[1]-=1;
				// Observamos si en la casilla que esta el robot presenta la escencia de otro robot
				// que se alla caido desde esa casilla.
				for(j=0;j<countFallen;++j){
					if(fallenPos[j][0]==robotInfo[0]){
						if(fallenPos[j][1]==robotInfo[1]){
							safe=1;
							break;
						}
					}
				}
				// Si no presentaba una escencia, entonces hacemos que el robot se caiga, registramos
				// su posicion previa a caerse con escencia, y luego salimos del ciclo para que se dejen
				// de ejecutar comandos de este robot.
				if(!safe){
					fallenPos[countFallen][0]=robotInfo[0];
					fallenPos[countFallen][1]=robotInfo[1];
					++countFallen;
					lost=1;
					break;
				}
			}
		}
		printf("%d %d %c", robotInfo[0], robotInfo[1], robotInfo[2]);
		if(lost) printf(" LOST");
		if(exit) break;
		else printf("\n");
	}
	return 0;
}

// Esta funcion simplemente devuelve la nueva orientacion del robot despues de ejecutar el comando.
char changeDirection(char current, char command){
	if(command=='R'){
		if(current=='N') return 'E';
		if(current=='E') return 'S';
		if(current=='S') return 'W';
		if(current=='W') return 'N';
	}
	if(command=='L'){
		if(current=='N') return 'W';
		if(current=='E') return 'N';
		if(current=='S') return 'E';
		if(current=='W') return 'S';
	}
}

// Esta funcion escanea una linea.
int lineScan(char *line){
	int pos=0;
	char c;
	while(1){
		c=getchar();
		if(c==EOF || c=='\n') break;
		*(line+pos)=c;
		++pos;
	}
	*(line+pos)='\0';
	if(c=='\n') return 0;
	if(c==EOF){
		return 1;
	}
}