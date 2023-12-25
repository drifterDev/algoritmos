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
int n,k;

bool f(vl& nums, ll tmp){
  ll act=0,j=0;
  for(int i=0;i<k;++i){
    act=nums[j];
    act+=2*tmp;
    // watch(act);
    while(act>=nums[j]){
      j++;
      if(j==n)return true;
    }
    // watch(j);
  }
  return false;
}

ll binary_search(vl& nums){
  ll l=0,r=1e9/2+1;
  while(l<=r){
    ll mid=l+(r-l)/2;
    if(f(nums, mid))r=mid-1;
    else l=mid+1;
  }
  return r+1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  cin>>n>>k;
  vl nums(n);
  for(int i=0;i<n;++i)cin>>nums[i];
  sort(all(nums));
  // cout<<binary_search(nums)<<"\n";
  cout<<f(nums, 5)<<"\n";
  return 0;
}