// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
int n;

// O(n+mlog(m))
vl dijkstra(vector<vll> &adj, int s){
  priority_queue<pll, vll, greater<pll>> pq;
  pq.push({0, s});
  vl dist(n, LONG_LONG_MAX); 
  dist[s]=0;
  while(!pq.empty()){
    pll act=pq.top();pq.pop();
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
  vector<vll> adj(n);
  for(int i=0,a,b,w;i<m;++i){
    cin>>a>>b>>w;
    adj[a-1].PB({b-1,w});
    adj[b-1].PB({a-1,w});
  }
  vl dist=dijkstra(adj,s-1);
  for(int i=0;i<n;i++)cout<<dist[i]<<" ";
  return 0;
}