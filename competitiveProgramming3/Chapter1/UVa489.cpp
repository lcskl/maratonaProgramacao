/*
	UVa 489 - Hangman Judge
	How to solve it: Simulate the game. Here a set was used to avoid any problems with repeated letters.
*/

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main (){
	int round;
	while(cin >> round && round > 0){
		string word,guess;
		cin >> word >> guess;

		set<char> letters;
		for(auto character: word)
			letters.insert(character);

		cout << "Round " << round << "\n";

		int wrong = 0;
		for(auto character: guess){
			wrong += (letters.erase(character) == 0);
			if(wrong == 7){
				cout << "You lose.\n";
				break;
			}

			if(letters.empty()){
				cout << "You win.\n";
				break;
			}

		}

		if(!letters.empty() && wrong < 7)
			cout << "You chickened out.\n";
	}
	return 0;
}