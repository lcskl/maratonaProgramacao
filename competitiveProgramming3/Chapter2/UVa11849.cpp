/*
  UVa11849 - CD
  How to solve it? Just use a set to check for duplicates
*/

#include <iostream>
#include <set>
using namespace std;

int main (){
  int n,m;
  set<int> cds;

  while(cin >> n >> m && (n+m)){
    cds.clear();

    int id,both = 0;
    for(int i=0;i<n;i++){
      cin >> id;
      cds.insert(id);
    }

    for(int j=0;j<m;j++){
      cin >> id;
      if(cds.find(id) != cds.end())
        both++;
    }
    cout << both << endl;
  }
  return 0;
}
