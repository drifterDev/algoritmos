// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Con recursión y más lento:
ll binpow(ll a, ll b){
  if(b==0) return 1;
  ll res=binpow(a,b/2);
  if(b%2) return res*res*a;
  else return res*res;
}

// Sin recursión y más rápido:
ll binpow(ll a, ll b){
  ll res=1;
  while(b>0){
    if(b&1)
      res=res*a;
    a=a*a;
    b>>=1;
  }
  return res;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
cout<<binpow(2, 10)<<"\n";
cout<<binpow(3, 3)<<"\n";
return 0;
}