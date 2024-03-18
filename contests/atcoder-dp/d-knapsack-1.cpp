// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int n,w;cin>>n>>w;
  vi ws(n);vl vs(n);
  for(int i=0;i<n;++i){
    cin>>ws[i]>>vs[i];
  }
  vector<vl> dp(n+1, vl(w+1, 0));
  for(int i=1;i<=n;++i){
    for(int j=1;j<=w;++j){
      ll tmp=0;
      if(j-ws[i-1]>=0){
        tmp=dp[i-1][j-ws[i-1]]+vs[i-1];
      }
      dp[i][j]=max(tmp, max(dp[i][j-1], dp[i-1][j]));
    }
  }
  cout<<dp[n][w]<<"\n";
  return 0;
}