// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int C(int n, int k) {
  double res=1;
  for (int i=1;i<=k;i++)res=res*(n-k+i)/i;
  return (int)(res+0.01);
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}