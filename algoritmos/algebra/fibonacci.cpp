// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// O(n)
// int fib(int n){
//   int a=0;
//   int b=1;
//   for(int i=0;i<n;i++){
//     int tmp=a+b;
//     a=b;
//     b=tmp;
//   }return a;
// }

// O(Log(n))
pair<int, int> fib(int n){
  if (n==0) return {0, 1};
  auto p=fib(n>>1);
  int c=p.first*(2*p.second-p.first);
  int d=p.first*p.first+p.second*p.second;
  if (n&1)return {d, c + d};
  else return {c, d};
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
pair<int, int> p = fib(5);
cout<<p.first<<" "<<p.second<<"\n";
return 0;
}