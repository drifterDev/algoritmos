// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n=4;
  vi nums={2,4,5,9};

  // Dividir en dos para poder reducir el 2^n a un 2^(n/2)
  n/=2;
  for(int b=0;b<(1<<n);b++){
    int suma=0;
    for(int i=0;i<n;i++)if(b&(1<<i))suma+=nums[i];
    cout<<suma<<" ";
  }cout<<"\n";

  for(int b=0;b<(1<<n);b++){
    int suma=0;
    for(int i=0;i<n;i++)if(b&(1<<i))suma+=nums[n+i];
    cout<<suma<<" ";
  }
  return 0;
}