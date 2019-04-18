#include <bits/stdc++.h>

using namespace std;

int main(){
	int t, n, sum, colSum, min, posMin, opti;
	vector< vector<int> > M;
	vector<int> ban;
	cin >> t;
	while(t--){
		for (int i=0; i<n; ++i){
			M[i].clear();
		}
		M.clear();
		ban.clear();
		cin >> n;
		M.resize(n);
		for (int i=0; i<n; ++i){
			M[i].resize(n);
		}
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<n ; ++j){
				cin >> M[i][j];
			}
		}
		sum=0;
		for(int k=0 ; k<n ; ++k){
			for(int j=0 ; j<n ; ++j){
				if(binary_search(ban.begin(), ban.end(), j)) continue;
				colSum=0;
				for (int i=k+1; i<n; ++i){
					colSum+=M[i][j];
				}
				if(j==0 || M[k][j]-colSum<min){
					min=M[k][j]-colSum;
					posMin=j;
				}
			}
			sum+=M[k][posMin];
			ban.push_back(posMin);
			sort(ban.begin(), ban.end());
		}
		cout << sum << endl;
	}
	return 0;
}