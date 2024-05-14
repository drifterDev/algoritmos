// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

ll mod(ll a){
	return ((a%MOD)+MOD)%MOD;
}

ll suma(ll a, ll b){
    return mod(mod(a)+mod(b));
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    vector<ll> dp(1<<n,0);
    vector<vector<bool>> mat(n, vector<bool>(n,false));
    for(int i=0;i<n;++i){
        for(int j=0,a;j<n;++j){
            cin>>a;mat[i][j]=a==1;
        }
    }
    dp[0]=1;
    for(int s=1;s<(1<<n);++s){
        for(int i=0;i<n;++i){
            if(!(s&(1<<i)))continue;
            int count=__builtin_popcount(s^(1<<i));
            if(!mat[count][i])continue;
            dp[s]=suma(dp[s], dp[s^(1<<i)]);
        }
    }
    cout<<dp[(1<<n)-1]<<"\n";
    return 0;
}
