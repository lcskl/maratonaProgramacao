/*
	UVa10684 - Jackpot
	How to solve it? Max 1D Range Sum -> Cumulative Sum until it is worth it (CumulSum > 0). Otherwise start another Cumulative Sum at next position.
*/

#include <iostream>
#define MAXN 10010
using namespace std;

int bets[MAXN];

int main (){
	int n;
	while(cin >> n && n){
		for(int i=0;i<n;i++)
			cin >> bets[i];

		int current_streak, best_streak;
		current_streak = 0;
		best_streak = 0;

		for(int i=0;i<n;i++){
			current_streak += bets[i];


			best_streak = max(best_streak,current_streak);
			current_streak = max(0,current_streak);
		}

		if(best_streak)
			cout << "The maximum winning streak is " << best_streak << ".";
		else
			cout << "Losing streak.";
		cout << endl;
	}
	return 0;
}