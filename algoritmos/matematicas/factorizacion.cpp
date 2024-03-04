// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;

// O(sqrt(n))
// f tiene los factores primos de n y sus exponentes
void primeFactors(ll x, map<ll,int>& f){
  for(ll i=2;i*i<=x;i++)
    while(x%i==0){
      f[i]++;
      x/=i;
    }
  if(x>1)f[x]++;
}

// Con criba
// O(sqrt(n)/log(sqrt(n)))
void primeFactors(ll n, map<ll,int>& f){
  for(int i=0;i<sz(primos) && 1ll*primos[i]*primos[i]<=n;++i)
    while(n%primos[i]==0){
      f[primos[i]]++;
      n/=primos[i];
    }
  if(n>1)f[n]++; 
}  
