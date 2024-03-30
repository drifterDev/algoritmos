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
const int maxn=200001;
int n,tmp;

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  cin>>n;
  vector<vi> res(maxn, vi());
  vi nums;
  int m=0;

  while(n--){
    cin>>tmp;
    int l=0,r=m-1;
    
    if(m==0){
      nums.PB(tmp);
      res[0].PB(tmp);
      m++;continue;
    }

    while(l<=r){
      int mid=l+(r-l)/2;
      if(nums[mid]<=tmp)r=mid-1;
      else l=mid+1;
    }
    // cout<<l<<" "<<r<<"\n";

    if(r+1==0){
      nums[0]=tmp;
      res[0].PB(tmp);
    }else if(l==m){
      m++;
      nums.PB(tmp);
      res[l].PB(tmp);
    }else{
      nums[r+1]=tmp;
      res[r+1].PB(tmp);
    }
  }

  int i=0;
  while(sz(res[i])){
    for(auto y:res[i])cout<<y<<" ";
    cout<<"\n";
    i++;
  }
  return 0;
}
