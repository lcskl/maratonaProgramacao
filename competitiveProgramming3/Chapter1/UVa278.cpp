/*
  UVa278 - Chess
  How to solve: Try to find closed formulas for each piece.
*/

#include <iostream>

using namespace std;

int main (){
	int x;
	cin >> x;
	while(x--){
		char piece;
		int m,n;
		cin >> piece >> m >> n;

		switch(piece){
			case 'r':
				cout << min(m,n);
				break;
			case 'K':
				cout << ((m+m%2)/2)*((n+n%2)/2);
				break;
			case 'Q':
				cout << min(m,n);
				break;
			case 'k':
				cout << ((m+m%2)/2)*((n+n%2)/2) + (m/2)*(n/2);
				break;
		}
		cout << endl;
	}
	return 0;
}