/*
	UVa10114 - Event Planning
	How to solve: Test whether each hotel has capacity for everyone in the group and the budget is enough.
				  From these Hotels choose the cheaper.
*/

#include <iostream>
using namespace std;

int main (){
	int n_people, budget, n_hotels, n_weeks;
	while (cin >> n_people >> budget >> n_hotels >> n_weeks && !cin.eof()){

		int best = 999999999;
		int singlePrice,vacancy;
		for(int i=0;i<n_hotels;i++){
			cin >> singlePrice;
			for(int j=0;j<n_weeks;j++){
				cin >> vacancy;
				if(vacancy >= n_people && budget >= singlePrice*n_people && singlePrice*n_people < best)
					best = singlePrice*n_people;

			}
		
		}
		
		if(best == 999999999)
			cout << "stay home\n";
		else
			cout << best << endl;	

	}

	return 0;
}