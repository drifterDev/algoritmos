// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define PB push_back
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vi permutation;int n=3;
  for(int i=0;i<n;i++)permutation.PB(i);
  do {
    cout<<"Permutation: ";
    for(int i=0;i<n;++i)cout<<permutation[i]<<" ";
    cout<<"\n";
  } while (next_permutation(all(permutation)));
  return 0;
}