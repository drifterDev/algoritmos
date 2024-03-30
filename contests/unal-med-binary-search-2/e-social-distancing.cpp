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
ll n,m;

bool f(vector<pair<ll, ll>>& intervals, ll d){
  ll act=intervals[0].F;
  int j=0;
  for(int i=1;i<n;++i){
    if(act+d<=intervals[j].S)act+=d;
    else if(act+d>intervals[j].S){
      while(act+d>intervals[j].S){
        j++;
        if(j==m)return false;
      }
      act=max(act+d, intervals[j].F);
    }
    // watch(act);
    // watch(j);
  }
  return true;
}

ll binary_search(vector<pair<ll,ll>>& intervals){
  ll l=1,r=intervals[m-1].S;
  while(l<=r){
    ll mid=l+(r-l)/2;
    if(f(intervals, mid))l=mid+1;
    else r=mid-1;
  }
  return l-1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  cin>>n>>m;
  vector<pair<ll, ll>> intervals;
  ll a,b;
  for(int i=0;i<m;++i){
    cin>>a>>b;
    intervals.PB({a,b});
  }
  sort(all(intervals));
  cout<<binary_search(intervals)<<"\n";
  // cout<<f(intervals,9,n)<<"\n";
  return 0;
}