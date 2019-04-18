#include <bits/stdc++.h>

using namespace std;

void placeOffices(int *off, int contOff, int pos, int *people);
int distances(int *off, int* people);

int main(){
 	int n, t, people[25], off[5], row, col, am;
	cin >> t;
	while(t--){
		cin >> n;
		fill(people, people+25, 0);
		while(n--){
			cin >> row >> col >> am;
			people[row*5+col] = am;
		}
		placeOffices(off, 0, 0, people);
		for(int i=0 ; i<5 ; ++i) cout << off[i] << " ";
		cout << endl;
	}
	return 0;
}

void placeOffices(int *off, int contOff, int pos, int *people){
	if(contOff == 5 || pos > 25) return;
	int minDist = INT_MAX, dist1, dist2, auxOff[5];
	for(int i=0 ; i<contOff ; ++i) auxOff[i] = off[i];
	placeOffices(off, contOff, pos+1, people);
	auxOff[contOff] = pos;
	contOff++;
	placeOffices(auxOff, contOff, pos+1, people);
	dist1 = distances(off, people);
	dist2 = distances(auxOff, people);
	if(dist1 < dist2) return;
	if(dist1 > dist2){
		for(int i=0 ; i<5 ; ++i) off[i] = auxOff[i];
		return;
	}
}

int distances(int *off, int* people){
	int minDist, dist, x, totalDist;
	totalDist = 0;
	for(int i=0 ; i<25 ; ++i){
		if(people[i] == 0) continue;
		minDist = INT_MAX;
		for(int j=0 ; j<5 ; ++j){
			x = abs(i - off[j]);
			dist = (x/5 + x%5) * people[i];
			if(dist < minDist) minDist = dist;
		}
		totalDist += minDist;
	}
	return totalDist;
}