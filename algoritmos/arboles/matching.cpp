// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
typedef vector<int> vi;
vector<bool> visited;
vector<vi> adj;
int ans=0;

// Maximo matching en arboles
void dfs(int v, int p=0){
  for(auto u:adj[v]){
    if(u==p)continue;
    dfs(u,v);
  }
  if(p==0)return;
  if(!visited[v] && !visited[p]){
    visited[v]=true;
    visited[p]=true;
    ans++;
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  int n;cin>>n;
  visited.assign(n+1, false);
  adj.assign(n+1,vi());
  for(int i=0,a,b;i<n-1;++i){
    cin>>a>>b;
    adj[a].PB(b);
    adj[b].PB(a);
  }
  dfs(1);
  cout<<ans<<"\n";
  return 0;
}