#include <bits/stdc++.h>

using namespace std;

int main(){
	bool isDoomed;
	int n, m, temp, coins;
	vector<int> diameters;
	vector<int> heights;
	while(true){

		// Valores iniciales.

		isDoomed=false;
		coins=0;
		diameters.clear();
		heights.clear();
		cin >> n >> m;

		// Si es que n y m son 0.

		if(!n & !m) break;

		// Escaneamos las medidas.

		while(n--){
			cin >> temp;
			diameters.push_back(temp);
		} 
		while(m--){
			cin >> temp;
			heights.push_back(temp);
		}

		// Si es que hay mas cabezas que caballeros, estamos perdidos.

		if(diameters.size() > heights.size()){
			cout << "Loowater is doomed!\n";
			continue;
		}

		// Ordenamos los vectores.

		sort(diameters.begin(),diameters.end());
		sort(heights.begin(),heights.end());

		// 	Para cada cabeza buscamos el primer caballero que pueda cortarla, si es que no hay
		// alguno que sea capaz, estamos perdidos. Pero si hay alguno que pueda, lo sumamos al
		// precio total.

		for(vector<int>::iterator itD=diameters.begin() ; itD!=diameters.end() ; itD++){
			isDoomed=true;
			for(vector<int>::iterator itH=heights.begin() ; itH!=heights.end() ; itH++){
				if(*itD <= *itH){
					coins+=*itH;
					heights.erase(itH);
					isDoomed=false;
					break;
				}
			}
			if(isDoomed) break;
		}
		if(isDoomed) cout << "Loowater is doomed!\n";
		else cout << coins << "\n";
	}
	return 0;
}