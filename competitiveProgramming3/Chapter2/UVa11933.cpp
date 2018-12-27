/*
  UVa11933 	Splitting Numbers
  How to solve it? Separate the powers of 2 from input number
*/

#include <iostream>
#include <cmath>
using namespace std;

int main (){
  int n;
  while(cin >> n && n){
    int a,b;
    a = b = 0;

    bool even = false;

    for(int i=0;i<31 && pow(2,i) <= n;i++){
      if((n & (1 << i))){
        if(even)
          b += (1 << i);
        else
          a += (1 << i);

        even = !even;
      }
    }
    cout << a << " " << b << endl;
  }
  return 0;
}
