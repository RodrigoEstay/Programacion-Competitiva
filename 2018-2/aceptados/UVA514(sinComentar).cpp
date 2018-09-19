#include <bits/stdc++.h>

using namespace std;

int main(){
	bool isPossible;
	int n, i, currentCoach;
	stack<int> coachesA;
	stack<int> coachesStation;
	while(1){
		cin >> n;
		if(!n) break;
		while(1){
			cin >> currentCoach;
			if(!currentCoach) break;
			while(!coachesA.empty())
				coachesA.pop();
			while(!coachesStation.empty())
				coachesStation.pop();
			isPossible=true;
			for(i=n ; i>0 ; --i)
				coachesA.push(i);
			for(i=0 ; i<n ; ++i){
				if(i) cin >> currentCoach;
				if(!coachesStation.empty() && coachesStation.top() == currentCoach) coachesStation.pop();
				else if(!coachesA.empty() && coachesA.top() <= currentCoach){
					while(coachesA.top() != currentCoach){
						coachesStation.push(coachesA.top());
						coachesA.pop();
					}
					coachesA.pop();
				}
				else isPossible=false;
			}
			if(isPossible) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << '\n';
	}
	return 0;
}