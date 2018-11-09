#include<bits/stdc++.h>

using namespace std;

int main(){
	char lastChar; 
	int currentValue, lastValue;
	bool isJolly, firstIt;
	int n;
	while(1){
		isJolly=true;
		firstIt=true;
		cin >> n;
		while(n--){
			cin >> currentValue;
			if(!isJolly) continue;
			if(!firstIt && abs(currentValue-lastValue)!=n+1) isJolly=false;
			lastValue=currentValue;
			if(firstIt) firstIt=false;
		}
		if(isJolly) cout << "Jolly\n";
		else cout << "Not jolly\n";
		lastChar=getchar();
		if(lastChar==EOF) break;
	}
	return 0;
}