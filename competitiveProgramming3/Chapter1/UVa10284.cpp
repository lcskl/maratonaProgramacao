/*
  UVa10284 - Chessboard in FEN
  How to solve: Build Chessboard situtation and mark every square attacked. Count number of unmarked squares.
*/


#include <iostream>
#include <string>

using namespace std;

char tabuleiro[8][8];

void marca(char peca,int x,int y){
  int i,j;
  switch (peca) {
    case 'p':
      if(x+1 <= 7 && y+1 <= 7 && tabuleiro[x+1][y+1] == '*')tabuleiro[x+1][y+1] = '+';
      if(x+1 <= 7 && y-1 >= 0 && tabuleiro[x+1][y-1] == '*')tabuleiro[x+1][y-1] = '+';
      break;
    case 'P':
      if(x-1 >= 0 && y+1 <= 7 && tabuleiro[x-1][y+1] == '*')tabuleiro[x-1][y+1] = '+';
      if(x-1 >= 0 && y-1 >= 0 && tabuleiro[x-1][y-1] == '*')tabuleiro[x-1][y-1] = '+';
      break;
    case 'n':
    case 'N':
      if(x+2 <= 7 && y+1 <= 7 && tabuleiro[x+2][y+1] == '*')tabuleiro[x+2][y+1] = '+';
      if(x+2 <= 7 && y-1 >= 0 && tabuleiro[x+2][y-1] == '*')tabuleiro[x+2][y-1] = '+';
      if(x-2 >= 0 && y+1 <= 7 && tabuleiro[x-2][y+1] == '*')tabuleiro[x-2][y+1] = '+';
      if(x-2 >= 0 && y-1 >= 0 && tabuleiro[x-2][y-1] == '*')tabuleiro[x-2][y-1] = '+';

      if(x+1 <= 7 && y+2 <= 7 && tabuleiro[x+1][y+2] == '*')tabuleiro[x+1][y+2] = '+';
      if(x+1 <= 7 && y-2 >= 0 && tabuleiro[x+1][y-2] == '*')tabuleiro[x+1][y-2] = '+';
      if(x-1 >= 0 && y+2 <= 7 && tabuleiro[x-1][y+2] == '*')tabuleiro[x-1][y+2] = '+';
      if(x-1 >= 0 && y-2 >= 0 && tabuleiro[x-1][y-2] == '*')tabuleiro[x-1][y-2] = '+';

      break;

    case 'b':
    case 'B':
      i = x;
      j = y;
      do
        tabuleiro[i++][j++] = '+';
      while (i <= 7 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i++][j--] = '+';
      while (i <= 7 && j >=0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i--][j++] = '+';
      while (i >= 0 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i--][j--] = '+';
      while (i >= 0 && j >= 0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      tabuleiro[x][y] = 'B';

      break;

    case 'r':
    case 'R':
      i = x;
      j = y;
      do
        tabuleiro[i][j++] = '+';
      while (i <= 7 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i++][j] = '+';
      while (i <= 7 && j >=0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i--][j] = '+';
      while (i >= 0 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i][j--] = '+';
      while (i >= 0 && j >= 0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      tabuleiro[x][y] = 'R';

      break;
    case 'q':
    case 'Q':
      i = x;
      j = y;
      do
        tabuleiro[i][j++] = '+';
      while (i <= 7 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i++][j] = '+';
      while (i <= 7 && j >=0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i--][j] = '+';
      while (i >= 0 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i][j--] = '+';
      while (i >= 0 && j >= 0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i++][j++] = '+';
      while (i <= 7 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i++][j--] = '+';
      while (i <= 7 && j >=0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i--][j++] = '+';
      while (i >= 0 && j <= 7 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      i = x;
      j = y;
      do
        tabuleiro[i--][j--] = '+';
      while (i >= 0 && j >= 0 && tabuleiro[i][j] == '*' || tabuleiro[i][j] == '+');

      tabuleiro[x][y] = 'Q';

      break;
    case 'k':
    case 'K':
      if(x+1 <= 7 && tabuleiro[x+1][y] == '*')tabuleiro[x+1][y] = '+';
      if(y+1 <= 7 && tabuleiro[x][y+1] == '*')tabuleiro[x][y+1] = '+';
      if(x-1 >= 0 && tabuleiro[x-1][y] == '*')tabuleiro[x-1][y] = '+';
      if(y-1 >= 0 && tabuleiro[x][y-1] == '*')tabuleiro[x][y-1] = '+';

      if(x+1 <= 7 && y+1 <= 7 && tabuleiro[x+1][y+1] == '*')tabuleiro[x+1][y+1] = '+';
      if(x+1 <= 7 && y-1 >= 0 && tabuleiro[x+1][y-1] == '*')tabuleiro[x+1][y-1] = '+';
      if(x-1 >= 0 && y+1 <= 7 && tabuleiro[x-1][y+1] == '*')tabuleiro[x-1][y+1] = '+';
      if(x-1 >= 0 && y-1 >= 0 && tabuleiro[x-1][y-1] == '*')tabuleiro[x-1][y-1] = '+';

      break;

  }
}

int main (){
  string fen;

  while (getline(cin,fen) && !cin.eof()){

    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
        tabuleiro[i][j] = '*';

    int pos,tam,l,c;
    pos = l = c = 0;
    tam = fen.size();

    while(pos < tam){
      if(fen[pos] == '/'){
        l++;
        c = 0;
      }else if (fen[pos] >= '1' && fen[pos] <= '8')
        c += fen[pos] - '0';
      else
        tabuleiro[l][c++] = fen[pos];
      pos++;
    }
/*
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        cout << tabuleiro[i][j] << ' ';
      }
      cout << endl;
    }
*/
    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
        if(tabuleiro[i][j] != '*' && tabuleiro[i][j] != '+')
          marca(tabuleiro[i][j],i,j);
/*
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        cout << tabuleiro[i][j] << ' ';
      }
      cout << endl;
    }
*/
    int resp = 0;
    for(int i=0;i<8;i++)
      for(int j=0;j<8;j++)
        if(tabuleiro[i][j] == '*')
          resp++;

    cout << resp << endl;
  }

  return 0;
}
