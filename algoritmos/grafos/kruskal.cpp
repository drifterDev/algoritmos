// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
int n,m;

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

// O(mlogn)
void kruskal(vector<pair<int,ii>>& edges){
  sort(all(edges));
  dsu uf(n);
  ll res=0;
  vii mst;
  for(auto& e:edges){
    if(!uf.isSameSet(e.S.F,e.S.S)){
      uf.unionSets(e.S.F,e.S.S);
      res+=e.F;
      mst.PB(e.S);
    }
  }
  for(auto& e:mst)cout<<e.F+1<<" "<<e.S+1<<"\n";
  cout<<res<<"\n";
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  cin>>n>>m;
  vector<pair<int,ii>> edges;
  for(int i=0,u,v,w;i<m;++i){
    cin>>u>>v>>w;
    edges.PB({w,{u-1,v-1}});
  }
  kruskal(edges);
  return 0;
}