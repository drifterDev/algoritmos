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
vi cities,towers;

bool f(ll act){
  for(auto c:cities){
    auto lower=lower_bound(all(towers),c);
    int id=distance(towers.begin(),lower);
    if(id==0){
      if(abs(c-towers[id])<=act)continue;
      return false;
    }else if(id==sz(towers)){
      if(abs(c-towers[id-1])<=act)continue;
      return false;
    }else{
      int index=(abs(c-towers[id-1])<abs(c-towers[id])?id-1:id);
      if(abs(c-towers[index])<=act)continue;
      return false;
    }
  }
  return true;
}

ll binary_search() {
  ll l=0,r=2*1e9;
  while(l<=r) {
    ll m=l+(r-l)/2;
    if(f(m))r=m-1;
    else l=m+1;
  }
  return r+1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  int n,m,tmp;cin>>n>>m;
  while(n--){cin>>tmp;cities.PB(tmp);}
  while(m--){cin>>tmp;towers.PB(tmp);}
  cout<<binary_search()<<"\n";
  return 0;
}