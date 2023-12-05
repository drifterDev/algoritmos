// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n=3;
vi nums={4,8,12};
for(int b=0;b<(1<<n);b++){
  vi subset;
  for(int i=0;i<n;i++)if(b&(1<<i))subset.PB(i);
  for(int x:subset)cout<<nums[x]<<" ";
  cout<<"\n";
}
return 0;
}