/*
  UVa146 - ID Codes
  How to solve it? Just use next_permutation
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main (){
  string input;
  while(cin >> input && input != "#"){
    bool exists = next_permutation(input.begin(),input.end());
    if(exists)
      cout << input;
    else
      cout << "No Successor";
    cout << endl;
  }
  return 0;
}
