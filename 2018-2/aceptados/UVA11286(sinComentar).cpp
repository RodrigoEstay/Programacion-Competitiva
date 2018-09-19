#include <bits/stdc++.h>

using namespace std;

int main(){
	map<string ,int> courses;
	int n, tempC[5], i, maxT, winners;
	ostringstream convert;
	while(1){
		cin >> n;
		if(n == 0) break;
		for(i=0 ; i<n ; ++i){
			convert.str(string());
			cin >> tempC[0] >> tempC[1] >> tempC[2] >> tempC[3] >> tempC[4];
			sort(tempC, tempC+5);
			convert << tempC[0] << tempC[1] << tempC[2] << tempC[3] << tempC[4];
			courses[convert.str()]++;
		}
		maxT=0, winners=0;
		for(map<string,int>::iterator j=courses.begin() ; j!=courses.end() ; ++j)
			if(j->second > maxT) maxT=j->second;
		for(map<string,int>::iterator j=courses.begin() ; j!=courses.end() ; ++j)
			if(j->second == maxT) winners+=j->second;
		cout << winners << "\n";
		courses.clear();
	}
	return 0;
}