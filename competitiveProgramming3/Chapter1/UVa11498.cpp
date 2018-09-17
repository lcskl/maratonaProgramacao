/*
	Problem: UVa11498 - Division of Nlogonia
	How to solve: Just implement if-else statements to check the location of query points
*/

#include <iostream>
using namespace std;

int main (){
	int k;
	while(cin >> k && k){
		int m,n;
		cin >> m >> n;
		int x,y;
		for(int i=0;i<k;i++){
			cin >> x >> y;
			if(x == m || y == n)cout << "divisa";
			else if(x > m && y > n)cout << "NE";
			else if(x > m) cout << "SE";
			else if(y > n) cout << "NO";
			else cout << "SO";

			cout << endl;
		}
	}

	return 0;
}