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

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  int a,b,n,q;cin>>n>>q;
  vi nums(n);
  for(int i=0;i<n;++i)cin>>nums[i];
  sort(all(nums));
  while(q--){
    cin>>a>>b;
    auto lower=lower_bound(all(nums),a);
    auto upper=upper_bound(all(nums),b);
    int id1=distance(nums.begin(),lower);
    int id2=distance(nums.begin(),upper);
    cout<<id2-id1<<"\n";
  }
  return 0;
}