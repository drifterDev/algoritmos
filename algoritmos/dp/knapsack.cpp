// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
ll k[101][100001];

void dp(vii& pesos, ll n, ll w){
  for(ll i=1;i<=n;i++){
    for(ll j=1;j<=w;j++){
      ll anterior=k[i-1][j];
      ll actual=0;
      if(j>=pesos[i-1].first) actual=pesos[i-1].second+k[i-1][j-pesos[i-1].first];
      k[i][j]=max(anterior, actual);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,w,wi,vi;vii pesos;cin>>n>>w;
  for(ll i=0;i<n;i++){
    cin>>wi>>vi;pesos.push_back({wi,vi});
  }
  sort(all(pesos));
  dp(pesos, n, w);
  cout<<k[n][w]<<"\n";
  return 0;
}

