#include <iostream>
#include <string>
using namespace std;

#define MAXN 30

int max2dsum[MAXN][MAXN];

int main (){
	int t;
	cin >> t;
	while(t--){

		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				max2dsum[i][j] = 0;

		int n;
		string input;
		cin >> input;

		n = input.size();
		for(int i=1;i<=n;i++)
			max2dsum[1][i] = (input[i-1]-'0') + max2dsum[1][i-1];

		for(int i=2;i<=n;i++){
			cin >> input;
			for(int j=1;j<=n;j++){
				max2dsum[i][j] = max2dsum[i-1][j] + max2dsum[i][j-1] - max2dsum[i-1][j-1] + input[j-1]-'0';
			}
		}

		int melhor = 0, tam = 0,atual;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=i;k<=n;k++){
					for(int l=j;l<=n;l++){
						atual = max2dsum[k][l] - max2dsum[i-1][l] - max2dsum[k][j-1] + max2dsum[i-1][j-1];
						if(atual == (k-i+1)*(l-j+1))
							melhor = max(melhor,atual);
					}
				}
			}
		}

		cout << melhor << endl;
		if(t)cout << endl;
	}

	return 0;
}