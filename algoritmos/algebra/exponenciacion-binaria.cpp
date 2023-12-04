// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Sin recursión y más rápido:
ll binpow(ll a, ll b){
  ll res=1;
  while(b>0){
    if(b&1)res=res*a;
    a=a*a;
    b>>=1;
  }
  return res;
}

// Lo mismo pero con modulo
ll binpow(ll a, ll b, ll m){  
  ll res=1;
  a%=m;
  while(b>0){
    if(b&1)res=res*a%m;
    a=a*a%m;
    b>>=1;
  }
  return res % m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}