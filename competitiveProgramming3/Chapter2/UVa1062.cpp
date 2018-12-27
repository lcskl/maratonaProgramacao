/*
  UVa1062 	Containers
  How to solve it? Just simulate the process with stacks
*/

#include <iostream>
#include <string>

using namespace std;

int topo[26];
int contFaltantes[26];

int main (){
  string conteiners;
  int caso = 0;
  while (cin >> conteiners && conteiners != "end"){
    caso++;
    for(int i=0;i<26;i++){
      topo[i] = -1; //Pilha Vazia
      contFaltantes[i] = 0;
    }

    int tam = conteiners.size();
    for(int i=0;i<tam;i++)
      contFaltantes[conteiners[i]-'A']++;

    //Separando os conteiners
    for(int i=0;i<tam;i++){
      for(int j=0;j<26;j++){
        if(topo[j] == -1 || (conteiners[i]-'A') <= topo[j]){ //|| ((conteiners[i]-'A') < topo[j] && contFaltantes[topo[j]] == 0) ){
          contFaltantes[conteiners[i]-'A']--;
          topo[j] = conteiners[i]-'A';
          break;
        }
      }
    }

    int nPilhas = 0;
    for(int i=0;i<26;i++)
      if(topo[i] != -1)nPilhas++;

    cout << "Case " << caso << ": " << nPilhas << endl;
  }

  return 0;
}
