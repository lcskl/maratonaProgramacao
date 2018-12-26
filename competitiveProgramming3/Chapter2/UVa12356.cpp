/*
  UVa12356 - Army Buddies
  How to solve it? Keep track of all intervals given and update them every time there is a intersection.
*/

#include <iostream>
#define MAXN 100010
using namespace std;

int right_loss[MAXN],left_loss[MAXN];

int main (){
  int b,s;
  while(cin >> s >> b && b && s){
    for(int i=0;i<=s+1;i++){
      right_loss[i] = left_loss[i] = -1;
    }

    int l,r;
    for(int i=0;i<b;i++){
      cin >> l >> r;

      int right_alive,left_alive;
      if(left_loss[r+1] != -1)
        right_alive = left_loss[r+1]+1;
      else
        right_alive = r+1;

      if(right_loss[l-1] != -1)
        left_alive = right_loss[l-1]-1;
      else
        left_alive = l-1;

      //Updates
      if(left_loss[r+1] != -1)
        right_loss[left_loss[r+1]] = left_alive +1;

      if(right_loss[l-1] != -1)
        left_loss[right_loss[l-1]] = right_alive -1;

      if(left_alive < 1)cout << "* ";
      else cout << left_alive << " ";

      if(right_alive > s)cout << "*\n";
      else cout << right_alive << endl;

      right_loss[r] = left_alive+1;
      left_loss[l] = right_alive-1;
    }
    cout << "-\n";
  }
  return 0;
}
