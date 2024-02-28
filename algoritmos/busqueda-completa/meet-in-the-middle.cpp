// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n=4, x=6;
  vi nums={2,4,6,9};
  sort(all(nums));

  if(n==1){
    cout<<(nums[0]==x?1:0)<<"\n";
    return 0;
  }

  // Dividir en dos para poder reducir el 2^n a un 2^(n/2)
  map<ll, int> sumas;
  for(int i=0;i<(1<<(n/2-1));i++){
    ll sum=0;
    for(int j=0;j<n/2-1;j++)if(i&(1<<j))sum+=nums[j];
    sumas[sum]++;
  }

  ll res=0;
  for(int i=0;i<(1<<((n+1)/2+1));i++){
    ll sum=0;
    for(int j=0;j<(n+1)/2+1;j++)if(i&(1<<j))sum+=nums[n/2-1+j];
    if(sumas.find(x-sum)!=sumas.end())res+=sumas[x-sum];
  }
  cout<<res<<"\n";
  return 0;
}