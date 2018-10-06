/*
  UVa462 - Bridge Hand Evaluator
  How to solve: Simply check all the rules
*/

#include <iostream>
#include <string>

using namespace std;

int rules[8];
int s,h,d,c;
string cards[13];

int naipe(char x){
  if(x == 'S')
    return s;
  if(x == 'D')
    return d;
  if(x == 'H')
    return h;
  return c;
}

int main (){

  while(cin >> cards[0] && !cin.eof()){
    for(int i=1;i<13;i++){
      cin >> cards[i];
    }

    for(int i=0;i<8;i++){
      rules[i] = 0;
    }

    s = h = d = c = 0;

    //Rule 1
    for(int i=0;i<13;i++){
      if(cards[i][1] == 'S')
        s++;
      else if (cards[i][1] == 'H')
        h++;
      else if (cards[i][1] == 'D')
        d++;
      else if (cards[i][1] == 'C')
        c++;

      if(cards[i][0]=='A')
        rules[1]+=4;
      else if(cards[i][0]=='K')
        rules[1]+=3;
      else if(cards[i][0]=='Q')
        rules[1]+=2;
      else if(cards[i][0]=='J')
        rules[1]+=1;
    }

    //Rules 2,3 e 4
    for(int  i=0;i<13;i++){
      if(cards[i][0] == 'K' && naipe(cards[i][1]) == 1)
        rules[2] -= 1;
      if(cards[i][0] == 'Q' && naipe(cards[i][1]) <= 2)
        rules[3] -= 1;
      if(cards[i][0] == 'J' && naipe(cards[i][1]) <= 3)
        rules[4] -= 1;
    }

    //Rules 5,6 e 7
    rules[5] = (s==2)+(h==2)+(d==2)+(c==2);

    rules[6] = (s==1)*2+(h==1)*2+(d==1)*2+(c==1)*2;

    rules[7] = (s==0)*2+(h==0)*2+(d==0)*2+(c==0)*2;

    //Result

    int total = 0,noTrump = 0;

    for(int i=1;i<=7;i++){
      total += rules[i];
    }

    noTrump = total - rules[5] - rules[6] - rules[7];

    if(total < 14)
      cout << "PASS" << endl;
    else{
      int stopped = 0;

      if(noTrump >= 16){
        for(int i=0;i<13;i++){
          if(cards[i][1] == 'S'){
            if(cards[i][0] == 'A'){
              stopped++;
              break;
            }
            if(cards[i][0] == 'K' && s >= 2){
              stopped++;
              break;
            }
            if(cards[i][0] == 'Q' && s >= 3){
              stopped++;
              break;
            }
          }
        }
        for(int i=0;i<13;i++){
          if(cards[i][1] == 'D'){
            if(cards[i][0] == 'A'){
              stopped++;
              break;
            }
            if(cards[i][0] == 'K' && d >= 2){
              stopped++;
              break;
            }
            if(cards[i][0] == 'Q' && d >= 3){
              stopped++;
              break;
            }
          }
        }
        for(int i=0;i<13;i++){
          if(cards[i][1] == 'H'){
            if(cards[i][0] == 'A'){
              stopped++;
              break;
            }
            if(cards[i][0] == 'K' && h >= 2){
              stopped++;
              break;
            }
            if(cards[i][0] == 'Q' && h >= 3){
              stopped++;
              break;
            }
          }
        }
        for(int i=0;i<13;i++){
          if(cards[i][1] == 'C'){
            if(cards[i][0] == 'A'){
              stopped++;
              break;
            }
            if(cards[i][0] == 'K' && c >= 2){
              stopped++;
              break;
            }
            if(cards[i][0] == 'Q' && c >= 3){
              stopped++;
              break;
            }
          }
        }

        if(stopped == 4)
          cout << "BID NO-TRUMP" << endl;
      }


      if(noTrump < 16  || stopped < 4){
        cout << "BID ";
        int maior = max(s,max(h,max(d,c)));
        if(s == maior)
          cout << "S\n";
        else if (h == maior)
          cout << "H\n";
        else if (d == maior)
          cout << "D\n";
        else
          cout << "C\n";
      }
    }
  }

  return 0;
}
