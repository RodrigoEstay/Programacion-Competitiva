#include <bits/stdc++.h>

using namespace std;

int main(){
	int K, divisaX, divisaY, tempX, tempY;
	while(1){
		cin >> K;
		if(K == 0) break;
		cin >> divisaX >> divisaY;
		for(int i = 0 ; i < K ; ++i){
			cin >> tempX >> tempY;
			if(abs(tempX) == abs(divisaX) || abs(tempY) == abs(divisaY)) cout << "divisa\n";
			else if(tempX > divisaX && tempY > divisaY) cout << "NE\n";
			else if(tempX > divisaX && tempY < divisaY) cout << "SE\n";
			else if(tempX < divisaX && tempY > divisaY) cout << "NO\n";
			else if(tempX < divisaX && tempY < divisaY) cout << "SO\n";
		}
	} 
	return 0;
}