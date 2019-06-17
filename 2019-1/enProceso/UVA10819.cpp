#include <bits/stdc++.h>

using namespace std;

pair<int,int> maximumTotalFavour(int money, int pos, vector<pair<int,int> > items, int ***memo){
	if(pos == items.size()) return make_pair(0, 0);
	if(memo[pos][money][1]) return make_pair(memo[pos][money][0], memo[pos][money][1]);
	int newMoney;
	pair<int,int> favour1, favour2, maxFavour;
	newMoney = money - items[pos].first;
	if(newMoney < 0) favour1 = make_pair(0, 0);
	else{
		favour1 = maximumTotalFavour(newMoney, pos+1, items, memo);
		favour1.first += items[pos].first;
		favour1.second += items[pos].second;
	}
	favour2 = maximumTotalFavour(money, pos+1, items, memo);
	if(favour1.second > favour2.second) maxFavour = favour1;
	else maxFavour = favour2;
	memo[pos][money][0] = maxFavour.first;
	memo[pos][money][1] = maxFavour.second;
	return maxFavour;
}

int main(){
	int m, n, ***memo;
	vector<pair<int,int> > items;
	pair<int,int> aux;
	while(1){
		cin >> m >> n;
		if(getc(stdin) == EOF) break;
		if(m > 1800) m += 200;
		memo = new int**[n];
		for(int i=0 ; i<n ; ++i){
			memo[i] = new int*[m+1];
			for(int j=0 ; j<m+1 ; ++j){
				memo[i][j] = new int[2]();
			}
		}
		for(int i=0 ; i<n ; ++i){
			cin >> aux.first >> aux.second;
			items.push_back(aux);
		}
		aux = maximumTotalFavour(m, 0, items, memo);
		if(m < 2200 && m > 2000 && aux.first <= 2000) aux = maximumTotalFavour(m-200, 0, items, memo);
		cout << aux.first << " " << aux.second << endl;
		items.clear();
		for(int i=0 ; i<n ; ++i){
			for(int j=0 ; j<m+1 ; ++j){
				delete[] memo[i][j];
			}
			delete[] memo[i];
		}
		delete[] memo;
	}
	return 0;
}