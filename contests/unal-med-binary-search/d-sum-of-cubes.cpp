// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll t,n,tope;cin>>t;
double act;
while(t--){
  cin>>n;tope=cbrt(n);
  bool pasa=false;
  for(ll i=1;i<tope+1;i++){
    act=cbrt(n-pow(i,3));
    if(act == static_cast<int>(act) && pow(act, 3)+pow(i,3)==n && act!=0){
      //cout<<act<<" "<<i<<"\n";
      pasa=true;break;
    }
  }
  if(pasa)cout<<"YES\n";
  else cout<<"NO\n";
}
return 0;
}