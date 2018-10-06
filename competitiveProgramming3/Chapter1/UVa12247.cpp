/*
  UVa12247 - Jollo
  How to solve: Test always the worst case
*/

#include <iostream>

using namespace std;

int irmao[2];
int irma[3];
bool carta[53];

int proxCarta(int carta1){
  for(int i=carta1+1;i<=52;i++){
    if(carta[i] == false){
      return i;
    }
  }
  return 99;
}

int main (){
  while (cin >> irma[0] >> irma[1] >> irma[2] >> irmao[0] >> irmao[1] && irma[0]){
    for(int i=0;i<53;i++)
      carta[i] = false;

    for(int i=0;i<3;i++){
      carta[irma[i]] = true;
      if(i<2)carta[irmao[i]] = true;
    }

    int menorCarta = proxCarta(0);

    int minimo = -1;
    int cartaFinalIrma;

    //Escolhendo a primeira carta no Round
    for(int k=0;k<2;k++){

      for(int i=0;i<3;i++){
        if(irmao[k] > irma[i]){

          for(int j=0;j<3;j++){
            if(j != i){
              if(i!=0 && j!=0)cartaFinalIrma = 0;
              else if (i!=1 && j!=1)cartaFinalIrma = 1;
              else cartaFinalIrma = 2;

              if(irmao[(k+1)%2] > irma[j])
                minimo = max(menorCarta,minimo);
              else
                minimo = max(minimo,proxCarta(irma[cartaFinalIrma]));
            }
          }
        }else{
          for(int j=0;j<3;j++){
            if(j != i){
              if(i!=0 && j!=0)cartaFinalIrma = 0;
              else if (i!=1 && j!=1)cartaFinalIrma = 1;
              else cartaFinalIrma = 2;

              if(irmao[(k+1)%2] > irma[j])
                minimo = max(minimo,proxCarta(irma[cartaFinalIrma]));
              else
                minimo = 99;
            }
          }
        }
      }

    }

    if(minimo == 99)
      cout << "-1" << endl;
    else
      cout << minimo << endl;

  }

  return 0;
}
