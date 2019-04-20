#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

bool findValues(int *xyz, int A, int B, int C, int it);

// Se escanean los valores A, B y C, luego ya que x y z pueden ser negativos, se usa como
// consideracion un limite superior e inferior que sera la raiz de C (ya que en este se usan
// cuadrados y asi no depende de negativos o positivos) y menos 2 ya que al ser enteros, los
// demas valores pueden ser 1 o -1 y el mayor ser la raiz de C-2.

int main(){
	int N, A, B, C, xyz[3];
	cin >> N;
	while(N--){
		cin >> A >> B >> C;
		xyz[0] = (int) -sqrt(C-2);
		xyz[1] = (int) -sqrt(C-2);
		xyz[2] = (int) -sqrt(C-2);
		if(findValues(xyz, A, B, C, 0)) cout << xyz[0] << " " << xyz[1] << " " << xyz[2] << endl;
		else cout << "No solution." << endl;
	}
	return 0;
}

// Se utiliza busqueda exhaustiva por retroceso para encontrar los valores que cumplan las 3 condiciones.

bool findValues(int *xyz, int A, int B, int C, int it){

	// Solo existen 3 valores.

	if(it > 2) return false;

	// Ocupamos los limites descritos anteriormente.

	for(int i=(int) -sqrt(C-2) ; i<=(int) sqrt(C-2)+1 ; ++i){

		// Nos aseguramos que no se repitan los numeros.

		if(it == 0 && (xyz[1] == i || xyz[2] == i)) continue;
		else if(it == 1 && (xyz[0] == i || xyz[2] == i)) continue;
		else if(it == 2 && (xyz[0] == i || xyz[1] == i)) continue;

		// Comprobamos si se cumplen las condiciones.

		xyz[it] = i;
		if(xyz[2]+xyz[1]+xyz[0] == A && xyz[2]*xyz[1]*xyz[0] == B 
			&& xyz[2]*xyz[2]+xyz[1]*xyz[1]+xyz[0]*xyz[0] == C) return true;

		// Vemos si nos pasamos.

		if(xyz[2]+xyz[1]+xyz[0] > A){
			xyz[it] = (int) -sqrt(C-2);
			return false;
		}

		// Si no pasa ninguno de los anteriores, este valor puede pertenecer a la solucion.

		if(findValues(xyz, A, B, C, it+1)) return true;
	}
	xyz[it] = (int) -sqrt(C-2);
	return false;
}