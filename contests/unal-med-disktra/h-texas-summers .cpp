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
typedef pair<int, double> par;
typedef vector<par> vecto;
int n;

void dijkstra(vector<vecto>& adj){
  priority_queue<par, vecto, greater<par>> pq;
  vector<double> dist(n+2, LONG_LONG_MAX); 
  pq.push({n, 0});
  dist[n]=0;
  vi path(n+2,-1);
  while(!pq.empty()){
    par act=pq.top();pq.pop();
    int u=act.F;double d=act.S;
    if(d>dist[u])continue;
    for(auto v:adj[u]){
      int b=v.F;
      double w=(v.S)*(v.S);
      if(dist[u]+w<dist[b]){
        dist[b]=dist[u]+w;
        path[b]=u;
        pq.push({b,dist[b]});
      }
    }
  }
  // for(int i=0;i<n+2;++i){
  //   cout<<i<<" "<<dist[i]<<"\n";
  // }
  if(path[n+1]==n)cout<<"-\n";
  else{
    vi res;
    for(int v=path[n+1];v!=n;v=path[v]){
      res.PB(v);
    }
    for(int i=sz(res)-1;i>=0;--i)cout<<res[i]<<"\n";
    cout<<"\n";
  }
  // return dist;
}

double dist(int x1,int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  cin>>n;
  vii puntos(n+2);
  vector<vecto> adj(n+2);
  for(int i=0,a,b;i<n+2;++i){
    cin>>a>>b;puntos[i]={a,b};
  }
  for(int i=0;i<n+2;++i){
    for(int j=i+1;j<n+2;++j){
      double dista=dist(puntos[i].F, puntos[i].S, puntos[j].F, puntos[j].S);
      adj[i].PB({j, dista});
      adj[j].PB({i, dista});
    }
  }
  dijkstra(adj);
  return 0;
}
