/*
    UVa11951 - Area
    Solution: Max 2D Sum -> if cost of area is affordable, then check whether it is the maximum area achieved.
*/

#include <iostream>
using namespace std;

#define MAXN 110
long long int area[MAXN][MAXN];

int main (){
    int t,current_case = 0;
    cin >> t;
    while(t--){
        current_case++;

        for(int i=0;i<MAXN;i++)
            for(int j=0;j<MAXN;j++)
                area[i][j] = 0;

        int n,m,max_price;
        cin >> n >> m >> max_price;

        int price;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> price;
                area[i][j] = price + area[i-1][j] + area[i][j-1] - area[i-1][j-1];
            }
        }

        int max_area = 0;
        long long int cost = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=i;k<=n;k++){
                    for(int l=j;l<=m;l++){
                        if((area[k][l] - area[k][j-1] - area[i-1][l] + area[i-1][j-1]) <= max_price && ((k-i+1)*(l-j+1)) >= max_area){
                             
                            if(max_area == (k-i+1)*(l-j+1))
                                cost = min(cost,area[k][l] - area[k][j-1] - area[i-1][l] + area[i-1][j-1]);
                            else
                            {
                                cost = area[k][l] - area[k][j-1] - area[i-1][l] + area[i-1][j-1];
                            }
                            max_area = (k-i+1)*(l-j+1);
                        }
                    }
                }
            }
        }


        cout << "Case #" << current_case << ": " << max_area << " " << cost << endl;
    }

    return 0;
}