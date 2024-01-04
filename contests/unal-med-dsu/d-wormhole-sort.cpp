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
const double EPS = 1e-9;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFL = 1e18;
const int dirx[8] = {0,1,0,-1,1,1,-1,-1};
const int diry[8] = {1,0,-1,0,1,-1,1,-1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";
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
bool kruskal(vector<pair<int,ii>>& edges,int act, vi& nums){
  dsu uf(n);
  for(int i=m-1;i>=0;--i){
    if(edges[i].F<act)break;
    uf.unionSets(edges[i].S.F, edges[i].S.S);
    // cout<<edges[i].F<<" ";
  }
  // cout<<"\n";
  for(int i=0;i<n;++i){
    if(!uf.isSameSet(nums[i], i))return false;
  }
  return true;
}


int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  freopen("wormsort.in", "r", stdin);
  freopen("wormsort.out", "w", stdout);
  cin>>n>>m;
  vi nums(n);
  vector<pair<int, ii>> edges(m);
  int cambios=0;
  for(int i=0;i<n;++i){
    cin>>nums[i];
    nums[i]--;
    if(nums[i]!=i)cambios++;
  }
  int l=INF,r=0;
  for(int i=0,a,b,c;i<m;++i){
    cin>>a>>b>>c;
    edges[i]={c,{a-1,b-1}};
    l=min(l,c);r=max(r,c);
  }
  sort(all(edges));
  if(cambios==0){
    cout<<"-1\n";return 0;
  }
  while(l<=r){
    int mid=l+(r-l)/2;
    if(kruskal(edges,mid,nums))l=mid+1;
    else r=mid-1;
  }
  cout<<l-1<<"\n";
  return 0;
}
