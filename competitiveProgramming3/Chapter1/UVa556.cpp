/*
  UVa556 - Amazing
  How to solve: Simulate. And pay close atention to details.
*/

#include <iostream>
#define MAXN 1010
using namespace std;

struct position{
  int x,y;
  position& operator+=(const position& b){ x += b.x; y += b.y; return *this;}
};

position operator+(position a, const position& b){ return a += b;}

char maze[MAXN][MAXN];
int n,m;

position direction[4];

int repetition[MAXN][MAXN];
int output[5];

void walk(position current,int dir){
  //First of all, lets make sure that we count every visit
  repetition[current.x][current.y]++;

  //Am I at the start point for the second time?
  if(current.x == n-1 && current.y == 0 && repetition[current.x][current.y] == 2)
    return;

  //Lets try to turn right.
  dir--;
  if(dir < 0)dir = 3;

  while(true){
    position next = current + direction[dir];

    //Is it possible to go to this direction?
    if((next.x >= 0) && (next.x < n) &&
       (next.y >= 0) && (next.y < m) &&
       maze[next.x][next.y] == '0'){

      walk(next,dir);
      break;
    }
    //No? Than rotate 90 degrees
    dir = (++dir)%4;
  }

  return ;
}

int main (){
  direction[3].x = 1;  direction[3].y = 0;
  direction[2].y = -1; direction[2].x = 0;
  direction[1].x = -1; direction[1].y = 0;
  direction[0].y = 1;  direction[0].x = 0;

  while(cin >> n >> m && n && m){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin >> maze[i][j];
        repetition[i][j] = 0;
      }
    }
    position start;
    start.x = n-1; start.y = 0;

    walk(start,0);

    output[0] = output[1] = output[2] = output[3] = output[4] = 0;

    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        if(maze[i][j] == '0')
          output[repetition[i][j]]++;

    //From the definition of visit, the first square is visited only once
    output[1]++; output[2]--;

    for(int i=0;i<5;i++){
      if(output[i] < 100)cout << " ";
      if(output[i] < 10) cout << " ";
      cout << output[i];
    }
    cout << endl;
  }
  return 0;
}
