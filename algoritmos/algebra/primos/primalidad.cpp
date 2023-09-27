// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// O(sqrt(n))
bool isPrime(int x){
  for(int d=2;d*d<=x;d++)if(x%d==0)return false;
  return x>=2;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}