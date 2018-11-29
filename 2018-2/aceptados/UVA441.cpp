#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){

	// 	El vector s almacena la secuencia S entregada mientras que el vector game
	// definira las combinaciones a imprimir a traves de booleanos que siempre
	// seran 6 true y todo el resto false.

	int k, first=1, aux;
	vector<int> s;
	vector<bool> game;
	while(1){
		s.clear();
		game.clear();
		cin >> k;
		if(!k) break;
		else if(!first) cout << "\n";
		else first=0;
		for(int i=0 ; i<k ; ++i){
			cin >> aux;
			s.push_back(aux);
		}
		sort(s.begin(), s.end());
		for(int i=0 ; i<k ; ++i){
			if(i<6) game.push_back(true);
			else game.push_back(false);
		}

		// Aqui se va modifiando game y se  imprimen las secuencias.

		while(1){
			int cont=0;

			// Imprimimos.

			for(int i=0 ; i<game.size() ; ++i){
				if(game[i]){
					cont++;
					cout << s[i];
					if(cont!=6) cout << " ";
					else break;
				}
			}
			cout << "\n";

			// 	Revisamos si se imprimieron todas las combinaciones, basicamente
			// revisamos si todos los false estan al inicio juntos.

			if(!game.front()){
				bool foundFalse=false, shouldEnd=true;
				for(int i=game.size()-1 ; i>=0 ; --i){
					if(game[i] && foundFalse){
						shouldEnd=false;
						break;
					}
					if(!game[i]) foundFalse=true;
				}
				if(shouldEnd) break;
			}

			// 	Si el ultimo elemento es un false, entonces movemos el primer true que se
			// encuentre de derecha a izquierda hacia la izquierda.

			if(!game.back()){
				for(int i=game.size()-2 ; i>=0 ; --i){
					if(game[i]){
						game[i]=false;
						game[i+1]=true;
						break;
					}
				}
			}

			//  Si el ultimo elemento es un true, tenemos que mover todos los trues que
			// esten seguidos despues del ultimo, luego al encontrar el primer true que
			// no esté en los trues anteriores (es decir que lo separe un false almenos
			// del resto), entonces se ponen todos los trues una posicion despues de este.

			else{
				int contTrues=1, posFirstOne;
				bool falseFound=false;
				for(int i=game.size()-2 ; i>=0 ; --i){
					if(game[i]){
						contTrues++;
						if(falseFound){
							posFirstOne=i;
							break;
						}
					}
					else if(!game[i] && !falseFound) falseFound=true;
				}
				game[posFirstOne]=false;
				for(int i=posFirstOne+1 ; i<game.size() ; ++i){
					if(contTrues){
						game[i]=true;
						contTrues--;
					}
					else game[i]=false;
				}
			}
		}
	}
	return 0;
}