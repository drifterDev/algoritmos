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
const ll INFL = LONG_LONG_MAX;
typedef pair<ll, ll> pll;
typedef pair<ll, pair<ll, pair<ll,ll>>> pares;
typedef vector<pll> vpll;
int n;

vl dijkstra(vector<vector<pares>> &adj, int s){
  priority_queue<pll, vpll, greater<pll>> pq;
  pq.push({0, s});
  vl dist(n, INFL); 
  dist[s]=0;
  // adj[a].PB({b,{d,{t,p}}});
  while(!pq.empty()){
    pll act=pq.top();pq.pop();
    ll d=act.F,u=act.S;
    if(d>dist[u])continue;
    for(auto v:adj[u]){
      ll b=v.F,dis=v.S.F,t=v.S.S.F,p=v.S.S.S,w;
      if(d<=t){
        w=t+dis;
      }else{
        if(p==0)w=INFL;
        else{
          ll tmp1,tmp2;
          tmp1=d-t;
          tmp2=tmp1/p;
          if(tmp1%p!=0)tmp2++;
          w=t+tmp2*p+dis;
        }
      } 
      if(w<dist[b]){
        dist[b]=w;
        pq.push({w,b});
      }
    }
  }
  return dist;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int m,s,q;
  cin>>n>>m>>q>>s;
  while(n!=0 || m!=0 || q!=0 || s!=0){
    vector<vector<pares>> adj(n);
    ll a,b,t,p,d;
    for(int i=0;i<m;++i){
      cin>>a>>b>>t>>p>>d;
      adj[a].PB({b,{d,{t,p}}});
    }
    vl dist=dijkstra(adj,s);
    int tmp;
    while(q--){
      cin>>tmp;
      if(dist[tmp]==INFL)cout<<"Impossible\n";
      else cout<<dist[tmp]<<"\n";
    }
    cin>>n>>m>>q>>s;
  }
  return 0;
}
