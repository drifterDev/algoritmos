// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// O(sqrt(n))
bool isPrime(ll x){
  for(ll d=2;d*d<=x;d++)if(x%d==0)return false;
  return x>=2;
}

// Con criba
// O(sqrt(n)/log(sqrt(n)))
bool isPrime(ll x){
  if(n<criba_len)return criba;
  for(int i=0;i<sz(p) && p[i]*p[i]<=n;++i)
    if(n%p[i]==0)return false;
  return true;  
}  

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}