// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
const int n = 100010;   
const int m = 1e9+7;
typedef long long ll;
ll factorial[n];

// m>n
// O(logm)
ll coeficientes(int n, int k){
  // Implementar el inverso mular
  if(n<k)return 0;
  return (((factorial[n]*inv(factorial[k]))%m)*inv(factorial[n-k]))%m;
}

int main() {
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  factorial[0]=1;
  for(int i=1;i<n;i++){
    factorial[i]=(factorial[i-1]*i)%m;
  }
  cout<<coeficientes(100000, 50000)<<"\n";
  cout<<coeficientes(40, 7)<<"\n";
  return 0;
}
