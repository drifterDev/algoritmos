// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD =1e9+7;

ll mod(ll a){return ((a%MOD)+MOD)%MOD;}
ll suma(ll a, ll b){return mod(mod(a)+mod(b));}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    string s;
    cin>>n>>s;
    // estados: [1...i disponibles][permutación finaliza en j]
    vector<vector<ll>> dp(n, vector<ll>(n,0));
    dp[0][0]=1;
    for(int i=1;i<n;++i){
        ll tmp=0;
        if(s[i-1]=='<'){
            for(int j=0;j<i+1;++j){
                dp[i][j]=tmp;
                tmp=suma(tmp, dp[i-1][j]);
            }
        }else{
            for(int j=n-1;j>=0;--j){
                tmp=suma(tmp, dp[i-1][j]);
                dp[i][j]=tmp;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<n;++i){
        ans=suma(ans, dp[n-1][i]);
    }
    cout<<ans<<"\n";
    return 0;
}
