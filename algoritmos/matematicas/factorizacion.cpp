// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define PB push_back
typedef long long ll;
typedef vector<ll> vl;

// Retorna solo los primos, no las potencias
vl primeFactors(ll n){
  vl factors;
  for(int i=0;sz(p) && (p[i]*p[i]<=n);++i){
    if(n%p[i]!=0)continue;
    while(n%p[i]==0)n/=p[i];
    factors.PB(p[i]);
  }
  if(n!=1)factors.PB(n);
  return factors;
}

// Retorna los primos y las potencias
vl primeFactors(ll n){
  vl factors;
  for(int i=0;sz(p) && (p[i]*p[i]<=n);++i){
    if(n%p[i]!=0)continue;
    while(n%p[i]==0){
      n/=p[i];
      factors.PB(p[i]);
    }
  }
  if(n!=1)factors.PB(n);
  return factors;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve(10000000);
  return 0;
}