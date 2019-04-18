#include <bits/stdc++.h>

using namespace std;

bool findValues(int *xyz, int A, int B, int C, int it);

int main(){
	int N, A, B, C, xyz[3];
	cin >> N;
	while(N--){
		cin >> A >> B >> C;
		xyz[0] = (int) -sqrt(C-2);
		xyz[1] = (int) -sqrt(C-2);
		xyz[2] = (int) -sqrt(C-2);
		if(findValues(xyz, A, B, C, 0)) cout << xyz[0] << " " << xyz[1] << " " << xyz[2] << endl;
		else cout << "No solution." << endl;
	}
	return 0;
}

bool findValues(int *xyz, int A, int B, int C, int it){
	if(it > 2) return false;
	for(int i=(int) -sqrt(C-2) ; i<=(int) sqrt(C-2)+1 ; ++i){
		if(it == 0 && (xyz[1] == i || xyz[2] == i)) continue;
		else if(it == 1 && (xyz[0] == i || xyz[2] == i)) continue;
		else if(it == 2 && (xyz[0] == i || xyz[1] == i)) continue;
		xyz[it] = i;
		if(xyz[2]+xyz[1]+xyz[0] == A && xyz[2]*xyz[1]*xyz[0] == B 
			&& xyz[2]*xyz[2]+xyz[1]*xyz[1]+xyz[0]*xyz[0] == C) return true;
		if(xyz[2]+xyz[1]+xyz[0] > A){
			xyz[it] = (int) -sqrt(C-2);
			return false;
		}
		if(findValues(xyz, A, B, C, it+1)) return true;
	}
	xyz[it] = (int) -sqrt(C-2);
	return false;
}