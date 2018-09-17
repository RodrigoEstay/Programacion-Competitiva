#include <bits/stdc++.h>

using namespace std;

int main(){
	int T, N, speed, maxSpeed, i;
	cin >> T;
	for(i=0;i<T;++i){
		maxSpeed=0;
		cin >> N;
		while(N--){
			cin >> speed;
			if(speed>maxSpeed) maxSpeed=speed;
		}
		printf("Case %d: %d\n", i+1, maxSpeed);
	}
	return 0;
}