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
cin.tie(0);
ll t;cin>>t;
ll n=90000000;
vector<bool> crib(n+1, true);
vi primos;
for(ll i=2;i<=n;i++){
  if(crib[i]){
    primos.push_back(i);
    for(ll j=i*i;j<=n+1;j+=i)crib[j]=false;
  }
}
while(t--){
    ll ind;cin>>ind;cout<<primos[ind-1]<<"\n";
}
return 0;}

