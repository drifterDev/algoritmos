// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll t,a,b;cin>>t;
while(t--){
  cin>>a>>b;
  if(b==1){
    cout<<"0\n";
    continue;
  }
  ll suma=0;
  for(ll i=1;i*i<=a;i++){
    if(a%i==0 && i!=a/i){
      if(i%b!=0)suma+=i;
      if((a/i)%b!=0)suma+=a/i;
    }else if(a%i==0 && i%b!=0){
      suma+=i;
    }
  }
  cout<<suma<<"\n";
}
return 0;
}