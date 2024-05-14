// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> adj;
vector<vector<ll>> dp3,dp4;
vector<ll> dp1,dp2;
int n;
ll m;

ll mod(ll a){return ((a%m)+m)%m;}
ll suma(ll a, ll b){return mod(mod(a)+mod(b));}
ll mult(ll a, ll b){return mod(mod(a)*mod(b));}

void dfs1(int v=1,int p=0){
    dp1[v]=1;
    dp3[v].push_back(1);
    for(auto u:adj[v]){
        if(u==p)continue;
        dfs1(u,v);
        dp1[v]=mult(dp1[v], suma(dp1[u], 1));
        dp3[v].push_back(suma(dp1[u], 1));
        dp4[v].push_back(suma(dp1[u], 1));
    }
    dp4[v].push_back(1);
    int h=dp3[v].size();
    for(int i=1;i<h;++i){
        dp3[v][i]=mult(dp3[v][i], dp3[v][i-1]);
        dp4[v][h-1-i]=mult(dp4[v][h-1-i], dp4[v][h-i]);
    }
}

void dfs2(int v=1, int p=0){
    int i=1;
    int h=dp3[v].size();
    for(auto u:adj[v]){
        if(u==p)continue;
        ll tmp=mult(dp3[v][i-1], dp4[v][i]);
        dp2[u]=suma(1, mult(dp2[v], tmp));
        dfs2(u,v);
        i++;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    adj.assign(n+1,vector<int>());
    dp1.assign(n+1, 0);
    dp2.assign(n+1, 0);
    dp3.assign(n+1, vector<ll>());
    dp4.assign(n+1, vector<ll>());
    for(int a,b,i=1;i<=n-1;++i){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1();
    dp2[1]=1ll;
    dfs2();
    for(int i=1;i<=n;++i){
        cout<<mult(dp1[i],dp2[i])<<"\n";
    }
    return 0;
}
