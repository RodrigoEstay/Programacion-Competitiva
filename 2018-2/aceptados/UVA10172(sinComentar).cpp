#include <bits/stdc++.h>

using namespace std;

int main(){
	stack<int> cargo;
	vector< queue<int> > platformB;
	queue<int> tempQueue;
	int SET, N, S, Q, amount, i, dest, time, pos;
	bool finished;
	cin >> SET;
	while(SET--){
		platformB.clear();
		cin >> N >> S >> Q;
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
		finished=false;
		pos=0;
		time=0;
		while(!finished){
			while(!cargo.empty() && platformB[pos].size() < Q){
				if(cargo.top() != pos+1) platformB[pos].push(cargo.top());
				cargo.pop();
				++time;
			}
			while(!cargo.empty() && cargo.top() == pos+1){
				cargo.pop();
				++time;
			}
			while(cargo.size()<S && !platformB[pos].empty()){
				cargo.push(platformB[pos].front());
				platformB[pos].pop();
				++time;
			}
			finished=cargo.empty();
			if(finished){
				for(i=0 ; i<N ; ++i)
					finished = finished && platformB[i].empty();
			}
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