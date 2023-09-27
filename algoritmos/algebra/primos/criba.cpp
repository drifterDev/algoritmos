// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll lon_criba;
bitset<1000001> bs;vl p;
void sieve(ll tope){
  lon_criba=tope+1;
  bs.set();
  bs[0]=bs[1]=0;
  for (ll i=2;i<lon_criba;++i)
    if(bs[i]){
      for (ll j = i * i; j < lon_criba; j += i)bs[j] = 0;
      p.push_back(i);
    }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve(1000000);
  return 0;
}