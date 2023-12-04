// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// Con recursión
int gcd(int a, int b){return b==0?a:gcd(b,a%b);} 
int lcm(int a, int b){return a/gcd(a,b)*b;}


// Sin recursión
int gcd(int a, int b){
  while (b){
    a%=b;swap(a,b);
  }return a;
}

// Identidad de Bezout
int gcd(int a, int b, int &x, int &y){
  x=1,y=0;
  int x1=0,y1=1,a1=a,b1=b;
  while(b1){
    int q=a1/b1;
    tie(x, x1)=make_tuple(x1, x - q * x1);
    tie(y, y1)=make_tuple(y1, y - q * y1);
    tie(a1, b1)=make_tuple(b1, a1 - q * b1);
  }return a1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x,y;
  int resultado=gcd(12,48,x,y);
  cout<<resultado<<" "<<x<<" "<<y<<"\n";
  return 0;
}