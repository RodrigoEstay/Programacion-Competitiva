#include <bits/stdc++.h>

using namespace std;

void seqCre(string w1, string w2, stack<char> s, int pos, vector<bool> seq);

// Programa hecho sin ayuda.

//	Escaneamos las palabras, y si se llega a que el caracter escaneado despues
// de las palabras es EOF o si las palabras escaneadas son vacias. Mientras
// tanto mandamos las palabras a una funcion que imprime las secuencias.

int main(){
	string word1, word2;
	stack<char> opStack;
	vector<bool> seq;
	char checkEnd;
	while(true){
		word1.clear();
		word2.clear();
		while(!opStack.empty()) opStack.pop();
		cin >> word1 >> word2;
		if(word1.empty() && word2.empty()) break;
		checkEnd=getchar();
		cout << "[\n";
		seqCre(word1,word2,opStack,0,seq);
		cout << "]\n";
		if(checkEnd==EOF) break;
	}
	return 0;
}

// 	Funcion recursiva que recive las palabras, un stack para simular las operaciones
// descritas en el problema, la posicion de la segunda palabra en la que va, y una
// secuencia de booleanos que representan los i y o.
// 	Se revisa si se puede tener el caso de poner un i y un o en cada iteracion, si se
// puede se manda el resto de lo que queda denuevo a la funcion, asi hasta que la
// secuancia de booleanos es del mismo largo que dos veces el largo de las palabras.

void seqCre(string w1, string w2, stack<char> s, int pos, vector<bool> seq){
	if(seq.size()==2*w2.size()){
		for(int i=0 ; i<seq.size() ; ++i){
			if(seq[i]) cout << "i";
			else cout << "o";
			if(i!=seq.size()-1) cout << " ";
		}
		cout << "\n";
		return;
	}
	vector<bool> auxSeq(seq);
	string auxW1(w1);
	stack<char> auxS(s); 
	char aux;
	if(!w1.empty()){
		auxSeq.push_back(true);
		aux=auxW1[0];
		auxW1.erase(auxW1.begin());
		auxS.push(aux);
		seqCre(auxW1,w2,auxS,pos,auxSeq);
	}
	if(!s.empty() && s.top()==w2[pos]){
		s.pop();
		seq.push_back(false);
		seqCre(w1,w2,s,pos+1,seq);
	}
}