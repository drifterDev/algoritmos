// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

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

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  freopen("mootube.in", "r", stdin);
  freopen("mootube.out", "w", stdout);
  int n,q;cin>>n>>q;

  vector<pair<int, ii>> edges(n-1);
  vector<pair<int, ii>> queries(q);
  vi res(q,0);
  dsu uf(n);

  for(int a,b,w,i=0;i<n-1;++i){
    cin>>a>>b>>w;
    edges[i]={w,{a-1,b-1}};
  }
  for(int w,u,i=0;i<q;++i){
    cin>>w>>u;
    queries[i]={w,{u-1,i}};
  }
  sort(all(queries));
  sort(all(edges));

  int i=n-2;
  for(int j=q-1;j>=0;--j){
    if(i>=0)while(queries[j].F<=edges[i].F){
      uf.unionSets(edges[i].S.F, edges[i].S.S);
      i--;if(i<0)break;
    }
    res[queries[j].S.S]=uf.sizes[uf.findSet(queries[j].S.F)]-1;
    // watch(uf.findSet(queries[j].S.F));
    // for(auto x:uf.sizes)cout<<x<<" ";
    // cout<<"\n";
  }
  for(auto x:res)cout<<x<<"\n";
  return 0;
}