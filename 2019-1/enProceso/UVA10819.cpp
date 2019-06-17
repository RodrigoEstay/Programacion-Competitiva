#include <bits/stdc++.h>

using namespace std;

int maximumTotalFavour(int money, int pos, bool refund, vector<pair<int,int> > items, int **memo){
	if(pos == items.size()) return 0;
	if(memo[pos][money]) return memo[pos][money];
	int newMoney, favour1, favour2, maxFavour;
	newMoney = money - items[pos].first;
	if()
	if(refund && newMoney < 0 && newMoney > -200){
		newMoney += 200;
		refund = false;
	}
	else if(newMoney < 0) favour1 = 0;
	else favour1 = maximumTotalFavour(newMoney, pos+1, refund, items, memo) + items[pos].second;
	favour2 = maximumTotalFavour(money, pos+1, refund, items, memo);
	if(favour1 > favour2) maxFavour = favour1;
	else maxFavour = favour2;
	memo[pos][money] = maxFavour;
	return maxFavour;
}

int main(){
	int m, n, **memo;
	vector<pair<int,int> > items;
	pair<int,int> aux;
	bool refund;
	while(1){
		cin >> m >> n;
		if(getc(stdin) == EOF) break;
		if(m > 1800) refund = true;
		else refund = false;
		memo = new int*[n];
		for(int i=0 ; i<n ; ++i){
			memo[i] = new int[m+1]();
		}
		while(n--){
			cin >> aux.first >> aux.second;
			items.push_back(aux);
		}
		cout << maximumTotalFavour(m, 0, refund, items, memo) << endl;
		items.clear();
		for(int i=0 ; i<n ; ++i){
			delete[] memo[i];
		}
		delete[] memo;
	}
	return 0;
}