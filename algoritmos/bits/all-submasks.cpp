// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int m=15;

for (int s = m;; s = (s - 1) & m)
{
  cout<<s<<" ";
  // ... you can use s... 
  if (s == 0) break;
}

return 0;
}