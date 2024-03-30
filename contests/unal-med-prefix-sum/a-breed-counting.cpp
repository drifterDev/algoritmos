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
typedef vector<string> vs;
typedef vector<ii> vii;
const double PI = acos(-1);
const double EPS = 1e-9;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFL = 1e18;
int dx4[4] = {0,-1,1,0};
int dy4[4] = {-1,0,0,1};
int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  int n,q;cin>>n>>q;
  vi a(n+1,0),b(n+1,0),c(n+1,0);
  for(int tmp,i=1;i<=n;++i){
    cin>>tmp;
    if(tmp==1)a[i]++;
    else if(tmp==2)b[i]++;
    else c[i]++;
    a[i]+=a[i-1];
    b[i]+=b[i-1];
    c[i]+=c[i-1];
  }
  // for(auto x:a)cout<<x<<" ";
  // cout<<"\n";
  // for(auto x:b)cout<<x<<" ";
  // cout<<"\n";
  // for(auto x:c)cout<<x<<" ";
  // cout<<"\n";
  int tmp1,tmp2;
  while(q--){
    cin>>tmp1>>tmp2;
    cout<<a[tmp2]-a[tmp1-1]<<" ";
    cout<<b[tmp2]-b[tmp1-1]<<" ";
    cout<<c[tmp2]-c[tmp1-1]<<"\n";
  }
  return 0;
}