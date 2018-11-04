/*
	UVa 10189 	Minesweeper
	How to Solve: Simply count the number of bombs surrounding each square
*/


#include <iostream>
#define MAXN 110
using namespace std;

char field[MAXN][MAXN];

int bombs(int i,int j){
	return (field[i-1][j] == '*') + (field[i+1][j] == '*') + (field[i][j-1] == '*') + (field[i][j+1] == '*')
			+ (field[i+1][j+1] == '*') + (field[i+1][j-1] == '*') + (field[i-1][j+1] == '*') + (field[i-1][j-1] == '*');
}

int main(){
	int n,m;
	int fields = 0;
	while(cin >> n >> m && n){
		if(fields)cout << endl;

		for(int i=0;i<MAXN;i++)
			for(int j=0;j<MAXN;j++)
				field[i][j] = '.';


		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin >> field[i][j];

		cout << "Field #" << ++fields << ":\n";

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(field[i][j] == '*')
					cout << "*";
				else
					cout << bombs(i,j);
			}
			cout << endl;
		}
	}
	return 0;
}