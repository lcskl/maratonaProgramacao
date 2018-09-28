/*
	UVa10114 - Horror Dash
	How to solve: Check the highest speed.
*/


#include <iostream>

using namespace std;

int main (){
	int t;
	cin >> t;
	for(int k=0;k<t;k++){
		int n;
		int speed,fastest = -1;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> speed;
			if(speed > fastest)
				fastest = speed;
		}
		cout << "Case " << k+1 << ": ";
		cout << fastest << endl;
	}
	return 0;
}