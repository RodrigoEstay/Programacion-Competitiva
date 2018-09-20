#include <bits/stdc++.h>

using namespace std;

// Programa hecho sin ayuda.

int main(){
	bool isPossible;
	int n, i, currentCoach;
	stack<int> coachesA;
	stack<int> coachesStation;

	//  Observamos que se trata de un problema de stacks, donde un stack es la linea A,
	// y otro es la estación.

	while(1){
		cin >> n;
		if(!n) break;
		while(1){
			cin >> currentCoach;
			if(!currentCoach) break;

			// Limpiamos el stack de A y de la estación.

			while(!coachesA.empty())
				coachesA.pop();
			while(!coachesStation.empty())
				coachesStation.pop();
			isPossible=true;

			// LLenamos la linea A con los vagones.

			for(i=n ; i>0 ; --i)
				coachesA.push(i);

			// Aquí revisamos si la salida de vagones por B es posible.

			for(i=0 ; i<n ; ++i){
				if(i) cin >> currentCoach; 

				// Revisamos si el vagón salió de la estación.

				if(!coachesStation.empty() && coachesStation.top() == currentCoach) coachesStation.pop();

				// Revisamos si el vagón estaba en A.

				else if(!coachesA.empty() && coachesA.top() <= currentCoach){

					// 	Si salió de A directo a B, todos los vagones que estaban antes
					// del que salió los dejamos en la estación.

					while(coachesA.top() != currentCoach){
						coachesStation.push(coachesA.top());
						coachesA.pop();
					}
					coachesA.pop();
				}

				// 	Si no se cumplen las condiciones anteriores, significa que la salida
				// a B no es posible.

				else isPossible=false;
			}
			if(isPossible) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << '\n';
	}
	return 0;
}