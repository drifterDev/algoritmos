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
  string s;cin>>s;
  int n=sz(s);
  vector<vi> prefix(26, vi(n+1,0));
  for(int i=0;i<n;++i){
    for(int j=0;j<26;++j){
      prefix[j][i+1]=prefix[j][i];
    }
    prefix[s[i]-'a'][i+1]++;
  }
  int l,r,q;cin>>q;
  while(q--){
    cin>>l>>r;
    if(l==r)cout<<"Yes\n";
    else{
      int ans=0;
      for(int i=0;i<26;++i){
        if(prefix[i][r]-prefix[i][l-1]){
          ans++;
          // cout<<prefix[i][r]-prefix[i][l-1]<<"\n";
        }
      }
      if(ans>=3 || s[l-1]!=s[r-1])cout<<"Yes\n";
      else cout<<"No\n";
    }
  }
  // for(auto x:prefix){
  //   for(auto y:x)cout<<y<<" ";
  //   cout<<"\n";
  // }
  return 0;
}