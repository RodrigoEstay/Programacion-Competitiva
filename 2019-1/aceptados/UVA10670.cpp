#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.


// Funcion usada por sort().

int cmpfunc(pair<string,int> a, pair<string,int> b){
	if(a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(){
	int cases, n, m, l, a, b, sum, amountB, wl;
	string line, name;
	vector<pair<string, int> > agen;
	cin >> cases;
	for(int i=0 ; i<cases ; ++i){
		agen.clear();
		cin >> n >> m >> l;
		while(l--){

			// Toda esta seccion separamos cada strin en nombre, a y b.

			cin >> line;
			int j = 0;
			name.clear();
			while(j < line.length()){
				if(line[j] == ':') break;
				name.push_back(line[j]);
				++j;
			}
			++j;
			a = 0;
			while(j < line.length()){
				if(line[j] == ',') break;
				a = a*10 + line[j] - '0';
				++j;
			}
			++j;
			b = 0;
			while(j < line.length()){
				b = b*10 + line[j] - '0';
				++j;
			}

			// Aqui calculamos el costo minimo para llegar exactamente a m con greedy.

			sum = 0;
			wl = n;
			while(wl > m){
				amountB = wl/2;
				if(wl%2) amountB++;
				if(a > b/amountB && wl-amountB >= m){
					sum += b;
					wl = wl/2;
				}
				else{
					sum += a;
					--wl;
				}
			}
			agen.push_back(make_pair(name, sum));
		}

		// Imprimimos como lo especifica el problema.

		sort(agen.begin(), agen.end(), cmpfunc);
		cout << "Case " << i+1 << endl;
		for(int j=0 ; j<agen.size() ; ++j){
			cout << agen[j].first << " " << agen[j].second << endl;
		}
	}
	return 0;
}