/*
	UVa 11459 	Snakes and Ladders
	How to Solve: Simply simulate the process. Take special care checking whether each player is at square 100
*/


#include <iostream>
#define MAXN 110
#define MAXP 1000100
using namespace std;

int snakes_ladders[MAXN];
int square_player[MAXP];

int main (){
	int t;
	cin >> t;
	while(t--){
		int players,numbSnkLddr,rolls;
		cin >> players >> numbSnkLddr >> rolls;

		for(int i=0;i<MAXN;i++)
			snakes_ladders[i] = -1;

		for(int i=0;i<players;i++)
			square_player[i] = 1;

		int a,b;
		for(int i=0;i<numbSnkLddr;i++){
			cin >> a >> b;
			snakes_ladders[a] = b;
		}

		int currentPlayer = 0,dice,final_square;
		bool gameOver = false;
		while(rolls--){
			cin >> dice;

			final_square = square_player[currentPlayer];

			for(int i=0;i<dice && !gameOver;i++){
				final_square++;

				if(final_square == 100)
					gameOver = true;
			}

			if(!gameOver && snakes_ladders[ final_square ] > 0)
				final_square = snakes_ladders[ final_square ];

			if(final_square == 100)
				gameOver = true;

			square_player[currentPlayer] = final_square;
			
			currentPlayer = (currentPlayer+1)%players;
		}
		for(int i=0;i<players;i++)
			cout << "Position of player " << i+1 << " is " << square_player[i] << ".\n";
	}
	return 0;
}