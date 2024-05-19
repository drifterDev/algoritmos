// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll> tp;

// primero a o b
// sb-wa o sa-wb => sb+wb o sa+wa, el que tenga mayor valor
bool comp(const tp& a,const tp& b){
    return get<0>(a)+get<1>(a)>get<0>(b)+get<1>(b);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    cin>>n;
    vector<tp> blocks;
    ll w,s,v;
    for(int i=0;i<n;++i){
        cin>>w>>s>>v;
        blocks.push_back({w,s,v});
    }
    sort(blocks.begin(), blocks.end(), comp);
    // maximo valor de torre con capacidad restante i
    vector<ll> dp(20001, 0);
    ll ans=0;
    for(auto x:blocks){
        w=get<0>(x);
        s=get<1>(x);
        v=get<2>(x);
        for(ll i=w;i<=20000;++i){
            if(i-w>s)break;
            dp[i-w]=max(dp[i-w], dp[i]+v);
            ans=max(ans, dp[i-w]);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
