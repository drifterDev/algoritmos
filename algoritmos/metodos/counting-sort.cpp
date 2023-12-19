// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef vector<int> vi;

// Funciona para elementos no negativos
// O(n+k) donde k es el maximo valor del arreglo
void counting_sort(vi &a){ 
  int n=sz(a);
  int maximo=*max_element(all(a));
  vi cnt(maximo+1);
  for(int i=0;i<n;++i)++cnt[a[i]];
  for(int i=0,j=0;i<=maximo;++i)
    while(cnt[i]--)a[j++]=i;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  vi a={9,4,6,3,67,35,7,2};
  counting_sort(a);
  for(auto x:a)cout<<x<<" ";
  return 0;
}