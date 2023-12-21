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
ll dp[1000001];
 
void coins(vl& values, ll total, ll n){
    sort(values.begin(), values.end());
    if(values[0]==1)dp[1]=1;
    else dp[1]=INF;
    for(int i=2;i<=total;i++){
        ll res=INF;
        for(int j=0;j<n;j++){
            if(i<values[j])break;
            else if(i==values[j])res=1;
            else res=min(res, 1+dp[i-values[j]]);
        }
        dp[i]=res;
    }
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll n,x;cin>>n>>x;
vl values(n,0);
for(ll i=0;i<n;i++)cin>>values[i];
coins(values, x, n);
// for(ll i=1;i<=x;i++)cout<<i<<" ";
// cout<<"\n";
// for(ll i=1;i<=x;i++)cout<<dp[i]<<" ";
// cout<<"\n";
if(dp[x]!=INF)cout<<dp[x]<<"\n";
else cout<<"-1\n";
return 0;
}
