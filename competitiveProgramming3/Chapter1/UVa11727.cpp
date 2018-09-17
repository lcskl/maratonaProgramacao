/*
	UVa11727 - Cost Cutting
	How to solve: Simple Min, Max Queries
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main (){
	int k;
	cin >> k;
	int a,b,c;
	for(int i=0;i<k;i++){
		cin >> a >> b >> c;
		cout << "Case " << i+1 << ": " << (a+b+c) - min(a,min(b,c)) - max(a,max(b,c)) << endl;
	}

	return 0;
}