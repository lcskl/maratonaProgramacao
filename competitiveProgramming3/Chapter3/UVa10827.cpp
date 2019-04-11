/*
    UVa10827 - Maximum sum on a torus
    Solution: Although not stated, Torus can be wrapped around BOTH HORIZONTALLY AND VERTICALLY!. Just Build 2n x 2n matrix and apply MAX 2d RANGE SUM.
*/

#include <iostream>
using namespace std;

#define MAXN 160

int maxSum[MAXN][MAXN];
int input[MAXN][MAXN];

int main (){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            maxSum[i][j] = 0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                cin >> input[i][j];
                input[i+n][j] = input[i][j];
                input[i][j+n] = input[i][j];
                input[i+n][j+n] = input[i][j];
        }
        
        int best = -999999999;
        for(int i=1;i<=2*n ;i++)
        for(int j=1;j<=2*n;j++)
            maxSum[i][j] = input[i][j] +maxSum[i][j-1] + maxSum[i-1][j] - maxSum[i-1][j-1];

        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=2*n;j++)
                for(int k=i;k<=min(i+n-1,2*n);k++)
                    for(int l=j;l<=min(j+n-1,2*n);l++)
                        best = max(best,maxSum[k][l]-maxSum[k][j-1]-maxSum[i-1][l]+maxSum[i-1][j-1]);
            
        cout << best << endl;
    }

    return 0;
}