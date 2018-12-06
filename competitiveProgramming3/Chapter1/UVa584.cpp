#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<pair<int,int> > jogadas;
  while(true){

    jogadas.clear();

    string a;
    cin >> a;
    if(a == "Game"){
      cin >> a;
      break;
    }
    char x,y;
    x = a[0];

    for(int i=0;i<10;i++){
      if(i!=0)cin >> x;
      if(x != 'X'){
        cin >> y;
        if(y == '/')
          jogadas.push_back (make_pair(x-'0', 10 - (x-'0')) );
        else
          jogadas.push_back(make_pair(x-'0', y-'0') );
      }else
        jogadas.push_back(make_pair(10,0));
    }

    //Caso em que última jogada é strike
    int pontExtra = 0;
    if(jogadas.back().first == 10){
      cin >> x >> y;

      if(x == 'X')
        pontExtra += 10;
      else pontExtra += (x-'0');

      jogadas.push_back(make_pair(pontExtra,0));

      if(y == 'X')
        pontExtra += 10;
      else{
        if(y == '/')
          pontExtra += (10 - (x-'0'));
        else
          pontExtra += (y-'0');
      }
    }else if(jogadas.back().first + jogadas.back().second == 10){
      cin >> x;

      if(x == 'X')
        pontExtra += 10;
      else pontExtra += (x-'0');

      jogadas.push_back(make_pair(pontExtra,0));
    }

    int pontosTotais = 0;

    for(int i=0;i<10;i++){
      if(jogadas[i].first == 10 && i!=9){ //Strike
        pontosTotais += (10 + jogadas[i+1].first + jogadas[i+1].second);
        if(jogadas[i+1].first == 10)
          pontosTotais += jogadas[i+2].first;
      }else{
        if(jogadas[i].first != 10 && jogadas[i].first + jogadas[i].second == 10)//Spare
          pontosTotais += (10 + jogadas[i+1].first);
        else if(jogadas[i].first != 10)
          pontosTotais += jogadas[i].first + jogadas[i].second;
      }
      //cout << pontosTotais << endl;
    }

    if(jogadas[9].first == 10)
      pontosTotais += 10 + pontExtra;

    cout << pontosTotais << endl;
  }
  return 0;
}
