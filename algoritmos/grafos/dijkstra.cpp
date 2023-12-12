// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define S second
#define F first
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 1e9;
int n;

// No usar con pesos negativos
// O (n+mlog(m))
vi dijkstra(vector<vii> &adj, int s){
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push({0, s});
  vi dist(n+1, INF); 
  dist[s]=0;
  while(!pq.empty()){
    ii act=pq.top(); pq.pop();
    int d=act.F,u=act.S;
    if(d>dist[u])continue;
    for(auto v:adj[u]){
      if(dist[u]+v.S<dist[v.F]){
        dist[v.F]=dist[u]+v.S;
        pq.push({dist[v.F],v.F});
      }
    }
  }
  return dist;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int m,s;
  cin>>n>>m>>s;
  vector<vii> adj(n+1);
  for(int i=0,a,b,w;i<m;++i){
    cin>>a>>b>>w;
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
  }
  vi dist=dijkstra(adj,s);
  for(int i=1;i<=n;i++)cout<<dist[i]<<" ";
  return 0;
}