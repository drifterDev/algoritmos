// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
const int maxn=1e5;
const int m=1e9+7;
ll dp[maxn+2][2];
int n;

ll mod(ll a){
	return ((a%m)+m)%m;
}

ll suma(ll a, ll b){
    return mod(mod(a)+mod(b));
}

ll multi(ll a, ll b){
    return mod(mod(a)*mod(b));
}

void dfs(int v, int p=-1){
    ll w=1,b=1;
    for(auto u:adj[v]){
        if(u==p)continue;
        dfs(u,v);
        w=multi(w, suma(dp[u][0],dp[u][1]));
        b=multi(b, dp[u][0]);
    }
    dp[v][0]=w;
    dp[v][1]=b;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n;
    adj.assign(n+1, vector<int>());
    for(int a,b,i=0;i<n-1;++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout<<suma(dp[1][0],dp[1][1])<<"\n";
    return 0;
}
