#include <iostream>
#include <map>
using namespace std;

int main (){
  int t;
  cin >> t;
  map<int,int> snowflake;
  while(t--){
    snowflake.clear();

    int n;
    int current_streak = 0,max_streak = -1,beginning = 0;

    cin >> n;
    int id;
    for(int i=0;i<n;i++){
      cin >> id;
      if(snowflake.find(id) == snowflake.end() || snowflake[id] < beginning){
        snowflake[id] = i;
        current_streak++;
      }else{
        max_streak = max(max_streak,current_streak);
        beginning = snowflake[id];
        current_streak = i-snowflake[id];
        snowflake[id] = i;
      }
    }
    max_streak = max(current_streak,max_streak);
    cout << max_streak << endl;
  }
  return 0;
}
