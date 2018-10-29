#include <iostream>
using namespace std;

int main (){
	int a,b;
	while (cin >> a >> b && (a || b)){
		int resp;

		int n = min (a,b), m = max(a,b);

		if(n < 2)
			resp = n*m;
		else if(n==2){
			if(m%4 == 1)
				resp = (m+1);
			else
				resp = (m- m%4 -4*(m%4==0)) + 4;
		}else 
			resp = 	((m+m%2)/2)*((n+n%2)/2) + (m/2)*(n/2);
		
		cout << resp << " knights may be placed on a " << a << " row " << b << " column board.\n";
	}
	return 0;
}