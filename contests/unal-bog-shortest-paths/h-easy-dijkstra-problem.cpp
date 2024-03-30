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
typedef vector<pll> vpll;
int n;

// O(n+mlog(m))
void dijkstra(vector<vpll> &adj, int s, int r){
  priority_queue<pll, vpll, greater<pll>> pq;
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
  if(dist[r]==LONG_LONG_MAX)cout<<"NO\n";
  else cout<<dist[r]<<"\n";
}

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  int t;cin>>t;
  while(t--){
    int m,a1,b1;
    cin>>n>>m;
    vector<vpll> adj(n);
    for(int i=0,a,b,w;i<m;++i){
      cin>>a>>b>>w;
      adj[a-1].PB({b-1,w});
    }
    cin>>a1>>b1;
    dijkstra(adj,a1-1,b1-1);
  }
  return 0;
}