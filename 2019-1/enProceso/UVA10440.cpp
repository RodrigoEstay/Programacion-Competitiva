#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	queue<int> q;
	int c, n, t, m, aux, time, cont, trips, noWaits;
	cin >> c;
	for(int i=0 ; i<c ; i++){
		cin >> n >> t >> m;
		noWaits = m%n;
		while(m--){
			cin >> aux;
			q.push(aux);
		}
		time = 0;
		trips = 0;
		while(!q.empty()){
			cont = 0;
			while(!q.empty() && q.front() <= time && cont < n){
				q.pop();
				cont++;
			}
			while(!q.empty() && cont < n && q.size() != n){
				time++;
				if(q.front() <= time){
					q.pop();
					cont++;
					if(noWaits){
						noWaits--;
						if(!noWaits) break;
					}
				}
			}
			if(q.size() <= n-cont){
				if(time < q.back()) time = q.back();
				while(!q.empty())
					q.pop();
			}
			trips++;
			if(q.empty()) time += t;
			else time += 2*t;
		}
		cout << time << " " << trips;
		if(i != c-1) cout << endl;
	}
	return 0;
}