/*
  UVa11581 - Grid Successors
  How to solve it? Note that the number of possible grids is quite small (=512). So it is just a matter of checking when a grid is starting to repeat itself. Here
                   a int was used to represent the grid.
*/


#include <iostream>
#include <cmath>
#define MAXN 1025
using namespace std;

bool access(int i,int j,int grid){
  bool retorno = 0;
  if(i < 0 || i > 2 || j<0 || j>2)retorno = 0;
  else{
    int pos = 3*i+j;
    retorno = (grid & (1 << pos));
  }
  return retorno;
}

void update(int *grid){
  int new_grid = 0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      new_grid += int(pow(2,3*i+j))*((access(i+1,j,*grid) + access(i-1,j,*grid) + access(i,j+1,*grid) + access(i,j-1,*grid))%2);
    }
  *grid = new_grid;
}

int main (){
  int t;
  cin >> t;
  while(t--){
    int check[MAXN];
    for(int i=0;i<MAXN;i++)
      check[i] = -1;


    int grid = 0;
    char input;
    for(int i=0;i<9;i++){
      cin >> input;
      grid += int(pow(2,i))*(input=='1');
    }

    int i = 0;

    do{
      check[grid] = i++;
      update(&grid);
    }while(check[grid] == -1);

    cout << check[grid] - 1 << endl;
  }
  return 0;
}
