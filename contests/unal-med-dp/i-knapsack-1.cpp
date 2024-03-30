// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
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
cin.tie(nullptr);
ll n,w,wi,vi;vii pesos;cin>>n>>w;
for(ll i=0;i<n;i++){
    cin>>wi>>vi;pesos.push_back({wi,vi});
}
sort(pesos.begin(), pesos.end());
dp(pesos, n, w);
//  for(ll i=0;i<n;i++){
//      for(ll j=0;j<w;j++){
//          cout<<k[i][j]<<" ";
//      }cout<<"\n";
// }
cout<<k[n][w]<<"\n";
return 0;
}