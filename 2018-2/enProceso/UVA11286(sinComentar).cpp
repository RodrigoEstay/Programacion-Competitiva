#include <bits/stdc++.h>
#include <sstream> // estudiar esto (pasar de int a string).

using namespace std;

int main(){
	map<int[5],int> courses;
	int n, tempC[5], i; 
	while(1){
		cin >> n;
		if(n == 0) break;
		for(i=0 ; i<n ; ++i){
			cin >> tempC[0] >> tempC[1] >> tempC[2] >> tempC[3] >> tempC[4];
			sort(tempC, tempC+5);
			courses[tempC]++;
		}

	}
	return 0;
}