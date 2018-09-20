#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	int K, divisaX, divisaY, tempX, tempY;
	while(1){
		cin >> K;
		if(K == 0) break;
		cin >> divisaX >> divisaY;

		//  Simplemente revisamos si las coordenasas son mayores, menores o iguales
		// a las coordenadas de la divisa, y simplemente imprimimos su dirección.

		for(int i = 0 ; i < K ; ++i){
			cin >> tempX >> tempY;
			if(abs(tempX) == abs(divisaX) || abs(tempY) == abs(divisaY)) cout << "divisa\n";
			else if(tempX > divisaX && tempY > divisaY) cout << "NE\n";
			else if(tempX > divisaX && tempY < divisaY) cout << "SE\n";
			else if(tempX < divisaX && tempY > divisaY) cout << "NO\n";
			else if(tempX < divisaX && tempY < divisaY) cout << "SO\n";
		}
	} 
	return 0;
}