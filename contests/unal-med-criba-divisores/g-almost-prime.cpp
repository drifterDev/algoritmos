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
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;

ll criba(ll tope){
  vl primos;
  ll c=0;
  ll n=tope;
  vl crib(n+1, 0);
  for(ll i=2;i<=n;i++){
    if(crib[i]==0){
      for(ll j=i*2;j<=n;j+=i)crib[j]+=1;
    }else if(crib[i]==2)c++;
  }
  return c;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll t;cin>>t;
ll casi=criba(t);
cout<<casi<<"\n";
return 0;}