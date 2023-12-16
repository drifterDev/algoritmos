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
typedef pair<ll, pair<ll, pair<ll,pair<ll, ll>>>> pares;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
int n;

void dijkstra(vector<vector<pares>> &adj){
  priority_queue<pll, vpll, greater<pll>> pq;
  pq.push({0, 0});
  vector<pair<ll, ll>>dist(n);
  for(int i=0;i<n;++i)dist[i]={INFL, INFL}; 
  dist[0]={0,0};
  // {b,{d,{t,{f,c}}}};
  while(!pq.empty()){
    pll act=pq.top();pq.pop();
    ll d=act.F,u=act.S;
    ll money=dist[u].S;

    if(d>dist[u].F)continue;

    for(auto v:adj[u]){
      ll b=v.F,dis=v.S.F,t=v.S.S.F,p=v.S.S.S.F,c=v.S.S.S.S,w;
      
      if(d<t){
        w=t-d+dis;
      }else{
        w=p-((d-t)%p)+dis;
      } 

      ll monkey=money+c;
      if(w+d<dist[b].F || (monkey<dist[b].S && w+d==dist[b].F)){
        dist[b].F=w+d;
        dist[b].S=monkey;
        pq.push({w+d,b});
      }
    }
  }
  // for(auto x:dist)cout<<x.F<<" "<<x.S<<"\n";
  cout<<dist[n-1].F<<" "<<dist[n-1].S<<"\n";
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int m;
  cin>>n>>m;
  vector<vector<pares>> adj(n);
  ll a,b,t,f,s,c;
  for(int i=0;i<m;++i){
    cin>>a>>b>>t>>c>>f>>s;
    adj[a-1].PB({b-1, {t, {s, {f, c}}}});
  }
  dijkstra(adj);
  return 0;
}
