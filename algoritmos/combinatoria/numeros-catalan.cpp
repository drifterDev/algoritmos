// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  // O(nlogm)
  const int n=10;
  ll catalan[n];
  catalan[0]=1;
  for(int i=0;i<n-1;++i){
    catalan[i+1]=((4*i+2)%MOD * catalan[i]%MOD * inv(i+2))%MOD;
  }

  // Visualizar
  for (int i = 0; i < n; i++)
  cout<<"Catalan["<<i<<"] = "<<catalan[i]<<"\n";
  return 0;
}