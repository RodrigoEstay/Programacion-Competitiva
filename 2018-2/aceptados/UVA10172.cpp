#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	stack<int> cargo;
	vector< queue<int> > platformB;
	queue<int> tempQueue;
	int SET, N, S, Q, amount, i, dest, time, pos;
	bool finished;
	cin >> SET;

	//  En este caso consideraremos nuestro montacarga como un stack, las
	// plataformas B como filas, y generaremos un vector de filas para todas
	// las plataformas de cada estación.

	while(SET--){
		platformB.clear();
		cin >> N >> S >> Q;

		// Escaneamos cada fila de cada estación.

		for(i=0 ; i<N ; ++i){
			while(!tempQueue.empty())
				tempQueue.pop();
			cin >> amount;
			while(amount--){
				cin >> dest;
				tempQueue.push(dest);
			}
			platformB.push_back(tempQueue);
		}

		// Valores iniciales.

		finished=false;
		pos=0;
		time=0;

		// Calculamos el tiempo que nos tomaría.

		while(!finished){

			// Descargamos el montacarga hasta que la plataforma B esté llena.

			while(!cargo.empty() && platformB[pos].size() < Q){
				if(cargo.top() != pos+1) platformB[pos].push(cargo.top());
				cargo.pop();
				++time;
			}

			// 	Si es que la plataforma B está llena, pero nuestro siguiente
			// cargamento es para esta estación, entonces descargamos a la
			// platforma A.

			while(!cargo.empty() && cargo.top() == pos+1){
				cargo.pop();
				++time;
			}

			// Cargamos el montacarga de cargamentos de la fila de la plataforma B.

			while(cargo.size()<S && !platformB[pos].empty()){
				cargo.push(platformB[pos].front());
				platformB[pos].pop();
				++time;
			}

			// Checkeamos si terminamos.

			finished=cargo.empty();
			if(finished){
				for(i=0 ; i<N ; ++i)
					finished = finished && platformB[i].empty();
			}

			// si no, pasamos a la siguiente estación.

			if(!finished){
				time+=2;
				++pos;
			 	if(pos == N) pos=0;
			}
		}
		cout << time << '\n';
	}
	return 0;
}