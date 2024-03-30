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
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int n,m;cin>>n>>m;
  dsu uf(n);
  for(int i=0,a,b;i<m;++i){
    cin>>a>>b;
    uf.unionSets(a-1,b-1);
  }
  vi sets(n,0);
  for(int i=0;i<n;++i)sets[i]=uf.findSet(i);
  // for(auto x:sets)cout<<x<<" ";
  int p,tmp1,tmp2;cin>>p;
  set<ii> prohibidos;
  for(int a,b,i=0;i<p;++i){
    cin>>a>>b;
    tmp1=sets[a-1];
    tmp2=sets[b-1];
    prohibidos.insert({min(tmp1,tmp2), max(tmp1,tmp2)});
  }
  // for(auto x:prohibidos)cout<<x.F<<" "<<x.S<<"\n";
  int q;cin>>q;
  while(q--){
    cin>>tmp1>>tmp2;
    tmp1=uf.findSet(tmp1-1);
    tmp2=uf.findSet(tmp2-1);
    if(prohibidos.count({min(tmp1,tmp2),max(tmp1,tmp2)}))cout<<"No\n";
    else cout<<"Yes\n";
  }
  return 0;
}