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
int n,m,c;

bool f(vi& nums,int tmp){
  int act=nums[0]+tmp,buses=1,cap=1,i=1;
  while(buses<=m){
    while(act>=nums[i] && cap<=c){
      cap++;
      i++;
      if(i==n)return true;
    }
    buses++;
    cap=1;
    act=nums[i]+tmp;
    // watch(buses);
    // watch(act);
  }
  return false;
}

int binary_search(vi& nums){
  int l=0,r=nums[n-1];
  while(l<=r){
    int mid=l+(r-l)/2;
    if(f(nums, mid))r=mid-1;
    else l=mid+1;
  }
  return r+1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  cin>>n>>m>>c;
  vi nums(n);
  for(int i=0;i<n;++i)cin>>nums[i];
  sort(all(nums));
  cout<<binary_search(nums)<<"\n";
  return 0;
}