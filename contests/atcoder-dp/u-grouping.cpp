// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;cin>>n;
    vector<ll> dp((1<<n), 0);
    vector<ll> cost(1<<n, 0);
    vector<vector<ll>> mat(n,vector<ll>(n,0));

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>mat[i][j];
        }
    }

    for(int s=0;s<(1<<n);++s){
        for(int i=0;i<n;++i){
            if(!(s&(1<<i)))continue;
            for(int j=i+1;j<n;++j){
                if(!(s&(1<<j)))continue;
                cost[s]+=mat[i][j];
            }
        }
    }

    ll ans=0;
    for(int s=1;s<(1<<n);++s){
        for(int mask=s;;mask=(mask-1)&s){
            if(mask==0)break;
            ll tmp=dp[s^mask]+cost[mask];
            dp[s]=max(dp[s], tmp);
        }
        ans=max(dp[s], ans);
    }
    cout<<ans<<"\n";
    return 0;
}
