// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

// Funciona para elementos no negativos
// O(n+k) donde k es el maximo valor del arreglo
void counting_sort(vi &a){ 
  int n=sz(a);
  int maxi=*max_element(all(a));
  int mini=*min_element(all(a));
  vi cnt(maxi-mini+1,0);
  for(int i=0;i<n;++i)++cnt[a[i]-mini];
  for(int i=0,j=0;i<=maxi-mini;++i)
    while(cnt[i]--)a[j++]=i+mini;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  vi a={9,4,6,3,67,35,7,2};
  counting_sort(a);
  for(auto x:a)cout<<x<<" ";
  return 0;
}