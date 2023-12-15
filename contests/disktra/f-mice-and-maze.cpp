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
const ll INFL = 1e18;
int dx4[4] = {0,-1,1,0};
int dy4[4] = {-1,0,0,1};
int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;    
int n;

bool dijkstra(vector<vpll> &adj, int s, ll time,ll end){
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
  if(end==s)return true;
  return dist[end]<=time;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // int t;cin>>t;
  // while(t--){
    ll m,end,time;
    cin>>n>>end>>time>>m;
    vector<vpll> adj(n);
    for(int i=0,a,b,w;i<m;++i){
      cin>>a>>b>>w;
      adj[a-1].PB({b-1,w});
    }
    int res=0;
    for(int i=0;i<n;++i){
      if(dijkstra(adj,i,time,end-1))res++;
    }cout<<res<<"\n";
  // }
  return 0;
}