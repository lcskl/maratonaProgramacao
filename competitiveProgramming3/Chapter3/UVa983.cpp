#include <iostream>
using namespace std;

#define MAXN 1010
int max2dsum[MAXN][MAXN];

int main (){
	int n,m;
	bool first = true;
	while(cin >> n >> m && !cin.eof()){
		if(!first) cout << endl;
		first = false;

		for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			max2dsum[i][j] = 0;

		int matrix[n+1][n+1];
		for(int i=n;i>=1;i--){
			for(int j=1;j<=n;j++){
				cin >> matrix[i][j];
			}
		}



		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				//cout << matrix[i][j] << " ";
				max2dsum[i][j] = matrix[i][j] + max2dsum[i-1][j] + max2dsum[i][j-1] - max2dsum[i-1][j-1];
			}
			//cout << endl;
		}
		//cout << endl << endl;

		int output_matrix[n-m+2][n-m+2];

		for(int i=m;i<=n;i++){
			for(int j=m;j<=n;j++){
				output_matrix[i-m+1][j-m+1] = max2dsum[i][j] - max2dsum[i-m][j] - max2dsum[i][j-m] + max2dsum[i-m][j-m];
			}
		}
		int total = 0;
		for(int i=n-m+1;i>=1;i--){
			for(int j=1;j<=n-m+1;j++){
				cout << output_matrix[i][j] << endl;
				total += output_matrix[i][j];
			}
		}
		cout << total << endl;
	}


	return 0;
}