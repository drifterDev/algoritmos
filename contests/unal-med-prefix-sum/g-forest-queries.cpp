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
  int n,q;char c;cin>>n>>q;
  vector<vl> matrix(n+1, vl(n+1,0));
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      cin>>c;
      matrix[i][j]=(c=='*'?1:0);
      matrix[i][j]+=matrix[i][j-1];
    }
  }
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      matrix[i][j]+=matrix[i-1][j];
    }
  }
  // for(auto x:matrix){
  //   for(auto y:x)cout<<y<<" ";
  //   cout<<"\n";
  // }
  int x1,x2,y1,y2;
  while(q--){
    cin>>x1>>y1>>x2>>y2;
    ll part1=matrix[x2][y2]+matrix[x1-1][y1-1];
    ll part2=matrix[x2][y1-1]+matrix[x1-1][y2];
    cout<<part1-part2<<"\n";
  }
  return 0;
}