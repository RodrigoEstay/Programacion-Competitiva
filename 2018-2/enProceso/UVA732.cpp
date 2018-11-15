#include <bits/stdc++.h>

using namespace std;

void seqCre(string w1, string w2, string pw, stack<char> s, int pos, bool *seq);

int main(){
	string word1, word2, pushWord;
	stack<char> opStack;
	vector<bool> seq;
	char checkEnd;
	while(true){
		word1.clear();
		word2.clear();
		pushWord.clear();
		seq=1;
		seqCheck=1;
		while(!opStack.empty()) opStack.pop();
		cin >> word1 >> word2;
		checkEnd=getchar();
		cout << "[\n";

		if(checkEnd==EOF) break;
	}
	return 0;
}

void seqCre(string w1, string w2, string pw, stack<char> s, int pos, vector<bool> seq){
	vector<bool> auxSeq(seq);
	string auxW1(w1);
	stack<char> auxS(s); 
	char aux;
	if(!w1.empty()){
		auxSeq.push_back(true);
		aux=auxW1[0];
		auxW1.erase(0);
		auxS.push(aux);
		seqCre(auxW1,w2,pw,auxS,pos+1,seq);
	}
}