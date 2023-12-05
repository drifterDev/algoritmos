// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// Con recursión
ll gcd(ll a, ll b){return b==0?a:gcd(b,a%b);} 
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}


// Sin recursión
ll gcd(ll a, ll b){
  while (b){
    a%=b;swap(a,b);
  }return a;
}

// Identidad de Bezout
// O(log(min(a, b))
ll gcd(ll a, ll b, ll &x, ll &y){
  x=1,y=0;
  ll x1=0,y1=1,a1=a,b1=b;
  while(b1){
    ll q=a1/b1;
    tie(x, x1)=make_tuple(x1, x - q * x1);
    tie(y, y1)=make_tuple(y1, y - q * y1);
    tie(a1, b1)=make_tuple(b1, a1 - q * b1);
  }return a1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x,y;
  ll resultado=gcd(12,48,x,y);
  cout<<resultado<<" "<<x<<" "<<y<<"\n";
  return 0;
}