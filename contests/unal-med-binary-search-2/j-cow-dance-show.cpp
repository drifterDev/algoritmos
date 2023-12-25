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
int n,maxt;

bool f(vi& nums, int tmp){
  priority_queue<int, vector<int>,greater<int>> pq;
  for(int i=0;i<tmp;++i)pq.push(nums[i]);
  for(int i=tmp;i<n;++i){
    int act=pq.top();pq.pop();
    act+=nums[i];
    if(act>maxt)return false;
    pq.push(act); 
  }
  return true;
}

ll binary_search(vi& nums){
  ll l=1,r=n;
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
  cin>>n>>maxt;
  vi nums(n);
  for(int i=0;i<n;++i)cin>>nums[i];
  cout<<binary_search(nums)<<"\n";
  // for(int i=1;i<=n;++i){
  //   cout<<f(nums, i)<<"\n";
  // }
  return 0;
}