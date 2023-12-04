// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// Algoritmo #3
vector<long long> primes;
vector<long long> trial_division3(long long n){
  vector<long long> factorization;
  for(long long d:primes){
    if (d*d>n)break;
    while(n%d==0){
      factorization.push_back(d);n/=d;
    }
  }
  if(n>1)factorization.push_back(n);
  return factorization;
}

// Algoritmo #2
vector<long long> trial_division2(long long n){
  vector<long long> factorization;
  while (n%2==0){
    factorization.push_back(2);n/=2;
  }
  for(long long d=3;d*d<=n;d+=2){
    while (n%d==0){
      factorization.push_back(d);n/=d;
    }
  }
  if (n>1)factorization.push_back(n);
  return factorization;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}