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

bool repartir(vl& nums, ll act, ll k){
  ll tmp=0;
  for(auto x:nums){
    if(x>act)continue;
    tmp+=act-x;
  }
  return tmp<=k;
}

ll binary_search(vl& nums, ll k){
  ll l=0,r=2000000000;
  while(l<=r) {
    ll m=l+(r-l)/2;
    if(repartir(nums, m, k))l=m+1;
    else r=m-1;
  }return l-1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  ll n,k;cin>>n>>k;
  vl nums(n);
  vl res;
  for(int i=0;i<n;++i)cin>>nums[i];
  sort(all(nums));
  for(int i=0;i<=n/2;++i)res.PB(nums[i+n/2]);
  cout<<binary_search(res, k)<<"\n";
  return 0;
}