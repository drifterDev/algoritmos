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

// Algoritmo #1
// calculates factorizations of all numbers in the segment [2;n] 
// O(n*log(log(n)))
int N;cin>>N;
// const int N = 10000000;
vector<int> lp(N + 1);
vector<int> pr;

for (int i = 2; i <= N; ++i){
  if(lp[i]==0){
    lp[i]=i;pr.push_back(i);
  }
  for(int j=0;i*pr[j]<=N;++j){
    lp[i*pr[j]]=pr[j];
    if(pr[j]==lp[i]) break;
  }
}

//Visualización
for(int i=2;i<=N;i++){
  cout<<i<<": ";
  for(int j=i;j!=1;j/=lp[j])cout<<lp[j]<<" ";
  cout<<"\n";
}
return 0;
}