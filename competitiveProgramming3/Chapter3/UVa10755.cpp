/*
	UVa10755	Garbage Heap
	How to solve it? Note that we need to calculate all sub-parallelepipeds sums. For that, it is enough to implement a MAX2DSUM strategy for 2 of its dimensions
					 and use a MAX1DSUM (Kadane's Algotihm). It is possible to expand MAX2D strategy into a 3D approach, but it is quite boring to think of all the
					 cases necessary to correctly implement inclusion-exclusion method.

*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 30

long long int garbage_piece;
long long int max2dSum[MAXN][MAXN][MAXN];

int main (){
	int t;
	cin >> t;
	while(t--){
		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				for(int k=0;k<MAXN;k++)
					max2dSum[i][j][k] = 0;

		int a,b,c;
		cin >> a >> b >> c;

		long long int best = 0;

		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				for(int k=1;k<=c;k++){
					cin >> garbage_piece;
					best += garbage_piece;
					max2dSum[i][j][k] = max2dSum[i][j-1][k] + max2dSum[i][j][k-1] - max2dSum[i][j-1][k-1] + garbage_piece;
				}
			}
		}
		
		long  long int section_value;
		long long int current;

		for(int j=1;j<=b;j++){
			for(int k=1;k<=c;k++){

				for(int l=j;l<=b;l++){
					for(int m=k;m<=c;m++){
						current = 0;

						for(int i=1;i<=a;i++){
							section_value = max2dSum[i][l][m] - max2dSum[i][j-1][m] - max2dSum[i][l][k-1] + max2dSum[i][j-1][k-1];

							current += section_value;

							best = max(current,best);
							if(current < 0)
								current = 0;
							
						}
					}
				}
			}
		}
		cout << best << endl;
		if(t)cout << endl;
	}
	return 0;
}