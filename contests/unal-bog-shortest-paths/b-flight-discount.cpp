// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const double EPS = 1e-9;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFL = 1e18;
const int dirx[8] = {0,1,0,-1,1,1,-1,-1};
const int diry[8] = {1,0,-1,0,1,-1,1,-1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
int n;

// O(n+mlog(m))
vl dijkstra(vector<vpll> &adj, int s){
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
  return dist;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int m;
  cin>>n>>m;
  vector<vpll> adj1(n);
  vector<vpll> adj2(n);
  for(int i=0,a,b,w;i<m;++i){
    cin>>a>>b>>w;
    adj1[a-1].PB({b-1,w});
    adj2[b-1].PB({a-1,w});
  }
  vl dist1=dijkstra(adj1,0);
  vl dist2=dijkstra(adj2,n-1);
  ll minimo=LONG_LONG_MAX;
  for(int i=0;i<n;++i){
    for(auto j:adj1[i]){
      if(dist1[i]==LONG_LONG_MAX || dist2[j.F]==LONG_LONG_MAX)continue;
      minimo=min(minimo, dist1[i]+dist2[j.F]+(j.S/2));
      // cout<<i<<" "<<j.F<<"\n";
    }
  }
  cout<<minimo<<"\n";
  return 0;
}
