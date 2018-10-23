#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, n, tempValue, maxCoins, prevValue, coins;
	long long unsigned int sum, sumMax;
	vector<int> values;
	cin >> T;
	while(T--){
		maxCoins=0;
		sumMax=0;
		values.clear();
		cin >> n;
		while(n--){
			cin >> tempValue;
			values.push_back(tempValue);
			sumMax+=tempValue;
		}
		vector<int>::iterator subIt=values.begin();
		while(sumMax!=0){
			prevValue=0;
			coins=0;
			sum=sumMax;
			while(sum!=0){
				for(vector<int>::iterator it=values.end()-1 ; it>=values.begin() ; it--){
					if(*it<=sum){
						sum-=*it;
						if(!prevValue || prevValue!=*it) coins++;
						prevValue=*it;
						break;
					}
				}
			}
			sumMax-=*subIt;
			subIt++;
			if(coins>maxCoins) maxCoins=coins;
		}
		cout << maxCoins << "\n";
	}
	return 0;
}