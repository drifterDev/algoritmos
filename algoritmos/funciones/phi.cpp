// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

// O(sqrt(n))
int phi(int n){
  int result=n;
  for (int i=2;i*i<=n;i++){
    if (n%i==0){
      while(n%i==0)n/=i;
      result-=result/i;
    }
  }
  if(n>1)result-=result/n;
  return result;
}

// O(n*log(log(n)))
void phi_1_to_n(int n){
  vector<int> phi(n+1);
  for(int i=0;i<=n;i++)phi[i]=i;
  for (int i=2;i<=n;i++){
    if(phi[i]==i){
      for(int j=i;j<=n;j+= i)phi[j]-=phi[j]/i;
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
return 0;
}