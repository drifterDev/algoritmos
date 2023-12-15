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
typedef vector<string> vs;
typedef vector<ii> vii;
const double PI = acos(-1);
const double EPS = 1e-9;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFL = 1152921504606846976;
int dx4[4] = {0,-1,1,0};
int dy4[4] = {-1,0,0,1};
int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
int n;

vl dijkstra(vector<vpll> &adj, vi& polices){
  priority_queue<pll, vpll, greater<pll>> pq;
  vl dist(n, INFL); 
  for(auto s:polices){
    pq.push({0,s});
    dist[s]=0;
  }
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
  // for(auto x:dist)cout<<x<<" ";
  // cout<<"\n";
  return dist;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  cin>>n;
  while(n!=-1){
    int m,b,p;
    cin>>m>>b>>p;
    vector<vpll> adj(n);
    for(int i=0,a,b,w;i<m;++i){
      cin>>a>>b>>w;
      adj[a].PB({b,w});
      adj[b].PB({a,w});
    }
    vi banks(b,0), polices(p,0);
    for(int i=0;i<b;++i)cin>>banks[i];
    for(int i=0;i<p;++i)cin>>polices[i];
    sort(all(banks));
    vl dist=dijkstra(adj, polices);
    ll maximo=0;
    ll res=0;
    for(int i=0;i<b;++i)maximo=max(maximo, dist[banks[i]]);
    for(int i=0;i<b;++i)if(maximo==dist[banks[i]])res++;
    if(maximo==INFL)cout<<res<<" *\n";
    else cout<<res<<" "<<maximo<<"\n";
    for(int i=0;i<b;++i)if(maximo==dist[banks[i]]){
      res--;
      cout<<banks[i]<<(res?" ":"\n");
    }
    n=-1;
    cin>>n;
  }
  return 0;
}

