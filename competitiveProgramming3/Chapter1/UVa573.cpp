/*
	UVa573 - The Snail
	How to solve: Simply simulate the process of climbing

	Observations: Test before sliding down.
*/

#include <iostream>

using namespace std;

int main(){
	int height,up,down,fatigue;
	while(cin >> height >> up >> down >> fatigue && height){

		double currentPosition = 0.0;
		double upToday = up, loss = (up*fatigue)/100.0;
		int day = 0;

		while(currentPosition >= 0.0){
			day++;

			if(upToday >= 0.0){
				currentPosition += upToday;
				upToday -= loss;
			}else
				upToday += loss;

			//cout << "Day: " << currentPosition << " ";

			if(currentPosition > height)break;

			currentPosition -= down;

			//cout << "Night: " << currentPosition << endl;
		}

		if(currentPosition > height)cout << "success ";
		else cout << "failure ";
		cout << "on day " << day << endl;
	}

	return 0;
}