#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	int T, N, speed, maxSpeed, i;
	cin >> T;

	//  Para revisar a que velocidad debe ir el payaso, debemos revisar
	// cual es la velocidad del mas rápido de los que lo siguen, y el
	// payaso deberá ir a la par con el. Asi que se resume a un problema
	// de encontrar el máximo valor.

	for(i=0;i<T;++i){
		maxSpeed=0;
		cin >> N;
		while(N--){
			cin >> speed;
			if(speed>maxSpeed) maxSpeed=speed;
		}
		printf("Case %d: %d\n", i+1, maxSpeed);
	}
	return 0;
}