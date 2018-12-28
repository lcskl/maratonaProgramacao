/*
  UVa11034 - Ferry Loading IV
  How to solve it? Just simulate the process of having 2 queues and filling the ferry with those queues
*/
#include <iostream>
#include <queue>
using namespace std;

int main (){
  int c;
  queue<int> left_bank,right_bank;
  cin >> c;
  while(c--){
    int l,cars;
    cin >> l >> cars;

    l*=100;
    string bank;
    int lenght;
    for(int i=0;i<cars;i++){
      cin >> lenght >> bank;
      if(bank == "left")
        left_bank.push(lenght);
      else
        right_bank.push(lenght);
    }

    //Simulate
    bool side = false; //left
    int capacity = l, crossings = 0;
    while(!left_bank.empty() || !right_bank.empty()){

      if(side == false){
        while(!left_bank.empty() && left_bank.front() <= capacity){
          capacity -= left_bank.front();
          left_bank.pop();
        }
      }else{
        while(!right_bank.empty() && right_bank.front() <= capacity){
          capacity -= right_bank.front();
          right_bank.pop();
        }
      }

      side = !side;
      capacity = l;
      crossings++;
    }
    cout << crossings << endl;
  }
  return 0;
}
