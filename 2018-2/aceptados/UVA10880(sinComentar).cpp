#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<long long int> divisors;
	int N;
	cin >> N;
	long long int C, R;
	for(int i=0;i<N;++i){
		cin >> C >> R;
		printf("Case #%d:", i+1);
		for(int j=1 ; j<=sqrt(C-R) ; ++j){
			if( (C-R) % j == 0){
				if(j > R)divisors.push_back(j);
				int alt=((C-R)/j);
				if( ((C-R) % alt == 0) && alt != j && alt > R) divisors.push_back(alt);
			}
		}
		sort(divisors.begin(), divisors.end());
		for(vector<long long int>::const_iterator k = divisors.begin(); k != divisors.end() ; ++k){
			if(k == divisors.begin()) cout << " ";
			cout << *k;
			if(k != divisors.end()-1) cout << " ";
		}
		if(R == C) cout << " " << 0;
		cout << "\n";
		divisors.clear();
	}
	return 0;
}