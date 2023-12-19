// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef vector<int> vi;

// O(sqrt(n))
int phi(int n){
  int res=n;
  for(int i=2;i*i<=n;++i){
    if(n%i==0){
      while(n%i==0)n/=i;
      res-=res/i;
    }
  }
  if(n>1)res-=res/n;
  return res;
}

// O(n*log(log(n)))
vi phi_1_to_n(int n){
  vi phi(n+1);
  for(int i=0;i<=n;++i)phi[i]=i;
  for(int i=2;i<=n;++i)
    if(phi[i]==i)
      for(int j=i;j<=n;j+=i)
        phi[j]-=phi[j]/i;
  return phi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout<<phi(12)<<"\n";
  vi ph=phi_1_to_n(12);
  for(int i=0;i<sz(ph);++i)cout<<ph[i]<<" ";
  return 0;
}