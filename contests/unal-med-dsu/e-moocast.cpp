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
int n;

struct dsu{
  vl parents,sizes;
  ll numSets;
  ll maxSz;

  dsu(ll n){
    parents.assign(n,0);
    sizes.assign(n,1);
    numSets=n;
    maxSz=1;
    for(int i=0;i<n;++i)parents[i]=i;
  }

  ll findSet(ll v){
    if(v==parents[v])return v;
    return parents[v]=findSet(parents[v]);
  }

  bool isSameSet(ll i,ll j){
    return findSet(i)==findSet(j);
  }

  void unionSets(ll a, ll b){
    a=findSet(a);
    b=findSet(b);
    if(a!=b){
      if(sizes[a]<sizes[b])swap(a, b);
      parents[b]=a;
      sizes[a]+=sizes[b];
      maxSz=max(maxSz,sizes[a]);
      numSets--;
    }
  }
};

void kruskal(vector<pair<ll,ii>>& edges){
  sort(all(edges));
  dsu uf(n);
  ll res=0;
  for(auto& e:edges){
    if(!uf.isSameSet(e.S.F,e.S.S)){
      uf.unionSets(e.S.F,e.S.S);
      res=max(res, e.F);
    }
  }
  cout<<res<<"\n";
}

struct point{
  ll x,y;
  point(): x(0),y(0){}
  point(ll _x,ll _y): x(_x),y(_y){}
};

ll dist(point p1, point p2){
  return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  freopen("moocast.in", "r", stdin);
  freopen("moocast.out", "w", stdout);
  cin>>n;
  vector<point> puntos(n);
  for(int a,b,i=0;i<n;++i){
    cin>>a>>b;
    point tmp(a,b);
    puntos[i]=tmp;
  }
  vector<pair<ll, ii>> edges;
  for(int i=0;i<n;++i){
    for(int j=i+1;j<n;++j){
      ll tmp2=dist(puntos[i],puntos[j]);
      edges.PB({tmp2, {i,j}});
    }
  }
  kruskal(edges);
  return 0;
}