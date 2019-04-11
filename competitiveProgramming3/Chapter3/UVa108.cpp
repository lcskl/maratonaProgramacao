#include <iostream>
using namespace std;

#define MAXN 110
int max2dsum[MAXN][MAXN];

int main (){
    int n,entrada;
    cin >> n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin >> entrada;
            max2dsum[i][j] = entrada + max2dsum[i-1][j] + max2dsum[i][j-1] - max2dsum[i-1][j-1];
        }

	int melhor = -999999999;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){

			for(int k=i;k<=n;k++){

				for(int l=j;l<=n;l++){
					melhor = max(melhor,max2dsum[k][l] - max2dsum[i-1][l] - max2dsum[k][j-1] + max2dsum[i-1][j-1]);
				}

			}

		}

	}

	cout << melhor << endl;

    return 0;
}