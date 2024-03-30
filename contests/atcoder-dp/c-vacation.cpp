// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  int n;cin>>n;
  vi a(n),b(n),c(n);
  vector<vi> dp(3, vi(n+1,0));
  for(int i=0;i<n;++i){
    cin>>a[i]>>b[i]>>c[i];
  }
  for(int i=0;i<n;++i){
    dp[0][i+1]=max(dp[1][i]+a[i], dp[2][i]+a[i]);
    dp[1][i+1]=max(dp[0][i]+b[i], dp[2][i]+b[i]);
    dp[2][i+1]=max(dp[0][i]+c[i], dp[1][i]+c[i]);
  }
  cout<<max(dp[0][n], max(dp[1][n], dp[2][n]))<<"\n";
  return 0;
}