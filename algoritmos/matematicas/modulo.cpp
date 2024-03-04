// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod(ll a, ll m){
  return ((a%m)+m)%m;
}

// O(log(min(a, b))
ll inv(ll b, ll m){
  // Implementar algoritmos de euclides
  ll x,y;
  ll d=gcd(b, m, x, y);  //obtiene b*x + m*y == d
  if(d!=1)return -1;          //indica error
  // b*x + m*y == 1, ahora aplicamos (mod m) para obtener b*x == 1 (mod m)
  return mod(x, m);
}

// O(log MOD)
// Si m es primo
ll inv(ll a, ll m){
  // Implementar exponenciacion binaria
  return binpow(a, m-2, m);
}

// Calcular el inv de [2,m)
const int n=1e6;
ll inverso[n+1];
void inv(ll m){
  inverso[1]=1;
  for(int i=2;i<=n;++i)
    inverso[i]=(m-(m/i)*inverso[m%i]%m)%m;
}