// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vi coins={1,2,5,10,20,50,100,200};
  int total=520;
  int n=sz(coins);
  for(int i=n-1;i>=0;--i){
    while(coins[i]<=total){
      total-=coins[i];
      cout<<coins[i]<<" ";
    }
  }cout<<"\n";
  return 0;
}