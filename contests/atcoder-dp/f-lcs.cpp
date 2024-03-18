// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  string s,t;cin>>s>>t;
  int n=sz(s),m=sz(t);
  vector<vi> dp(n+1,vi(m+1,0));
  for(int i=1;i<=n;++i){
    for(int j=1;j<=m;++j){
      dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
      if(s[i-1]==t[j-1]){
        dp[i][j]=max(dp[i][j], dp[i-1][j-1]+1);
      }
    }
  }
  // Construir la respuesta
  int x=n,y=m;
  vector<char> res;
  while(dp[x][y]!=0){
    if(dp[x-1][y]==dp[x][y])x--;
    else if(dp[x][y-1]==dp[x][y])y--;
    else{
      res.PB(s[x-1]);
      x--;y--;
    }
  }
  reverse(all(res));
  for(auto x:res)cout<<x;
  cout<<"\n";
  return 0;
}