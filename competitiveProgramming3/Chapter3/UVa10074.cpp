#include <iostream>
#define MAXN 110
using namespace std;

int landSum[MAXN][MAXN];

int main (){
	int n,m;
	while(cin >> n >> m && n){
		int tree;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> tree;
				landSum[i][j] = tree + landSum[i-1][j] + landSum[i][j-1] - landSum[i-1][j-1];
			}
		}

		int maxSize = 0,atual;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){

				for(int k=i;k<=n;k++){
					for(int l=j;l<=m;l++){
						atual = landSum[k][l] - landSum[i-1][l] - landSum[k][j-1] + landSum[i-1][j-1];
						if(atual == 0)
							maxSize = max(maxSize,(k-i+1)*(l-j+1));
					}

				}

			}

		}
		cout << maxSize << endl;
	}
	return 0;
}