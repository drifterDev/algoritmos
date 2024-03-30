// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
int n,m;

void dfs(vector<vi>& adj, vi& dp, int v, vi& order){
  if(dp[v]!=-1)return;
  dp[v]=0;
  for(auto u:adj[v]){
    dfs(adj, dp, u, order);
    dp[v]=max(dp[v], 1+dp[u]);
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  cin>>n>>m;
  vector<vi> adj(n,vi());
  vi order(n,0),dp(n,-1);
  for(int i=0,a,b;i<m;++i){
    cin>>a>>b;
    adj[a-1].PB(b-1);
    order[b-1]++;
  }
  for(int i=0;i<n;++i){
    if(order[i]==0 && dp[i]==-1){
      dfs(adj, dp, i, order);
    }
  }
  int ans=0;
  for(auto x:dp)ans=max(ans, x);
  cout<<ans<<"\n";
  return 0;
}