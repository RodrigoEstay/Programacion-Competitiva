#include <bits/stdc++.h>

using namespace std;

// Codigo hecho sin ayuda.

int main(){
	int t, s, a, f, aux;
	vector<int> st, av;
	cin >> t;

	//  Se ubican las direcciones de los amigos en vectores que luegos son ordenados,
	// y luego la ubicacion del almuerzo sera la media de cada coordenada, ya que
	// ese es el lugar que minimiza el camino recorrido por todos. (Primero se creia
	// que podia ser el promedio, pero este al ser muy afectado por amigos muy lejanos
	// se elijen distancias muy alejadas de los grupos grandes, mientras que la mediana
	// beneficia principalmente a los grupos grandes).

	while(t--){
		st.clear();
		av.clear();
		cin >> s >> a >> f;
		for(int i=0 ; i<f ; ++i){
			cin >> aux;
			st.push_back(aux);
			cin >> aux;
			av.push_back(aux);
		}
		sort(st.begin(),st.end());
		sort(av.begin(),av.end());

		//  Si la cantidad de amigos es impar, la mediana es la clasica, en caso contrario
		// se tiene que por regla decidida por los amigos, la calle y avenida debe ser la
		// menor, asi que entre los dos numeros de la mediana, se escoge el menor.

		if(f%2!=0) cout << "(Street: " << st.at(f/2) << ", Avenue: " << av.at(f/2) << ")\n";
		else cout << "(Street: " << st.at(f/2-1) << ", Avenue: " << av.at(f/2-1) << ")\n";
	}
	return 0;
}