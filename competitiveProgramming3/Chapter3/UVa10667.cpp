#include <iostream>
using namespace std;
#define MAXS 110

int board[MAXS][MAXS];
int max2dsum[MAXS][MAXS];

int main (){
	int p;
	cin >> p;
	while(p--){
		int s;
		cin >> s;

		for(int i=0;i<MAXS;i++)
		for(int j=0;j<MAXS;j++){
			board[i][j] = 0;
			max2dsum[i][j] =0;
		}


		int n,r1,c1,r2,c2;
		cin >> n;
		for(int k=0;k<n;k++){
			cin >> r1 >> c1 >> r2 >> c2;
			for(int i=r1;i<=r2;i++)
			for(int j=c1;j<=c2;j++)
				board[i][j] = 1;
		}


		for(int i=1;i<=s;i++){
			for(int j=1;j<=s;j++){
				max2dsum[i][j] = board[i][j] + max2dsum[i-1][j] + max2dsum[i][j-1] - max2dsum[i-1][j-1];
			}
		}

		int maxArea = 0,atual;
		for(int i=1;i<=s;i++){
			for(int j=1;j<=s;j++){

				for(int k=i;k<=s;k++){
					for(int l=j;l<=s;l++){
						atual = max2dsum[k][l] - max2dsum[i-1][l] - max2dsum[k][j-1] + max2dsum[i-1][j-1];
						if(atual == 0)
							maxArea = max(maxArea,(k-i+1)*(l-j+1));
					}

				}
			}

		}
		cout << maxArea << endl;
	}
	return 0;
}