/*
	UVa12060 - All Integer Average
	How to solve: Mathematically, very simple. Just simulate the process of division (eliminating equal prime factors).
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

#define MAXN 110
#define MAXNUM 10010

bool is_prime[MAXNUM];
vector<int> primes;

void sieve(){
  for(int i=0;i<MAXNUM;i++)
    is_prime[i] = true;

  for(int i=2;i<MAXNUM;i++){
    if(is_prime[i]){
      for(int j=2*i;j<MAXNUM;j+=i)
        is_prime[j] = false;

      primes.push_back(i);
    }
  }
}

struct Number{
  int value;
  map<int,int> prime_factors;
};

Number numerator;
Number denominator;

int main() {
  sieve();
  int n,k = 0;
  while(cin >> n && n){
    k++;
    numerator.prime_factors.clear();
    denominator.prime_factors.clear();
    numerator.value = 0;


    int num;
    for(int i=0;i<n;i++){
      cin >> num;
      numerator.value+=num;
    }
    bool negative = (numerator.value < 0);
    numerator.value = abs(numerator.value);

    denominator.value = n;

    //Factorizing
    int aux,exponent;

    aux = numerator.value;
    for(int k=0;k < primes.size() && primes[k] <= aux;k++){
      exponent = 0;
      while(aux%primes[k] == 0){
        aux/=primes[k];
        exponent++;
      }
      if(exponent)
        numerator.prime_factors[primes[k]] = exponent;

      //cout << primes[k] << "^" << exponent << ".";
    }

    //cout << endl;

    aux = denominator.value;
    for(int k=0;k < primes.size() && primes[k] <= aux;k++){
      exponent = 0;
      while(aux%primes[k] == 0){
        aux/=primes[k];
        exponent++;
      }
      if(exponent)
        denominator.prime_factors[primes[k]] = exponent;

      //cout << primes[k] << "^" << exponent << ".";
    }

    //cout << endl;

    //Eliminating common factors in numerator and denominator
    for(auto& [prime,exp]: numerator.prime_factors){
      if(denominator.value == 1)break;

      if(denominator.prime_factors.find(prime) != denominator.prime_factors.end() ){
        if(denominator.prime_factors[prime] < exp){
          denominator.value /= int(pow(prime,denominator.prime_factors[prime]));
          numerator.value /= int(pow(prime,denominator.prime_factors[prime]));

          numerator.prime_factors[prime] -= denominator.prime_factors[prime];
          denominator.prime_factors.erase(prime);
        }else if (denominator.prime_factors[prime] > exp) {
          denominator.value /= int(pow(prime,exp));
          numerator.value /= int(pow(prime,exp));

          denominator.prime_factors[prime] -= exp;
          numerator.prime_factors.erase(prime);
        }else{
          denominator.value /= int(pow(prime,exp));
          numerator.value /= int(pow(prime,exp));

          numerator.prime_factors.erase(prime);
          denominator.prime_factors.erase(prime);
        }
      }
    }
    cout << "Case " << k << ":\n";

    if(numerator.value == 0)
      cout << "0\n";
    else{

      int integer = numerator.value / denominator.value;
      numerator.value -= integer*denominator.value;

      //Formatting output
      string firstLine = to_string(numerator.value);
      string thirdLine = to_string(denominator.value);
      string secondLine = "";
      if(negative)
        secondLine += "- ";
      if(integer)
        secondLine += to_string(integer);
      if(numerator.value)
        for(int i=0;i < thirdLine.size();i++)
          secondLine += "-";

      while(thirdLine.size() < secondLine.size())
        thirdLine.insert(0," ");

      while(firstLine.size() < thirdLine.size())
        firstLine.insert(0," ");


      if(numerator.value)cout << firstLine << endl;
      cout << secondLine << endl;
      if(numerator.value)cout << thirdLine << endl;
    }
  }
  return 0;
}
