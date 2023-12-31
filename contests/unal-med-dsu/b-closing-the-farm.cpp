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
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);
  int n,m;cin>>n>>m;
  dsu uf(n);
  vi nums(n,0);
  vector<vi> adj(n,vi());
  for(int i=0,a,b;i<m;++i){
    cin>>a>>b;
    adj[a-1].PB(b-1);
    adj[b-1].PB(a-1);
  }
  vi res(n,0);
  for(int i=0;i<n;++i){
    cin>>res[i];res[i]--;
  }
  int j=1;
  vector<bool> ans(n,false);
  for(int i=n-1;i>=0;--i){
   nums[res[i]]=1;
    for(auto x:adj[res[i]])if(nums[x])uf.unionSets(x,res[i]);
    ans[i]=uf.maxSz==j;
    j++;
  }
  for(auto x:ans)cout<<(x?"YES":"NO")<<"\n";
  return 0;
}