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
int n;

// No usar con pesos negativos
// O (n+mlog(m))
vi dijkstra(vector<vii> &adj, int s){
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push({0, s});
  vi dist(n, INT_MAX); 
  dist[s]=0;
  while(!pq.empty()){
    ii act=pq.top();pq.pop();
    int d=act.F,u=act.S;
    if(d>dist[u])continue;
    for(auto v:adj[u]){
      int w=v.S,b=v.F;
      if(dist[u]+w<dist[b]){
        dist[b]=dist[u]+w;
        pq.push({dist[b],b});
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
  vector<vii> adj(n);
  for(int i=0,a,b,w;i<m;++i){
    cin>>a>>b>>w;
    adj[a-1].push_back({b-1,w});
    adj[b-1].push_back({a-1,w});
  }
  vi dist=dijkstra(adj,s-1);
  for(int i=0;i<n;i++)cout<<dist[i]<<" ";
  return 0;
}