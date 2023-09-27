// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// Coeficientes binomiales
int C(int n, int k) {
  double res=1;
  for (int i=1;i<=k;i++)res=res*(n-k+i)/i;
  return (int)(res+0.01);
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);

// Triángulo de Pascal O(n^2)
const int maxn = 10;
int C[maxn + 1][maxn + 1];
C[0][0] = 1;
for (int n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
}

// Visualizar
for(int n=0;n<=maxn;n++){
  for (int k=0;k<=n;k++)cout<<C[n][k]<<" ";
  cout<<"\n";
}

return 0;
}