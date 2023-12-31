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

int n;
vector<pair<int, ii>> findEdges(vector<vi>& matrix){
  vector<pair<int, ii>> adj;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
      // cout<<i*n+j<<" ";
      for(int k=0;k<4;++k){
        int x=i+dirx[k];
        int y=j+diry[k];
        if(x<0 || x>=n || y<0 || y>=n)continue;
        int costo=abs(matrix[i][j]-matrix[x][y]);
        adj.PB({costo, {i*n+j, x*n+y}});
      }
    }
  }
  return adj;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  freopen("tractor.in", "r", stdin);
  freopen("tractor.out", "w", stdout);
  cin>>n;
  vector<vi> matrix(n, vi(n,0));
  for(int i=0;i<n;++i)for(int j=0;j<n;++j)cin>>matrix[i][j];
  if(n==1){
    cout<<"0\n";
    return 0;
  }
  // for(int i=0;i<n;++i){
  //   for(int j=0;j<n;++j)cout<<matrix[i][j]<<" ";
  //   cout<<"\n";
  // }
  dsu uf(n*n);
  vector<pair<int, ii>> edges=findEdges(matrix);
  sort(all(edges));
  int mitad=(n*n)/2;
  mitad+=(n%2==0?0:1);
  // cout<<mitad<<"\n";
  // for(auto x:edges)cout<<x.F<<" "<<x.S.F<<" "<<x.S.S<<"\n";
  int last=edges[0].F;
  for(auto x:edges){
    if(uf.maxSz>=mitad)break;
    if(!uf.isSameSet(x.S.F,x.S.S)){
      uf.unionSets(x.S.F,x.S.S);
      last=x.F;
    }
  }
  cout<<last<<"\n";
  return 0;
}