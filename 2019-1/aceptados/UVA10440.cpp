#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	queue<int> q;
	int c, n, t, m, aux, time, trips, firsts;
	cin >> c;
	for(int i=0 ; i<c ; i++){

		// Se colocan los autos en una queue.

		cin >> n >> t >> m;
		for(int j=0 ; j<m ; ++j){
			cin >> aux;
			q.push(aux);
		}
		time = 0;
		trips = 0;

		// 	Dejaremos que siempre el ultimo viaje lleve el ultimo auto,
		// de esta manera el ultimo viaje lleva n autos (o m si n>m),
		// por eso en el primer viaje debemos llevar m%n autos.
		// 	Si n%m = 0 significa que el ultimo viaje ya lleva n autos.

		firsts = m%n;
		for(int j=0 ; j<firsts ; ++j){
			time = q.front();
			q.pop();
		}
		if(firsts){
			trips++;
			time += 2*t;
		}

		// 	Ya que debemos tener los minimos viajes posibles, se usa greedy
		// donde intentamos llenar cada viaje independiente del tiempo de
		// llegada de los autos que se esperan.

		while(!q.empty()){
			for(int j=0 ; j<n ; ++j){
				if(q.front() > time) time = q.front();
				q.pop();
			}
			trips++;
			time += 2*t;
		}

		// El ultimo viaje solo cuenta el viaje de ida.

		time -= t;
		cout << time << " " << trips << endl;
	}
	return 0;
}