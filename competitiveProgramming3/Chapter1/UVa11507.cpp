/*
	UVa11507 - Bender B. Rodríguez Problem
	How to solve: If-Else of current direction and next bend operation.
*/


#include <iostream>
#include <string>

using namespace std;


int main (){
  int l;

  while (cin >> l && l){
    string dobra,dir;
    dir = "+x";
    for(int i=l-1;i>=1;i--){
      cin >> dobra;
      if(dir == "+x"){
        if(dobra == "+y")dir = "+y";
        else if(dobra == "-y")dir = "-y";
        else if(dobra == "+z")dir = "+z";
        else if(dobra == "-z")dir = "-z";
      }else{
        if(dir == "-x"){
          if(dobra == "+y")dir = "-y";
          else if(dobra == "-y")dir = "+y";
          else if(dobra == "+z")dir = "-z";
          else if(dobra == "-z")dir = "+z";
        }else{
          if(dir == "+y"){
            if(dobra == "+y")dir = "-x";
            else if(dobra == "-y")dir = "+x";
          }else{
            if(dir == "-y"){
              if(dobra == "+y")dir = "+x";
              else if(dobra == "-y")dir = "-x";
            }else{
              if(dir == "+z"){
                if(dobra == "+z")dir = "-x";
                else if(dobra == "-z")dir = "+x";
              }else
                if(dir == "-z"){
                  if(dobra == "+z")dir = "+x";
                  else if(dobra == "-z")dir = "-x";
                }
            }
          }
        }
      }
      //cout << dir << endl;
    }

    cout << dir << endl;
  }

  return 0;
}
