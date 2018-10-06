/*
  UVa10646 - What is the Card?
  How to solve: Simulate the game
*/

#include <iostream>
#include <string>
using namespace std;

int value(string card){
  if(card[0] == 'A' || card[0] == 'K' || card[0] == 'Q' || card[0] == 'J' || card[0] == 'T')
    return 10;
  else
    return card[0]-'0';
}

string deck[53];

int main (){
  int t;
  cin >> t;

  for(int k=1;k<=t;k++){
    for(int i=1;i<=52;i++){
      cin >> deck[i];
    }

    int x,y = 0;

    int top = 25;

    for(int i=1;i<=3;i++){

      x = value(deck[top]);
      y += x;

      top -= (1 + (10-x));
    }

    cout << "Case " << k << ": ";

    if(y <= top)
      cout << deck[y] << endl;
    else
      cout << deck[y - top + 25] << endl;
  }


  return 0;
}
