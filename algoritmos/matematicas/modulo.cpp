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
ll inv1(ll b, ll m){
    // Implementar algoritmos de euclides
    ll x, y;
    ll d = gcd(b, m, x, y);  //obtiene b*x + m*y == d
    if (d != 1) return -1;          //indica error
    // b*x + m*y == 1, ahora aplicamos (mod m) para obtener b*x == 1 (mod m)
    return mod(x, m);
}

// O(log MOD)
ll inv2(ll a, ll m){
  // Implementar exponenciacion binaria
  return binpow(a, m-2, m);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a=3, b=5, m=7;
  // Calcula el inverso modular de b respecto a m
  int b_inv=inv1(b,m);
  // Calcula a / b (mod m)
  int result=(a*b_inv)%m;
  cout<<a<<" / "<<b<<" (mod "<<m<<") = "<<result<<"\n";
  return 0;
}